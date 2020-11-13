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
    } >sram1 AT>flash

    .init :
    {
        ./crt0.o(.text);
        ./init.o(.text);
        *(.init);
    } >flash

    .text :
    {
        *(.text);
    } >sram1 AT>flash

    .rodata :
    {
        *(.rodata*);
    } >flash

    .data :
    {
        *(.data);
    } >sram1 AT>flash

    .bss :
    {
        _bstart = . ;
        *(.bss) *(*COM*);
        _bend = . ;
    } >sram1
}

_stack = ORIGIN(sram2) + LENGTH(sram2);

_vtor_lma = LOADADDR(.vect_table);
_vtor_lma_end = LOADADDR(.vect_table) + SIZEOF(.vect_table);
_vtor_vma = ADDR(.vect_table);

_text_lma = LOADADDR(.text);
_text_lma_end = LOADADDR(.text) + SIZEOF(.text);
_text_vma = ADDR(.text);

_data_lma = LOADADDR(.data);
_data_lma_end = LOADADDR(.data) + SIZEOF(.data);
_data_vma = ADDR(.data);
