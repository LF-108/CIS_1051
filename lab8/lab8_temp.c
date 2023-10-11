#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "../include/upc.h"

/*#define AV_0				"Unassigned."
#define AV_1				"Audio: 12\" Video CDV, Video: 12\" Video CDV."
#define AV_2				"Audio: 3\" or 5\" CD, CD-ROM CDI and VDI, Video: Unassigned."
#define AV_3				"Audio: Unassigned, Video: VHS."
#define AV_4				"Audio: Cassette, Video: Unassigned."
#define AV_5				"Audio: DCC, Video: Beta."
#define AV_6				"Audio: Unassigned, Video: Laserdisk."
#define AV_7				"Audio: 7\" single, Video: Unassigned."
#define AV_8				"Audio: Mini Disc, Video: 8mm tape."
#define AV_9				"Audio: Music DVD, Video: Video DVD."

#define UPC_MOST PRODUCTS "General Product"
#define UPC_2             "Reserved for Local Use (Items sold by weight)"
#define UPC_3             "Drugs (By National Drug Code Number)"
#define UPC_4             "Reserved for Local Use (Coupons and Loyaltly cards)"
#define UPC_COUPONS       "Coupons"



#define MESSAGE_SUCCESSFULL_VALIDATION "The barcode has been successfully validated."
#define MESSAGE_VALIDATION_FAILURE "Warning: Barcode error encountered with barcode "
//prototypes
int promptforUPCbarcode (int barcode_array[12]);
int convertToDigit(char c);
int foundDigitsOnly (char barcode_chars[12]);
int calculateUPCCheckDigit(int barcode_array[12]);
void display_UPC_designation(int barcode_array[12]);
char *upc_audio_visual(int barcode_array[]);
*/

int main()
{
    int upc[12];

    while(!promptforUPCbarcode(upc)){
        display_UPC_designation(upc);
    }

    return EXIT_SUCCESS;
}

int promptforUPCbarcode (int barcode_array[12]){

    char barcode_chars[12];
    int i;

    printf("Enter a 12-digit UPC barcode or 'Q' to quit: \n");
    scanf("%c", &barcode_chars[0]);
    if(barcode_chars[0] == 'Q'){
        return 1;
    }
    else{
        barcode_array[0] = convertToDigit(barcode_chars[0]);
    }

    for(i = 1; i<12; i++ ){
        scanf("%c", &barcode_chars[i]);
        barcode_array[i] = convertToDigit(barcode_chars[i]);
        printf("Element %d is %c \n", i, barcode_chars[i]);
    }

    getchar();
    printf("The results of foundDigitsOnly is %d.\n", foundDigitsOnly(barcode_chars));
    printf("The result of calculateUPCCheckDigit is %d. \n", calculateUPCCheckDigit(barcode_array));

    return 0;
}

//Works
int convertToDigit(char c){

    int value = c - '0';
    int i;
    int temp;

    int barcode_array[12];
    return value;
}

//Works
int foundDigitsOnly(char barcode_chars[12]){
    int only_digits = 1;
    int i;

    for(i = 0; i<12; i++){
if(isdigit(barcode_chars[i])==0){
            only_digits = 0;
        }
    }

    return only_digits;
}

//Works
int calculateUPCCheckDigit(int barcode_array[12]){
    int step1 = 0;
    int step2 = 0;
    int step3 = 0;
    int step4 = 0;
    int last_digit = 0;
    int check_digit = 0;
    int validated = 0;

    int i;
    int j;

    for(i = 1; i<12; i+=2){
    step1+=barcode_array[i];
    }

    step2 = step1*3;

    for(j = 0; j<12; j+=2){
    step3+=barcode_array[j];
    }

    step4 = step2 + step3;

    last_digit = step4%10;

    if(last_digit!=0){
        check_digit = 10-last_digit;
    }
    else{
        check_digit = 0;
    }

    if(check_digit == barcode_array[11]){
        validated += 1;
    }
    printf("step1 = %d. \n", step1);
     printf("step2 = %d. \n", step2);
     printf("step3 = %d. \n", step3);
      printf("step4 = %d. \n", step4);
      printf("last_digit = %d. \n", last_digit);
     printf("check_digit = %d. \n", check_digit);
     printf("validated = %d. \n", validated);

    return check_digit;
}

void display_UPC_designation(int barcode_array[12]){
     printf("This is the UPC designation.\n");

}
char *upc_standard( int barcode_array[] )
{             
	char *rc = "There's a logic error in the UPC Designation.";

	if ( barcode_array[11] == 1 )                                    
		rc = AV_1;
	if ( barcode_array[11] == 2 )
		rc = AV_2;
	if ( barcode_array[11] == 3 )
		rc = AV_3;
	if ( barcode_array[11] == 4 )
		rc = AV_4;
	if ( barcode_array[11] == 5 )
        rc = AV_5;
	if ( barcode_array[11] == 6 )
		rc = AV_6;
	if ( barcode_array[11] == 7 )
		rc = AV_7;
	if ( barcode_array[11] == 8 )
		rc = AV_8;
	if ( barcode_array[11] == 9 )
		rc = AV_9;
	if ( barcode_array[11] == 0 )
		rc = AV_0;
	return rc;
}


char *upc_audio_visual(int barcode_array[])
{             
	char *rc = "There's a logic error in the audio/video digit.";

	if ( barcode_array[11] == 1 )                                    
		rc = AV_1;
	if ( barcode_array[11] == 2 )
		rc = AV_2;
	if ( barcode_array[11] == 3 )
		rc = AV_3;
	if ( barcode_array[11] == 4 )
		rc = AV_4;
	if ( barcode_array[11] == 5 )
        rc = AV_5;
	if ( barcode_array[11] == 6 )
		rc = AV_6;
	if ( barcode_array[11] == 7 )
		rc = AV_7;
	if ( barcode_array[11] == 8 )
		rc = AV_8;
	if ( barcode_array[11] == 9 )
		rc = AV_9;
	if ( barcode_array[11] == 0 )
		rc = AV_0;
	return rc;
}


void printArray(int arr[], int size)
/*Preconditions: int arr[] is declared 
	int size is size of arr
Postconditions: exits function after printing {} if array is empty
Globals: none
Returns: none
Description: Prints out every item in an int array*/


{
    if (size == 0)
    {
        printf("{}");
        return;
    }

    printf("{%d", arr[0]);

    for (int i = 1; i < size; i++)
    {
        printf(", %d", arr[i]);
    }
    
    printf("}\n");
}
