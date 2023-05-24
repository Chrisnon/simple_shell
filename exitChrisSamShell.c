#include "chrissamshell.h"

/*********************************************************
* Project: ALX Simple Shell
*
*
* Team/Group/Collaboration Project

*
*
* Date: 15/05/2023
*
*
* Authors:
*      1. Samuel Atiemo
*    2. Christian Obi
*
*********************************************************/

/*Main functiion which runs the functiion*/
int main();

/*Show prompt for the user to input characters*/          
void displayPrompt();

/*Exits the chrissamshell any time it's called*/
void exit_chrissamshell();


/*Main functn*/
int main(){

/*constant stream of user's inputs are continually called*/ 	
 while(1){ 
   displayPrompt();
 }
return(0);
}

/*Prompt for user input and get input from user*/
/*Quits if the user types "exit" or presses Ctrl-D*/
void displayPrompt(){

/*Inputs that are 479 characters in length*/
 char input[480];

/*Stores chunk data*/
 char chunk[480]; 
 const char delimiter[9] = "; |\n\t&<>";

/*This is token that stores and checks for input*/
 char *token;
 int found = 1; 
 char cwd[192];
  if(getcwd(cwd,sizeof(cwd)) != NULL){
    printf("%s>",cwd);
 }else {

/*User'sprompt is been print to the console*/
   printf("Please Prompt>");
 }

/*Ctrl-D uses fgets then returns NULL to check if Ctrl-D press*/ 
if((fgets(input,480,stdin)) == NULL){
    printf("\n");
    exitProgram();
   }else {
      
/*search for '\0' symbolizationn in input; output is too bigg if not found*/
for(int i = 0; i<479;i++){
       if (input[i] == '\0'){
        found = 0;
   }
 }

 if(found == 1){

/*prints error message if input is big*/ 
  printf("Error char limit exceeded\n");

/*reads chunk data, thus newline*/
  fgets(chunk,480,stdin);

/*Reads chunk data, thus exceeded characters or limits*/
  fgets(chunk,480,stdin);
 }

 /*Looks and determines if input is "exit" ; program exits if so*/
if (!strcmp(input,"exit\n")){
       exitProgram();
 } 

/*token sets to input and includes spaces*/
 token = strtok(input,delimiter);

 /*Looks if no input  and display no input if so*/
 if (input[0] == '\n' && input[1] == '\0'){
       printf("No input detected\n");
 }else {

/*Prints out token if not NULL; sets to NULL after prints*/
   while( token != NULL && found == 0) {
     		printf( " '%s'\n", token );
     		token = strtok(NULL, delimiter);
    }
   }
  }
 }

void exit_chrissamshell(){

printf("Exiting chrissamshell....\n");
exit(0);

}

