MEMORY {
    flash (rx) : ORIGIN = 0x08000000, LENGTH = 1M
    sram1 (!rx) : ORIGIN = 0x20000000, LENGTH = 96K
    sram2 (!rx) : ORIGIN = 0x10000000, LENGTH = 32K
}

ENTRY(_start)

SECTIONS {
    .text :
    {
        crt0.o(.text)
        *(.text)
    } >sram1

    .rodata :
    {
        *(.rodata*);
    } >sram1

    .data :
    {
        _data = . ;
        *(.data);
        _edata = . ;
    } >sram1

    .bss :
    {
        _bstart = . ;
        *(.bss) *(*COM*);
        _bend = . ;
    } >sram1
}

_stack = ORIGIN(sram2) + LENGTH(sram2);
