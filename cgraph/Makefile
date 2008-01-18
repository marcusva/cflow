# $FreeBSD$

PROG=	cgraph
SRCS=	clexer.c cgraph.c graph.c printgraph.c
CLEANFILES=	*~ *.core
MAN=	cgraph.1
CFLAGS+=-I${.CURDIR}/../common -W -Wall -pedantic -g -O0 ${WWFLAGS}

.PATH: ${.CURDIR}/../common

.include <bsd.prog.mk>
