#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>
#include<Windows.h>
#include<dos.h>
#include<time.h>
#include<stdlib.h>

void Hangman(int n);
void game(char ch);
char title();
void loading();


void main() {
	srand(time(NULL));


	system("COLOR 3");


	char ch;
oxy:
	

	
	ch = title();

	if (ch == 'P' || ch == 'p' || ch == 'C' || ch == 'c' || ch == 'I' || ch == 'i' || ch == 'Q' || ch == 'q')
	{
		game(ch);
	}
	else
	{

	printf("\t\t\t\t Wrong CHOICE!!\n\t\t\t\t Enter Again");
	Sleep(2000);
	system("cls");
	goto oxy;
	}// Wrong character  repeat

	_getch();
}

void Hangman(int n)
{
	
	(n == 5) ? printf("\n\t\t\t\t\t\t\t________\n\n\n\n\n\n\n") :
		(n == 4) ? printf("\n\t\t\t\t\t\t\t________\n\t\t\t\t\t\t\t   |\n\n\n\n\n\n") :
		(n == 3) ? printf("\n\t\t\t\t\t\t\t________\n\\t\t\t\t\t\t\t   |\n\t\t\t\t\t\t\t  \\O/\n\n\n\n\n") :
		(n == 2) ? printf("\n\t\t\t\t\t\t\t________\n\t\t\t\t\t\t\t   |\n\t\t\t\t\t\t\t  \\O/\n\t\t\t\t\t\t\t   |\n\t\t\t\t\t\t\t   |\n\n\n\n") :
		(n == 1) ? printf("\n\t\t\t\t\t\t\t________\n\t\t\t\t\t\t\t   |\n\t\t\t\t\t\t\t  \\O/\n\t\t\t\t\t\t\t   |\n\t\t\t\t\t\t\t   |\n\t\t\t\t\t\t\t  / \\\n\n\n\n") :
		printf("\n\t\t\t\t\t\t\t________\n\t\t\t\t\t\t\t   |\n\t\t\t\t\t\t\t  \\X/\n\t\t\t\t\t\t\t   |\n\t\t\t\t\t\t\t   |\n\t\t\t\t\t\t\t  / \\\n\n\n\n");
		
}

void game(char ch)
{
	int i;
	char Words[][16] = { "boiii", "watermellon", "really", "baka", "expectations", "homoglobin", "lover", "program", "random" };
	char word, guess[16];
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

		switch (ch)
		{
		case 'P':
		case'p':

			if (Wordsguessed[randomindex] == 1)
			{
				break;
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
					printf("\t\t\t\t\tenter a letter:");
					fgets(guess, 16, stdin);//Charater input


					if (strncmp(guess, "quit", 4) == 0) {
						quit = 1;
						break;
					}//if character types quit the game ends

					letterentered = guess[0];
					printf("\n\t\t\t\t\t\tletter Entered:%c \n", letterentered);//Letter entered debugging
					

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




					}
					if (oldcorrect == numcorrect)
					{
						numoflifes--;
						printf("\t\t\t\t\t\tsorry, Wrong guess\n");

						if (numoflifes == 0) {
							break;
						}//no of lifes counter

					}
					else
					{
						printf("\t\t\t\t\t\tCorrect guess\n");
					}//Result shower


					MessageBeep(400);
					Sleep(1000);
					system("cls");




				}
			}//while loop end
			break;

		case 'C':
		case'c':
			system("cls");
			printf("\n\n\n\n\t\t\t\t\t Made by Pir UbaidUllah Jan Sarhandi , Hasnain Ali & Areeba Azam");

			_getch();
			system("cls");
			printf("\n\n\n\n\t\t\t\t\t Made for Sir Anees Ahmed");


			_getch();
			system("cls");
			printf("\n\n\n\n\t\t\t\t\t Iqra University");

			break;// Credits

		case 'i':
		case'I':
			system("cls");

			printf("\n\n\n\n\n\t\t\t\t\t\tEnter a word to check if the word is correct. ");
			break;//instructions

		case'Q':
		case'q':
			quit = 1;
			break;//Quiter



			

		}

		system("cls");
		if (quit == 1) {
			printf("\n YOU QUIT!!!\n");
			break;
		}
		else if (numoflifes == 0)
		{
			printf("\n  YOU LOST!!\n");
			break;
		}
		else
		{
			printf("YOU WIN !!\n");
		}//End game messages
		
	}
	
}

char title()
{
	 char ch;
	printf("\t\t--------------------------------------------------------------------------\n");
	printf("\t\t| #      #      ##      #     #   #######   #      #      ##     #     # |\n");
	printf("\t\t| #      #     #  #     ##    #   #         ##     #     #  #    ##    # |\n");
	printf("\t\t| #      #    #    #    # #   #   #         # #   ##    #    #   # #   # |\n");
	printf("\t\t| ########   ########   #  #  #   #  ####   #   #  #   ########  #  #  # |\n");
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


