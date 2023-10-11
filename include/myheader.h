#ifndef MYHEADER_H
#define MYHEADER_H 
 
#define PROGRAMMER_NAME "Lara Fernandes" 

void program_identification(const int lab_number, const char *assignment_name, const char *assignment_description)
{
	printf("Lab Number %d \n" , lab_number);
	printf("%s \n" , assignment_name);
	printf("%s \n" , assignment_description);

	printf("This program was written by %s and was compiled on %s at %s \n", PROGRAMMER_NAME,__DATE__, __TIME__); 
}
 
#endif //MYHEADER_H 
 
