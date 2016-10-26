#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Stuctures.h"
#include <stdlib.h>
#include <string.h>

#define CLIENTS_FILE_PATH "./clients.bin"
#define SUPPLIERS_FILE_PATH "./suppliers.txt"

static int amountOfCLients = 0;
static int amountOfSuppliers = 0;


//////////// Declarations
Client* initiateClients();
void printClients(Client *head);
void addSingleClient(Client *head);


////////////
void createTest()
{
	Client one = { 1, "3233", 1045600, "Alex"};
	Client two = { 2, "3146", 100002, "Alex2" };
	Client three = { 3,"3400", 1045600, "Alex3" };
	Client four = { 4, "96486",1045600, "Alex4" };
	FILE *file = fopen(CLIENTS_FILE_PATH, "wb");
	fwrite(&one, sizeof(Client), 1, file);
	fwrite(&two, sizeof(Client), 1, file);
	fwrite(&three, sizeof(Client), 1, file);
	fwrite(&four, sizeof(Client), 1, file);
	fclose(file);
}


int loadFiles(Client *clients_List_Head)
{
	FILE *suppliersFile = NULL;
	FILE *employeesFile = NULL;


		clients_List_Head = initiateClients();

	return _SUCCESS;
}

Client* initiateClients()
{
	createTest();
	FILE *clientsFile = NULL;

	Client tempClient;
	Client *head = NULL;
	Client *tail = NULL;

	clientsFile = fopen(CLIENTS_FILE_PATH, "rb");

	if (!clientsFile)
	{
		printf("Can not open file : %s \n", CLIENTS_FILE_PATH);	
	}
	else
	{
		while (fread(&tempClient, sizeof(Client), 1, clientsFile))
		{
			Client *current = (Client*)malloc(sizeof(Client));
			strcpy(current->id, tempClient.id);
			strcpy(current->clientName.name, tempClient.clientName.name);
			current->balance = tempClient.balance;
			current->clientNumber = tempClient.clientNumber;
			amountOfCLients++;

			if (head == NULL)
			{
				head = current;
				tail = head;
				head->next = NULL;
			}
			else
			{
				tail->next = current;
				tail = current;
				tail->next = NULL;
			}
		}
	}
	fclose(clientsFile);

	return head;
}

void printClients(Client *head)
{
	Client* temp = head;
	unsigned counter = 0;
	while (temp)
	{
		printf("---------- Client #%u ----------\n", ++counter);
		printf("ID : %d \n", temp->id);
		printf("Name : %s\n", temp->clientName.name);
		printf("Balance : %d \n", temp->balance);
		puts(" ");

		temp = temp->next;
	}
}

void addSingleClient(Client *head)
{
	Client *newClient = (Client*)malloc(sizeof(Client));
	Client *tail = NULL;
	Client *current = NULL;


	fflush(stdin);
	puts("To add new client, fill bellow form");
	printf("Name : ");

	gets(newClient->clientName.name);
	printf("Current Ballance : ");
	scanf("%d", &newClient->balance);
	fflush(stdin);
	printf("ID : ");
	scanf("%s",&newClient->id);
	fflush(stdin);

	*newClient->id = ++amountOfCLients;

	newClient->next = NULL;
	
	if (head == NULL){
		head = newClient;
	}

	else
	{
		//loop through the list and find the last
		//node, insert next to it
		current = head;
		while (1) 
		{
			if (current->next == NULL)
			{
				current->next = newClient;
				break;
			}
			current = current->next;
		};
	}
}