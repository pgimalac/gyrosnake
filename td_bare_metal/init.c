extern char _bend, _bstart;

void init_bss() {
    char *dst = &_bstart;
    while (dst < &_bend)
        *dst++ = 0;
}
