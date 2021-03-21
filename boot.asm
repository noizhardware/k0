bits 32

section .multiboot               ;according to multiboot spec
        dd 0x1BADB002            ;set magic number for
                                 ;bootloader
;it's a doubleword(dd), 4bytes
        dd 0x0                   ;set flags
        dd - (0x1BADB002 + 0x0)  ;set checksum

section .text
global start
extern main                      ;defined in the C file

start:
        cli                      ;block interrupts (CLean Interrupt flags)
        mov esp, stack_space     ;set stack pointer to point to the empty function "stack_space"
        call main		;execute the external "main" function
        hlt                      ;halt the CPU

section .bss
resb 8192                        ;8KB for stack
stack_space:
