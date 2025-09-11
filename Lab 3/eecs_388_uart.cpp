/******************************************************************************
 *   Header Includes
 *******************************************************************************/
#include <Arduino.h>

#include "eecs_388_lib.h"

/******************************************************************************
 *   Function: echo() - Print the received character back to the terminal
 *      Pre condition: 
 *          UART has been initialized
 *          Character has been received and is passed in as the 'c' variable
 *      Post condition: 
 *          Prints out the received character to the Serial Monitor
 *******************************************************************************/
static void echo(const char c) 
{
ser_printline("You typed: " );
ser_write( c );
ser_write( '\n' );

return;
}

/******************************************************************************
 *   Function: setup() - Initializes the Arduino System
 *      Pre condition: 
 *          Hardware must be properly connected (sensors, LEDS, etc.)
 *      Post condition: 
 *          Runs initialization calls one time on power up
 *          Input/Output (IO) pins are configured
 *******************************************************************************/
void setup() 
{
gpio_mode(GPIO_13, GPIO_OUTPUT);
gpio_mode(GPIO_12, GPIO_OUTPUT);
gpio_mode(GPIO_11, GPIO_OUTPUT);

uart_init();

return;
}

/******************************************************************************
 *   Function: loop() - Main execution loop
 *      Pre condition: 
 *          setup() has been executed and system is initialized
 *      Post condition: 
 *          Performs a single iteration of the system's function
 *          Repeates indefinetely unless the board is reset or powered off
 *******************************************************************************/
void loop() 
{
char char_rcvd;   /* use this to hold the received character */

ser_printline("Type 'r' for red, 'g' for green, or 'b' for blue");

char_rcvd = ser_read();
/* Task 1.4 - Implement logic for enabling red/green/blue LED */
if (char_rcvd == 'r'){
    gpio_write(GPIO_13, ON);
    gpio_write(GPIO_12, OFF);
    gpio_write(GPIO_11, OFF);
} else if (char_rcvd == 'g'){
    gpio_write(GPIO_13, OFF);
    gpio_write(GPIO_12, ON);
    gpio_write(GPIO_11, OFF);
} else if (char_rcvd == 'b'){
    gpio_write(GPIO_13, OFF);
    gpio_write(GPIO_12, OFF);
    gpio_write(GPIO_11, ON);
}


echo(char_rcvd);  /* echo back the received character to serial monitor */

return;
}