#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<stdlib.h>
#define MAX 2




static int id=1100;
const char password[]="password";

struct movies{
	char name[30];
	char release_date[10];
	char screen_date[10];
	char timing[10];
	int  front,mid,back,balcony;
}ma[MAX],mc[MAX],mn[MAX];



void Select_Cinema();

void Book_Ticket_Cineplex();

void Book_Ticket_Nueplex();

void Book_Ticket_Atrium();

void add_movie_cine();

void view_movie_cine();

void add_movie_atr();

void view_movie_atr();

void add_movie_nupl();

void view_movie_nupl();

void Select_Cinema_admin();





main(){
	
int f;
system("cls");
system("color 0C");
here:
        printf("\n||~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~||");

        printf("\n||                                                                       ||");

        printf("\n||                        Movie Ticket Booking System                    ||");

        printf("\n||                                                                       ||");

        printf("\n||~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~||");
   
        printf("\n||                          Press 1 for admin                            ||");
        
		printf("\n||-----------------------------------------------------------------------||");
        
		printf("\n||                        Press 2 for customer                           ||");
        
		printf("\n||~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~||");
        
		printf("\nENTER YOUR CHOICE: ");
        scanf("%d",&f);
      
	    if(f==1)
        Select_Cinema_admin();
      
	    else if(f==2)
        Select_Cinema();
       
	    else
        printf("Wrong selection");
        goto here;



}



void Select_Cinema_admin()
{
system("color F4");
int cin, c, ch, count=1;
char pass[10],ans;

printf("Enter password: ");
login:
scanf ("%s",&pass);

if (count==3)
	{	
		printf("TOO MANY TRIES... TRY AGAIN LATER\n");
		exit(1);
	}

if (strcmp(pass,password)==0)
{

 	printf("\n||=======================================================================||");

    printf("\n||                         Press [1] for Cinepax                         ||");

	printf("\n||-----------------------------------------------------------------------||");

    printf("\n||                         Press [2] for  Nueplex                        ||");

	printf("\n||-----------------------------------------------------------------------||");

    printf("\n||                         Press [3] for  Atrium                         ||");

    printf("\n||=======================================================================||\n\n");


printf("Enter Your choice: ");
select:
scanf("%d",&cin);
	if(cin==1)
	{
	system("cls");
	system("color 0C");

	printf("\n||=======================================================================||");

    printf("\n||                          CINEPAX  CINEMA                              ||");

    printf("\n||=======================================================================||\n\n");




 add_movie_cine(c); 


}








else if(cin==2)
{
system("cls");
system("color 0E");


printf("\n||=======================================================================||");

    printf("\n||                           NUEPLEX CINEMA                              ||");

    printf("\n||=======================================================================||\n\n");

 add_movie_nupl();
}




else if(cin==3)
{
system("cls");
system("color 0A");

printf("\n||=======================================================================||");

    printf("\n||                         ATRIUM CINEMA                                 ||");

    printf("\n||=======================================================================||\n\n");




 add_movie_atr(); }

}
	else 
	{
		printf("Wrong password...try again\n");
		count++;
		goto login;
	}
}



void Select_Cinema()
{
	int cin ,ch; 
	
    printf("\n||-----------------------------------------------------------------------||");                                                                

    printf("\n||                         Press [1] for Cinepax                         ||");

	printf("\n||-----------------------------------------------------------------------||");

    printf("\n||                         Press [2] for  Nueplex                        ||");

	printf("\n||-----------------------------------------------------------------------||");

    printf("\n||                         Press [3] for  Atrium                         ||");

    printf("\n||-----------------------------------------------------------------------||\n\n");
	
	
	printf("Enter Your choice: ");
select:
	scanf("%d",&cin);
	if(cin==1)
	{
	system("cls");
	system("color 0C");

	printf("\n||=======================================================================||");

    printf("\n||                          CINEPAX  CINEMA                              ||");

    printf("\n||=======================================================================||\n\n");
	
	printf("Press [1] to Book tickets.\n");
	printf("press [2] to View movie\n");
	printf("Enter Your Choice: ");

	scanf("%d",&ch);
	
	switch(ch)
	{
	case 1: Book_Ticket_Cineplex(); break;
	
	case 2: view_movie_cine(); break;
	
	default: printf("Invalid choice...\n"); 

	}
	}




	else if(cin==2)
	{
	system("cls");
	system("color 0E");
	
	
	printf("\n||=======================================================================||");

    printf("\n||                           NUEPLEX CINEMA                              ||");

    printf("\n||=======================================================================||\n\n");
	
	printf("Press [1] to Book tickets.\n");
	printf("press [2] to View movie\n");
	printf("Enter Your Choice: ");
	scanf("%d",&ch);
	
	switch(ch)
	{
    case 1: Book_Ticket_Nueplex(); break;
	case 2: view_movie_nupl(); break;
	
	default: 	printf("Invalid choice...\n"); 
			    
				

	}
	}
	
	
	
	
	else if(cin==3)
	{
	system("cls");
	system("color 0A");
	
	printf("\n||=======================================================================||");

    printf("\n||                         ATRIUM CINEMA                                 ||");

    printf("\n||=======================================================================||\n\n");
	
	printf("Press [1] to Book tickets.\n");
	printf("press [2] to View movie\n");
	printf("Enter Your Choice: ");
	scanf("%d",&ch);
	
	switch(ch)
	{
    case 1: Book_Ticket_Atrium(); break;
	case 2: view_movie_atr(); break;
	
	default: printf("Invalid choice...\n"); 
			
	}
	
	
	}
	
	else
	{
	printf("Invalid Selection...\n");
	goto select;
	}

}




void Book_Ticket_Nueplex(){
 
 
 struct movies mn[2];

	int i,k;
	int n1[2],n2[2],n3[2],n4[2];
	char name[30],ch;
	long int mob_no;

	
	FILE *fptr,*ufp;
	fptr=fopen("add_movie_nupl.txt","r");

	if (fptr==NULL)

	{
		printf("File not found...\n");
		exit(1);
	}
	
	else if(ch=fgetc(fptr)==EOF)

    {

        printf("\nNo Movie is available to book right now! Check after few days!!!");

        main();

    }

	else 

	{
	
		fptr=fopen("add_movie_nupl.txt","r");
		
		printf("\n\n\t\t||============FOLLLOWING MOVIE IS ON SCREEN==========||\n\n");
		
		printf("Code:\n");
		
		for(i=0;i<2;i++)
		{
		
        fscanf(fptr,"%[^\n]  %s  %s  %s  %d  %d  %d  %d\n%d %d %d %d\n",&mn[i].name,mn[i].release_date,mn[i].screen_date,mn[i].timing, &mn[i].front,&mn[i].mid,&mn[i].back,&mn[i].balcony,&n1[i],&n2[i],&n3[i],&n4[i]);
	
	
		printf("%d\t\t\tMovie Name: %s\n",i+1,mn[i].name);

        printf("\t\t\tScreening on: %s\n",mn[i].screen_date);
        
        printf("\t\t\tTiming: %s\n",mn[i].timing);

		printf("\n\t\t||====================================================||\n\n");

	Sleep(700);
	
	}
	
	 
	 if(n1[i]==0&&n2[i]==0&&n3[i]==0&&n4[i]==0)
    {
	
        printf("\nThe seats are full! Visit after few days...\n\n");

        main();

    }
	
	}
	
	fclose(fptr);
	
	

	rewind(fptr);
	
	printf("Enter Code of the movie you want to see: ");
	scanf("%d",&k);
	k-=1;

		
		printf("Enter Your Name: ");
		fflush(stdin);	
	
/*label*/	enter_name: 
	
		gets(name);
		
			for(i=0;i<strlen(name);i++)
			{
				if(name[0]==' ')
				{
					printf("Invalid Name...\nPlease re-enter your name: ");
					goto enter_name;
				}
				
				
				else if((name[i]>='a' && name[i]<='z') || (name[i]>='A' && name[i]<='Z') || name[i]==' ' )
				{
					continue;	
				}

				else 
				{
					printf("Invalid Name...\nPlease re-enter your name: ");
					goto enter_name;
				}
				
			}
			
			
			
			printf("Enter Mobile Number (format: 03*********): ");
			
			number:
			scanf("%ld",&mob_no);
			
	
		/*	if(mob_no<00000000000 && mob_no>9999999999){
			printf("Invalid Mobile Number...\nPlease Re-enter number: ");
			goto number;}
			
			
			if(mob_no<920000000000 || mob_no>929999999999) 
			{
			printf("Invalid Mobile Number...\nPlease Re-enter number: ");
			goto number;
			}
		*/
		
		int order,seat,amount,ticket_price;
		char ch1;
			
	
		
		printf("\n\t============SEATING PRICES (per seat)==================\n\n");
		printf("\t1.Front seats (Row 1 to 5)  : Rs. %d <%d seats available>\n",mn[k].front,n1[k]);
		printf("\t2.Mid seats (Row 6 to 10)   : Rs. %d <%d seats available>\n",mn[k].mid,n2[k]);
		printf("\t3.Back seats (Row 11 to 15) : Rs. %d <%d seats available>\n",mn[k].back,n3[k]);
		printf("\t4.Balcony seats             : Rs. %d <%d seats available>\n",mn[k].balcony,n4[k]);
		printf("\n\t=======================================================\n\n");
            
            
    
		seat_order:
		printf("Which seating order would you like? (1,2,3 or 4): ");
		scanf("%d",&order);
		
		if (order==1)
		
			ticket_price=mn[k].front;
		
		else if(order==2)
			
			ticket_price=mn[k].mid;
			
		else if(order==3)
			
			ticket_price=mn[k].back;
	
		else if(order==4)
			
			ticket_price=mn[k].balcony;
		
		else
		{
			("Wrong Input...\n");
			goto seat_order;
		}
		
		
		
		seats:
		printf("How many seats you want to book: ");
		scanf("%d",&seat);
		
		if (seat==0)
		{
			printf("Seats cant be 0...\n");
			goto seats;
		}
		else if(order==1)
		{
			if(n1[k]==0)
			{
					printf("All seats are booked...Do you want to choose another seating order?(y/n): ");
				fflush(stdin);
					scanf("%c",&ch1);
				
					if(ch1=='y') 
						goto seat_order;
					
					else
					{
						printf("We're Sorry for the inconvenience.\nReturning to main menu...\n");
						Sleep(2000); main(); 
					}
			}
			else if(seat>n1[k])
			{
					printf("Not enough seats...Do you want to choose another seating order?(y/n): ");
				fflush(stdin);
					scanf("%c",&ch1);
				
					if(ch1=='y') 
						goto seat_order ;
					
					else
					{
						printf("We're Sorry for the inconvenience.\nReturning to main menu...\n");
						Sleep(2000); main(); 
					}
				
			}
			else 
			{
				n1[k]-=seat;
				goto booking;
			}
		}




		else if(order==2)
		{
			if(n2[k]==0)
			{
					printf("All seats are booked... Do you want to choose another seating order?(y/n): ");
				fflush(stdin);	
					scanf("%c",&ch1);
				
					if(ch1=='y') 
						goto seat_order;
					
					else
					{
						printf("We're Sorry for the inconvenience.\nReturning to main menu...\n");
						Sleep(2000); main(); 
					}
			}
			else if(seat>n2[k])
			{
					printf("Not enough seats... Do you want to choose another seating order?(y/n): ");
				fflush(stdin);	
					scanf("%c",&ch1);
				
					if(ch1=='y') 
						goto seat_order ;
					
					else
					{
						printf("We're Sorry for the inconvenience.\nReturning to main menu...\n");
						Sleep(2000); main(); 
					}
				
			}
			else 
			{
				n2[k]-=seat;
				goto booking;
			}
		}
				
		
		else if(order==3)
		{
			if(n3[k]==0)
			{
					printf("All seats are booked... Do you want to choose another seating order?(y/n): ");
				fflush(stdin);	
					scanf("%c",&ch1);
				
					if(ch1=='y') 
						goto seat_order;
					
					else
					{
						printf("We're Sorry for the inconvenience.\nReturning to main menu...\n");
						Sleep(2000); main(); 
					}
			}
			else if(seat>n3[k])
			{
					printf("Not enough seats... Do you want to choose another seating order?(y/n): ");
					scanf("%c",&ch1);
				
					if(ch1=='y') 
						goto seat_order ;
					
					else
					{
						printf("Returning to main menu...");
						Sleep(2000); main(); 
					}
				
			}
			else 
			{
				n3[k]-=seat;
				goto booking;
			}
		}
		
		
		
		
		else if(order==4)
		{
			if(n4[k]==0)
			{
					printf("All seats are booked... Do you want to choose another seating order?(y/n): ");
					scanf("%c",&ch1);
				
					if(ch1=='y') 
						goto seat_order;
					
					else
					{
						printf("Returning to main menu...\n");
						Sleep(2000); main(); 
					}
			}
			else if(seat>n4[k])
			{
					printf("Not enough seats... Do you want to choose another seating order?(y/n): ");
					scanf("%c",&ch1);
				
					if(ch1=='y') 
						goto seat_order ;
					
					else
					{
						printf("Returning to main menu...");
						Sleep(2000); main(); 
					}
				
			}
			else 
			{
				n4[k]-=seat;
				goto booking;
			}
		}
			
		
		booking:
		
	    amount=ticket_price*seat;
		
		printf("\n\tTickets Booked Successsfully...\n\nPlease Wait");
		Sleep(800);
		printf(".");
		Sleep(800);
		printf(".");
		Sleep(800);
		printf(".");		
	 	
	 	
	system("cls");
	
		printf("\n\t\t||======== Bill ========||\n\n");
		printf("\t\t Booking no.    %d\n",id);
		printf("\t\t Movie Name:    %s\n",mn[k].name);
		printf("\t\t Timing:        %s\n", mn[k].timing);
		printf("\t\t Screen Date:   %s\n\n",mn[k].screen_date);
		printf("\t\t Name:          %s\n",name);
		printf("\t\t Mobile Number: 0%ld\n",mob_no);
		printf("\t\t Total Seats:   %d\n",seat);
		printf("\t\t Amount:        Rs. %d\n",amount);
		if(order==1)
		
			printf("\t\t Front Seats::  Row 1 to 5\n");
		
		else if(order==2)
		
			printf("\t\t Mid Seats::    Row 6 to 10\n");
		
		else if(order==3)
		
			printf("\t\t Back Seats::   Row 11 to 15\n");
		
		else if(order==4)
		
			printf("\t\t Balcony Seats\n");
		
		
		
		
		
		printf("\n***ENJOY YOUR MOVIE***\n");
		printf("Show this Bill to cinema counter to get your tickets.\nThank you, visit again sometime...\n\n");
		
		id++;
		
		ufp=fopen("add_movie_nupl.txt","w");

		for(i=0;i<2;i++)

       	fprintf(fptr,"%s\n%s  %s  %s  %d  %d  %d  %d\n%d %d %d %d",mn[i].name,mn[i].release_date,mn[i].screen_date,mn[i].timing,mn[i].front,mn[i].mid,mn[i].back,mn[i].balcony,n1[i],n2[i],n3[i],n4[i]);

            fclose(fptr);
            
        fclose(ufp);
		
		
		
		
		printf("Press Enter to Return to Main Menu.\n");
		while(getch()!=13)
		printf(" ");
		
		printf("\nRETURNING TO  MAIN MENU");
		Sleep(800);
		printf(".");
		Sleep(800);
		printf(".");
		Sleep(800);
		printf(".");		

		main();
		
		
		
		
		
			
	}



void Book_Ticket_Cineplex()
{
	
 
 struct movies mc[2];

	int i,k; int c1[2],c2[2],c3[2],c4[2];
	char name[30],ch;
	long int mob_no;
	
	FILE *ptr, *ufp;
	ptr=fopen("add_movie_cine.txt","r");

	if (ptr==NULL)

	{
		printf("File not found...\n");
		exit(1);
	}
	
	else if(ch=fgetc(ptr)==EOF)

    {

        printf("\nNo Movie is available to book right now! Check after few days!!!");

        main();

    }

	else 

	{
	
		ptr=fopen("add_movie_cine.txt","r");
		
		printf("\n\n\t\t||============FOLLLOWING MOVIE IS ON SCREEN==========||\n\n");
		
		printf("Code:\n");
		
		for(i=0;i<2;i++)
		
		{
		
        fscanf(ptr,"%[^\n]%s  %s  %s  %d  %d  %d  %d\n%d %d %d %d\n",mc[i].name,mc[i].release_date,mc[i].screen_date,mc[i].timing, &mc[i].front,&mc[i].mid,&mc[i].back,&mc[i].balcony,&c1[i],&c2[i],&c3[i],&c4[i]);
	
	
		printf("%d\t\t\tMovie Name: %s\n",i+1,mc[i].name);

        printf("\t\t\tScreening on: %s\n",mc[i].screen_date);
        
        printf("\t\t\tTiming: %s\n",mc[i].timing);

		printf("\n\t\t||====================================================||\n\n");

	Sleep(700);
	
	
	
	 if(c1[i]==0&&c2[i]==0&&c3[i]==0&&c4[i]==0)

    {

        printf("\nThe seats are full! Visit after few days...\n\n");

        main();

    }
	
	
		}

 }
	fclose(ptr);
	
	

	rewind(ptr);
	
	
			printf("Enter Code of the movie you want to see: ");
			scanf("%d",&k);
			k-=1;
		
		
		printf("Enter Your Name: ");
		fflush(stdin);	
	
/*label*/	enter_name: 
	
		gets(name);
		
			for(i=0;i<strlen(name);i++)
		{
		
		for(i=0;i<strlen(name);i++)
			{
				if(name[0]==' ')
				{
					printf("Invalid Name...\nPlease re-enter your name: ");
					goto enter_name;
				}
				
				
				else if((name[i]>='a' && name[i]<='z') || (name[i]>='A' && name[i]<='Z') || name[i]==' ' )
				{
					continue;	
				}

				else 
				{
					printf("Invalid Name...\nPlease re-enter your name: ");
					goto enter_name;
				}
				
			}
			
			
			
			printf("Enter Mobile Number (format: 03*********): ");
			
			number:
			scanf("%ld",&mob_no);
			
	
		/*	if(mob_no<00000000000 && mob_no>9999999999){
			printf("Invalid Mobile Number...\nPlease Re-enter number: ");
			goto number;}
			
			
			if(mob_no<920000000000 || mob_no>929999999999) 
			{
			printf("Invalid Mobile Number...\nPlease Re-enter number: ");
			goto number;
			}
		*/
		
		int order,seat,amount,ticket_price;
		char ch1;
			
	
		
		printf("\n\t============SEATING PRICES (per seat)==================\n\n");
		printf("\t1.Front seats (Row 1 to 5)  : Rs. %d <%d seats available>\n",mc[k].front,c1[k]);
		printf("\t2.Mid seats (Row 6 to 10)   : Rs. %d <%d seats available>\n",mc[k].mid,c2[k]);
		printf("\t3.Back seats (Row 11 to 15) : Rs. %d <%d seats available>\n",mc[k].back,c3[k]);
		printf("\t4.Balcony seats             : Rs. %d <%d seats available>\n",mc[k].balcony,c4[k]);
		printf("\n\t=======================================================\n\n");
            
            
    
		seat_order:
		printf("Which seating order would you like? (1,2,3 or 4): ");
		scanf("%d",&order);
		
		if (order==1)
		
			ticket_price=mc[k].front;
		
		else if(order==2)
			
			ticket_price=mc[k].mid;
			
		else if(order==3)
			
			ticket_price=mc[k].back;
	
		else if(order==4)
			
			ticket_price=mc[k].balcony;
		
		else
		{
			("Wrong Input...\n");
			goto seat_order;
		}
		
	
		
		seats:
		printf("How many seats you want to book: ");
		scanf("%d",&seat);
		
		if (seat==0)
		{
			printf("Seats cant be 0...\n");
			goto seats;
		}
		else if(order==1)
		{
			if(c1[k]==0)
			{
					printf("All seats are booked...Do you want to choose another seating order?(y/n): ");
				fflush(stdin);
					scanf("%c",&ch1);
				
					if(ch1=='y') 
						goto seat_order;
					
					else
					{
						printf("We're Sorry for the inconvenience.\nReturning to main menu...\n");
						Sleep(2000); main(); 
					}
			}
			else if(seat>c1[k])
			{
					printf("Not enough seats...Do you want to choose another seating order?(y/n): ");
				fflush(stdin);
					scanf("%c",&ch1);
				
					if(ch1=='y') 
						goto seat_order ;
					
					else
					{
						printf("We're Sorry for the inconvenience.\nReturning to main menu...\n");
						Sleep(2000); main(); 
					}
				
			}
			else 
			{
				c1[k]-=seat;
				goto booking;
			}
		}




		else if(order==2)
		{
			if(c2[k]==0)
			{
					printf("All seats are booked... Do you want to choose another seating order?(y/n): ");
				fflush(stdin);	
					scanf("%c",&ch1);
				
					if(ch1=='y') 
						goto seat_order;
					
					else
					{
						printf("We're Sorry for the inconvenience.\nReturning to main menu...\n");
						Sleep(2000); main(); 
					}
			}
			else if(seat>c2[k])
			{
					printf("Not enough seats... Do you want to choose another seating order?(y/n): ");
				fflush(stdin);	
					scanf("%c",&ch1);
				
					if(ch1=='y') 
						goto seat_order ;
					
					else
					{
						printf("We're Sorry for the inconvenience.\nReturning to main menu...\n");
						Sleep(2000); main(); 
					}
				
			}
			else 
			{
				c2[k]-=seat;
				goto booking;
			}
		}
				
		
		else if(order==3)
		{
			if(c3[k]==0)
			{
					printf("All seats are booked... Do you want to choose another seating order?(y/n): ");
				fflush(stdin);	
					scanf("%c",&ch1);
				
					if(ch1=='y') 
						goto seat_order;
					
					else
					{
						printf("We're Sorry for the inconvenience.\nReturning to main menu...\n");
						Sleep(2000); main(); 
					}
			}
			else if(seat>c3[k])
			{
					printf("Not enough seats... Do you want to choose another seating order?(y/n): ");
					scanf("%c",&ch1);
				
					if(ch1=='y') 
						goto seat_order ;
					
					else
					{
						printf("Returning to main menu...");
						Sleep(2000); main(); 
					}
				
			}
			else 
			{
				c3[k]-=seat;
				goto booking;
			}
		}
		
		
		
		
		else if(order==4)
		{
			if(c4[k]==0)
			{
					printf("All seats are booked... Do you want to choose another seating order?(y/n): ");
					scanf("%c",&ch1);
				
					if(ch1=='y') 
						goto seat_order;
					
					else
					{
						printf("Returning to main menu...\n");
						Sleep(2000); main(); 
					}
			}
			else if(seat>c4[k])
			{
					printf("Not enough seats... Do you want to choose another seating order?(y/n): ");
					scanf("%c",&ch1);
				
					if(ch1=='y') 
						goto seat_order ;
					
					else
					{
						printf("Returning to main menu...");
						Sleep(2000); main(); 
					}
				
			}
			else 
			{
				c4[k]-=seat;
				goto booking;
			}
		}
			
		
		booking:
		
	    amount=ticket_price*seat;
		
		printf("\n\tTickets Booked Successsfully...\n\nPlease Wait");
		Sleep(800);
		printf(".");
		Sleep(800);
		printf(".");
		Sleep(800);
		printf(".");		
	 	
	 	
	system("cls");
	
		printf("\n\t\t||======== Bill ========||\n\n");
		printf("\t\t Booking no.    %d\n",id);
		printf("\t\t Movie Name:    %s\n",mc[k].name);
		printf("\t\t Timing:        %s\n", mc[k].timing);
		printf("\t\t Screen Date:   %s\n\n",mc[k].screen_date);
		printf("\t\t Name:          %s\n",name);
		printf("\t\t Mobile Number: 0%ld\n",mob_no);
		printf("\t\t Total Seats:   %d\n",seat);
		printf("\t\t Amount:        Rs. %d\n",amount);
		if(order==1)
		
			printf("\t\t Front Seats::  Row 1 to 5\n");
		
		else if(order==2)
		
			printf("\t\t Mid Seats::    Row 6 to 10\n");
		
		else if(order==3)
		
			printf("\t\t Back Seats::   Row 11 to 15\n");
		
		else if(order==4)
		
			printf("\t\t Balcony Seats\n");
		
		
		
		
		
		printf("\n***ENJOY YOUR MOVIE***\n");
		printf("Show this Bill to cinema counter to get your tickets.\nThank you, visit again sometime...\n\n");
		
		id++;
		
		ufp=fopen("add_movie_cine.txt","w");

		for(i=0;i<2;i++)
		{
			fprintf(ufp,"%s\n%s %s %s ",mc[i].name,mc[i].release_date,mc[i].screen_date,mc[i].timing);
			fprintf(ufp,"%d %d %d %d\n",mc[i].front,mc[i].mid,mc[i].back,mc[i].balcony);
			fprintf(ufp,"%d %d %d %d\n",c1[i],c2[i],c3[i],c4[i]);
		}

                fclose(ptr);

        fclose(ufp);
		
		
		
		
		printf("Press Enter to Return to Main Menu.\n");
		while(getch()!=13)
		printf(" ");
		
		printf("\nRETURNING TO  MAIN MENU");
		Sleep(800);
		printf(".");
		Sleep(800);
		printf(".");
		Sleep(800);
		printf(".");		

		main();
				
		}
	}	



void Book_Ticket_Atrium(){
 
	int i,k,n;
	char name[30],ch;
	long int mob_no;
struct movies ma [n];
int s1[n],s2[n],s3[n],s4[n];
	
	FILE *ptr, *ufp;
	
	ptr=fopen("add_movie_atr.txt","r");
	
	
	if (ptr==NULL)

	{
		printf("File not found...\n");
		exit(1);
	}

	else if(ch=fgetc(ptr)==EOF)

    {

        printf("\nNo Movie is available to book right now! Check after few days!!!");

        main();

    }
	else 

	{
		
		ptr=fopen("add_movie_atr.txt","r");
				
	
		printf("\n\n\t\t||============FOLLLOWING MOVIE IS ON SCREEN==========||\n\n");
		
		
		printf("Code:\n");
		for(i=0;i<n;i++)
		{
		
		fscanf(ptr,"%[^\n]  %s  %s  %s  %d  %d  %d  %d\n%d %d %d %d\n",&ma[i].name,ma[i].release_date,ma[i].screen_date,ma[i].timing,&ma[i].front,&ma[i].mid,&ma[i].back,&ma[i].balcony,&s1[i],&s2[i],&s3[i],&s4[i]);	
		
		printf("\n%d\t\t\tMovie Name: %s\n",i+1,ma[i].name);

        printf("\t\t\tScreen Date (DD/MM/YYYY): %s\n",ma[i].screen_date);
        
        printf("\t\t\tTiming: %s\n",ma[i].timing);

		printf("\n\t\t||====================================================||\n\n");
		}
	Sleep(700);
	
	
	
	 if(s1[i]==0&&s2[i]==0&&s3[i]==0&&s4[i]==0)

    {

        printf("\nThe seats are full! Visit after few days...\n\n");
        

        main();

    }
	
}

		
	fclose(ptr);

	
	
	printf("Enter Code of the movie you want to see: ");

	scanf("%d",&k);

	k-=1;
		
		
		printf("Enter Your Name: ");
		fflush(stdin);	
	
/*label*/	enter_name: 
	
		gets(name);
		
		for(i=0;i<strlen(name);i++)
			{
				if(name[0]==' ')
				{
					printf("Invalid Name...\nPlease re-enter your name: ");
					goto enter_name;
				}
				
				
				else if((name[i]>='a' && name[i]<='z') || (name[i]>='A' && name[i]<='Z') || name[i]==' ' )
				{
					continue;	
				}

				else 
				{
					printf("Invalid Name...\nPlease re-enter your name: ");
					goto enter_name;
				}
				
			}
			
			
			
			number:
			printf("Enter Mobile Number (format: 03*********): ");
			
			scanf("%ld",&mob_no);
			
	
		/*	if(mob_no<00000000000 && mob_no>9999999999){
			printf("Invalid Mobile Number...\nPlease Re-enter number: ");
			goto number;}
			
			
			if(mob_no<920000000000 || mob_no>929999999999) 
			{
			printf("Invalid Mobile Number...\nPlease Re-enter number: ");
			goto number;
			}
		*/
		
		int order,seat,amount,ticket_price;
		char ch1;
			
			
		printf("\n\t============SEATING PRICES (per seat)==================\n\n");
		printf("\t1.Front seats (Row 1 to 5)  : Rs. %d <%d seats available>\n",ma[k].front,s1[k]);
		printf("\t2.Mid seats (Row 6 to 10)   : Rs. %d <%d seats available>\n",ma[k].mid,s2[k]);
		printf("\t3.Back seats (Row 11 to 15) : Rs. %d <%d seats available>\n",ma[k].back,s3[k]);
		printf("\t4.Balcony seats             : Rs. %d <%d seats available>\n",ma[k].balcony,s4[k]);
		printf("\n\t=======================================================\n\n");

            
    
		seat_order:
		printf("Which seating order would you like? (1,2,3 or 4): ");
		scanf("%d",&order);
		
		if (order==1)
		
			ticket_price=ma[k].front;
		
		else if(order==2)
			
			ticket_price=ma[k].mid;
			
		else if(order==3)
			
			ticket_price=ma[k].back;
	
		else if(order==4)
			
			ticket_price=ma[k].balcony;
		
		else
		{
			("Wrong Input...\n");
			goto seat_order;
		}
		
		
		seats:
		printf("How many seats you want to book: ");
		scanf("%d",&seat);
		
		if (seat==0)
		{
			printf("Seats cant be 0...\n");
			goto seats;
		}
		else if(order==1)
		{
			if(s1[k]==0)
			{
					printf("All seats are booked...Do you want to choose another seating order?(y/n): ");
				fflush(stdin);
					scanf("%c",&ch1);
				
					if(ch1=='y') 
						goto seat_order;
					
					else
					{
						printf("We're Sorry for the inconvenience.\nReturning to main menu...\n");
						Sleep(2000); main(); 
					}
			}
			else if(seat>s1[k])
			{
					printf("Not enough seats...Do you want to choose another seating order?(y/n): ");
				fflush(stdin);
					scanf("%c",&ch1);
				
					if(ch1=='y') 
						goto seat_order ;
					
					else
					{
						printf("We're Sorry for the inconvenience.\nReturning to main menu...\n");
						Sleep(2000); main(); 
					}
				
			}
			else 
			{
				s1[k]-=seat;
				goto booking;
			}
		}




		else if(order==2)
		{
			if(s2[k]==0)
			{
					printf("All seats are booked... Do you want to choose another seating order?(y/n): ");
				fflush(stdin);	
					scanf("%c",&ch1);
				
					if(ch1=='y') 
						goto seat_order;
					
					else
					{
						printf("We're Sorry for the inconvenience.\nReturning to main menu...\n");
						Sleep(2000); main(); 
					}
			}
			else if(seat>s2[k])
			{
					printf("Not enough seats... Do you want to choose another seating order?(y/n): ");
				fflush(stdin);	
					scanf("%c",&ch1);
				
					if(ch1=='y') 
						goto seat_order ;
					
					else
					{
						printf("We're Sorry for the inconvenience.\nReturning to main menu...\n");
						Sleep(2000); main(); 
					}
				
			}
			else 
			{
				s2[k]-=seat;
				goto booking;
			}
		}
				
		
		else if(order==3)
		{
			if(s3[k]==0)
			{
					printf("All seats are booked... Do you want to choose another seating order?(y/n): ");
				fflush(stdin);	
					scanf("%c",&ch1);
				
					if(ch1=='y') 
						goto seat_order;
					
					else
					{
						printf("We're Sorry for the inconvenience.\nReturning to main menu...\n");
						Sleep(2000); main(); 
					}
			}
			else if(seat>s3[k])
			{
					printf("Not enough seats... Do you want to choose another seating order?(y/n): ");
					scanf("%c",&ch1);
				
					if(ch1=='y') 
						goto seat_order ;
					
					else
					{
						printf("Returning to main menu...");
						Sleep(2000); main(); 
					}
				
			}
			else 
			{
				s3[k]-=seat;
				goto booking;
			}
		}
		
		
		
		
		else if(order==4)
		{
			if(s4[k]==0)
			{
					printf("All seats are booked... Do you want to choose another seating order?(y/n): ");
					scanf("%c",&ch1);
				
					if(ch1=='y') 
						goto seat_order;
					
					else
					{
						printf("Returning to main menu...\n");
						Sleep(2000); main(); 
					}
			}
			else if(seat>s4[k])
			{
					printf("Not enough seats... Do you want to choose another seating order?(y/n): ");
					scanf("%c",&ch1);
				
					if(ch1=='y') 
						goto seat_order ;
					
					else
					{
						printf("Returning to main menu...");
						Sleep(2000); main(); 
					}
				
			}
			else 
			{
				s4[k]-=seat;
				goto booking;
			}
		}
			
		
		booking:
		
	    amount=ticket_price*seat;
		
		printf("\n\tTickets Booked Successsfully...\n\nPlease Wait");
		Sleep(800);
		printf(".");
		Sleep(800);
		printf(".");
		Sleep(800);
		printf(".");		
	 	
	 	
	system("cls");
	
		printf("\n\t\t||======== Bill ========||\n\n");
		printf("\t\t Booking no.    %d\n",id);
		printf("\t\t Movie Name:    %s\n",ma[k].name);
		printf("\t\t Timing:        %s\n", ma[k].timing);
		printf("\t\t Date:          %s\n\n", ma[k].screen_date);
		printf("\t\t Name:          %s\n",name);
		printf("\t\t Mobile Number: 0%ld\n",mob_no);
		printf("\t\t Total Seats:   %d\n",seat);
		printf("\t\t Amount:        Rs. %d\n",amount);
		if(order==1)
		
			printf("\t\t Front Seats::  Row 1 to 5\n");
		
		else if(order==2)
		
			printf("\t\t Mid Seats::    Row 6 to 10\n");
		
		else if(order==3)
		
			printf("\t\t Back Seats::   Row 11 to 15\n");
		
		else if(order==4)
		
			printf("\t\t Balcony Seats\n");
		
		
		
		printf("\n***ENJOY YOUR MOVIE***\n");
		printf("Show this Bill to cinema counter to get your tickets.\nThank you, visit again sometime...\n\n");
	
		id++;
		
		ufp=fopen("add_movie_atr.txt","w");

		for(i=0;i<2;i++)
		fscanf(ptr,"%d\n%[^\n]  %s  %s  %s  %d  %d  %d  %d\n%d %d %d %d\n",&n,ma[i].name,ma[i].release_date,ma[i].screen_date,ma[i].timing,&ma[i].front,&ma[i].mid,&ma[i].back,&ma[i].balcony,&s1[i],&s2[i],&s3[i],&s4[i]);	

                fclose(ptr);

        fclose(ufp);
		
	fclose(ptr);
		
		
		
		printf("Press Enter to Return to Main Menu.\n");
		while(getch()!=13)
		printf(" ");
		
		printf("\nRETURNING TO  MAIN MENU");
		Sleep(800);
		printf(".");
		Sleep(800);
		printf(".");
		Sleep(800);
		printf(".");		

		main();
				
			
	}	






void add_movie_atr()
{
	int i,j,k;
	char ans;



	struct movies ma[2];
	int s1[2],s2[2],s3[2],s4[2];
	

for(i=0;i<2;i++)
{
	s1[i]=20; s2[i]=20; s3[i]=20; s4[i]=40;
}

				

	FILE *fp;
	fp=fopen("add_movie_atr.txt","a");

	
		if(fp==NULL)
				{
					printf("FILE NOT FOUND");
					exit(0);
				}
		else {

			
				for(i=0;i<2;i++)
				{
				
				printf("Enter Name of Movie you want to add:\n");
				fflush(stdin);
				gets(ma[i].name);
				printf("Enter release date: ");
				gets(ma[i].release_date);
				printf("Enter screening date: ");
				gets(ma[i].screen_date);
				printf("Timings: ");
				gets(ma[i].timing);
				printf("\nEnter Prices of seating order\n");
				printf("Fronts seats:: From Row 1 to 5: Rs. ");
				scanf("%d",&ma[i].front);
				printf("Middle seats:: From Row 6 to 10: Rs. ");
				scanf("%d",&ma[i].mid);
				printf("Back seats:: From Row 11 to 15: Rs.");
				scanf("%d",&ma[i].back);
				printf("Balcony seat prices: Rs. ");
				scanf("%d",&ma[i].balcony);
			
			
				fprintf(fp,"%s\n%s %s %s ",ma[i].name,ma[i].release_date,ma[i].screen_date,ma[i].timing);
				fprintf(fp,"%d %d %d %d\n",ma[i].front,ma[i].mid,ma[i].back,ma[i].balcony);
				fprintf(fp,"%d %d %d %d\n",s1[i],s2[i],s3[i],s4[i]);
				
				printf("\n");
				}
				
				
				printf("Movie successfully added...");
				
				fclose(fp);
			
			
			}
				
					fflush(stdin);	
				printf("Do you want to return to main menu?(y/n)");
				scanf("%c",&ans);
				if (ans=='y' || 'Y')
					main();
				else
					exit(0);
	
	
	}
	

void view_movie_atr()
{
	
	int i,n;
	char ch;

		struct movies ma[2];
		int s1[2],s2[2],s3[2],s4[2]; 

	FILE *fp;
	fp=fopen("add_movie_atr.txt","r");

	if (fp==NULL)
	{
		printf("File not found...\n");
		exit(0);
	}
	else
	{
	
system("cls");

        if((ch=fgetc(fp))!=EOF)

        {


		   // fp=fopen("add_movie_atr.txt","r");
			
          
		  
		    printf("================ ON SCREENS !!! =====================");
           
	

for(i=0;i<2;i++)
{
		
		 fscanf(fp,"%[^\n]  %s  %s  %s  %d  %d  %d  %d\n%d %d %d %d\n",&ma[i].name,ma[i].release_date,ma[i].screen_date,ma[i].timing, &ma[i].front,&ma[i].mid,&ma[i].back,&ma[i].balcony,&s1[i],&s2[i],&s3[i],&s4[i]);
	

            printf("\nMovie Name: %s",ma[i].name);

            printf("\nRelease Date: %s",ma[i].release_date);
            
            printf("\nScreening Date: %s",ma[i].screen_date);
            
            printf("\nTimings: %s",ma[i].timing);

            printf("\nTicket pricing:\n\n1.Row 1 to 5: %d Rs per seat (%d seats available)\n2.Row 6 to 10: %d Rs per seat (%d seats available)\n3.Row 11 to 15: %d Rs per seat (%d seats available)\n4.Balcony: %d Rs per seat (%d seats available)\n",ma[i].front,s1[i],ma[i].mid,s2[i],ma[i].back,s3[i],ma[i].balcony,s4[i]);

			printf("=====================================================");
}
        printf("\nPress Enter to Return to Main Menu.\n");
		while(getch()!=13)
		printf(" ");
		
		printf("\nRETURNING TO  MAIN MENU");
		printf(".");
		Sleep(500);
		printf(".");
		Sleep(500);
		printf(".");
		Sleep(500);
				


            fclose(fp);
		fclose(fp);

            main();

        }

        else

        {

            printf("No movie available, please check after few days!!!");

            Sleep(2000);

            main();

        }

	}

    fclose(fp);

	
}




void add_movie_cine()
{
	struct movies mc[2];
	char ans;
	int i;
	int c1[2],c2[2],c3[2],c4[2];

	for(i=0;i<2;i++)
	c1[i]=20, c2[i]=20, c3[i]=20, c4[i]=40;
		
				FILE *ptr;
				
				ptr=fopen("add_movie_cine.txt","a");
				
				if(ptr==NULL)
				{
					printf("File not found");
					exit(0);
				}
				else
				{
					for(i=0;i<2;i++)
					{
						printf("Enter Name of Movie you want to add:\n");
						fflush(stdin);
						gets(mc[i].name);
						printf("Enter release date: ");
						gets(mc[i].release_date);
						printf("Enter screening date: ");
						gets(mc[i].screen_date);
						printf("Timings: ");
						gets(mc[i].timing);
						printf("\nEnter Prices of seating order\n");
						printf("Fronts seats:: From Row 1 to 5: Rs. ");
						scanf("%d",&mc[i].front);
						printf("Middle seats:: From Row 6 to 10: Rs. ");
						scanf("%d",&mc[i].mid);
						printf("Back seats:: From Row 11 to 15: Rs.");
						scanf("%d",&mc[i].back);
						printf("Balcony seat prices: Rs. ");
						scanf("%d",&mc[i].balcony);
					
					
						fprintf(ptr,"%s\n%s %s %s ",mc[i].name,mc[i].release_date,mc[i].screen_date,mc[i].timing);
						fprintf(ptr,"%d %d %d %d\n",mc[i].front,mc[i].mid,mc[i].back,mc[i].balcony);
						fprintf(ptr,"%d %d %d %d\n",c1[i],c2[i],c3[i],c4[i]);
						
					}
						printf("Movie successfully added...\n");
				
				
					fclose(ptr);
					
				}
			
				fflush(stdin);	
				printf("Do you want to return to main menu?(y/n)");
				scanf("%c",&ans);
				if (ans=='y' || 'Y')
					main();
				else
					exit(1);
			
		 
		

}


void view_movie_cine()
{
	struct movies mc[2];
	char ch;
	int i, c1[2],c2[2],c3[2],c4[2];
	
	FILE *ptr;
	ptr=fopen("add_movie_cine.txt","r");
	if (ptr==NULL)
	{
		printf("File not found...\n");
		exit(1);
	}
	else
	{
	
system("cls");

        if((ch=fgetc(ptr))!=EOF)

        {


            ptr=fopen("add_movie_cine.txt","r");
            
            printf("\t\t================ Now Playing =====================");
            for(i=0;i<2;i++)
            {
            fscanf(ptr,"%[^\n]  %s  %s  %s  %d  %d  %d  %d\n%d %d %d %d\n",mc[i].name,mc[i].release_date,mc[i].screen_date,mc[i].timing, &mc[i].front,&mc[i].mid,&mc[i].back,&mc[i].balcony,&c1[i],&c2[i],&c3[i],&c4[i]);


            printf("\n\t\tMovie Name: %s",mc[i].name);

            printf("\n\t\tRelease Date: %s",mc[i].release_date);
            
            printf("\n\t\tScreening Date: %s",mc[i].screen_date);
            
            printf("\n\t\tTimings: %s",mc[i].timing);

            printf("\n\n\t\tTicket pricing:\n\t\t1.Row 1 to 5: %d Rs per seat (%d seats available)\n\t\t2.Row 6 to 10: %d Rs per seat (%d seats available)\n\t\t3.Row 11 to 15: %d Rs per seat (%d seats available)\n\t\t4.Balcony: %d Rs per seat (%d seats available)\n",mc[i].front,c1[i],mc[i].mid,c2[i],mc[i].back,c3[i],mc[i].balcony,c4[i]);

			printf("\t\t==================================================");
             	
            } 
            
        printf("\nPress Enter to Return to Main Menu.\n");
		while(getch()!=13)
		printf(" ");
		
		printf("\nRETURNING TO  MAIN MENU");
		printf(".");
		Sleep(500);
		printf(".");
		Sleep(500);
		printf(".");
		Sleep(500);
				


            fclose(ptr);

            main();

        }

        else

        {

            printf("No movie available, please check after few days!!!");

            Sleep(2000);

            main();

        }

	}

    fclose(ptr);

}





void add_movie_nupl()
{
	struct movies mn[2];
	char ans;
	int i, n1[2],n2[2],n3[2],n4[2];

	for(i=0;i<2;i++)
	n1[i]=20, n2[i]=20, n3[i]=20, n4[i]=40;
	
	

				
				FILE *fptr;
				
				fptr=fopen("add_movie_nupl.txt","a");
				
				if(fptr==NULL)
				{
					printf("FILE NOT FOUND");
					exit(0);
				}
				
				else
				{
				
					for(i=0;i<2;i++)
					{
						
					printf("Enter Name of Movie you want to add:\n");
					fflush(stdin);
					gets(mn[i].name);
					printf("Enter release date: ");
					gets(mn[i].release_date);
					printf("Enter Screening date: ");
					gets(mn[i].screen_date);
					printf("Timings: ");
					gets(mn[i].timing);
					printf("\nEnter Prices of seating order\n");
					printf("Fronts seats:: From Row 1 to 5: Rs. ");
					scanf("%d",&mn[i].front);
					printf("Middle seats:: From Row 6 to 10: Rs. ");
					scanf("%d",&mn[i].mid);
					printf("Back seats:: From Row 11 to 15: Rs.");
					scanf("%d",&mn[i].back);
					printf("Balcony seat prices: Rs. ");
					scanf("%d",&mn[i].balcony);
				
				
					fprintf(fptr,"%s\n%s %s %s ",mn[i].name,mn[i].release_date,mn[i].screen_date,mn[i].timing);
					fprintf(fptr,"%d %d %d %d\n",mn[i].front,mn[i].mid,mn[i].back,mn[i].balcony);
					fprintf(fptr,"%d %d %d %d\n",n1[i],n2[i],n3[i],n4[i]);
					}
					printf("Movie successfully added...");
				
					fclose(fptr);
				}
				fflush(stdin);	
				printf("Do you want to return to main menu?(y/n)");
				scanf("%c",&ans);
				if (ans=='y' || 'Y')
					main();
				else
					exit(1);
			
			
		  
}


void view_movie_nupl()
{
	struct movies mn[2];
	char ch;
	int i,n1[2],n2[2],n3[2],n4[2];
	FILE *fptr;
	fptr=fopen("add_movie_nupl.txt","r");
	if (fptr==NULL)
	{
		printf("File not found...\n");
		exit(1);
	}
	else
	{
	
system("cls");

        if((ch=fgetc(fptr))!=EOF)

        {


            fptr=fopen("add_movie_nupl.txt","r");
            
            printf("\t\t================ Now Playing =====================");
           
		    for(i=0;i<2;i++)
			
			{
				
            fscanf(fptr,"%[^\n]  %s  %s  %s  %d  %d  %d  %d\n%d %d %d %d\n",&mn[i].name,mn[i].release_date,mn[i].screen_date,mn[i].timing, &mn[i].front,&mn[i].mid,&mn[i].back,&mn[i].balcony,&n1[i],&n2[i],&n3[i],&n4[i]);

            printf("\n\t\tMovie Name: %s",mn[i].name);

            printf("\n\t\tRelease Date: %s",mn[i].release_date);
            
            printf("\n\t\tScreeing Date: %s",mn[i].screen_date);
            
            printf("\n\t\tTimings: %s",mn[i].timing);

            printf("\n\t\tTicket pricing:\n\t\t1.Row 1 to 5: %d Rs per seat (%d seats available)\n\t\t2.Row 6 to 10: %d Rs per seat (%d seats available)\n\t\t3.Row 11 to 15: %d Rs per seat (%d seats available)\n\t\t4.Balcony: %d Rs per seat (%d seats available)\n",mn[i].front,n1[i],mn[i].mid,n2[i],mn[i].back,n3[i],mn[i].balcony,n4[i]);

            printf("\t\t==================================================");
            
        	}

        printf("\nPress Enter to Return to Main Menu.\n");
		while(getch()!=13)
		printf(" ");
		
		printf("\nRETURNING TO  MAIN MENU");
		printf(".");
		Sleep(500);
		printf(".");
		Sleep(500);
		printf(".");
		Sleep(500);
				


            fclose(fptr);

            main();

        }

	}
}



