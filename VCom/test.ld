MEMORY
{
        FLASH (rx) : ORIGIN = 0x00002000, LENGTH = 0x00080000
        SRAM (rwx) : ORIGIN = 0x10000000, LENGTH = 0x00008000
}

__top_RamLoc32 = 0x10007FFF;

SECTIONS {
         .text : {
                 * (.isr_vector);
                 * (.text);
                 _etext = .;
         } > FLASH

         .data : {
                 _data = .;
                 * (.data);
                 _edata = .;
         } > SRAM AT> FLASH

         .bss : {
                _bss = .;
                * (.bss);
                _ebss = .;
         } > SRAM

		_end = .;
		PROVIDE(end = .);

         .rodata : {
                 * (.rodata);
         } > FLASH

		_vRamTop = __top_RamLoc32;
		_vStackTop = _vRamTop - 10;
}
