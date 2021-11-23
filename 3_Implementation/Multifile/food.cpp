#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

void mainmenu(void);
void customer(void);
void osnack(void);
void cdetails(void);
void checkourmenu(void);
int main()
{
	mainmenu();
	return 0;
}
	int choice;
	int again;
	int quantity;
	double total=0;
	
void mainmenu(void)
{
	system("cls");
	printf("\t______________________________________________________\n");
	printf("\t\t\tWELCOME TO FOOD ORDERING SYSTEM\n");
	printf("\t1. CUSTOMER SECTION-->\n\t2. CHECK OUR MENU\n\t3. EXIT-->\n\n\n\tEnter your choice-->\n");
	printf("\t______________________________________________________\n");
	
	int select;
	scanf("%d",&select);
	if(select==1)
	{
		customer();
	}
	else if(select==2)
	{
		checkourmenu();
	}
	else if(select==3)
	{
		system("cls");
		printf("\n\n\n");
		printf("\t______________________________________________________\n");
		printf("\t\tTHANK YOU! VISIT US AGAIN\n");
		printf("\t\tFeeling Hungry? Time to snack!\n");
		printf("\t______________________________________________________\n");
		exit(0); 
	}
}

void customer(void)
{
	system("cls");
	printf("\t______________________________________________________\n");
	printf("\t You are about to-->\n\t1. Order Snack\n\t2. View Order\n\t3. Back to Main Menu\n\n\n\tEnter your choice-->");
	
	int c;
	scanf("%d",&c);
	
	int load;
	for(load=0;load<5000;load++)
	{
	printf("\rLoadig :%d,load/500");	
	}
	
	if(c==1)
	{
		system("cls");
		osnack();
	
	}
	else if(c==2)
	{
		FILE*vorder;
		char v;
		vorder=fopen("order.txt","r");
		while((v=fgetc(vorder))!=EOF)
		{
			printf("%c",v);
		}
		if(getch())
		customer();
		
		
	}
	else if(c==3)
	{
		system("cls");
		mainmenu();
	}
	else
	{
		printf("\tWrong input! Kindly input the correct option...\n\n");
		customer();
	}
}

void osnack(void)
{
	printf("\t______________________________________________________\n");
	printf("\t\t\tSNACK MENU\n");
	printf("\t______________________________________________________\n");
	printf("\t\tINPUT NUMBER FOR SELECTED MENUE\n\n\t#1 Fries\t50.00\n\t#2 Burger\t70.00\n\n\t#3 Back to main menu\n\tEnter your choice-->");
	
	char s;
	FILE*snkmenu;
	
	snkmenu=fopen("menu.txt","rt");
	while((s=getc(snkmenu))!=EOF)
	{
		printf("%c",s);
	}
	fclose(snkmenu);
	printf("\n\nInput Customer Order:");
	printf("\n\n");
	scanf("%d",&choice);
	if(choice==1)
	{
		printf("Quantity: ");
		scanf("%d",&quantity);
		total=total+50*(quantity);
		printf("\n");
		printf("\tpress 1 To Order Again:\n\tpress 2 To Get Your Total:\n\n\n\tENTER YOUR CHOICE-->");
		scanf("%d",&again);
		printf("\n");
		if(again==1)
		{
			printf("\n\n");
			osnack();
		}
		else if(again==2)
		printf("Your Total Amount is: %.2f\n\n",total);
		
		int totl=total;
		FILE*ttl;
		ttl=fopen("order.txt","a");
		fprintf(ttl,"\nGrand Total:%d\n",totl);
		fclose(ttl);
		
		
		cdetails();
	}
	else if(choice==2)
	{
		{
		printf("Quantity: ");
		scanf("%d",&quantity);
		total=total+70*(quantity);
		printf("\n");
		printf("\tpress 1 To Order Again:\n\tpress 2 To Get Your Total:\n\n\n\tENTER YOUR CHOICE-->");
		scanf("%d",&again);
		printf("\n");
		if(again==1)
		{
			printf("\n\n");
			osnack();
		}
		else if(again==2)
		printf("Your Total Amount is: %.2f\n\n",total);
		
		int totl=total;
		FILE*ttl;
		ttl=fopen("order.txt","a");
		fprintf(ttl,"\nGrand Total:%d\n",totl);
		fclose(ttl);
		
		cdetails();
	}
	}
	else if(choice==3)
	{
		system("cls");
		customer();
	}
	else
	{
		printf("\tWrong input! Kindly input the correct option...\n\n");
		if(getch())
		osnack();
	}
}


void cdetails(void)
{
char fname[20];
char lname[20];
long long int phone;

printf("\tInput Customer Details\n");
printf("First Name: ");
scanf("%s",&fname);
printf("Last Name: ");
scanf("%s",&lname);
printf("Phone: ");
scanf("%lld",&phone);
printf("\n\n");
printf("Your Details Entered Are-->\n");
FILE*cust;
cust=fopen("order.txt","a");
fprintf(cust,"Order by: %s %s\nphone Number: %lld\n",fname,lname,phone);
fclose(cust);
printf("-->First Name: %s\n-->Last Name: %s\n-->phone: %lld\n",fname,lname,phone);
printf("\n\n\n");
printf("\t______________________________________________________\n");
printf("\t\tYour Order Will be in 5 minutes..\n");
printf("\t\tThank You!\n");
printf("\t______________________________________________________\n");
printf("Press Any Key And Back to Main Menu\n\n\n");
if(getch())
mainmenu();
}
void checkourmenu(void)
{
	system("cls");
	printf(".....FOOD FOR YOU.....\n");
	printf("1.Samosa 10.00\n2.Maggi 12.00\n3.Chicken Curry 200.00\n4.Burger 70.00\n5.Fish Curry 180.00\n");
	printf("........Press Any Key And Back to Main Menu........");
	if(getch())
	mainmenu();
}
