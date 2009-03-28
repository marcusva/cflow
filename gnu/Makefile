CC?= cc
RM = rm -rf 
MKDIR ?= mkdir -p
CFLAGS ?= -W -Wall
LDFLAGS ?=
GZIP ?= gzip
INSTALL ?= install

ASMPROG= asmgraph
ASMSRCS= asmgraph/aslexer.c asmgraph/nasmlexer.c asmgraph/asmgraph.c
ASMOBJS= $(ASMSRCS:%.c=bld/%.o)
ASMMAN=	asmgraph.1
ASMLDFLAGS= 
ASMCFLAGS= -I../common

CMSRCS= common/graph.c common/printgraph.c
CMOBJS= $(CMSRCS:%.c=bld/%.o)

CPROG= cgraph
CSRCS= cgraph/clexer.c cgraph/cgraph.c 
COBJS= $(CSRCS:%.c=bld/%.o)
CMAN= cgraph.1
CLDFLAGS= 
CCFLAGS= -I../common

CFLOW= cflow
CFLOWMAN= cflow.1

all: clean mkdirs build

mkdirs:
	$(MKDIR) bld/asmgraph
	$(MKDIR) bld/common
	$(MKDIR) bld/cgraph

build: $(CMOBJS) asmgraph cgraph cflow

$(CMOBJS): bld/%.o: ../%.c
	$(CC) -c $(CFLAGS) $(CCFLAGS) -c -o $@ ../$*.c

$(ASMOBJS): bld/%.o: ../%.c $(CMOBJS)
	$(CC) -c $(CFLAGS) $(ASMCFLAGS) -c -o $@ ../$*.c

asmgraph: $(ASMOBJS) $(CMOBJS)
	$(CC) $(LDFLAGS) $(ASMLDFLAGS) $(ASMOBJS) $(CMOBJS) -o $(ASMPROG)
	$(GZIP) -cn ../asmgraph/$(ASMMAN) > $(ASMMAN).gz

$(COBJS): bld/%.o: ../%.c $(CMOBJS)
	$(CC) -c $(CFLAGS) $(CCFLAGS) -c -o $@ ../$*.c


cgraph: $(COBJS) $(CMOBJS)
	$(CC) $(LDFLAGS) $(CLDFLAGS) $(COBJS) $(CMOBJS) -o $(CPROG)
	$(GZIP) -cn ../cgraph/$(CMAN) > $(CMAN).gz

cflow:
	$(INSTALL) -c -m 0755 ../scripts/$(CFLOW).sh $(CFLOW)
	$(GZIP) -cn ../scripts/$(CFLOWMAN) > $(CFLOWMAN).gz

clean:
	$(RM) $(ASMPROG) $(CPROG) $(CFLOW) bld/
	$(RM) $(CFLOWMAN).gz $(CMAN).gz $(ASMMAN).gz
