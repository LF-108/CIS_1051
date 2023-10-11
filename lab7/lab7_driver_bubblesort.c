#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "../include/myheader.h"

//prototypes
void fill_random(int arr[], int array_size);
void bubble_sort(int arr[], int array_size);
void print_array(int arr[], int size);

int main(){

const int size_test_array = 10;
int test_array[size_test_array];

fill_random(test_array, size_test_array);
bubble_sort(test_array, size_test_array);
print_array(test_array, size_test_array);

return EXIT_SUCCESS;

}

void fill_random(int arr[], int array_size)
/*
 * Preconditions:
 *      array arr[]-         An integer array
 *      variable array_size- An int that represents the size of arr[]
 * Postconditions:           An integer array (arr[]) with array_size number of elements
 *                           with values between 0 and 200.
 * Globals:                  NULL-
 * Returns:                  NONE
 * Description:              Takes an integer array and a given size and fills the array with a number of elements equal to the size,
 *                           where the elements have values between 0 and 200.
 *
 */
{
srandom(time(NULL) + getpid());

//Declares var to store values generated by random()
int rand;

//Loop Control Variable and Array Subscript
int i;

//Fills the array with a certain number elements depending on the value of array_size
for(i = 0; i<array_size; i++){
        rand = random() % (201);
        arr[i] = rand;
}

}

void bubble_sort(int arr[], int array_size){

//Declares temp, which will be used to swap values of array elements
int temp;

//Declares loop control variables for the nested for loop.
int i;
int j;


/*Loops through all the elements of the array, and if the current element a[j]
  is greater than the next element a[j+1], it swaps them using a temp variable.
  This repeats for array_size times, where array_size is the size of the array.*/
for(i = 0; i<array_size; i++){
    for(j = 0; j<array_size-i-1; j++){
    if(arr[j]>arr[j+1]){
    temp = arr[j];
    arr[j] = arr[j+1];
    arr[j+1] = temp;
}
}
}

}
void print_array(int arr[], int size)
/*
 * Preconditions:
 *      array arr[]-         An integer array
 *      variable array_size- An int that represents the size of arr[]
 * Postconditions:           Exits function after printing {} is array is empty
 * Globals:                  NONE
 * Returns:                  NONE
 * Description:              Prints out every item in an integer array.
 *
 */
{

    //Declares loop control variable
    int i;

    //Prints out {} if array has no elements
    if (array_size == 0)
    {
        printf("{}");
        return;
    }

    //Prints out first element of array
    printf("{%d", arr[0]);

    //Prints out other array elements
    for (i = 1; i < size; i++)
    {
        printf(", %d", arr[i]);
    }

    printf("}\n");
}
