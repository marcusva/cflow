About
=====
cflow is a call graph generator tool for C and Assembler code. It reads C or
Assembler source code files and prints call graphs from the contents. As such
it is useful for creating hierarchical trees of function invocations and
static variable usage and allows a developer to get a rough overview about the
calling hierarchy within the source code files.

Status
======
At its current stage, cflow supports the K&R, ANSI and ISO C conventions and
most of the GNU and NASM Assembler syntax. It also provides some nice features
such as

* keyword filters for ANSI, C99, POSIX and GCC in C source code files
* dot graph creation for graphviz output
* C preprocessor support
* reversed calling hierarchies
* graph creation for multiple files at once

Besides that it is planned to add object file and lex and yacc source code file
support to cflow so it is fully compliant with the POSIX.1 sepecification.
Though most parts of the specification are already implemented, these three file
types still have to be done. cflow also ignores the locale settings for e.g.
sorting at the moment, which is another requirement of the specification.

