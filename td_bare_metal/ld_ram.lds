MEMORY {
    flash (rx) : ORIGIN = 0x08000000, LENGTH = 1M
    sram1 (!rx) : ORIGIN = 0x20000000, LENGTH = 96K
    sram2 (!rx) : ORIGIN = 0x10000000, LENGTH = 32K
}

ENTRY(_start)

SECTIONS {
    .vect_table :
    {
        src/irq.o(*vectors*)
    } >flash

    .text :
    {
        ./crt0.o(.text)
        *(.text)
    } >flash

    .rodata :
    {
        *(.rodata*);
    } >flash

    .data :
    {
        _data = . ;
        *(.data);
        _edata = . ;
    } >sram1 AT>flash

    .bss :
    {
        _bstart = . ;
        *(.bss) *(*COM*);
        _bend = . ;
    } >sram1
}

_stack = ORIGIN(sram2) + LENGTH(sram2);
_data_lma = LOADADDR(.data);
_data_lma_end = LOADADDR(.data) + SIZEOF(.data);
_data_vma = ADDR(.data);
