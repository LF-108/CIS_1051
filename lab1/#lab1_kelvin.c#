#include <stdio.h>
#include <stdlib.h>

/*Programmer Name:     Lara Fernandes
 *Class and Semester:  CIS 1057 Section 004  Fall 2022
 *Date:                Wednesday, August 31, 2022
 *Assignment:          Lab 1
 *Name:                Temperature Conversion(Kelvin)
 *Description:         Prompt for input, converts Fahrenheit to
 *                     Kelvin, dispaly output.
 */

#define KELVIN_ADJUSTMENT 0.555555555555 + 273.15

int main()
{

    printf("Please enter farenheit number you want to convert:");

    double fahrenheit; //Declaring the variable fahrenheit
    double kelvin;     //Declaring the varuable kelvin

    scanf("%lf", &fahrenheit);

    printf("The value of fahrenheit is %lf \n", fahrenheit);

    kelvin = (fahrenheit-32)*KELVIN_ADJUSTMENT;
    //Calculates the right hand side, and stores that value in kelvin

    printf("The value in kelvin is %lf", kelvin);

    return EXIT_SUCCESS;
}
