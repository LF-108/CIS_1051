#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*Programmer Name:    Lara Fernandes
 *Class and Semester: CIS 1057 Section 004 Fall 2022 
 *Date:               Wednesday, September 7, 2022
 *Assignment:         Lab 2
 *Name:               Pythagorean Theorem
 *Description:        Given two positive integers, m and n, where m>n, calculates the three sides
 *                    of a pythagorean triple and returns the value of side 1, side 2, and the hypotenuse.
 */

int main(){

int m; //Declares int m, which will be the greater of the two input values
int n; //Declares int n, which will be the lesser of the two input values 

printf("Please enter the greater of the two integers: \n"); 
scanf("%d", &m);

printf("Please enter the lesser of the two values integers: \n");
scanf("%d", &n);

int side1;      //Declares int side1, which will hold the value of side 1, which is m^2-n^2
int side2;      //Declares int side2, which will hold the value of side 2, which is 2mn
int hypotenuse; //Declares int hypotenuse, which will hold the value of side 3(the hypotenuse), which is m^2 + n^2

side1 = pow(m,2)-pow(n,2);
//Calculates the right hand side using the pow function, and stores the value in side1

side2 = 2*m*n;
//Calculates the right hand side and stores the value in side2

hypotenuse = pow(m,2)+pow(n,2);
//Calculates the right hand side and stores the value in hypotenuse

printf("The following right triangle can be generated from these numbers: \n");
printf(" Side 1 is:%3d \n ", side1);
printf("Side 2 is: %d \n ", side2);
printf("Hypotenuse is: %d \n ", hypotenuse);

return EXIT_SUCCESS;

}
