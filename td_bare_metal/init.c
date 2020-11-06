extern char _bend, _bstart;
extern char _data_lma, _data_lma_end, _data_vma;

void init_bss() {
    char *dst = &_bstart;
    while (dst < &_bend)
        *dst++ = 0;
}

void memcopy(char *src, char *srcend, char *dst) {
    while (src < srcend)
        *dst++ = *src++;
}
