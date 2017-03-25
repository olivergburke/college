#include "stdafx.h"
#include <stdio.h>
#include "string.h"
#include "stdlib.h"

typedef struct
{
	char userName[30];
	char firstName[30]
	char lastName[30];
	char displayName[60];
	char jobTitle[30];
	char department[30];
	char officeNumber[10];
	char officePhone[30];
	char mobile[15];
	char fax[30];
	char address[30];
	char city[20];
	char state[5];
	char zip[10];
	char country[30];
}contact;

contact *contacts[10];

int numContacts = 0;

int readFile(char *fileName);
void initialiseContacts();
void printContact(contact *aContact);

int main()
{
	char fileName[] = "U:\\contacts.txt";
	int i=0;

	void initialiseContacts();

	if (!readFile(fileName))
	{
		printf( "File could not be opened !!\n " );
		return 0;
	}


	while (contacts[i] != NULL)
	{
		printContact(contacts[i]);
		i++;
	}

	return 0;
}
void initialiseContacts()
{
	int i = 0;

	free(*contacts);
	for(i=0;i<10;i++)
	{
		*(contacts+i) = NULL;
	}
}

int readFile(char *fileName)
{
	int i=0;
	FILE *fptr;
	char *tempString;
	fptr = fopen(fileName, "r");
	char line[300];

	fgets(line, 300, fptr);

	while (!feof(fptr))
	{
		contacts[i] = (contact *)malloc(sizeof(contact));
		fgets(line, 300, fptr);

		tempString = strtok(line, ",");
		strcpy(contacts[i]->userName, tempString);
		tempString = strtok(NULL, ",");
		strcpy(contacts[i]->firstName, tempString);
		tempString = strtok(NULL, ",");
		strcpy(contacts[i]->lastName, tempString);
		tempString = strtok(NULL, ",");
		strcpy(contacts[i]->displayName, tempString);
		tempString = strtok(NULL, ",");
		strcpy(contacts[i]->jobTitle, tempString);
		tempString = strtok(NULL, ",");
		strcpy(contacts[i]->department, tempString);
		tempString = strtok(NULL, ",");
		strcpy(contacts[i]->officeNumber, tempString);
		tempString = strtok(NULL, ",");
		strcpy(contacts[i]->officePhone, tempString);
		tempString = strtok(NULL, ",");
		strcpy(contacts[i]->mobile, tempString);
		tempString = strtok(NULL, ",");
		strcpy(contacts[i]->fax, tempString);
		tempString = strtok(NULL, ",");
		strcpy(contacts[i]->address, tempString);
		tempString = strtok(NULL, ",");
		strcpy(contacts[i]->city, tempString);
		tempString = strtok(NULL, ",");
		strcpy(contacts[i]->state, tempString);
		tempString = strtok(NULL, ",");
		strcpy(contacts[i]->zip, tempString);
		tempString = strtok(NULL, "\n");
		strcpy(contacts[i]->country, tempString);

		numContacts++;
		i++;
	}
	fclose(fptr);
	return 1;
}

void printContact(contact *aContact)
{
	printf("User Name: %s\nFirst Name: %s\Last Name: %s\nDisplay Name: %s\nJob Title: %s\nDepartment: %s\nOffice Number: %s\nOffice Phone: %s\nMobile Phone: %s\nFax: %s\nAddress: %s\nCity: %s\nState: %s\nZIP: %s\n\n", aContact->userName, aContact->firstName, aContact->lastName, aContact->displayName, aContact->jobTitle, aContact->department, aContact->officeNumber, aContact->officePhone, aContact->mobile, aContact->fax, aContact->address, aContact->city, aContact->state, aContact->zip, aContact->country);
}
