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
    } >sram1

    .rodata :
    {
        _rodata = . ;
        *(.rodata*);
        _erodata = . ;
    } >sram1

    .data :
    {
        _data = . ;
        *(.data);
        _edata = . ;
    } >sram1

    .bss :
    {
        __bss_start__ = . ;
        *(.bss) *(*COM*);
        __bss_end__ = . ;
    } >sram1
}

_stack = ORIGIN(sram2) + LENGTH(sram2);
