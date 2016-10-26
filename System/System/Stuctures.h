#define _CRT_SECURE_NO_WARNINGS

typedef enum { FAIL, SUCCESS } Bool; // boolean
typedef enum {CLIENT=1, SUPPLIER, EMPLOYEE } UserType;
typedef enum {_SUCCESS,_INCORRECT_CHOICE, _INCORRECT_INPUT, _FILE_NOT_OPENED};

#define STRING_LENGTH 32
#define MAX_LINE 265


typedef struct {
	char name[STRING_LENGTH];
} Name;

typedef struct Client{
	int clientNumber;
	char id[STRING_LENGTH]; 
	long int balance;
	Name clientName;
	struct Client* next;
}Client;

typedef struct {
	int id, licenseNumber;
	Name supplier;
} Supplier;

typedef struct{
	Name employee;
	int id, seniority, salary;
}Employee;


//////////////// LISTS
//typedef struct ClientsList {
//	Client *next;
//};