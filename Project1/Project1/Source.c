#include<stdio.h>
#include<conio.h>
#include<ctype.h>

void main() {
	int i, j, k;
	char Words[][3] = { "Hey", "How", "Are", "You" };
	char word;

	for (i = 0; i < 4; i++) {
		printf("enter a word:");
		word = _getche();

		if (Words[i][0] == word) {
			printf("\nGood Job");
			_getch();
		}
		else if (Words[i][1] == word)
		{
			printf("\nGood Job");
				_getch();
		}
		else if (Words[i][2] == word)
		{
			printf("\nGood Job");
			_getch();
		}
		else if (Words[i][3] == word)
		{
			printf("\nGood Job");
			_getch();
		}else{
			printf("\nTry Again");
		}
		system("cls");
	}
	system("pause");

}
