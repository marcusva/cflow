#!/bin/sh
# cflow(1) - a flow graph creator for C, Lex, Yacc and Assembler sources.

# Let the environment override the CC and CPP variables.
: ${CC:="cc"}
: ${CPP:="$CC -E"}

basename=`basename $0`
program=""
graphfile=""
usecpp=0
asparams=""
cgparams=""
cppparams=""
graphviz=0
PROGNAME=$0
# any
usage()
{ 
    echo "usage: $PROGNAME [-aAcCGgnpPr] [-d n] [-D name[=value]] [-i x|_] [-U name]"
    echo "                [-I directory] [-R root] file"
}

# Check the arguments.
while getopts AcCd:D:Gi:I:hpPrR:U: arg; do
    case $arg in
        a)
            asparams="$asparams -a"
            ;;
        A)
            cgparams="$cgparams -A"
            ;;
        c)
            params="$params -c"
            ;;
        C)
            cgparams="$cgparams -C"
            ;;
	d)
	    params="$params -d $OPTARG"
	    ;;
        D)
            cppparams="$cppparams -D $OPTARG"
            ;;
        G)
            params="$cgparams -G"
            ;;
        g)
            graphviz=1
            ;;
	i)
	    params="$params -i $OPTARG"
	    ;;
        I)
            cppparams="$cppparams -I $OPTARG"
            ;;
        n)
            asparams="$asparams -n"
            ;;
	p)
	    usecpp=1
	    ;;
        P)
            params="$cgparams -P"
            ;;
        r)
            params="$params -r"
            ;;
        R)
            params="$params -R $OPTARG"
            ;;
        U)
            cppparams="$cppparams -U $OPTARG"
            ;;
	\? | h)
	    usage
	    exit 2
    esac
done

# Forward the argument list.
shift $(expr $OPTIND - 1)
if [ $# -eq 0 ]; then
    usage
    exit 1
fi

# Check for the file and invoke the correct graph generator.
for f in $@; do
    case $f in
	*.c|*.cc|*.C)
	    program="cgraph"
	    graphfile=$f
            params="$cgparams $params"
	    ;;
	*.i)
	    program="cgraph"
	    graphfile=$f
            # We do not need to preprocess the file.
            usecpp= 0
            params="$cgparams $params"
	    ;;
	*.s|*.S)
	    program="asmgraph"
	    graphfile=$f
            if [ $asparams = "" ]; then
                asparams=" -n" # Implicitly use NASM syntax on demand.
            fi
            params="$asparams $params"
	    ;;
	*.l)
	    program="lexgraph"
	    graphfile=$f
	    ;;
	*.y)
	    program="yaccgraph"
	    graphfile=$f
	    ;;
	*)
	    usage
	    exit 2
	    ;;
    esac
done

# Do we want C preprocessing?
if [ $program = "cgraph" ]; then
    if [ $usecpp -eq 1 ]; then
        # Create a temporary file for the preprocessor.
        tmpfile=`mktemp -t $basename` || exit 2
	
        $CPP $cppparams $graphfile > $tmpfile
        ./$program $params $tmpfile || {
            rm $tmpfile
            exit 2
        }

        # Clean up
        rm $tmpfile
        exit 0
    fi
fi

./$program $params $graphfile || exit 2
