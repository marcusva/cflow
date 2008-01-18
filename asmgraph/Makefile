# $FreeBSD$

PROG=	asmgraph
SRCS=	aslexer.c nasmlexer.c asmgraph.c graph.c printgraph.c
CLEANFILES=	*~ *.core
MAN=	asmgraph.1

CFLAGS+=-I${.CURDIR}/../common -W -Wall -pedantic -g -O0 ${WWFLAGS}

.PATH: ${.CURDIR}/../common

.include <bsd.prog.mk>
