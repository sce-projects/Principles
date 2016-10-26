#define _CRT_SECURE_NO_WARNINGS
#include "DataBase.h"
int menu(Client*);

int main()
{

	Client *client_List_Head = NULL;
	menu(client_List_Head);

	puts("It's my try");

	return 0;
}

int menu(Client *client_List_Head)
{
	UserType choise=-1;
	puts("Welcome to our managment system!\nchoose on of below\n");
	puts("1. Client");
	puts("2. Supplier");
	puts("3. Employee");
	puts("4. Option 4");
	puts("5. Option 5");
	puts("6. Quit");
	scanf("%d", &choise);
	switch (choise)
	{
	case CLIENT:
		puts("CLIENT");
		loadFiles(client_List_Head);
		break;

	case SUPPLIER:
		puts("SUPPLIER");

		break;

	case EMPLOYEE:
		puts("EMPLOYEE");

		break;

	default:
		puts("INCORRECT");
		return _INCORRECT_CHOICE;
		break;
	}
	//loadFiles(choise);

	return SUCCESS;
}