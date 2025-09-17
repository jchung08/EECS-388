/******************************************************************************
 *   Header Includes
 *******************************************************************************/
#include <Arduino.h>
#include <stdint.h>
#include <stdio.h>

#include "eecs_388_lib.h"

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
uint16_t dist = 0;              /* LIDAR distance data is 16 bits. */

ser_printline("Setup completed.");
ser_write( '\n' );

while( 1 )
    { 
    /* 
        Task 1.2: 
        - read a data frame from the TFmini sensor
        
        - from Table 6, we know each LIDAR measurement sends 9 bytes
        - the function `ser_read()` can process 1 byte per function call

        - This if-statement below will read (and check) the first two bytes of a valid data frame
        - You will need to write code to read the subsequent bytes to get the distance data
        - You will need to process the data received from the sensor to get the correct distance value
    */
    if ('Y' == ser_read() && 'Y' == ser_read()) 
        {
            uint8_t dist_L, dist_H;
            dist_L = ser_read();
            dist_H = ser_read();

            dist = (dist_H << 8) | dist_L;

            for(int i = 0; i < 5; i++) {
                ser_read();
            }
        
            if (dist < 50){
                gpio_write(GPIO_13, ON);
                gpio_write(GPIO_12, OFF);
            } else {
                gpio_write(GPIO_13, OFF);
                gpio_write(GPIO_12, ON);
            }

            ser_printf("Distance: %d cm", dist);
            
            /* 
            
            Task 1.3: 
            - turn on the red LED if the distance measured is less than 50 cm. 
            - otherwise turn on the green LED 

            - print the measured value to the console (i.e. the serial monitor) 
            - You can use ser_printf() or ser_printline() or ser_write()
            
            - Helpful guide for printing with variadic function similiar to printf()
            - https://en.cppreference.com/w/cpp/io/c/fprintf
        */
            delay_ms(100);
        }
    }

return;
}