set -x
rm -rf iso
rm boot.o
rm kernel.o
rm kernel.bin
rm mykernel.iso

nasm -f elf32 boot.asm -o boot.o
gcc -m32 -c kernel.c -o kernel.o
ld -m elf_i386 -T linker.ld -o kernel.bin boot.o kernel.o

mkdir -p iso/boot/grub
cp kernel.bin iso/boot/
cp grub.cfg iso/boot/grub/

grub-mkrescue -o mykernel.iso iso/
