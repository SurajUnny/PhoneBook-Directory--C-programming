#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define ENTER 13
#define TAB 9
#define BCKSPC 8
int n=0;
struct node
{
 char name[100];
 char phoneno[100];
 char email[100];
 struct node *next;
};

typedef struct node contact;

contact *head = NULL;

int create(char name[],char no[],char mail[])
{
 if(head == NULL) 
 {
 head = (contact *)malloc(sizeof(contact)); 
 strcpy(head->name,name);
 strcpy(head->phoneno,no);
 strcpy(head->email,mail);  
 head->next = NULL; 
 }
 else 
 {
 contact *t = head;
 while(t->next != NULL)
 {
 t = t->next;
 }
 t->next = (contact *)malloc(sizeof(contact)); 
 strcpy(t->next->name,name);
 strcpy(t->next->phoneno,no);
 strcpy(t->next->email,mail); 
 t->next->next = NULL; 
 }
 n++;
 printf("\nContact succsessfully created\n");
 return n;
}

void search1(char no[])
{
	contact *t;
	t=head;
	int f=0;
	while(t!=NULL)
	{
		if(strcmp(t->phoneno,no)==0)
		{
		    printf("\nName:%s",t->name);
 	        printf("\nPhoneno:%s",t->phoneno);
 	        printf("\nPhoneno:%s\n",t->email);
 	        f=1;
 	        break;
		}
		t=t->next;
	}
	if(f==0)
	{
		printf("\nNo results found\n");
	}
}

void search2(char name[])
{
	contact *t;
	t=head;
	int f=0;
	while(t!=NULL)
	{
		if(strcmp(t->name,name)==0)
		{
		    printf("\nName:%s",t->name);
 	        printf("\nPhoneno:%s",t->phoneno);
 	        printf("\nPhoneno:%s\n",t->email);
 	        f=1;
 	        break;
		}
		t=t->next;
	}
	if(f==0)
	{
		printf("\nNo results found\n");
	}
}

int delete2(char name[])
{
 contact *t;
 int f = 0;
 if(head == NULL) 
 {
 printf("\nEmpty contact list\n");
 }
 else if(strcmp(head->name,name)==0) 
 {
 printf("\n%s is successfully deleted\n",head->name);
 head = head->next;
 n--;
 }
 else 
 {
 t = head;
 while(t->next != NULL)
 {
 if(strcmp(t->next->name,name)==0)
 {
 printf("\n%s is successfully deleted\n",t->next->name);
 t->next = t->next->next; 
 f = 1;
 break;
 }
 t= t->next;
 n--;
 }
 if(f == 0) 
 {
 printf("\nNot Results Found\n");
 }
 }
 return n;
}

int delete1(char no[])
{
 contact *t;
 int f = 0;
 if(head == NULL) 
 {
 printf("Empty contact list");
 }
 else if(strcmp(head->phoneno,no)==0) 
 {
 printf("\n%s is successfully deleted\n",head->name);
 head = head->next;
 n--;
 }
 else 
 {
 t = head;
 while(t->next != NULL)
 {
 if(strcmp(t->next->phoneno,no)==0)
 {
 printf("\n%s is successfully deleted\n",t->next->name);
 t->next = t->next->next; 
 f = 1;
 break;
 }
 t= t->next;
 n--;
 }
 if(f == 0) 
 {
 printf("\nNo Results Found\n");
 }
 }
 return n;
}

void disp()
{
 int count=0;
 contact *curr,*pre;
 pre=head;
 char a[100];
 char b[100];
 char c[100];
 while(pre!=NULL)
 {
 	curr=pre->next;
 	while(curr!=NULL)
 	{	
 		if(strcmp(pre->name,curr->name)==1)
 		{
 			strcpy(a,pre->name);
 			strcpy(pre->name,curr->name);
 			strcpy(curr->name,a);
 			strcpy(b,pre->phoneno);
 			strcpy(pre->phoneno,curr->phoneno);
 			strcpy(curr->phoneno,b);
 			strcpy(c,pre->email);
 			strcpy(pre->email,curr->email);
 			strcpy(curr->email,c);
		 }
		 curr=curr->next;
	 }
	 pre=pre->next;
 }
 contact *t = head;
 if(t == NULL)
 {
 printf("List is Empty\n");
 return;
 }
 contact *p = head;
  while (p != NULL)
 {
 count++;
 p = p->next;
 }
 printf("\nSearch among %d contacts\n",count);
 while (t != NULL)
 {
 printf("\nName:%s",t->name);
 printf("\nPhoneno:%s",t->phoneno);
 printf("\nemail:%s",t->email);
 t = t->next;
 printf("\n");
 }
}

void edit(char no[])
{
 contact *t;
 int f = 0;
 if(head == NULL) 
 {
 printf("Empty contact list");
 }
 else 
 {
 	char nam[100];
	char num[100];
	char email[100];
 t = head;
 while(t != NULL)
 {
 if(strcmp(t->phoneno,no)==0)
 {
 	fflush(stdin);
	printf("\nEnter new name: ");
	gets(nam);
	fflush(stdin);
	printf("Enter new no: ");
	gets(num);
	fflush(stdin);
	printf("Enter new email: ");
	gets(email);
    strcpy(t->name,nam);
    strcpy(t->phoneno,num);
    strcpy(t->email,email); 		
    printf("\nsuccessfully edited\n");
    f = 1;
    break;
 }
 t= t->next;
 }
 if(f == 0) 
 {
 printf("\nNo Results Found\n");
 }
 }
}
int main()
{
	int ch;
	char name[100];
	char no[100];
	char mail[100];
	char pass[20]="1234";
   	int i;
    char ch1, pwd[20];
   	printf("Enter your password:");
   	while(1){
        ch1 = getch();
        if(ch1 == ENTER || ch1 == TAB){
            pwd[i] = '\0';
            break;
        }
        else if(ch1 == BCKSPC){
        	if(i>0){
                i--;
                printf("\b \b");
            }
        }
        else
        {
            pwd[i++] = ch1;
            printf("* \b");
        }
    }
    printf("\n");
	if(strcmp(pass,pwd)!=0){
		printf("\nInvalid password\n");
		}
	else{
	do
	{
		printf("\n1.Create new contact +\n2.Search contact by phoneno\n3.Search contact by name\n4.Delete contact by phoneno\n5.Delete contact by name\n6.edit\n7.Contacts\n8.Exit\n\nEnter ur choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
		case 1:
			if(n==3){
				printf("\nMemory is full.Delete some contacts\n");
     				}
        	else{
		    	fflush(stdin);
	   		    printf("\nEnter name: ");
				gets(name);
				fflush(stdin);
				printf("Enter no: ");
				gets(no);
				fflush(stdin);
				printf("Enter email: ");
				gets(mail);
				n=create(name,no,mail);
				}
			break;
		case 2:
			fflush(stdin);
			printf("Enter the no to be searched : ");
			gets(no);			
		    search1(no);
	    	break;
		case 3:
			fflush(stdin);
			printf("Enter the name to be searched : ");
			gets(name);			
		    search2(name);
			break;
		case 4:
			fflush(stdin);
			printf("Enter no to be deleted: ");
			gets(no);
			n=delete1(no);
			break;
		case 5:
			fflush(stdin);
			printf("Enter name to be deleted: ");
			gets(name);
			n=delete2(name);
			break;
		case 6:
			fflush(stdin);
			printf("Enter no of contact to be edited: ");
			gets(no);
			edit(no);
			break;
		case 7:
			disp();
			break;
		case 8:
			break;
		default :
			printf("\nWrong choice..\n");
		}
	}while(ch!=8);
}
	return 0;
}
