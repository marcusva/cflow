static void
second_func (void)
{
}

int
main (int argc, char **argv)
{
    /* Call some function defined in b.c */
    invoke_bc ();
    second_func ();
    return 0;
}
