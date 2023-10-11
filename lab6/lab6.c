#include <stdio.h>
#include <stdlib.h>
#include "../include/myheader.h"

#define SUNDAY 0
#define MONDAY 1
#define TUESDAY 2
#define WEDNESDAY 3
#define THURSDAY 4
#define FRIDAY 5
#define SATURDAY 6

//prototypes
int this_is_a_leapyear(int year);

int calculate_a_doomsday(int year);

int identify_anchor_day(int year);

int read_in_valid_date( int *month, int *day, int *year);

int select_doomsday (int month, int this_is_a_leapyear);

int move_from_doomsday(int calculate_a_doomsday, int select_doomsday, int date);

void compute_date(int month, int date, int year);

void print_calculated_doomsday_date(int day);

int main(){

	//Calls the header function
        program_identification(6, "Doomsday Algorithm", "Calculates the day of the week for any date using the doomsday algorithm.");

	int date; //variable that stores in the day of the date
	int month;//variable that stores in the month of the date
	int year; //variable that stores the year of the date

	while(EXIT_SUCCESS == read_in_valid_date( &month, &date, &year)){
	   compute_date(month, date, year);
	}
	//Loop that keeps taking in dates until a negative value is inputted 

	return EXIT_SUCCESS;

}

int this_is_a_leapyear(int year)
/*
 * Preconditions:
 *      variable year-      The year of the given date.
 * Postconditions:          NONE
 * Globals:                 NONE
 * Returns:                 True or false (1 or 0) depending on if year is a leap year.
 * Description:             Checks if a year is a leap year depending on the value of year mod four.
 *                          
 */
{
	
	//Creates a var to store the truth value of year being a leap year and sets it to 0.
	int is_leap_year; 
	is_leap_year = 0;

	//Checks if year is a leap year, and sets the truth value to 1 if it is
	if (year%4 == 0){
        is_leap_year = 1;
	}

	return is_leap_year;

}

int calculate_a_doomsday(int year)
/*
 * Preconditions:
 *      variable month-     The month of the given date.
 *      variable year-      The year of the given date
 * Postconditions:          NONE
 * Globals:                 NONE
 * Returns:                 The weekday of the year's doomsday as an int value
 * Description:             Using the steps within step three of the doomsday algoritm, calculates the weekday of a year's doomsday dates
 *                          
 */
{

	 //Finds the last two digits of the year
	 int last_two_digits = year%100;
	
	 //Performs steps within step three of the doomsday algorithm to find the weekday of year's doomsday
	 int step1 = last_two_digits/12;

         int step2 = last_two_digits - (step1*12);

         int step3 = step2/4;

	 //uses function identify anchor day to find anchor day depending on value of year
         int step4 = identify_anchor_day(year);

         int step5 = step1 + step2 + step3+ step4;
	
	 int step6 = step5 % 7;
	 
	 return step6;

}

int identify_anchor_day(int year)
/*
 * Preconditions:
 *      variable month-     The month of the given date
 *      variable year-      The year of the given date
 * Postconditions:          NONE
 * Globals:                 FRIDAY -    represents the value of Friday as 5 for calculations
 *                          WEDNESDAY - represents the value of Wednesday as 3 for calculations
 *                          TUESDAY -   represents the value of Tuesday as 2 for calculations
 *			    SUNDAY -    represents the value of Sunday as 0 for calculations
 * Returns:                 The weekday of the year's doomsday as an int value
 * Description:             Using the steps within step three of the doomsday algoritm, calculates the weekday of a year's doomsday dates
 *
 */
{
	
	//Finds the anchor day, a special weekday, based on the value of year
	if( year >= 1800 && year<= 1899){
            return FRIDAY;
	}

	else if( year >= 1900 && year<= 1999){
            return WEDNESDAY;
        }	

	else if( year >= 2000 && year<= 2099){
            return TUESDAY;
        }

	else if( year >= 2100 && year<= 2199){
            return SUNDAY;
        }
	}

int read_in_valid_date( int *month, int *day, int *year)
/*
 * Preconditions:           NONE
 * Postconditions:          
 *      variable *month-    A user inputted value that must be greater than zero or the program exits
 *      variable *year-     A user inputted value that must be greater than zero or the program exits
 *      variable *day-      A user inputted value that must be greater than zero or the program exits
 * Globals:                 EXIT_SUCCESS - represents that the program ran successfully
 *                          EXIT_FAILURE - represents the program was not run as intended
 * Returns:                 EXIT_SUCCESS if all the values were successfully scanned in and are not negative, and EXIT_FAILURE otherwise
 * Description:             Prompts the user for a month, day, and year value, scans them in and sets them, and checks if the values are valid (non-negative)
 *
 */
{
	
	//Creats an integer variable, all_good, that stores EXIT_SUCCESS or EIXT_FAILURE depending on the values scanned in.
	int all_good = EXIT_SUCCESS;

	//Prompt for input for month, day, and year and scan them in
	printf("Please enter a value for the month.\n");
	scanf("%d", month);
	
	printf("Please enter a value for the day.\n");
        scanf("%d", day);

	printf("Please enter a value for the year.\n");
        scanf("%d", year);
	
	//Checks if any of the scanned values are negative so the loop can be terminated if they are
	if(*month < 0){
          all_good = EXIT_FAILURE;
	}

	else if(*day < 0){
	 all_good = EXIT_FAILURE;
	}

	else if(*year < 0){
         all_good = EXIT_FAILURE;
        }

	return all_good;
}

int select_doomsday (int month, int this_is_a_leapyear)
/*
 * Preconditions:           
 *	variable month-              the month of the given date
 * 	function this_is_a_leapyear- a function that checks whether a given year is a leap year
 * Postconditions:                   NONE
 * Globals:                          NONE
 * Returns:                          The closest doomsday date depending on the month and year
 * Description:                      Using the value of the month and whether the given year is a leap year or not, determines the doomsday date by month
 *
 */
{

//Sets value date to 0, and creates variable to return
int date = 0;

//Checks for doomsday date depending on month and year, and sets date accordingly
if(month == 1 && this_is_a_leapyear == 0){
    date = 3;
}

else if(month == 1 && this_is_a_leapyear != 0){
    date = 4;
}

else if(month == 2 && this_is_a_leapyear == 0){
    date = 29;
}

else if(month == 2 && this_is_a_leapyear != 0){
    date = 28;
}

else if(month == 3){
    date = 7;
}

else if(month == 4){
    date = 4;
}

else if(month == 5){
    date = 9;
}

else if(month == 6){
    date = 6;
}

else if(month == 7){
    date = 11;
}

else if(month == 8){
    date = 8;
}

else if(month == 9){
    date = 5;
}

else if(month == 10){
    date = 10;
}

else if(month == 11){
    date = 7;
}

else if(month == 12){
    date = 12;
}

return date;
}

int move_from_doomsday(int calculate_a_doomsday, int select_doomsday, int date)
/*
 * Preconditions:
 *      function calculate_a_doomsday- A function that finds the weekday of a year's doomsday
 *      function select_doomsday-      a function that finds the doomsday of a given month 
 *      variable date-                 The day of the given date 
 * Postconditions:                     NONE
 * Globals:                 	       NONE
 * Returns:                 	       The day of the week of the date the user entered as a value between 0 and 6
 * Description:                        Following step four of the doomsday algorithm, finds the weekday of the given date
 *
 */

{

//Follows the steps within step four of the doomsday algorithm to find the distance between the doomsday and the given day, and figure out which weekday the given date is
int difference = date - select_doomsday;
int diff_step_two = difference%7;

//Declares and intializes var final_day_of_week and fina_val to store values for calculations
int final_day_of_week = 0;
int final_val = 0;

if (diff_step_two < 0){
diff_step_two+=7;
}

final_day_of_week = diff_step_two + calculate_a_doomsday;
final_val = final_day_of_week%7;

return final_val;
}

void compute_date(int month, int date, int year)
/*
 * Preconditions:
 *      variable month- The month of the given date        
 *      variable date-  The day of the given date       
 *      variable year-  The year of the given date
 * Postconditions:      NONE
 * Globals:             NONE
 * Returns:             NONE
 * Description:         Calls all the functions needed to calculate the doomsday date, and prints out which weekday the given date is
 *
 */
{
 
  //Declares variables for calculations and to store values of function calls
  int is_leap_year; 
  int doomsday_of_week;
  int doomsday_date;
  int final_day_of_week;

  //Sets the value of is_leap_year, doomsday_of_week and doomsday_date to this_is_leapyear, calculate_a_doomsday, and select_doomsday respectively
  is_leap_year = this_is_a_leapyear(year);
  doomsday_of_week = calculate_a_doomsday(year);
  doomsday_date = select_doomsday(month, is_leap_year);

  //Sets final_day_of_week to move_from_doomsday which calls the above variables
  final_day_of_week = move_from_doomsday(doomsday_of_week, doomsday_date, date);
  
  //Calls print_calculated_doomsday to print the weekday of the given date based on the value of final_day_of_week
  print_calculated_doomsday_date(final_day_of_week);

}

void print_calculated_doomsday_date( int day ) 
/*
 * Preconditions:
 *      function calculate_a_doomsday- A function that finds the weekday of a year's doomsday
 *      function select_doomsday-      a function that finds the doomsday of a given month       
 *      variable date-                 The day of the given date
 * Postconditions:                     NONE
 * Globals:                            NONE
 * Returns:                            The closest doomsday date depending on the month and year
 * Description:                        Using the value of the month and whether the given year is a leap year or not, determines the doomsday date by month
 *
 */
{ 
    //Declares string c   
    char *c;  
    
    //Based on the value of day, finds the corresponding string weekday and sets c to that 
    switch ( day ) { 
        case SUNDAY:  c= "Sunday";   break; 
        case MONDAY:  c= "Monday";   break; 
        case TUESDAY:  c= "Tuesday";  break; 
        case WEDNESDAY:  c= "Wednesday";   break; 
        case THURSDAY:  c= "Thursday";  break; 
        case FRIDAY:  c= "Friday";   break; 
        case SATURDAY:  c= "Saturday";  break; 
 
        default:   
        //Prints an error message is day is not between zero and six
 
         puts( "Error in value passed to print_calculated_doomsday_date."); 
         printf( "Day must be between 0 and 6.  Value passed is %d.\n", day ); 
         exit( EXIT_FAILURE ); 
    } 
     
    printf( "The calculated day is %s.\n", c ); 
     
    return; 
} 
