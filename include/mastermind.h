#ifndef MASTERMIND_H
#define MASTERMIND_H

// Symbolic Constants go here ----
#define CODE_STRING_MAXIMUM_SIZE 36
	// "|Orange| |Orange| |Orange| |Orange|" would be 28 characters, the longest string.
#define DEFAULT_RETURN_STRING  "None"      // When there are none to return.
#define NUMBER_OF_PEG_COLORS  6            // Six colors to choose from.
#define COLORS_PER_GUESS  4                // Users get 4 color guesses per round.
#define NUMBER_OF_ROUNDS  9                // User gets 9 tries at guessing the code.
#define VALID_GUESS_STRING  "(b)lue, (y)ellow, (g)reen, (p)urple, (o)range, b(l)ack"

// Typedefs go here ----
typedef enum {
	Blue, Yellow, Green, Purple, Orange, Black
} mastermind_peg;

typedef enum {
	Red, White, Empty
} key_peg;

// peg_array is a type that holds four mastermind_peg values ( colors )
// key_array is a type that holds four key_peg values ( red, white, empty ).
typedef mastermind_peg       peg_array[ COLORS_PER_GUESS ];	// Used for the color codes
typedef key_peg              key_array[ COLORS_PER_GUESS ];	// Our response to the color code

// prototypes
char *mastermind_peg_tostring( const mastermind_peg p );	// convert a single peg to string
char *mastermind_key_tostring( const key_peg c );		// convert a single key peg to string

char *peg_array_tostring( const peg_array c );			// convert entire peg array to a string
char *key_array_tostring( const key_array c );		        // convert entire key array to a string

void  generate_random_code( peg_array code );			// let the computer pick colors and positions
void  get_codebreaker_guess( peg_array guess );			// user input

void get_single_guess( mastermind_peg *guess );                 // gets one guess
void say_goodbye_and_exit_program( const char *message );       // prints a message and ends the program

                                                                // calculates a response to a guess
key_array *mastermind_response( const peg_array code, const peg_array guess, int *win );


// Create the DODEBUG macro based on whether DEBUG is defined.
#ifdef DEBUG
#define DODEBUG(x)      { x }
#else
#define DODEBUG(x)
#endif

// Used to display mastermind_response thought process.
#define display_debugging( i, j, ut, code, guess ) \
        { \
        printf( "      * ( i = %d, j = %d )\n", i, j ); \
        printf( "        Used Tracker array = %3d %3d %3d %3d.\n",    ut[0],    ut[1],    ut[2],    ut[3] ); \
        printf( "        Code array         = %3d %3d %3d %3d.\n",  code[0],  code[1],  code[2],  code[3] ); \
        printf( "        Guess array        = %3d %3d %3d %3d.\n", guess[0], guess[1], guess[2], guess[3] ); \
        }

#endif //MASTERMIND_H

