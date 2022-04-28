#ifndef _PATIENT_LIST_H
#define _PATIENT_LIST_H
#include"../../StandardDataModifier.h"

typedef struct Node_type node;

struct Node_type{
    u8 Patient_Name;
	u8 Patient_Age;
	u8 Patient_Gender;
	u32 Patient_ID;
    node *Next;
};

void Add_Patient(u8 name_val,u8 age_val,u8 gender_val,u32 ID_val);
void Edit_Patient(u32 ID,u8 val_ID);

void Print_PatientRecords();
void Print_PatientRecordByID(u32 ID);

#endif