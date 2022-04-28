#include"../../StandardDataModifier.h"
#include "PatientList.h"
#include <stdlib.h>
#include <stdio.h>

extern node head;
u32 ListLength=0;

void Add_Patient(u8 name_val,u8 age_val,u8 gender_val,u32 ID_val)
{
	if(ListLength == 0)
	{
		head.Patient_Age=age_val;
		head.Patient_Gender=gender_val;
		head.Patient_ID=ID_val;
		head.Patient_Name=name_val;
		head.Next= NULL; 
	}
	else
	{
		node *last;
		
		node *new = (node*) malloc(sizeof(node));
		
		new ->Patient_Name=name_val;
		new -> Patient_Age=age_val;
		new -> Patient_Gender=gender_val;
		new -> Patient_ID =ID_val;
		new -> Next = NULL;
		last= &head;
		
		while((last -> Next != NULL))
		{
			last = (last -> Next);
		}
		last -> Next = new;
	}
	ListLength++;
	return;
}

void Edit_Patient(u32 ID,u8 val_ID)
{
	u32 newVal;
	u8 newVal2;
	u8 newCVal;
	if(val_ID<3)
	{
		scanf(" %c",&newCVal);
	}
	else if(val_ID==3)
	{
		scanf("%d",&newVal2);
	}
	else
	{
		scanf("%d",&newVal);
	}
	if(ListLength > 0)
	{
		node *Last = &head;
		if(Last->Patient_ID==ID)
		{
			if(val_ID==1)
			{
				Last->Patient_Name=newCVal;
			}
			if(val_ID==2)
			{
				Last->Patient_Gender=newCVal;
			}
			if(val_ID==3)
			{
				Last->Patient_Age=newVal2;
			}
			if(val_ID==4)
			{
				Last->Patient_ID=newVal;
			}
			Print_PatientRecordByID(ID);
		}
		else
		{
			while ((Last -> Next) != NULL)
			{
				Last = Last -> Next;
				if(Last->Patient_ID==ID)
				{
					if(val_ID==1)
					{
						Last->Patient_Name=newCVal;
					}
					if(val_ID==2)
					{
						Last->Patient_Gender=newCVal;
					}
					if(val_ID==3)
					{
						Last->Patient_Age=newVal2;
					}
					if(val_ID==4)
					{
						Last->Patient_ID=newVal;
					}
					Print_PatientRecordByID(ID);
					break;
				}
			}
		}
	}
	
}
void Print_PatientRecords()
{
	printf("\n\n----------------------\n");
	/* at lease 1 node is created */
	if (ListLength > 0)
	{
		node *Last = &head;
		u32 i = 1;
		
		/* Print the list head */
		printf("Patient %d ID = %d\n", i,Last -> Patient_ID);
		printf("Patient %d Name = %c\n", i,Last -> Patient_Name);
		
		printf("Patient %d Age = %d\n", i,Last -> Patient_Age);
		printf("Patient %d Gender = %c\n", i,Last -> Patient_Gender);
		
		/* Print all nodes util you find the last node
		which has the next pointer equals to NULL  */
		while ((Last -> Next) != NULL)
		{
			i++;
			Last = Last -> Next;
			printf("Patient %d ID = %d\n", i,Last -> Patient_ID);
			printf("Patient %d Name = %c\n", i,Last -> Patient_Name);
			
			printf("Patient %d Age = %d\n", i,Last -> Patient_Age);
			printf("Patient %d Gender = %c\n", i,Last -> Patient_Gender);
		}
	}
	
	else
	{
		printf("List is Empty\n");
	}
	
	printf("----------------------\n\n\n");
}

void Print_PatientRecordByID(u32 ID)
{
	printf("\n\n----------------------\n");
	/* at lease 1 node is created */
	if (ListLength > 0)
	{
		node *Last = &head;
		u32 i = 1;
		
		/* Print the list head */
		if(Last -> Patient_ID==ID)
		{
			printf("Patient %d ID = %d\n", i,Last -> Patient_ID);
			printf("Patient %d Name = %c\n", i,Last -> Patient_Name);
			
			printf("Patient %d Age = %d\n", i,Last -> Patient_Age);
			printf("Patient %d Gender = %c\n", i,Last -> Patient_Gender);
		}
		
		
		/* Print all nodes util you find the last node
		which has the next pointer equals to NULL  */
		while ((Last -> Next) != NULL)
		{
			i++;
			Last = Last -> Next;
			if(Last -> Patient_ID==ID)
			{
				printf("Patient %d ID = %d\n", i,Last -> Patient_ID);
				printf("Patient %d Name = %c\n", i,Last -> Patient_Name);
				
				printf("Patient %d Age = %d\n", i,Last -> Patient_Age);
				printf("Patient %d Gender = %c\n", i,Last -> Patient_Gender);
			}
		}
	}
	
	else
	{
		printf("List is Empty\n");
	}
	
	printf("----------------------\n\n\n");
}