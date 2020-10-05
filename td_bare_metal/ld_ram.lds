MEMORY {
    flash (rx) : ORIGIN = 0x08000000, LENGTH = 1M
    sram1 (!rx) : ORIGIN = 0x20000000, LENGTH = 96K
    sram2 (!rx) : ORIGIN = 0x10000000, LENGTH = 32K
}

ENTRY(main)

SECTIONS {
    .text :
    {
        *(.text)
        _etext = . ;
    } >ram

    .rodata :
    {
        _rodata = . ;
        *(.rodata*);
        _erodata = . ;
    } >ram

    .data :
    {
        _data = . ;
        *(.data);
        _edata = . ;
    } >ram

    .bss :
    {
        _bstart = . ;
        *(.bss) *(*COM*);
        _bend = . ;
    } >ram
}

_stack = ORIGIN(sram2) + LENGTH(sram2);
