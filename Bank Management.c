//             Header Files               //  


#include <stdio.h>     //  scanf() , printf()
#include <string.h>     // strcmpi(a,b) ->  for comparing strings
#include <stdlib.h>    //  rename() and remove() Functions (FILES) 
#include <time.h>      //   time_t t=time(NULL)          
#include <conio.h>     // getch() , system("CLS")
#include <unistd.h>

//         Functions  Declaration          //


void login();
void loading();
void add_account();
void show_all_account();
void search_account();
void delete_account();
void update_account_detail();
void exit_program();

//        Define Required  Structures       //


struct account_detail
{   char s_no[10];
	char registration_id[25];
	char name[30];
	char phone[15];
	char email[100];
	char address[1000];
	char aadhar_number[15];
	char pan_number[15];
}det;



int main()
{
   int opt;
   system("CLS");
   login();
   loading();
do{ 
    system("CLS");
printf("\n\n\t\t\t*************************************************\n\t\t\t*************************************************\n\n");
printf("\t\t\t\t------------ Hello ------------\n\n\n");
printf("\t\t\t*************************************************\n\t\t\t*************************************************\n\n");
printf("\t\t\tMini Project For Banking Management\n");
 printf("\t\t\tChoose The Operation\n\n"); 
 printf("\t\t\t1. Add Account\n");
 printf("\t\t\t2. Show Account\n");
 printf("\t\t\t3. Search Account\n");
 printf("\t\t\t4. Delete Account\n");
 printf("\t\t\t5. Update Account Details\n");
 printf("\t\t\t6. Exit\n");
 scanf("\t\t\t %d",&opt);
 switch(opt)
{ case 1: system("CLS");
          add_account();break;
  case 2: system("CLS");
          show_all_account();break;
  case 3: system("CLS");
          search_account();break;
  case 4: system("CLS");
          delete_account();break;
  case 5: system("CLS");
          update_account_detail();break;
  case 6:system("CLS");  
          exit_program();break;
          }
		  }while(opt!=6);	  

return 0;
}


//           User Defined Functions               //

void login()
{

char pass[20],password[20]="bank";
      login_try:
    printf("\n\n\t\t\tEnter the password to login:\t");

    scanf("%s",pass);
    if (strcmp(pass,password)==0)
        {printf("\n\n\t\t\t\t\tPassword Match!");
        
        sleep(1);
        
        }
    else
        {   printf("\n\n\t\t\t\t\a\a\a**Wrong password!!**\a\a\a\n\n\t\t\t\t**Try Again!!*\a\a\a\t\t\a\a\a");
           
            goto login_try;
        }
}


void loading()
{ int i=0;
for(i=1;i<=10;i++)
{   sleep(1);
    system("CLS");
    printf("\n\n\n\n\t\t\t\t\tloading...........");
    
    printf("\n\n\n\n\n\t\t\t\t\t %d percent complete",10*i);
    if(i>=1 && i<=3)
   {
   printf("\n\n\n\t\t\t\t\t\t \\\// \n");
   printf("\n\n\t\t\t\t .............Hold on Buddy...........") ;
   }
   else if(i>3 && i<=7)
   {
	printf("\n\n\n\t\t\t\t\t\t || ");
   printf("\n\n\n\t\t\t\t .........Reaching To Banking Menu.......") ;
   }
   else if(i>7)
   {  
   printf("\n\n\n\t\t\t\t\t\t //\\ \n");
   printf("\n\n\n\t\t\t Just Seconds Away From The World of Money.....\n\n ") ;
   } 
}
}

void add_account()
    {
	printf("\t\t\t You Chose 1. Add Account\n\n\n");
    printf("\t\t\t Enter Information\n");
    
	FILE *sb;
	sb=fopen("Account_details.txt","ab+");
	
	if(sb==NULL)
	{
		printf("\n\t Error : Cannot open the file!!!");
		getch();
	}
	else {
	
	printf("\t\t\t S.NO :");
	scanf("%s",det.s_no);
	 
	printf("\n\t\t\t Registration ID :");
	scanf("%s",det.registration_id);
	
	 printf("\n\t\t\t Name :");
	scanf("%s",det.name);
	
	 printf("\n\t\t\t Phone :");
	scanf("%s",det.phone);
	
	 printf("\n\t\t\t E-mail :");
	scanf("%s",det.email);
	
	printf("\n\t\t\t Address :");
	scanf("%s",det.address);
	
    printf("\n\t\t\t Aadhar Number :");
    scanf("%s",det.aadhar_number);
    
    printf("\n\t\t\t PAN Number :");
    scanf("%s",det.pan_number);
	
	fwrite(&det,sizeof(det),1,sb);         //   write the input into the file   //
	
	printf("\n\n\n\t\t\t***********Account Successfully Opened************\n\n");
    getch();
	fclose(sb);
	}}
	
	
	void update_account_detail()
{   system("CLS");
    char regid[20];
	char regisid[25];
	char nam[30];
	char phon[15];
	char e_mail[100];
	char addres[1000];
	char aadharnumber[15];
	char pannumber[15];
    int flag=0;
    
	FILE *sb;
	sb=fopen("Account_details.txt","rb+");  //   Open file for reading and writing in binary mode   //
	
	if(sb==NULL)
	{
		printf("\n\t Error : Cannot open the file!!!");
		getch();
	}
	else
	{
	printf("\n\n\t\t\t Enter Registration Id Whose Information You Want To Update : ");
	scanf("%s",regid);
		
	while(fread(&det,sizeof(det),1,sb)==1)
	{
	    if(strcmpi(regid,det.registration_id)==0)
			{    system("CLS");
				flag=1;
				
	printf("=================================================================\n\n");
	printf("\ns_no : %s \n\n",det.s_no);
	printf("client_id : %s\n\n",det.registration_id);
	printf("name : %s \n\n",det.name);
    printf("phone : %s \n\n",det.phone);
	printf("E-mail : %s \n\n",det.email);
	printf("Address : %s \n\n",det.address);
	printf("Aadhar_number : %s \n\n",det.aadhar_number);
	printf("Pan_number : %s \n\n",det.pan_number);
	printf("=================================================================\n\n\n");
	
	printf("\n\t\t\t Enter 'R' for retain that detail");      
	printf("\n\n\t\t\t Now Enter The New Info \n\n");
	    fflush(stdin);                      // Flush The Buffer        //
	    
		printf("\n\t\t\t Updated Registration Id :");
	    gets(regid);
	    
	    if(strcmpi(regisid,"R")!=0)
	    {
	      strcpy(det.registration_id,regid);	
		}
       
        printf("\n\t\t\t Updated Name :");
        gets(nam);
        
        if(strcmpi(nam,"R")!=0)
        
        { 
         strcpy(det.name,nam);
		}
       
	    printf("\n\t\t\t Updated Phone :");
        gets(phon);
       
       if(strcmpi(phon,"R")!=0)
       {
       	strcpy(det.phone,phon);
	   }
	   
	    printf("\n\t\t\t Updated E-mail :");
        gets(e_mail);
        
        if(strcmpi(e_mail,"R")!=0)
       {
       	strcpy(det.email,e_mail);
	   }
		
		printf("\n\t\t\t Updated Client Address :");
        gets(addres);
        
		
		if(strcmpi(addres,"R")!=0)
       {
       	strcpy(det.address,addres);
	   }
	   
		printf("\n\t\t\t Updated Client Aadhar Number :");
        gets(aadharnumber);
        
        if(strcmpi(aadharnumber,"R")!=0)
       {
         strcpy(det.aadhar_number,aadharnumber);
	   }
		
		printf("\n\t\t\t Updated Client PAN Number :");
        gets(pannumber);
       
       if(strcmpi(pannumber,"R")!=0)
       {
       	strcpy(det.pan_number,pannumber);
	   }
       
       	system("CLS");
	    printf("\t\t\t***********Account Successfully Updated************\n\n");
	    getch();
       }
	}
	
	   fseek(sb,-(long)sizeof(det),1);     //            Moves The File Pointer              // 
       
       fwrite(&det,sizeof(det),1,sb);       //       To Write the New data in the file        // 
       
    if(flag==0)
	{
	  	printf("\n\t Error : Cannot Update the file!!!");	
	 	
	}
	fclose(sb);
	}}
	
	void show_all_account()

{   printf("\t\t\t You Chose 2. Show Account\n\n\n");

	FILE *sb;
	sb=fopen("Account_details.txt","rb");
	
	if(sb==NULL)
	{
	 printf("\n\t\t\t Error : Cannot open the file!!!");
	 getch();
	}
	else {
	
	printf("\t\t\t##########################################################\n\n");
	printf("\t\t\t******************* Account Detais Are *******************\n\n");
	printf("\t\t\t##########################################################\n\n\n\n\n\n\n\n");
	
	while(fread(&det,sizeof(det),1,sb)==1)
	{
	printf("=================================================================\n\n");
	printf("\ns_no : %s \n\n",det.s_no);
	printf("client_id : %s\n\n",det.registration_id);
	printf("name : %s \n\n",det.name);
    printf("phone : %s \n\n",det.phone);
	printf("E-mail : %s \n\n",det.email);
	printf("Address : %s \n\n",det.address);
	printf("Aadhar_number : %s \n\n",det.aadhar_number);
	printf("Pan_number : %s \n\n",det.pan_number);
	printf("=================================================================\n");
	getch();
    }
    {
	printf("\n\n\n\t\t################################ END OF FILE ###############################\n\n");
    }
	getch();
    fclose(sb);
    }
	}
	
	
	void search_account()
	{ 
	  char regid[15];
	  int flag=0;
	   FILE *sb;
	   sb=fopen("Account_details.txt","rb");
	   
	   	if(sb==NULL)
	{
		printf("\n\t\t\t Error : Cannot open the File!!!");
		getch();
	}
		printf("\t\t\t# Enter Client ID : ");
		scanf("%s",regid);
	   
	   while(fread(&det,sizeof(det),1,sb)==1 && flag==0)
	   {
	   	if(strcmpi(regid,det.registration_id)==0)
	   	{flag=1;
	   	 printf("\n\n\n*************** Search Successful Account Found ***************\n\n");
	   	 printf("s_no : %s \n",det.s_no);
	     printf("client_id : %s\n",det.registration_id);
	     printf("name : %s \n",det.name);
         printf("phone : %s \n",det.phone);
	     printf("E-mail : %s \n",det.email);
	     printf("Address : %s \n",det.address);
	     printf("Aadhar_number : %s \n",det.aadhar_number);
	     printf("Pan_number : %s \n",det.pan_number);
	     getch();system("CLS");
	   	}}
	   	if(flag==0) 
	   	{ 
	   		printf("\n\n\t\t\t*************** OOPS!!!! Account Not Found. :/ ***************");
	   		getch();
	   	}
	   	fclose(sb);	
		}

void delete_account()
   {
     char regid[20];
     int flag=0;
   
     FILE *sb,*eb;
	
	sb=fopen("Account_details.txt","rb");
	
	eb=fopen("temp.txt","ab+");
	
	if(sb==NULL || eb==NULL)
	{
		printf("\n\t\t\t Error : Cannot open the Details!!!");
		getch();
	}
	else 
	{
	
	printf("\n\n\t\t\t Enter Registration Id Which You Want To Delete \n");
	printf("\t\t\t Registration Id :");
	scanf("%s",regid);
	
	while(fread(&det,sizeof(det),1,sb)==1)
	   {
		if(strcmpi(regid,det.registration_id)!=0)
		{
		 fwrite(&det,sizeof(det),1,eb);
	    
		}
		else 
		flag=1;
	   }
		fclose(sb);
		fclose(eb);
	    if(flag==0)
	    {
	    printf("\n\n\t\t\t*************** OOPS!!!! Account Not Found. :/ ***************");
	    remove("temp.txt");
		}
		else
			{
			remove("Account_details.txt");
			rename("temp.txt","Account_details.txt");
			printf("\n\t\t\t Account Deleted Sucessfully \n");
	        }
			system("CLS");
			printf("\t\t################### Done =' ###################");
		    getch();
	}}


void exit_program()
{ 
	system("CLS");
	printf("\t\t\t-------------------!!!---------------------\n");
    printf("\t\t\t-----Thank you for using Our Banking Service!!!-----\n");
    printf("\t\t\t-------BROUGHT TO YOU BY DESI BANK-------\n");
    getch();
}



