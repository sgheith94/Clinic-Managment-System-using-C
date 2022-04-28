#include<stdio.h>
#include<stdlib.h>
#include"../../StandardDataModifier.h"
#include"PatientList.h"


node head;

typedef struct s1
{
	u8 Day_ID;
	u32 Slot[5];
	u32 ID[5]  ;
	
}Days;


void Reserve_Slot(Days*p_Appoinment,u32 Patient_ID,u8 Day_ID,u8 Slot_ID);
void Cancel_Reserve(Days*p_Appoinment,u32 Patient_ID);
void PrintReservations(Days*p_Appoinment);
void ShowAvailableAppointment(Days*p_Appoinment);
u8 CheckID(node ptr,u32 Patient_ID);
void PrintSingleReservation(Days*p_Appoinment,u32 Patient_ID);

void main()
{
	Days Appointment[7];
	u8 mode;
	u32 admin_input;
	u32 admin_password;
	u32 user_input;
	u8  ExitFlag = 0;
	u8 pass_trial;
	u8 flagadmin=0;
	u32 patient_ID;
	u32 temp;
	u8 name;
	u8 flagout=0;
	u8 gender;
	u8 age;
	u8 res=2;
	u8 day_ID;
	u8 slot_ID;
	u8 res2;
	u8 userflag=0;
	u32 user_ID;
	u8 oldID=0;
	u8 valIDTemp;
	for(int i=0;i<7;i++)
	{
		Appointment[i].Day_ID=i;
		
		for(int y=0;y<5;y++)
		{
			Appointment[i].ID[y]=-1;
			Appointment[i].Slot[y]=-1;
		}
	}
	
	while(ExitFlag==0)
	{
		printf("Enter 1 for admin mode and 2 for user mode: \n");
		printf("Enter 3 to Exit: \n ");
		scanf("%d",&mode);
		
		switch(mode)
		{
			case 1:
			printf("welcome to admin mode! \n");
			pass_trial=0;
			while(pass_trial<3)
			{
				printf("Please Enter the password");
				scanf("%d",&admin_password);
				if(admin_password==1234)
				{
					ExitFlag=0;
					break;
				}
				else
				{
					ExitFlag=1;
					printf("Wrong password,Please try again! \n");
				}
				pass_trial++;
			}
			if(ExitFlag==0)
			{
				while(flagadmin==0)
				{
					printf("Welcome Admin! \n");
					printf("To add new patient record, Enter 1: \n");
					printf("To edit patient record, Enter 2: \n");
					printf("To reserve a slot with doctor, Enter 3: \n");
					printf("To cancel reservation, Enter 4: \n");
					printf("To print patients, Enter 5: \n");
					printf("To print reservations, Enter 6: \n");
					printf("To exit, Enter 7: \n");
					scanf("%d",&admin_input);
					switch(admin_input)
					{
						case 1:printf("Please Enter your ID:");
						scanf("%d",&patient_ID);
						temp=patient_ID;
						printf("\nPlease Enter your age:  ");
						scanf("%d",&age);
						printf("\nPlease Enter your Gender F for female, M for male:");
						scanf(" %c",&gender);
						printf("\nPlease Enter your Name:");
						scanf(" %c",&name);
						res2=CheckID(head,temp);
						if(res2==1)
						{
							printf("ID already exists! \n");
						}
						else
						{
							Add_Patient(name,age,gender,temp);
							printf("Successfuly added! \n");
						}
						//printf("added");
						break;
						case 2:
						printf("Please enter the ID:");
						scanf("%d",&patient_ID);
						res2=CheckID(head,patient_ID);
						if(res2==1)
						{
							printf("To edit the Name enter 1: \n");
							printf("To edit the Gender enter 2: \n");
							printf("To edit the Age enter 3: \n");
							printf("To edit the ID enter 4: \n");
							scanf("%d",&oldID);
							valIDTemp=oldID;
							Edit_Patient(patient_ID,valIDTemp);
						}
						else
						{
							printf("ID doesn't exist! \n");
						}
						
						break;
						case 3:
						ShowAvailableAppointment(Appointment);
						printf("Please Enter your ID: \n");
						scanf("%d",&patient_ID);
						printf("Please Enter prefered Day: \n");
						scanf("%d",&day_ID);
						printf("Please Enter prefered Slot: \n");
						scanf("%d",&slot_ID);
						res2=CheckID(head,patient_ID);
						if(res2==1)
						{
							Reserve_Slot(Appointment,patient_ID,day_ID,slot_ID);
							
						}
						else
						{
							printf("ID doesn't exist! \n");
						}
						
						break;
						case 4:
						printf("Please Enter your ID: \n");
						scanf("%d",&patient_ID);
						Cancel_Reserve(Appointment,patient_ID);
						break;
						case 5:
						Print_PatientRecords();
						break;
						case 6:
						PrintReservations(Appointment);
						break;
						case 7 : flagout=1; break;
						default:
						printf("wrong value,please try again \n");
						break;
					}
					if(flagout==1)
					{
						printf("bye admin!");
						break;
					}
				}
			}
			else
			{
				printf("Wrong password for 3 times, system will shut down! \n");
			}
			break;
			case 2:
			printf("Enter your ID: \n ");
			scanf("%d",&user_ID);
			res2=CheckID(head,user_ID);
			if(res2==1)
			{
				userflag=0;
			}
			else
			{
				printf("Doesn't exists! \n");
				userflag=1;
			}
			while(userflag==0)
			{
				printf("welcome to user mode! \n");
				printf("Enter 1 to view patient record: \n");
				printf("Enter 2 to view patient reservation: \n");
				printf("Enter 3 to Exit: \n ");
				scanf("%d",&user_input);
				
				switch(user_input)
				{
					case 1:
					Print_PatientRecordByID(user_ID);
					break;
					case 2:
					PrintSingleReservation(Appointment,user_ID);
					break;
					case 3:
					userflag=1;
					printf("Bye Bye user");
					break;
				}
				
			}
			break;
			case 3:
			printf("system says goodbye! \n");
			ExitFlag=1;
			break;
			default:
			printf("wrong input");
			break;
		}
				
		
	}
	
}

void Reserve_Slot(Days*p_Appoinment,u32 Patient_ID,u8 Day_ID,u8 Slot_ID)
{
	printf(" slot %d",p_Appoinment[Day_ID].Slot[Slot_ID]);
	printf(" patient id %d",p_Appoinment[Day_ID].ID[Slot_ID]);
	if(p_Appoinment[Day_ID].Slot[Slot_ID]==-1&&p_Appoinment[Day_ID].ID[Slot_ID]==-1)
	{
		p_Appoinment[Day_ID].Slot[Slot_ID]=1;
		p_Appoinment[Day_ID].ID[Slot_ID]=Patient_ID;
		printf(" slot %d",p_Appoinment[Day_ID].Slot[Slot_ID]);
		printf(" patient id %d",p_Appoinment[Day_ID].ID[Slot_ID]);
		printf("appointment reserved! \n");
	}
	
}
void Cancel_Reserve(Days*p_Appoinment,u32 Patient_ID)
{
	u8 f=-1;
		for(int i=0;i<7;i++)
		{
			for(int y=0;y<5;y++)
			{
				if(p_Appoinment[i].ID[y]==Patient_ID)
				{
					p_Appoinment[i].ID[y]=-1;
					p_Appoinment[i].Slot[y]=-1;
					f=1;
					break;
				}
			}
			if(f==1)
			{
				printf("Appointment got canceled! \n");
				break;
			}
		}
	if(f==-1)
	{
		printf("ID hasn't reserved any appointments! \n");
	}
}
void PrintReservations(Days*p_Appoinment)
{
	printf("/////RESERVATIONS///// \n");
	for(int i=0;i<7;i++)
	{
		for(int y=0;y<5;y++)
		{
			if(p_Appoinment[i].ID[y]!=-1)
			{
				if(i==0)
				{
					printf("Sunday");
				}
				if(i==1)
				{
					printf("Monday");
				}
				if(i==2)
				{
					printf("Tuesday");
				}
				if(i==3)
				{
					printf("Wednesday");
				}
				if(i==4)
				{
					printf("Thursday");
				}
				if(i==5)
				{
					printf("Friday");
				}
				if(i==6)
				{
					printf("Saturday");
				}
				if(y==0)
				{
					printf("From 2 -> 2:30 for patient %d \n",p_Appoinment[i].ID[y]);
				}
				if(y==1)
				{
					printf("From 2:30 -> 3 for patient %d \n",p_Appoinment[i].ID[y]);
				}
				if(y==2)
				{
					printf("From 3 -> 3:30 for patient %d \n",p_Appoinment[i].ID[y]);
				}
				if(y==3)
				{
					printf("From 3:30 -> 4 for patient %d \n",p_Appoinment[i].ID[y]);
				}
				if(y==4)
				{
					printf("From 4 -> 4:30 for patient %d \n",p_Appoinment[i].ID[y]);
				}
			}
		}			
	}
}

void ShowAvailableAppointment(Days*p_Appoinment)
{
	for(int i=0;i<7;i++)
	{
		printf("////Day//// \n");
		if(i==0)
		{
			printf("For Sunday enter 0 \n");
		}
		if(i==1)
		{
			printf("For Monday enter 1 \n");
		}
		if(i==2)
		{
			printf("For Tuesday enter 2 \n");
		}
		if(i==3)
		{
			printf("For Wednesday enter 3 \n");
		}
		if(i==4)
		{
			printf("For Thursday enter 4 \n");
		}
		if(i==5)
		{
			printf("For Friday enter 5 \n");
		}
		if(i==6)
		{
			printf("For Saturday enter 6 \n");
		}
		printf("////Available Slots//// \n");
		for(int y=0;y<5;y++)
		{
			
			if(p_Appoinment[i].Slot[y]==-1)
			{
				if(y==0)
				{
					printf("From 2 -> 2:30 enter 0 \n");
				}
				if(y==1)
				{
					printf("From 2:30 -> 3 enter 1 \n");
				}
				if(y==2)
				{
					printf("From 3 -> 3:30 enter 2 \n");
				}
				if(y==3)
				{
					printf("From 3:30 -> 4 enter 3 \n");
				}
				if(y==4)
				{
					printf("From 4 -> 4:30 enter 4 \n");
				}
			}
		}
	}
}

u8 CheckID(node ptr,u32 Patient_ID)
{
	node *Last = &head;
	u8 f=-1;
	if(Last->Patient_ID==Patient_ID)
	{
		return 1;
		f=1;
	}
	
	while ((Last -> Next) != NULL)
	{
		if(Last->Patient_ID==Patient_ID)
		{
			f=1;
			return 1;
		}
	}
	if(f==-1)
	{
		return 0;
	}
}

void PrintSingleReservation(Days*p_Appoinment,u32 Patient_ID)
{
	for(int i=0;i<7;i++)
	{
		for(int y=0;y<5;y++)
		{
			if(p_Appoinment[i].ID[y]==Patient_ID)
			{
				if(i==0)
				{
					printf("Sunday");
				}
				if(i==1)
				{
					printf("Monday");
				}
				if(i==2)
				{
					printf("Tuesday");
				}
				if(i==3)
				{
					printf("Wednesday");
				}
				if(i==4)
				{
					printf("Thursday");
				}
				if(i==5)
				{
					printf("Friday");
				}
				if(i==6)
				{
					printf("Saturday");
				}
				if(y==0)
				{
					printf("From 2 -> 2:30 for patient %d \n",p_Appoinment[i].ID[y]);
				}
				if(y==1)
				{
					printf("From 2:30 -> 3 for patient %d \n",p_Appoinment[i].ID[y]);
				}
				if(y==2)
				{
					printf("From 3 -> 3:30 for patient %d \n",p_Appoinment[i].ID[y]);
				}
				if(y==3)
				{
					printf("From 3:30 -> 4 for patient %d \n",p_Appoinment[i].ID[y]);
				}
				if(y==4)
				{
					printf("From 4 -> 4:30 for patient %d \n",p_Appoinment[i].ID[y]);
				}
				break;
			}
		}
	}
}
