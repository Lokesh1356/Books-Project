//	Book Mini Project

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
	typedef struct Book
	{
		int bid;
		char bname[20];
		char aname[20];
		float price;
		float ratings;
	}book;
	
	void storeBook(book*);
	void displayBook(book*);
	void minBook(book*);
	void maxBook(book*);
	void searchBook(book*);
	void updateBook(book*);
	void deleteBook(book*);
	void top_3_Book_Price(book*);
	int size;
	void main()
	{
		book* b1;
		int choice, exit;
		
		printf("\t\t\t\t--------Book Details -------------");
		printf("\n\nEnter number of book: ");
		scanf("%d",&size);
		
		b1 = (book*)malloc(size * sizeof(book));
		
		storeBook(b1);
		
		do
		{
			printf("\nBook Menu: \n1.Display Book\n2.Minimum Price Book\n3.Maximum Price Book\n4.Searching The Book\n5.Update Book\n6.Delete Book\n7.Top 3 Book Price\n");
			printf("\nEnter your choice: ");
			scanf("%d",&choice);
		
			if(choice == 1)
			{
				displayBook(b1);		
			}
			
			if(choice == 2)
			{
				displayBook(b1);		
			}
			
			if(choice == 2)
			{
				minBook(b1);
			}
			
			if(choice == 3)
			{
				maxBook(b1);		
			}
			
			if(choice == 4)
			{
				searchBook(b1);
			}
			
			if(choice == 5)
			{
				updateBook(b1);
			}
			
			if(choice == 6)
			{
				deleteBook(b1);
			}
			
			if(choice == 7)
			{
				top_3_Book_Price(b1);
			}
			
			if(choice == 8)
			break;
			
			printf("\nIf you want to exit press 0 or press any key for continue....");
			scanf("%d",&exit);
			
		}while(exit!=0);
	}
	
	void storeBook(book* ptr)
	{
		int i;
		
		for(i = 0; i < size; i++)
		{	
			printf("\nEnter book id: ");
			scanf("%d",&ptr[i].bid);
			
			printf("\nEnter the book name: ");
			scanf("%s",&ptr[i].bname);
			
			printf("\nEnter book author name: ");
			scanf("%s",&ptr[i].aname);
				
			printf("\nEnter book price: ");
			scanf("%f",&ptr[i].price);
			
			printf("\nEnter book ratings: ");
			scanf("%f",&ptr[i].ratings);
		}
	}
	
	void displayBook(book* ptr)
	{
		int i;
		printf("----------------------------------------------------------------------------------------------------------");
		printf("\n\t\t\t\t@@@@@@@@@@ Display Book Details @@@@@@@@@@\n");
		printf("----------------------------------------------------------------------------------------------------------");
		printf("\nBook Id\t\tBook Name\tBook Author Name\tBook Price\tBook Ratings");
		for(i = 0; i < size; i++)
		{
			printf("\n");
			printf("%d\t\t%s\t\t%s\t\t\t%0.2f\t\t%0.2f",ptr[i].bid,ptr[i].bname,ptr[i].aname,ptr[i].price,ptr[i].ratings);
		}
		printf("\n----------------------------------------------------------------------------------------------------------");
		printf("\n");
	}
	
	void minBook(book* b1)
	{
		int i, ch, index = 0;
		float min = 0;
		
		printf("\nEnter your choice: 1)By Price\t2)By Ratings.");
		printf("\n\nEnter your choice: ");
		scanf("%d",&ch);
		
		if(ch == 1)
		{
			for(i = 0; i < size; i++)
			{
				if(b1[i].price < min)
				{
					min = b1[i].price;
					index = i;
				}
			}
		}
		
		if(ch == 2)
		{
			for(i = 0; i < size; i++)
			{
				if(b1[i].ratings < min)
				{
					min = b1[i].ratings;
					index = i;
				}
			}
		}
				
		printf("Book Id: %d\tBook Name: %s\tBook Author Name: %s\tBook Price: %f\tBook Ratings: %f",b1[index].bid,b1[index].bname,b1[index].aname,b1[index].price,b1[index].ratings);		
	}
	
	void maxBook(book* b1)
	{
		int i, ch, index = 0;
		float max = 0;
		
		printf("\nEnter your choice: 1)By Price\t2)By Ratings.");
		printf("\n\nEnter your choice: ");
		scanf("%d",&ch);
		
		if(ch == 1)
		{
			for(i = 0; i < size; i++)
			{
				if(b1[i].price > max)
				{
					max = b1[i].price;
					index = i;
				}
			}
		}
		
		if(ch == 2)
		{
			for(i = 0; i < size; i++)
			{
				if(b1[i].ratings > max)
				{
					max = b1[i].ratings;
					index = i;
				}
			}
		}
				
		printf("\nBook Id: %d\tBook Name: %s\tBook Author Name: %s\tBook Price: %f\tBook Ratings: %f",b1[index].bid,b1[index].bname,b1[index].aname,b1[index].price,b1[index].ratings);		
	}
	
	void searchBook(book* b1)
	{
		int i, bid, index = 0, count = 0;
		char search[20];
		int ch;
		
		printf("\nEnter your book search choice: 1)By Id\t2)By Book Name\t3)By Book Author");
		printf("\n\nEnter your choice: ");
		scanf("%d",&ch);
		
		if(ch == 1)
		{
			printf("\nEnter book id to be search: ");
			scanf("%d",&bid);
		
			for(i = 0; i < size; i++)
			{
				if(bid == b1[i].bid)
					{
						count++;
						index=i;
					}
			}
			if(count == 1)
				printf("\nBook Id: %d\tBook Name: %s\tBook Author Name: %s\tBook Price: %0.2f\tBook Ratings: %0.2f",b1[index].bid,b1[index].bname,b1[index].aname,b1[index].price,b1[index].ratings);
			else
				printf("\nBook id is not found.");
		}
	
		else if(ch == 2)
		{
			printf("\nEnter book name to be search: ");
			scanf("%s",&search);
		
			for(i = 0; i < size; i++)
			{
				if(strcmp(b1[i].bname,search) == 0)
					{
						index=i;
						count++;
					}
			}
//			printf("%d",count);
			if(count == 1)
				printf("\nBook Id: %d\tBook Name: %s\tBook Author Name: %s\tBook Price: %0.2f\tBook Ratings: %0.2f",b1[index].bid,b1[index].bname,b1[index].aname,b1[index].price,b1[index].ratings);
			else
				printf("\nBook name not found.");
		}
		
		else if(ch == 3)
		{
			printf("\nEnter book author name to be search: ");
			scanf("%s",&search);
		
			for(i = 0; i < size; i++)
			{
				if(strcmp(b1[i].aname,search) == 0)
					{
						index=i;
						count++;
					}
			}
//			printf("%d",count);
			if(count == 1)
				printf("\nBook Id: %d\tBook Name: %s\tBook Author Name: %s\tBook Price: %0.2f\tBook Ratings: %0.2f",b1[index].bid,b1[index].bname,b1[index].aname,b1[index].price,b1[index].ratings);
			else
				printf("\nBook name not found.");	
		}
		else
			printf("\nInvalid Choice.");
		
	}
	
	void updateBook(book* b1)
	{
		int i, bid, count = 0;
		
		printf("\nEnter bid which you want to be update the data: ");
		scanf("%d",&bid);
		
		for(i = 0; i < size; i++)
		{
			if(bid == b1[i].bid)
			{
				count++;
				
				printf("\n1.Book Name\t2.Book Author Name\t3.Book Price\t4.Ratings.");
				printf("\n\nEnter your choice: ");
				scanf("%d",&bid);
				if(bid == 1)
				{
					printf("\nEnter book name to be update: ");
					scanf("%s",&b1[i].bname);
				}
				
				if(bid == 2)
				{
					printf("\nEnter book author name to be update: ");
					scanf("%s",&b1[i].aname);
				}
				
				if(bid == 3)
				{
					printf("\nEnter book price to be update: ");
					scanf("%f",&b1[i].price);
				}
				
				if(bid == 4)
				{
					printf("\nEnter book ratings to be update: ");
					scanf("%f",&b1[i].ratings);
				}
			}	
		}
		printf("\nBook Id\t\tBook Name\tBook Author Name\tBook Price\tBook Ratings");
		if(count == 1)
		{
			for(i = 0; i < size; i++)
			{	
				printf("\n");	
				printf("   %d\t\t%s\t\t  %s\t\t\t%0.2f\t\t%0.2f",b1[i].bid, b1[i].bname, b1[i].aname, b1[i].price, b1[i].ratings);
			}
		}
		else
			printf("\nInvalid Choice.");
	}
	
	void top_3_Book_Price(book* b1)
	{
		int first = 0, second = 0, third = 0;
		int i;
		int p , q, r;
		
		for(i = 0; i < size; i++)
		{
			if(b1[i].price > first)
			{
				third = second;
				second = first;
				first = b1[i].price;
			}
			
			else if(b1[i].price > second)
			{
				third = second;
				second = b1[i].price;
			}
			
			else if(b1[i].price > third)
			{
			
				third = b1[i].price;
			}
		}
		
		for(i = 0; i < size; i++)
		{
			if(first == b1[i].price)
				p = i;
			
			else if(second == b1[i].price)
				q = i;
			
			else if(third == b1[i].price)
				r = i;
		}
		
		printf("\nBook Id\t\tBook Name\tBook Author Name\tBook Price\tBook Ratings");		
		printf("\n%d\t\t%s\t\t%s\t\t\t%0.2f\t\t%0.2f",b1[p].bid, b1[p].bname, b1[p].aname, b1[p].price, b1[p].ratings);
		printf("\n%d\t\t%s\t\t%s\t\t\t%0.2f\t\t%0.2f",b1[q].bid, b1[q].bname, b1[q].aname, b1[q].price, b1[q].ratings);
		printf("\n%d\t\t%s\t\t%s\t\t\t%0.2f\t\t%0.2f",b1[r].bid, b1[r].bname, b1[r].aname, b1[r].price, b1[r].ratings);
	}
	
	
	void deleteBook(book* b1)
	{
		int i, bid, a, count = 0;
		
		printf("\nEnter book id to be deleted: ");
		scanf("%d",&bid);
		
		for(i = 0; i < size; i++)
		{
			if(bid == b1[i].bid)
			{	
				count++;
				a = i;
			}	
		} 
		
		for(i = a; i < size; i++)
		{
			strcpy(b1[i].bname, b1[i + 1].bname);
			b1[i].bid = b1[i + 1].bid;	
			
			strcpy(b1[i].aname, b1[i + 1].aname);
			b1[i].price = b1[i + 1].price;
			
			b1[i].ratings = b1[i + 1].ratings;
		}	
		
		size = size - 1;
			if(count == 1)
				printf("\nData deleted successfully.");
			else
				printf("\nData not deleted successfully.");	
	}
