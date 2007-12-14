# $FreeBSD$

PROG=	cgraph
SRCS=	clexer.c cgraph.c graph.c
CLEANFILES=	*~ *.core
MAN=	cgraph.1

WWFLAGS=	-Wimplicit-int -Wimplicit-function-declaration -Wimplicit \
	-Wmain -Wreturn-type -Wunused -Wswitch -Wcomment -Wtrigraphs -Wformat \
	-Wchar-subscripts -Wuninitialized -Wparentheses -Wpointer-arith \
	-Wcast-qual -Winline -Wcast-align -Wconversion -Wstrict-prototypes \
	-Wmissing-prototypes -Wmissing-declarations -Wnested-externs \
	-Wshadow -Wredundant-decls
CFLAGS+=	-I${.CURDIR}/../common -W -Wall -pedantic -g -O0 ${WWFLAGS}

.PATH: ${.CURDIR}/../common

# CCFLOW=sh cflow.sh
# FFILES!=find /usr/src/ -name '*.c'
# test:
# .for ff in ${FFILES}
# 	@${CCFLOW} ${ff} > /dev/null || echo FAILURE: ${ff}
# .endfor

.include <bsd.prog.mk>
