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
 *
 * $FreeBSD$
 *
 */

static const char* ansi_keywords[] = 
{
    "abort", "atexit", "exit",
    "abs", "labs",
    "acos", "asin", "atan", "atan2",
    "asctime", "ctime", "gmtime", "localtime", "strftime",
    "assert",
    "atof", "atoi", "atol", "strtod", "strtol", "strtoul",

    "bsearch", "qsort",

    "calloc", "malloc", "realloc", "free",
    "ceil", "floor",
    "cos", "sin", "tan",
    "cosh", "sinh", "tanh",
    "clock", "difftime", "mktime", "time",

    "div", "ldiv",

    "errno",
    "exp", "frexp", "ldexp",

    "fclose", "fflush",
    "feof", "clearerr", "ferror", "perror",
    "fgetc", "fgets",
    "fgetpos", "fsetpos", "fseek", "ftell", "rewind",
    "fmod", "modf",
    "fopen", "freopen",
    "fprintf", "printf", "sprintf", "vfprintf", "vprintf", "vsprintf",
    "fputc", "fputs",
    "fread", "fwrite",
    "fscanf",
    
    "getenv",
    "getc", "getchar", "gets",

    "isascii", "isalnum", "isalpha", "iscntrl", "isdigit", "isgraph",
    "islower", "isprint", "ispunct", "isspace", "isupper", "isxdigit",

    "log", "log10",
    "localeconv", "setlocale",
    "longjmp", "setjmp",

    "memcpy", "memmove", "memset", "strcpy", "strncpy",
    "memcmp", "strcmp", "strncmp",
    "memchr", "strchr",
    "offsetof",

    "pow", "sqrt",
    "putc", "putchar", "puts",

    "rand", "srand",
    "raise", "signal",
    "remove", "rename",

    "scanf", "sscanf",
    "setbuf", "setvbuf"
    "strcat", "strncat",
    "strcoll", "strxfrm",
    "strcspn", "strpbrk", "strrchr", "strstr", "strtok",
    "strerror", "strlen",
    "system",

    "tmpfile", "tmpnam",
    "tolower", "toupper",

    "ungetc",
    "va_arg", "va_start", "va_end",
    NULL
};
