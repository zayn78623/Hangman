#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

int fact(int);
int main()
{
  char hangmanword[100];
  int num;
  printf("This has been hell, it better be working now or else im done with this shit.");
  _getch(); 
  printf("Enter number:");
  scanf_s("%d", &num);
  printf("%d! = %d ", num, fact(num));
  _getch();
}
int fact(int n)
{
	int loop;
	int result;

	for ( loop = 1; loop <= n ; loop++)
	{
		result = result*loop;
		return result;
	}
}
