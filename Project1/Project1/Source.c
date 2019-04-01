#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>
#include<Windows.h>
#include<dos.h>
#include<stdlib.h>

void main() {
	srand(time(NULL));

	int i, j, k, randomindex = rand() % 9;
	char Words[][16] = { "boiii", "watermellon", "really", "baka", "expectations", "homoglobin", "lover", "program", "random" };
	char word, guess[16];
	int lengthofword = strlen(Words[randomindex]);
	int numoflifes = 5;
	int numcorrect = 0;
	int oldcorrect = 0;
	char letterentered;
	int letterguessed[12] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };//checker
	int quit = 0;
	char ch;
oxy:

	printf("\t\t--------------------------------------------------------------------------\n");
	printf("\t\t| #      #      ##      #     #   #######   #      #      ##     #     # |\n");
	printf("\t\t| #      #     #  #     ##    #   #         ##     #     #  #    ##    # |\n");
	printf("\t\t| #      #    #    #    # #   #   #         # #   ##    #    #   # #   # |\n");
	printf("\t\t| ########   ########   #  #  #   #  ####   #   #  #   ########  #  #  # |\n");
	printf("\t\t| #      #   #      #   #   # #   #     #   #      #   #      #  #   # # |\n");
	printf("\t\t| #      #   #      #   #    ##   #     #   #      #   #      #  #    ## |\n");
	printf("\t\t| #      #   #      #   #     #   #######   #      #   #      #  #     # |\n");
	printf("\t\t--------------------------------------------------------------------------\n");


	printf("\n\n\n\n\n\t\t\t\tPress P to play\n\t\t\t\tPress I for Instructions\n\t\t\t\tPresss C for Credits\n\t\t\t\tPress Q to Quit\n\n\t\t\t\tYour Choice: ");
	scanf_s("%c", &ch);
	getchar();

	if (ch == 'P' || ch == 'p' || ch == 'C' || ch == 'c' || ch == 'I' || ch == 'i' || ch == 'Q' || ch == 'q')
	{
		switch (ch)
		{
		case 'P':
		case'p':


			system("cls");
			Sleep(500);
			printf("loading.");
			Sleep(500);
			printf(".");
			Sleep(500);
			printf(".");
			Sleep(500);
			printf(".");
			Sleep(500);
			printf(".");//loading
			system("cls");

			printf("\nGuess Words : %s randomindex:%d lengthofwords: %d \n",
				Words[randomindex], randomindex, lengthofword);//word checker

			//game loop
			while (numcorrect < lengthofword)
			{
				printf("Next Turn \n WORD : ");
				for (i = 0; i < lengthofword; i++)
				{

					if (letterguessed[i] == 1) {
						printf("%c", Words[randomindex][i]);
					}
					else
					{
						printf("-");
					}
				}//correct word shower

				printf("\nscore:%d\n", numcorrect);//Score
				printf("Lives Left :%d\n", numoflifes);//number of lives
				printf("enter a letter:");
				fgets(guess, 16, stdin);//Charater input

				if (strncmp(guess, "quit", 4) == 0) {
					quit = 1;
					break;
				}//if character types quit the game ends

				letterentered = guess[0];
				printf("letter Entered:%c \n", letterentered);//Letter entered debugging

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
					}//Score increaser




				}
				if (oldcorrect == numcorrect)
				{
					numoflifes--;
					printf("sorry Wrong guess\n");

					if (numoflifes == 0) {
						break;
					}//no of lifes counter

				}
				else
				{
					printf("Correct guess\n");
				}//Result shower


				MessageBeep(400);
				Sleep(1000);
				system("cls");




			}//while loop end
			break;

		case 'C':
		case'c':
			system("cls");
			printf("\n\n\n\n\t\t\t\t\t Made by Ubaid");

			_getch();
			system("cls");
			printf("\n\n\n\n\t\t\t\t\t Made for Anees");


			_getch();
			system("cls");
			printf("\n\n\n\n\t\t\t\t\t Iqra University");


			_getch();
			system("cls");
			printf("\n\n\n\n\t\t\t\t\t ok");
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

		if (quit == 1)
		{
			printf("\nYOU QUIT!!\n");
		}
		else if (numoflifes == 0)
		{
			printf("\n  you lost.\n");
		}
		else {
			printf("YOU WIN !!\n");
		}//End game messages
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