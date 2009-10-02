PREFIX?=/usr/local
MANDIR?=$(PREFIX)/share/man
MAN1DIR=$(MANDIR)/man1

CC ?= cc
RM ?= rm -f
MKDIR ?= mkdir -p
CFLAGS ?= -pipe -O2 -W -Wall
LDFLAGS ?=
GZIP ?= gzip
SED ?= sed
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
	$(SED) -e "s|progprefix=/usr/bin|progprefix=$(PREFIX)/bin|g" ../scripts/$(CFLOW).sh > $(CFLOW)
	$(GZIP) -cn ../scripts/$(CFLOWMAN) > $(CFLOWMAN).gz

clean:
	$(RM) $(ASMPROG) $(CPROG) $(CFLOW)
	$(RM) -r bld/
	$(RM) $(CFLOWMAN).gz $(CMAN).gz $(ASMMAN).gz

install: mkdirs build
	$(INSTALL) -d $(PREFIX)/bin
	$(INSTALL) -c -m 0755 $(CFLOW) $(PREFIX)/bin/$(CFLOW)
	$(INSTALL) -c -m 0755 $(ASMPROG) $(PREFIX)/bin/$(ASMPROG)
	$(INSTALL) -c -m 0755 $(CPROG) $(PREFIX)/bin/$(CPROG)
	$(INSTALL) -d $(MAN1DIR)
	$(INSTALL) -c -m 0644 $(CFLOWMAN).gz $(MAN1DIR)/$(CFLOWMAN).gz
	$(INSTALL) -c -m 0644 $(ASMMAN).gz $(MAN1DIR)/$(ASMMAN).gz
	$(INSTALL) -c -m 0644 $(CMAN).gz $(MAN1DIR)/$(CMAN).gz
