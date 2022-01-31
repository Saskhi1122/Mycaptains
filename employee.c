#include<stdio.h>
#include<string.h>
#include<stdlib.>

void read_employee_details();
void show_employee_details();

struct Employee
{
	char emp_name[50];
	char age[10];
	char department_name[50];
	char emp_phone_no[20];
	char emp_salary[100];
}empdet[100];

int main()
{ char opt[1];
	printf("\nWelcome To N.K Group of Industries");
	printf("\nEnter 'Y'/'y' to Add Employee : ");
	scanf("%s",opt);
	if(strcmpi(opt,"Y")==0)
	{
		read_employee_details();
	}
	else
	printf("\nWrong Input");
	return 0;	
}

void read_employee_details()
{ int opt,i=0;
	printf("\nEnter Employee Name : ");
	scanf("%s",empdet[0].emp_name);
	printf("\nEnter Employee Age : ");
	scanf("%s",empdet[0].age);
	printf("\nEnter Employee Department Name : ");
	scanf("%s",empdet[0].department_name);
	printf("\nEnter Employee Phone Number : ");
	scanf("%s",empdet[0].emp_phone_no);
	printf("\nEnter Employee Salary : ");
	scanf("%s",empdet[0].emp_salary);
	
L1: 
	printf("\n\nEnter '1' for Enter Details Of Other Employee\nEnter '2' for Show Employee : ");
	scanf("%d",&opt);
	switch(opt)
	{case 1:
	printf("\nEnter Employee Name : ");
	scanf("%s",empdet[1].emp_name);
    printf("\nEnter Employee Age : ");
	scanf("%s",empdet[1].age);
	printf("\nEnter Employee Department Name : ");
	scanf("%s",empdet[1].department_name);
	printf("\nEnter Employee Phone Number : ");
	scanf("%s",empdet[1].emp_phone_no);
	printf("\nEnter Employee Salary : ");
	scanf("%s",empdet[1].emp_salary);
	i++;
	goto L1;
    break;
	case 2: show_employee_details();break;
	}
}

void show_employee_details()
{  int opt,i=0;
     printf("\nEnter Number Of Clients To Show : ");
     scanf("%d",&opt);

	for(i=0;i<=opt;i++)
	{
	printf("\n\nEmployee Name : %s",empdet[i].emp_name);
	printf("\n\nEmployee Age : %s",empdet[i].age);
	printf("\n\nEmployee Department Name : %s",empdet[i].department_name);
	printf("\n\nEmployee Phone Number : %s",empdet[i].emp_phone_no);
	printf("\n\nEmployee Salary : %s",empdet[i].emp_salary);
	}
	getch();
}
