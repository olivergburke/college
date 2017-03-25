#include "stdafx.h"
#include <stdio.h>
#include "string.h"
#include "stdlib.h"

struct date
{
	int day, month, year;
};

struct record
{
	struct date orderDate;
	char region[20];
	char rep[20];
	char item[20];
	int units;
	float unitCost;
	float totalCost;
};

int nRecords = 0;
struct record records[501];
int readFile(char *fileName);
void findByRegion(char *region);
void findByRep(char *rep);
void findByItem(char *item);
void findByYear(int year);

int getOption();

void main()
{
	char fileName[] = "F:\\SampleData.txt";
	int option, year;
	char temp[20];


	readFile(fileName);

	if (!readFile(fileName))
	{
		printf("File could not be opened !!\n");
		return;
	}
	option = getOption();


	while (option != 0)
	{
		switch (option)
		{
		case 1:
			puts("Enter Region");
			gets_s(temp);
			findByRegion(temp);
			break;
		case 2:
			puts("Enter Rep");
			gets_s(temp);
			findByRep(temp);
			break;
		case 3:
			puts("Enter Item");
			gets_s(temp);
			findByItem(temp);
			break;
		case 4:
			puts("Enter Year");
			gets_s(temp);
			year = atoi(temp);
			findByYear(year);
			break;
		}
		option = getOption();

	}
}

int readFile(char *fileName)
{

	char *tempString;
	int i = 0;

	FILE *fptr;
	char line[300];

	fptr = fopen(fileName, "r");

	fgets(line, 300, fptr);
	
	while (!feof(fptr))
	{
		fgets(line, 300, fptr);

		tempString = strtok(line, "/");
		records[nRecords].orderDate.day = atoi(tempString);

		tempString = strtok(NULL, "/");
		records[nRecords].orderDate.month = atoi(tempString);
		
		tempString = strtok(NULL, "\t");
		records[nRecords].orderDate.year = atoi(tempString);

		tempString = strtok(NULL, "\t");
		strcpy(records[nRecords].region, tempString);

		tempString = strtok(NULL, "\t");
		strcpy(records[nRecords].rep, tempString);

		tempString = strtok(NULL, "\t");
		strcpy(records[nRecords].item, tempString);

		tempString = strtok(NULL, "\t");
		records[nRecords].units = atoi(tempString);

		tempString = strtok(NULL, "\t");
		records[nRecords].unitCost = atof(tempString);
		
		records[nRecords].totalCost = (records[nRecords].unitCost)*(records[nRecords].units);
		nRecords++;
	}
	
	fclose(fptr);
	return 1;
}


void findByRegion(char *region)
{
	int i = 0;
	float total = 0.0;

	for (i = 0; i<nRecords; i++)
	{
		if ((!strcmp(records[i].region, region))==0)
		{
			total = total + records[i].totalCost;
		}
	}
	
	printf("Sales for region: %s = %.2f\n", region, total);
}

void findByRep(char *rep)
{
	int i = 0;
	float total = 0.0;

	for (i = 0; i<nRecords; i++)
	{
		if ((!strcmp(records[i].rep, rep)) == 0)
		{
			total = total + records[i].totalCost;
		}
	}
	printf("Sales for rep: %s = %.2f\n", rep, total);
}

void findByItem(char *item)
{
	int i = 0;
	float total = 0.0;

	for (i = 0; i<nRecords; i++)
	{
		if ((!strcmp(records[i].item, item)) == 0)
		{
			total = total + records[i].totalCost;
		}
	}
	printf("Sales for item: %s = %.2f\n", item, total);
}

void findByYear(int year)
{
	int i = 0;
	float total = 0.0;

	for (i = 0; i<nRecords; i++)
	{
		if(records[i].orderDate.year = year)
		{
			total = total + records[i].totalCost;
		}
	}
	printf("Sales for year: %d = %.2f\n", year, total);
}


int getOption()
{
	int option = 0;
	char inp[3];

	puts("Enter one of the follow options:");
	puts("1 - sales by region");
	puts("2 - sales by rep");
	puts("3 - sales by item");
	puts("4 - sales by year");
	puts("0 - quit");
	gets_s(inp);
	option = atoi(inp);

	return option;
}
