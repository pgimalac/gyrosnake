extern char _bend, _bstart;
extern char _data_lma, _data_vma, _data_lma_end;

void init_bss() {
    char *dst = &_bstart;
    while (dst < &_bend)
        *dst++ = 0;
}

void copy_data() {
    char *src = &_data_lma;
    char *dst = &_data_vma;

    while (src < &_data_lma_end)
        *dst++ = *src++;
}
