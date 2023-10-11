#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "../include/mastermind.h"

void say_goodbye_and_exit_program( const char *message )
/*
 *Preconditions:     const char *message - a string message
 *Postconditions:    Program exits after called
 *Globals:           EXIT_FAILURE - A value of 1 that represents the unsuccessful execution of a program
 *Returns:           NONE
 *Description:       Takes in a string message, and prints it out, and exits after.
 *                   
 *              
 */
{
        fprintf( stderr, "%s\n", message );
        exit( EXIT_FAILURE );
}

void generate_random_code(peg_array code)
/*
 *Preconditions:     NONE
 *Postconditions:    peg_array code - An array of randomly generated mastermind_peg elements
 *Globals:           COLORS_PER_GUESS - A value that represents the number of guesses a player gets per round
 *                   NULL - A constant that represents 0
 *                   NUMBER_OF_PEG_COLORS - Number of colors available to enter
 *Returns:           NONE
 *Description:       Takes an array of mastermind_peg values, and stores in each element an integer that corresponds to 
 *                   a value within the mastermind_peg enumerated type (corresponds to a peg color)
 *  
 *
 */
{
    srandom(time(NULL) + getpid());
    int i;
    for(i = 0; i < COLORS_PER_GUESS; i++){
        code[i] = (random() % 5);
    }
}

char *peg_array_tostring( const peg_array c )
/*
 *Preconditions:     const peg_array c - an array of peg_array elements that holds type key_peg elements
 *Postconditions:    NONE
 *Globals:           CODE_STRING_MAXIMUM_SIZE - A value that represents the most characters a guess could have
 *Returns:           string buf - a string that displays the colors of each peg inputted by the user's guess
 *Description:       Takes an array of key_peg values, uses mastermind_peg_tostring to find the corresponding string with a color name to 
 *                   the users guess, formats these values and stores them in buf which is returned.
 *              
 */
{
        static char buf[ CODE_STRING_MAXIMUM_SIZE ];

        char *peg1 = mastermind_peg_tostring( c[0] );
        char *peg2 = mastermind_peg_tostring( c[1] );
        char *peg3 = mastermind_peg_tostring( c[2] );
        char *peg4 = mastermind_peg_tostring( c[3] );
 snprintf( buf, CODE_STRING_MAXIMUM_SIZE, "|%-6s| |%-6s| |%-6s| |%-6s|", peg1, peg2, peg3, peg4 );

        return buf;
}

char *mastermind_key_tostring( const key_peg c)
/*
 *Preconditions:     const key_peg c - a key_peg value representing a color of a peg
 *Postconditions:    NONE
 *Globals:           DEFAULT_RETURN_STRING - "None" a default value that is returned when there is nothing else to return
 *Returns:           string rc - a string that displays whether each peg is in the correct position with a color
 *Description:       Takes a peg and assigns a string value to rc based on whether the peg is in the correct position
 *                   and part of the generated code, and returns this string
 *    
 *
 */
{
       char *rc = (char *)DEFAULT_RETURN_STRING;

        switch ( c ) {
                case Red:   rc = "Red";    break;
                case White: rc = "White";  break;
                case Empty:  rc = "Empty";   break;
                default: ; // none
        }

        return rc;

}

char *key_array_tostring( const key_array c )
/*
 *Preconditions:     const key_array c - an array of peg_array elements that holds type key_peg elements
 *Postconditions:    NONE
 *Globals:           CODE_STRING_MAXIMUM_SIZE - A value that represents the most characters a guess could have
 *Returns:           string buf - a string that displays the colors of each peg inputted by the user's guess
 *Description:       Takes an array of key_peg values, uses mastermind_peg_tostring to find the corresponding string with a color name to 
 *                   the users guess, formats these values and stores them in buf which is returned.
 *              
 */
{
        static char buf[ CODE_STRING_MAXIMUM_SIZE ];

        char *k1 = mastermind_key_tostring( c[0] );
        char *k2 = mastermind_key_tostring( c[1] );
        char *k3 = mastermind_key_tostring( c[2] );
        char *k4 = mastermind_key_tostring( c[3] );

        snprintf( buf, CODE_STRING_MAXIMUM_SIZE, "[%-5s] [%-5s] [%-5s] [%-5s]", k1, k2, k3, k4 );

        return buf;
}

char *mastermind_peg_tostring( const mastermind_peg p)
/*
 *Preconditions:  const mastermind_peg p - a value that represents the color of a peg
 *Postconditions: NONE
 *Globals:        NONE
 *Returns:        string rc - a string that represents the color of a peg
 *Description:    Returns a string value corresponding to a color based on the value of mastermind_peg p
 *
 *
 */
{
       char *rc = (char *)DEFAULT_RETURN_STRING;

        switch ( p ) {
                case Blue:   rc = "Blue";    break;
                case Yellow: rc = "Yellow";  break;
                case Green:  rc = "Green";   break;
                case Purple: rc = "Purple";  break;
                case Orange: rc = "Orange";  break;
                case Black:  rc = "Black";   break;
                default: ; // none
        }

        return rc;


}

key_array *mastermind_response( const peg_array code, const peg_array guess, int *win )
/*
 *Preconditions:  const peg_array code - Array of mastermind_peg elements containing the correct answer
 *                const peg_array guess -  Array of mastermind_peg elements containing user guess
 *Postconditions: int *win - represents if the user won the game or not
 *Globals:        COLOR_PER_GUESS - - A value that represents the number of guesses a player gets per round
 *Returns:        &rc - An array of key_pegs that contains the corresponding value for each guess 
 *Description:    Checks which pegs should be designated as red, white, and empty and stores these values in an array
 *
 *
 */
{
        static key_array rc;            // rc is the response we return.

        // make a local copy of the codes as integers
        int code_tracker[]  = { code[0], code[1], code[2], code[3] };

        // make a local copy of the guess as integers
        int guess_tracker[] = { guess[0], guess[1], guess[2], guess[3] };

        // flag to indicate we've already used this peg position.
        const int USED_THIS_PEG = -1;

        // initialize our win flag formal parameter to false
        *win = 0;

        // start with empty response code.
        rc[ 0 ] = rc[ 1 ] = rc[ 2 ] = rc[ 3 ] = Empty;

        // indicates the next element in the response code to be populated.
        int build = 0;

        int i, j;

        // put all the red pegs in place.
        for ( i = 0; i < COLORS_PER_GUESS; i++ )
                if ( guess_tracker[ i ] == code_tracker[ i ] ) {
                        rc[ build++ ] = Red;
                        guess_tracker[ i ] = code_tracker[ i ] = USED_THIS_PEG;
                }

        DODEBUG( printf( "    Red pegs computed.  Response built so far = %s.\n",
                        key_array_tostring( rc ) ); )
                        for ( i = 0; i < COLORS_PER_GUESS; i++ )
                for ( j = 0; j < COLORS_PER_GUESS; j++ ) {
                        DODEBUG( display_debugging( i, j, code_tracker, code, guess_tracker ); )
                        if ( guess_tracker[ i ] != USED_THIS_PEG &&
                             guess_tracker[ i ] == code_tracker[ j ] ) {
                                rc[ build++ ] = White;
                                DODEBUG(
                                        printf( "    --> matched.  i=%d, j=%d."
                                                "   guess[%d]=%d used[%d]=%d\n",
                                                i, j, i, guess[i], j, code_tracker[j] );
                                )
                                code_tracker[ j ] = -1;
                                break;
                        }
                }

        // if we have all red, we're done the game!  Set the flag.
        if ( ( rc[ 0 ] == Red ) && ( rc[ 1 ] == Red ) &&
             ( rc[ 2 ] == Red ) && ( rc[ 3 ] == Red ) )
                *win = 1;
        DODEBUG( puts( "    *** Set the win flag to TRUE!" ); )

        return &rc;
}
