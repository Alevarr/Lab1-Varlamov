#include "header.h"
#include <stdlib.h>
#include <stdio.h>

int ask(const char *msgs[], int n)
{
	// system("clear");
	int choice = -1;
	char *err = "";
	while (choice < 0 || choice >= n)
	{
		puts(err);
		err = "Wrong input";
		for (int i = 0; i < n; i++)
		{
			printf("%s\n", msgs[i]);
		}
		printf("Enter option: ");
		scanf("%d", &choice);
	}
	if (!choice)
		choice -= 20;
	return choice;
}

void menu(String* Str)
{
	const char *MSGS_MAIN[] = {
		"0. Quit",
		"1. Input with keyboard",
		"2. Concatenate",
		"3. Get substring from i to j",
		"4. Split into words",
		"5. Print out"
	};
	const int MAIN_NMEMB = 6;

	int option = 0;

	while (option >= 0)
	{
		switch (option)
		{
		case 0:
			option = ask(MSGS_MAIN, MAIN_NMEMB);
			break;

		case 1:
			Str->Info->keyboardInput(Str);
			option = 0;
			break;

		case 2:
			Str->Info->concatenate(Str);
			option = 0;
			break;

		case 3:
			Str->Info->getSubString(Str);
			option = 0;
			break;

		case 4:
			Str->Info->splitIntoWords(Str);
			option = 0;
			break;

		case 5:
			Str->Info->print(Str);
			option = 0;

		default:
			option = 0;
		}
		
	}
}
