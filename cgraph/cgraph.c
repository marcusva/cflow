/*-
 * Copyright (c) 2007, Marcus von Appen
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer 
 *    in this position and unchanged.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <sys/cdefs.h>
__FBSDID("$FreeBSD$");

#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <locale.h>
#include <errno.h>

#include "cgraph.h"

/* Forward declarations. */
static void usage (void);

/**
 * Displays the usage command of the application.
 */
static void
usage (void)
{
    fprintf (stderr,
             "usage: cgraph [-AcCGPr] [-d num] [-i incl] [-R root] file ...\n");
    exit (EXIT_FAILURE);
}

int
main (int argc, char *argv[])
{
    int excludes = 0;      /* Bitwise combineable int to keep track of the
                            * excludes. */
    node_t *exlist = NULL; /* List of excludes. */
    bool_t statics = FALSE;
    bool_t privates = FALSE;
    char *root = "main";   /* Root function to use. */
    graph_t graph;         /* Actual graph to process. */
    int ch;                /* Option to parse. */
    int i;                 /* Counter. */
    int depth = INT_MAX;   /* Depth to traverse. */
    bool_t complete = FALSE;
    bool_t reversed = FALSE;

    setlocale (LC_ALL, "");

    while ((ch = getopt (argc, argv, "AcCd:Gi:PrR:")) != -1)
    {
        switch (ch)
        {
        case 'A':
            excludes |= NO_ANSI_KWDS;
            break;
        case 'c':
            complete = TRUE;
            break;
        case 'C':
            excludes |= NO_C99_KWDS;
            break;
        case 'd':
        {
            long val = strtol (optarg, NULL, 10);
            if (val == 0 && (errno == ERANGE || errno == EINVAL))
                usage();
            if (val > INT_MAX)
                usage();
            depth = (int) val;
            break;
        }
        case 'G':
            excludes |= NO_GCC_KWDS;
            break;
        case 'i':
            if (strlen (optarg) > 1)
                usage ();
            if (optarg[0] == 'x')
                statics = TRUE;
            else if (optarg[0] == '_')
                privates = TRUE;
            else
                usage ();
            break;
        case 'P':
            excludes |= NO_POSIX_KWDS;
            break;
        case 'r':
            reversed = TRUE;
            break;
        case 'R':
            root = strdup (optarg);
            if (!root)
                exit (EXIT_FAILURE);
            break;
        }
    }

    if (excludes)
    {
        exlist = create_excludes (exlist, excludes);
        if (!exlist)
        {
            perror (NULL);
            return 1;
        }
    }

    /* Defaults are parsed, now get through the files. */
    argc -= optind;
    argv += optind;

    if (argc <= 0) /* No more arguments? */
        usage ();

    /* Go through all the files and create the graph for each of it. */
    for (i = 0; i < argc; i++)
    {
        /* Open the file and create the graph struct to pass around. */
        graph.fp = fopen (argv[i], "r");
        if (!graph.fp)
        {
            perror (argv[i]);
            return 1;
        }
        graph.name = argv[i];
        graph.root = root;
        graph.defines = NULL;
        graph.excludes = exlist;
        graph.statics = statics;
        graph.privates = privates;
        graph.depth = depth;
        graph.complete = complete;
        graph.reversed = reversed;

        /* Create the graphs. */
        lex_create_graph (&graph);
        fclose (graph.fp);
        print_graph (&graph);
        free_nodes (graph.excludes);
        free_g_nodes (graph.defines);
    }
    return 0;
}
