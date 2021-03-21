OUTPUT_FORMAT(elf32-i386)/* will produce a 32bit x86 executable */
ENTRY(start)/* name of the function to call first(it's in boot.asm) */
SECTIONS
 {
/* kernel code will be placed at 1M(1megabyte) offset,
this is where the bootloader expects it */
   . = 1M;
   .text BLOCK(4K) : ALIGN(4K)
   {
       *(.multiboot)
       *(.text)
   }
   .data : { *(.data) }
   .bss  : { *(.bss)  }
 }
