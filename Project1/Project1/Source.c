#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>
#include<Windows.h>


char title();
void credits();
void instructions();
void Hangman(int n);
void loading();
void game();



void main() {
		system("COLOR 3");
		char ch;
		int i = 0;

		while(i == 0)
		{
		
	
			ch = title();
			switch (ch)
			{
			case 'P':
			case 'p':
				game(ch);
				i++;
				_getch();
				break;

			case 'C':
			case 'c':
				credits();
				break;

			case 'I':
			case 'i':
				instructions();
				break;

			case 'Q':
			case 'q':
				printf("\n\n\n\n\t\t\t\t\tYOU QUIT MATE!");
				i++;
				break;

			default:
				printf("Wrong Choice");
				Sleep(2000);
				break;


			}
		}
		_getch();
}



char title()
{
	 char ch;
	 system("cls");

	printf("\t\t--------------------------------------------------------------------------\n");
	printf("\t\t| #      #      ##      #     #   #######   #      #      ##     #     # |\n");
	printf("\t\t| #      #     #  #     ##    #   #         ##    ##     #  #    ##    # |\n");
	printf("\t\t| #      #    #    #    # #   #   #         # #  # #    #    #   # #   # |\n");
	printf("\t\t| ########   ########   #  #  #   #  ####   #  ##  #   ########  #  #  # |\n");
	printf("\t\t| #      #   #      #   #   # #   #     #   #      #   #      #  #   # # |\n");
	printf("\t\t| #      #   #      #   #    ##   #     #   #      #   #      #  #    ## |\n");
	printf("\t\t| #      #   #      #   #     #   #######   #      #   #      #  #     # |\n");
	printf("\t\t--------------------------------------------------------------------------\n");

	printf("\n\t\t\t\t\t________\n\t\t\t\t\t   |\n\t\t\t\t\t  \\O/\n\t\t\t\t\t   |\n\t\t\t\t\t   |\n\t\t\t\t\t  / \\");
	printf("\n\t\t\t\t\tSAVE ME!!");
	printf("\n\n\n\n\n\t\t\t\tPress P to play\n\t\t\t\tPress I for Instructions\n\t\t\t\tPresss C for Credits\n\t\t\t\tPress Q to Quit\n\n\t\t\t\tYour Choice: ");
	scanf_s("%c", &ch);
	getchar();
	return ch;
}

void loading() {


	system("cls");
	Sleep(500);
	printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tloading.");
	Sleep(500);
	printf(".");
	Sleep(500);
	printf(".");
	Sleep(500);
	printf(".");
	Sleep(500);
	printf(".");
	system("cls");
}

void game()
{

	srand(time(NULL));
	int i;
	char Words[][16] = { "boiii", "watermellon", "really", "baka", "expectations", "homoglobin", "lover", "program", "random" };
	char guess[16];
	int numoflifes = 5;
	int score = 0;
	int oldcorrect = 0;
	char letterentered;
	int Wordsguessed[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };//checker
	int quit = 0;

	for (int j = 0; j < 9; j++)
	{
										
		int randomindex = rand() % 9; 
		int lengthofword = strlen(Words[randomindex]);
		int letterguessed[15] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 , 0 , 0 , 0 };//checker
		int numcorrect = 0;

		if (Wordsguessed[randomindex] == 1)
		{
			j--;
			continue;
		}
		else
		{
			loading();
			Wordsguessed[randomindex]++;

			//game loop
			while (numcorrect < lengthofword)
			{
				printf("\t\t\t\t\t\t\tNew Turn \n\t\t\t\t\t\t WORD : ");
				for (i = 0; i < lengthofword; i++)
				{

					if (letterguessed[i] == 1)
					{
						printf("%c", Words[randomindex][i]);
					}
					else
					{
						printf("-");
					}

				}//correct word shower


				printf("\n\t\t\t\tGuess Words : %s randomindex:%d lengthofwords: %d \n",
					Words[randomindex], randomindex, lengthofword);//word checker
				printf("\n\t\t\t\t\t\t\tscore:%d\n", score);//Score

				Hangman(numoflifes);

				printf("\n\t\t\t\t\t\tLives Left :%d\n", numoflifes);//number of lives
				printf("\t\t\t\t\t        Enter a letter:");
				fgets(guess, 16, stdin);//Charater input

				_strlwr_s(guess , 16);

				if (strncmp(guess, "quit", 4) == 0) {
					quit = 1;
					break;
				}//if character types quit the game ends

				letterentered = guess[0];
				printf("\n\t\t\t\t\t\tLetter Entered:%c \n", letterentered);//Letter entered debugging


				oldcorrect = numcorrect;

				for (i = 0; i < lengthofword; i++)
				{
					if (letterguessed[i] == 1)
					{
						continue;
					}

					if (letterentered == Words[randomindex][i])
					{
						letterguessed[i] = 1;
						++numcorrect;
						score++;
					}//Score increaser
				}// loop end 

				if (oldcorrect == numcorrect)
				{
					numoflifes--;
					printf("\t\t\t\t\t\tsorry, Wrong guess\n");					

				}//no of lifes counter
				else
				{
					printf("\t\t\t\t\t\tCorrect guess\n");
				}//Result shower

			
				MessageBeep(400);
				Sleep(1000);
				system("cls");

				if (quit == 1) {
					printf("\n\t\t\t\t\t\t\t\t YOU QUIT!!!\n");
					break;
				}
				else if (numoflifes == 0)
				{
					printf("\n\t\t\t\t\t\t\tYOU LOST!!\n");
					
				}
				else if (numcorrect == lengthofword)
				{
					printf("\n\n\n\t\t\t\t\t\t CORRECT WORD !! NEXT!?\n");
					Sleep(2000);
					
				}//End game messages


				if (numoflifes == 0) {
					Hangman(numoflifes);
					_getch();
						break;
				}
			}//while loop end
		}

		if (numoflifes == 0 || quit == 1 )
		{
			break;
		}
	}
}

void credits()
{
	system("cls");
	printf("\n\n\n\n\t\t\t\t\t Made by Pir UbaidUllah Jan Sarhandi \n\n\t\t\t\t\t Hasnain Ali \n\n\t\t\t\t\t Areeba Azam");
	_getch();

	system("cls");
	printf("\n\n\n\n\t\t\t\t\t Made for Sir Anees Ahmed\n\n\t\t\t\t\t\t Miss Ruksana Majeed \n\n\t\t\t\t\t\t Miss Sania Marium");
	_getch();

	system("cls");
	printf("\n\n\n\n\t\t\t\t\t Iqra University");
	_getch();
	
}

void instructions()
{
	system("cls");
	printf("\n\n\n\n\n\t\t\t\t\t\tEnter a word to check if the word is correct.\n\n\t\t\t\t The game will continue until you either type 'quit' or you lose lifes.  ");
	_getch();
	

}

void Hangman(int n)
{

		(n == 5) ? printf("\n\t\t\t\t\t\t\t________\n\n\n\n\n\n\n") :
		(n == 4) ? printf("\n\t\t\t\t\t\t\t________\n\t\t\t\t\t\t\t   |\n\n\n\n\n\n") :
		(n == 3) ? printf("\n\t\t\t\t\t\t\t________\n\t\t\t\t\t\t\t   |\n\t\t\t\t\t\t\t  \\O/\n\n\n\n\n") :
		(n == 2) ? printf("\n\t\t\t\t\t\t\t________\n\t\t\t\t\t\t\t   |\n\t\t\t\t\t\t\t  \\O/\n\t\t\t\t\t\t\t   |\n\t\t\t\t\t\t\t   |\n\n\n\n") :
		(n == 1) ? printf("\n\t\t\t\t\t\t\t________\n\t\t\t\t\t\t\t   |\n\t\t\t\t\t\t\t  \\O/\n\t\t\t\t\t\t\t   |\n\t\t\t\t\t\t\t   |\n\t\t\t\t\t\t\t  / \\\n\n\n\n") :
		printf("\n\t\t\t\t\t\t\t________\n\t\t\t\t\t\t\t   |\n\t\t\t\t\t\t\t  \\X/\n\t\t\t\t\t\t\t   |\n\t\t\t\t\t\t\t   |\n\t\t\t\t\t\t\t  / \\\n\n\n\n");

}

