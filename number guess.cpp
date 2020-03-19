//Jacob Davidson	
//03/19/2020
//Number guessing game!

#include <stdio.h>
#include <stdlib.h> 
#include <conio.h>
#include <unistd.h>

int compGuess();
int guessComp();
void vsMode();
int mainMenu();

int main()
{
  mainMenu();
}

int mainMenu()
{
	int selection;
	
	//list the options
	printf("Guessing Game Main Menu");
	printf("\n\n\n1. Guess computers number!");
	printf("\n2. Computer guess your number!");
	printf("\n3. Versus mode!");
	printf("\n4. Exit");
	
	//initial selection
		printf("\nSelect an option: ");
		scanf("%d", &selection);
		
	//loop main menu
	while (selection != 4)
	{
		//selection 1 for guessing computers number
		if (selection == 1){
			guessComp();
			selection = 0;
 			}
		//selection 2 for having computer guess your number!
			else if (selection == 2){
	 		compGuess();
	 		selection = 0;
		 }
		//selection 2 for having computer guess your number!
			else if (selection == 3){
	 		vsMode();
	 		selection = 0;
		 }
		 //selection 4 will teminate program if inputed after initial selection
			else if (selection == 4){
				return 0;
		 }
		 // stops user from soft locking or teminating program prematurely
		else {
				system("cls");
				printf("Guessing Game Main Menu");
				printf("\n\n\n1. Guess computers number!");
				printf("\n2. Computer guess your number!");
				printf("\n3. Versus mode!");
				printf("\n4. Exit");
				printf("\nTry again, select a number (1-4): ");
				scanf("%d", &selection);
		}
	}
	return 0;	
}

int guessComp()
{
	//Make a random number generate and have the user guess what the number is and recieve an output from the program stating whether they are too high or too low

  //do not allow users to input the same number twice
  int numTries;
  int guess, i = 0;  
  int tries [100];
  int random1 = rand() % (100 + 1 - 1) + 1;
  
  //assign all int in array to 0
      for (int i = 0; i < 100; i++){
       tries[i] = 0;
       }

  //for testing only comment line out when not debugging
  printf("Answer: %d", random1);
  
  //initial guess
  	system("cls");
	printf("You will guess the computer's number!");
    printf("\nEnter a number between 1 and 100: \n");
    scanf("%d", &guess);

//loop for each guess
  while (guess != random1){
  	
//loop for checking repeated numbers
      for (int i = 0; i < 100; i++){
       if(guess == tries[i]){
          printf("\nYou have guessed this number already!");
          break;
       }
      }
//if statement for checking too high, too low, and out of range
	if(guess > 100 || guess < 1){
      printf("\nOut of range. try again\n");
    }
	else if(guess < random1){
      printf("\nToo low, try again!\n");
  	}    
  	else if(guess > random1){
      printf("\nToo high, try again!\n");
    } 
      tries[i]= guess;
      scanf("%d", &guess);
      i++;
  }
//print correct
  if (guess == random1){
  	
  	for (int i = 0; i < 100; i++){
       if (tries[i] != 0){
	   numTries++;
	   }
       }
  	numTries++;
    printf("\nCorrect, good job!");
    printf("\nIt took you %d tries!", numTries);
    printf("\nReturning to main menu...");
    sleep(5);
    return numTries;
  }
}

int compGuess()
{
	int tries [100];
	int answer, random = 0, guessNum = 0, min = 1, max = 100, i = 0;
	
	//assign all int in array to 0
	for (int i = 0; i < 100; i++){
       tries[i] = 0;
    }
	
	//initial guess
	system("cls");
	printf("Computer will guess your number!");
	printf("\nEnter the answer for the computer to guess: (1-100)\n");
	scanf("%d", &answer);
	
	//make sure answer is within limits
	while (answer > 100 || answer < 1){
		printf("Please enter a number between 1 and 100:");
		scanf("%d", &answer);
	}
	
	//loop for each guess
	while (random != answer){
		random = rand() % (max + 1 - min) + min;
		guessNum++;

		printf("\nGuess number %d: %d",guessNum, random);

	//check for repeated guesses
		for (int i = 0; i < 100; i++){
       		if(random == tries[i]){
          		printf("\nYou have guessed this number already!");
          		break;
       		}
     	}
     	
     	//set new min or max depending on if guess was too high or low
			if(random < answer){
		      printf("\nToo low, try again!\n");
		      min = random;
		  	}    
		  	else if(random > answer){
		      printf("\nToo high, try again!\n");
		      max = random;
		    } 
		    
		tries[i] = random;
      	i++;  
		    
      	if(random != answer){
			sleep(3);
		}
		
	}
	
	//Correct answer has been guessed
	if (random == answer){
		printf("\nThe computer guessed your number!");
    	printf("\nIt took the computer %d tries!", guessNum);
   		printf("\nReturning to main menu...");
    sleep(8);
    return guessNum;
	}
	
}

void vsMode()
{
	int comp, user, diff;
	
	user = guessComp();
	system("cls");
	comp = compGuess();
	
	system("cls");
	printf("The results are in!");
	printf("\nIt took you %d guesses to get the computers number correct!", user);
	printf("\nIt took the computer %d guesses to get your number correct!", comp);
	
	if(user > comp){
		diff = user - comp;
		printf("\nThe computer won by %d guesses! Better luck next time!",diff);
	}
	else{
		diff = comp - user;
		printf("\ncongratulations! You won by %d guesses!", diff);	
	}
	sleep(8);
	printf("\nEnter any number to return to the main menu.", diff);
	scanf("%d");
	return;
}
