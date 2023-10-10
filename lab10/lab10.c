#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#define NUMBER_OF_QUESTIONS 11
#define MAXIMUM_STUDENTS_IN_GROUP 15
#define STUDENT_ID_SIZE 5

typedef struct {
	char student_id[ STUDENT_ID_SIZE + 1 ];
	char student_answers[ NUMBER_OF_QUESTIONS + 1 ];
	char student_name[30];
	int right, wrong, grade;		// # right, # wrong, grade out of 100.
} student_response_t;

typedef struct {
	char group[ 3 ];
	int number_of_students;
	student_response_t r[ MAXIMUM_STUDENTS_IN_GROUP ];
} group_t; 


void read_complete_group( FILE **in_fileptr, group_t *g );
void calculateScore(char correctAnswers[NUMBER_OF_QUESTIONS], student_response_t *student);

int main()
{
    
	FILE *INFILE = fopen( "group_results.txt", "r" );
	FILE *OUTFILE = fopen("full_data.csv", "w");
	
	if ( ! INFILE ) {
		fprintf( stderr, "Can't find input file group_results.txt.");
		exit( EXIT_FAILURE );
	}
	
	group_t group[30];
	
	char correctAnswer[NUMBER_OF_QUESTIONS];
	
	fscanf(INFILE, "%*d %*d %*d %s", correctAnswer);
	
	for(int i = 0; i<30; i++){
	read_complete_group( &INFILE, &group[i] );
	
	  for(int j = 0; j < group[i].number_of_students; j++){
	      student_response_t student= group[i].r[j];
	      //fputs(OUTFILE, "check");
	      fprintf(OUTFILE, "%s, %s, %s,", student.student_name, group[i].group, student.student_id);
	      for (int a = 0; a<NUMBER_OF_QUESTIONS; a++){
	          fprintf(OUTFILE, "%c,", student.student_answers[a]);
	      }
	      calculateScore(correctAnswer, &student);
	      fprintf(OUTFILE, "%d, %d,%d", student.right, student.wrong, student.grade);
	      fprintf(OUTFILE, "\n");
	  }
	}
	
	printf("%d", group[0].number_of_students);
	
	fclose( INFILE );

}
void calculateScore(char correctAnswers[NUMBER_OF_QUESTIONS], student_response_t *student){
    student->right = 0;
    student -> wrong = 0;
    
    printf("\n Name: %s \n", student->student_name);
    
    for (int i = 0; i<NUMBER_OF_QUESTIONS; i++){
        if(student-> student_answers[i] == correctAnswers[i])
        {
         (student->right)++;
         printf("\t%d. right!\n", i);
        }
        
        else
        {
         (student->wrong)++;
         printf("\t%d. wrong!\n", i);
        }
    }
    
    int grade = ((double)(student->right))/NUMBER_OF_QUESTIONS * 100;
    student -> grade = grade;
}

void read_complete_group( FILE **in_fileptr, group_t *g )
{
	FILE *IN = *in_fileptr;

	fscanf( IN, "%s", g->group );
	fscanf( IN, "%d", &g->number_of_students );
	printf( "Processing group %s with %d students.\n", g->group, g->number_of_students );

	int i;
	for ( i = 0; i < g->number_of_students; i++ ) 
	{
		fscanf( IN, "%5s", g->r[ i ].student_id );
		g->r[ i ].student_id[ STUDENT_ID_SIZE ] = '\0';
		printf( "Read in THIS student id %s.\n", g->r[ i ].student_id );
		
		FILE *STUDENT = fopen("student_names.txt", "r");
		
		while(!feof(STUDENT)){
		    char name[40];
		    char check_id[6];
		    
		    fscanf(STUDENT, "%5s", check_id);
		    if(strcmp(check_id, g->r[i].student_id)==0){
		        fgets(name, 40, STUDENT);
		        name[strlen(name)-1] = '\0';
		        strcpy(g->r[i].student_name, name);
		        rewind(STUDENT);
		        break;
		    }
		 
		}
		
		fgets( g->r[ i ].student_answers, NUMBER_OF_QUESTIONS+1, IN );
		g->r[ i ].student_answers[ NUMBER_OF_QUESTIONS ] = '\0';
		printf( "Read in the list of questions: %s.\n", g->r[ i ].student_answers );
	}
	return;
}
