/*** DEFINES */
#define VGA_ADDRESS 0xB8000   /* video memory begins here on x86 architecture */
/* for graphic modes it'd be at 0x000A0000 */

/* VGA provides support for 16 colors */
#define BLACK 0
#define GREEN 2
#define RED 4
#define YELLOW 14
#define WHITE_COLOR 15
/* If the first bit is set the character will blink on-screen.
The next 3 bits then detail the background color
the final 4 bits of the first byte are the foreground (or the text character)'s color.*/

#define uint8_t unsigned char
#define uint16_t unsigned short
#define uint32_t unsigned int
#define int32_t int
/* DEFINES end. */

/*** GLOBALS */
uint16_t* terminal_buffer; /* array containing chars+colors for the text screen */
uint32_t vga_index; /* pointing to that array */
/* GLOBALS end. */

/*** FUNCTIONS */
void clear_screen(void)
{
    int32_t index = 0;
    /* there are 25 lines each of 80 columns;
       each element takes 2 bytes */
    while (index < 80 * 25 * 2) {
            terminal_buffer[index] = ' ';
            index += 2;
    }
}

void print_string(char* str, unsigned char color)
{
    int32_t index = 0;
    while (str[index]) {
/* combine the char and the color in a single uint16 for the terminal_buffer array */
            terminal_buffer[vga_index] = (uint16_t)str[index]|(uint16_t)color << 8;
            index++;
            vga_index++;
    }
}

void main(void)
{
    /* make terminal_buffer start at the magic address, */
    /* the real physical address where the video mem is */
    terminal_buffer = (uint16_t*)VGA_ADDRESS;
    vga_index = 0;

    clear_screen();
    print_string("PORCODIO!", YELLOW);
    vga_index = 80;    /* next line */
    print_string("PORCOMADONNE!", RED);
    return;
}
