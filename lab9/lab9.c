#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "../include/mastermind.h"
#include "../include/myheader.h"


int main()
{
        peg_array code, guess;          // code is the mastermind code, guess is the user's current guess.
        char *code_string;
        
        //Calls program identification function
        program_identification( 9, "Mastermind", "Play the game of Mastermind!" );

        code[ 0 ] = Black;
        code[ 1 ] = Yellow;
        code[ 2 ] = Green;
        code[ 3 ] = Black;

        DODEBUG(
                code_string = peg_array_tostring( code );
                printf( "    ---DEBUG: The secret code to be GUESSED is %s.\n", code_string );
        )

        int i = 0;
        int did_I_win = 0;
        while ( ! did_I_win && ( i++ <= NUMBER_OF_ROUNDS ) ) {
                get_codebreaker_guess( guess );
                printf( "Your guess is %s.\n\n", peg_array_tostring( guess ) );
                key_array *r = mastermind_response( code, guess, &did_I_win );
                printf( "\nThe mastermind responds: %s.\n\n", key_array_tostring( *r ) );
        }

        if ( did_I_win )
                printf( "Congratulations, you beat the mastermind code in only %d tries!\n", i );
        else
                puts( "Sorry, you've had too many guesses.  You lose.\n" );

        DODEBUG( puts( "Program complete."); )

        return EXIT_SUCCESS;
}


void get_codebreaker_guess( peg_array guess )
/*
 * Preconditons:   None
 * Postconditions: guess will contain 4 valid guesses
 * Returns:        NONE
 * Globals:        VALID_GUESS_STRING - characters accepted for colors.  Should be text of "bygpol".
 *                 COLORS_PER_GUESS   - number of colors to get from user.  Should be 4.
 *Description:     Takes in 4 guesses from the user, and displays the guess with peg_array_tostring()
 *
 *
 */
{
        printf( "Given the following colors:\n    %s\n"
                "enter your 4 color guesses using the letter in parentheses or 0 to quit: ",
                        VALID_GUESS_STRING );

        int i = 0;
        for ( i = 0; i < COLORS_PER_GUESS; i++ )
                get_single_guess( &guess[ i ] );

        // discard whitespace character after reading in the four guesses.
        scanf( "%*c" );

        DODEBUG(
                printf( "    ---DEBUG: Your guess was:\n              %s\n", peg_array_tostring( guess ) );
                puts(   "              RETURNING TO MAIN." );
        )

        return;
}


void get_single_guess( mastermind_peg *guess )
/*
 * Precondtions:  NONE
 * Postcondtions: guess will contain a validated guess
 * Returns:       NONE
 * Globals:       NONE
 * Description:   Takes in a guess from the user and assigns guess a value based on that. 
 *                If the value if 0 the the program ends or if the guess is invalid, the program ends.
 *
 *
 */
{
        char c = getchar();

        DODEBUG( printf( "    ---DEBUG: Processing character '%c'.\n", c ); )

        switch ( c ) {
                case 'b': *guess = Blue;   break;
                case 'y': *guess = Yellow; break;
                case 'g': *guess = Green;  break;
                case 'p': *guess = Purple; break;
                case 'o': *guess = Orange; break;
                case 'l': *guess = Black;  break;
                case '0': say_goodbye_and_exit_program( "\n\nThanks for playing Mastermind!" );   break;
                default:
                       printf( "Invalid character in guess: '%c'.\n\n", c );
                        puts(   "    Valid guess characters are 'bygpol'.\n"
                                "    All characters must be entered together.  For example,\n"
                                "    'ygpl' would represent yellow, green, purple, and black.\n" );
                        say_goodbye_and_exit_program( "Program ends." );
        }
        return;
}

