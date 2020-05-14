#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>

void welcome(); // to display the welcome screen
void login(); // to display the login screen
void mainmenu(); // to display the main menu
void add_books(); // to display the add books screen
void delete_books();// to display the delete function
void edit_books(); // to display the edit function
void BookRating();
void search_books(); // to display the search function
void view_books();// too display the view books function
void viewuser();



int wrong=1, count;//global variable for login function of int type
int i=0, valid=0;
char choice=0 ;

char answer;
int target=0,found=0;

struct books// to call in program
{
	int books_id; // declare the integer data type
	char b_name[20];// declare the character data type
	char a_name[20];// declare the charecter data type
	char s_name[20];// declare the character data type
	int add;// registeration number
	int rat;
	int yr; // declare the integer data type
	
}m;
void gotoxy(short x, short y)// declare the gotoxy function
{
	COORD pos ={x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}

int main() // declare main function
{
	welcome(); // call welcome screen
	login();// call login screen
	return  0;
}
// welcomr function
void welcome()
{

	gotoxy(25,6);
printf("  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**");
gotoxy(25,7);
printf("  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**");
gotoxy(25,8);
printf("        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
gotoxy(25,9);
printf("        =                 WELCOME                   =");
gotoxy(25,10);
printf("        =                   TO                      =");
gotoxy(25,11);
printf("        =                  BOOK                     =");
gotoxy(25,12);
printf("        =                 RATING                    =");
gotoxy(25,13);
printf("        =                 SYSTEM                    =");
gotoxy(25,14);
printf("        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
gotoxy(25,15);
printf("  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**");
gotoxy(25,16);
printf("  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**");
gotoxy(28,22);
printf(" Enter any key to continue.....");
getch();
}
// login function
void login()
{
	system("cls");
	int L=0;
	char a[30], b[30];
	system("cls");
	
		
	
	printf("------------------------------------------------------------------------------------------------\n");
	printf("\t\t\t\t\tLogin Screen");
	printf("\n------------------------------------------------------------------------------------------------");
	
	do
	{
		printf("\n\t\t\t\tEnter Username and Password");
	
		printf("\n\t\t\t\tUsername:");
		scanf("%s" ,a);
	
		printf("\n\t\t\t\tPassword:");
		scanf("%s" ,b);
		if((strcmp(a,"abc123")==0)&& (strcmp(b,"12345")==0))
		{
			printf("\n\t\t\t\tLogged Into System.");
			printf("\n\t\t\t\tPress any key to go next.....");
			printf("\n------------------------------------------------------------------------------------------------");
			getch();
			mainmenu();
		}
		else
		{
			
			printf("\t\t\t\tLogin Failed Enter Again Username & Password Again\n\n");
			L++;
		}
	} while(L<=3);
	if(L>3){
		system("cls");
		gotoxy(40,15);
		printf("Sorry,Unknown User.");
		getch();
		system("cls");
	}
	
}
// mainmenu function
void mainmenu()
	{
		int choice;
	
		system("cls");
		printf("\n------------------------------------------------------------------------------------------------");
		gotoxy(20,2);
		printf("MAIN MENU");
		printf("\n------------------------------------------------------------------------------------------------");
		gotoxy(20,5);
		printf("1. Add Books Rating");
		gotoxy(20,7);
		printf("2. Search Book Rating Entered by you");
		gotoxy(20,9);
		printf("3. View Rating History");
		gotoxy(20,11);
		printf("4.Avg Book Rating");
		gotoxy(20,13);
		printf("5. Delete Books rating");
		gotoxy(20,15);
		printf("6. Close Application");
		gotoxy(20,17);
		printf("7. Books in sorted order");
		gotoxy(20,19);
		printf("Please Enter a choice[1-7]:");
		scanf("%d",&choice);
		switch(choice)
			{
				case 1:
				add_books();
				break;
				case 2:
			    search_books();
				break;
				case 3:
				view_books();
				break;
				case 4:
				BookRating();
				break;
				case 5:
				delete_books();
				case 6:
				exit(0);
				break;
				case 7:
				viewuser();
				break;
				default:
					printf("Wrong Entry!!");
					exit(0);
					
						
			}
}
void add_books()
{
	int days;
	system("cls");
	FILE *sfile;
	sfile = fopen("BookRecord.txt","a");
	printf("\n\t\t****************************************************");
	printf("\n\t*********************ADD NEW BOOKS*********************");
	printf("\n\t\t******************************************************");
	printf("\n\n\t\t  ENTER YOUR DETAILS BELOW:");
	printf("\n\t\t------------------------------");
	printf("\n\t\tBook ID NO.\t\t:");
	fflush(stdin);
	scanf("%i",&m.books_id);
	do
	{
		printf("\n\t\tBook Name\t\t:");
		fflush(stdin);
		gets(m.b_name);
		m.b_name[0]=toupper(m.b_name[0]);
		for (i=0;i<strlen(m.b_name); ++i)
		{
			if(isalpha(m.b_name[i]))
			{
				valid = 1;
			}
			else
			{
				valid = 0;
				break;
			}
		}
		if (!valid)
		{
			printf("\nName contain invalid character. Please enter again.");
		}
	}while(!valid);
	do
	{
		printf("\n\t\tPublication\t\t:");
		fflush(stdin);
		gets(m.a_name);
		m.a_name[0]=toupper(m.a_name[0]);
		for (i=0;i<strlen(m.a_name); ++i)
		{
			if(isalpha(m.a_name[i]))
				valid = 1;
			else
			{
				valid = 0;
				break;
			}
		}
		if (!valid)
		{
			printf("\nName contain invalid character. Please enter again.");
		}
	}while(!valid);
	do
	{
		printf("\n\t\tStudent Name\t\t:");
		fflush(stdin);
		gets(m.s_name);
		m.s_name[0]=toupper(m.s_name[0]);
		for (i=0;i<strlen(m.s_name); ++i)
		{
			if(isalpha(m.s_name[i]))
				valid = 1;
			else
			{
				valid = 0;
				break;
			}
		}
		if (!valid)
		{
			printf("\nName contain invalid character. Please enter again.");
		}
	}while(!valid);
		
			printf("\n\t\tStudent Regno.\t\t:");
			fflush(stdin);
			scanf("%i",&m.add);
			printf("\n\t\tBOOK RATING[1-10]\t:");
			fflush(stdin);
			scanf("%i",&m.rat);

	fprintf(sfile,"%i %s %s %s %i  %i\n\n",m.books_id, m.b_name, m.a_name, m.s_name,m.add,m.rat);
	fclose(sfile);
	printf("\n\t SUCCESFULLY RECORDED.\n");
	getch();
	printf("\n\t\t Do you want to add another book?[Y/N]:");
	scanf("%s",&answer);
	while(toupper(answer)!='Y'&& toupper(answer)!='N')
	{
		printf("Invalid!\n\tDo you want to add book?[Y/N]:");
		scanf("%s",&answer);
	}
	if(toupper(answer)=='Y')
	{
		add_books();
	}
	else
	{
		printf("\n\t\tPress any key to go to mainmenu.....");
		mainmenu();
	}
	
}

//SEARCH BOOKS

void search_books()
{
	int found=0;
	int id,reg;
	FILE *sfile;
	system("cls");
	sfile=fopen("BookRecord.txt","rb");
	printf("\n\t\t******************************************************");
	printf("\n\t\t***************** SEARCH BOOKS LIST*******************");
	printf("\n\t\t******************************************************\n\n");

	printf("\nEnter regno and book_id to search:");
	fflush(stdin);
	scanf("%i %i",&reg,&id);
	 
	printf("                                                                                     \n");
	printf(" Book ID NO. Book Name    Publication    Student Name  Student Regno. Rating ");

	printf("\n=====================================================================================\n");
	while(fscanf(sfile,"%i %s %s %s %i %i\n\n",&m.books_id, m.b_name, m.a_name, m.s_name, &m.add,&m.rat)!=EOF)
	{
		if(reg==m.add && id==m.books_id)
		{
			found=1;
			gotoxy(1,10);
			printf("%i",m.books_id);
			gotoxy(12,10);
			printf("%s",m.b_name);
			gotoxy(24,10);
			printf(" %s",m.a_name);
			gotoxy(40,10);
			printf(" %s",m.s_name);
			gotoxy(56,10);
			printf("%i",m.add);
			gotoxy(74,10);
			printf("%i",m.rat);
			gotoxy(92,10);
		}
	}
		if(!found) printf("\n\n\tNo Record");
		fclose(sfile);
		printf("\t\t\n\n\nPress any key to go to mainmenu.....");
		getch();
		mainmenu();
	
}

//VIEW BOOKS

void view_books()
{
	int i,e,reg,found=0;
	FILE*sfile;
	system("cls");
	sfile=fopen("BookRecord.txt","r");
	printf("\n\t\t\t*********************************************************");
	printf("\n\t\t\t**************** VIEW ALL BOOK RECORDS *****************");
	printf("\n\t\t\t*********************************************************");
	if(sfile==NULL)
	{
		printf("\n\n\t\t RECORD EMPTY");
		getch();
	}
	else
	{
	printf("\nEnter regno to search:");
	fflush(stdin);
	scanf("%i",&reg);
		gotoxy(1,6);
		printf("Book Id NO.");
		gotoxy(13,6);
		printf("Book Name");
		gotoxy(30,6);
		printf("Publication");
		gotoxy(45,6);
		printf("Students Name");
		gotoxy(63,6);
		printf("Students regno");
		gotoxy(83,6);
		printf("BOOK RATING");
		printf("        \n");
		for(i=0;i<95;i++)
		{
			printf("-");
		}
		e=8;
		while(fscanf(sfile,"%i %s %s %s %i %i \n\n",&m.books_id,m.b_name,m.a_name,m.s_name,&m.add,&m.rat)!=EOF)
		{	
			if(reg==m.add)
			{
				found=1;
			gotoxy(1,e);
			printf("%i",m.books_id);
			gotoxy(13,e);
			printf("%s",m.b_name);
			gotoxy(30,e);
			printf("%s",m.a_name);
			gotoxy(45,e);
			printf("%s",m.s_name);
			gotoxy(63,e);
			printf("%i",m.add);
			gotoxy(83,e);
			printf("%i",m.rat);
			e++;
			}
		printf("\n");
		for(i=0;i<95;i++)
		printf("-");
		}
	}
	if(!found) printf("\n\n\tNo Record");
	printf("\n\n\t Press any key for main menu........");
	fclose(sfile);
	getch();
	mainmenu();


}
void BookRating()
{
int i,e,reg,found=0,x=0;
float total=0;
	FILE*sfile;
	system("cls");
	sfile=fopen("BookRecord.txt","r");
	printf("\n\t\t\t*********************************************************");
	printf("\n\t\t\t****************Avg  BOOK RATING *****************");
	printf("\n\t\t\t*********************************************************");
	if(sfile==NULL)
	{
		printf("\n\n\t\t RECORD EMPTY");
		getch();
	}
	else
	{
	printf("\nEnter BooK ID to search:");
	fflush(stdin);
	scanf("%i",&reg);
		gotoxy(1,6);
		printf("Book Id NO.");
		gotoxy(13,6);
		printf("Book Name");
		gotoxy(30,6);
		printf("Publication");
		gotoxy(45,6);
		printf("Students Name");
		gotoxy(63,6);
		printf("Students regno");
		gotoxy(83,6);
		printf("BOOK RATING");
		printf("        \n");
		for(i=0;i<95;i++)
		{
			printf("-");
		}
		e=8;
		while(fscanf(sfile,"%i %s %s %s %i %i \n\n",&m.books_id,m.b_name,m.a_name,m.s_name,&m.add,&m.rat)!=EOF)
		{	
			if(reg==m.books_id)
			{
				total=(total+m.rat);
				x++;
			found=1;
			gotoxy(1,e);
			printf("%i",m.books_id);
			gotoxy(13,e);
			printf("%s",m.b_name);
			gotoxy(30,e);
			printf("%s",m.a_name);
			gotoxy(45,e);
			printf("%s",m.s_name);
			gotoxy(63,e);
			printf("%i",m.add);
			gotoxy(83,e);
			printf("%i",m.rat);
			e++;
			}
		printf("\n");
		for(i=0;i<95;i++)
		printf("-");
		}
	}
	if(!found) printf("\n\n\tNo Record\n");
	printf("Avg. Rating is %f",total/x);
	printf("\n\n\t Press any key for main menu........");
	fclose(sfile);
	getch();
	mainmenu();
}
int HEAP_SIZE = 20;

struct Heap{
    int *arr;
    int count;
    int capacity;
    int heap_type; // for min heap , 1 for max heap
};

int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;

        // If the element is present at the middle
        // itself
        if (arr[mid] == x)
            return mid;

        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);

        // Else the element can only be present
        // in right subarray
        return binarySearch(arr, mid + 1, r, x);
    }

    // We reach here when element is not
    // present in array
    return -1;
}

typedef struct Heap Heap;

Heap *CreateHeap(int capacity,int heap_type);
void insert(Heap *h, int key);
void print(Heap *h);
void heapify_bottom_top(Heap *h,int index);
void heapify_top_bottom(Heap *h, int parent_node);
int PopMin(Heap *h);


Heap *CreateHeap(int capacity,int heap_type){
    Heap *h = (Heap * ) malloc(sizeof(Heap)); //one is number of heap

    //check if memory allocation is fails
    if(h == NULL){
        printf("Memory Error!");
        return 0;
    }
    h->heap_type = heap_type;
    h->count=0;
    h->capacity = capacity;
    h->arr = (int *) malloc(capacity*sizeof(int)); //size in bytes

    //check if allocation succeed
    if ( h->arr == NULL){
        printf("Memory Error!");
        return 0;
    }
    return h;
}

void insert(Heap *h, int key){
    if( h->count < h->capacity){
        h->arr[h->count] = key;
        heapify_bottom_top(h, h->count);
        h->count++;
    }
}

void heapify_bottom_top(Heap *h,int index){
    int temp;
    int parent_node = (index-1)/2;

    if(h->arr[parent_node] > h->arr[index]){
        //swap and recursive call
        temp = h->arr[parent_node];
        h->arr[parent_node] = h->arr[index];
        h->arr[index] = temp;
        heapify_bottom_top(h,parent_node);
    }
}

void heapify_top_bottom(Heap *h, int parent_node){
    int left = parent_node*2+1;
    int right = parent_node*2+2;
    int min;
    int temp;

    if(left >= h->count || left <0)
        left = -1;
    if(right >= h->count || right <0)
        right = -1;

    if(left != -1 && h->arr[left] < h->arr[parent_node])
        min=left;
    else
        min =parent_node;
    if(right != -1 && h->arr[right] < h->arr[min])
        min = right;

    if(min != parent_node){
        temp = h->arr[min];
        h->arr[min] = h->arr[parent_node];
        h->arr[parent_node] = temp;

        // recursive  call
        heapify_top_bottom(h, min);
    }
}

int PopMax(Heap *h){
    int pop;
    if(h->count==0){
        printf("\n__Heap is Empty__\n");
        return -1;
    }
    // replace first node by last and delete last
    pop = h->arr[0];
    h->arr[0] = h->arr[h->count-1];
    h->count--;
    heapify_top_bottom(h, 0);
    return pop;
}

int * sort(Heap *h)
{
    int x=PopMax(h);
    int *p=(int*)malloc(sizeof(int)*100);
    int i=0;
    p[i]=x;
    i++;
    return p;
}
void delete_books()
{
	
	int target,reg;
	system("cls");
	printf("\n\t\t*************************************************");
	printf("\n\t***************Delete Books Rating****************");
	printf("\n\t\t*************************************************");
	FILE *sfile,*mfile;
	sfile=fopen("BookRecord.txt","r");
	printf("\nEnter Book ID NO. and reg no for delete:");
	scanf("%i%i",&target,&reg);
	mfile=fopen("TempBook.txt","w+");
	if(sfile==NULL)
	{
		printf("\n\tNo Record in File!");
		printf("\n\t\t\tPress any key to Main Menu..");
		getch();
		mainmenu();
	}
	else
	{
		while(fscanf(sfile,"%i %s %s %s %i %i\n",&m.books_id,m.b_name,m.a_name,m.s_name,&m.add,&m.rat)!=EOF)
		{
			if(target!=m.books_id && reg!=m.add)
			{
				fprintf(mfile,"%i %s %s %s %i %i\n",m.books_id,m.b_name,m.a_name,m.s_name,m.add,m.rat);
			}
			else
			{
				found=1;
			}
		}
		if(!found)
		{
			printf("\nRecord not found");
		}
		else
		{
			printf("\n\tRecord deleted successfully.....");
		}
		fclose(sfile);
		fclose(mfile);
		remove("BookRecord.txt");
		rename("TempBook.txt","BookRecord.txt");
	}
	getch();
	mainmenu();
}

void viewuser()
{

int i=0,e;
FILE*sfile;
system("cls");
sfile=fopen("BookRecord.txt","r");
int j=4;
	printf("\n\t\t\t*********************************************************");
	printf("\n\t\t\t**************** VIEW ALL BOOK Rating in sorted order *****************");
	printf("\n\t\t\t*********************************************************");
	if(sfile==NULL)
	{
		printf("\n\n\t\t RECORD EMPTY");
		getch();
	}
	else
	{
		gotoxy(1,6);
		printf("Book Id NO.");
		gotoxy(13,6);
		printf("Book Name");
		gotoxy(30,6);
		printf("Publication");
		gotoxy(45,6);
		printf("Students Name");
		gotoxy(63,6);
		printf("Students regno");
		gotoxy(83,6);
		printf("BOOK RATING");
		printf("        \n");
		for(i=0;i<95;i++)
		{
			printf("-");
		}
		e=8;
struct books temp[100];
int l=0;
	while(fscanf(sfile,"%i %s %s %s %i %i \n\n",&m.books_id,m.b_name,m.a_name,m.s_name,&m.add,&m.rat)!=EOF)
	{	
		
	temp[l].books_id=m.books_id;
	strcpy(temp[l].b_name,m.b_name);
	strcpy(temp[l].a_name,m.a_name);
	strcpy(temp[l].s_name,m.s_name);
	temp[l].add=m.add;
	temp[l].rat=m.rat;
	l++;

}
for(int i=0;i<l;i++)
{
    for(int j=0;j<l;j++)
    {
        if(temp[j].rat<temp[j+1].rat)
        {
            struct books t;
            t=temp[j];
            temp[j]=temp[j+1];
            temp[j+1]=t;
        }
    }
}
for(int i=0;i<l;i++)
{
	gotoxy(1,e);
			printf("%i",temp[i].books_id);
			gotoxy(13,e);
			printf("%s",temp[i].b_name);
			gotoxy(30,e);
			printf("%s",temp[i].a_name);
			gotoxy(45,e);
			printf("%s",temp[i].s_name);
			gotoxy(63,e);
			printf("%i",temp[i].add);
			gotoxy(83,e);
			printf("%i",temp[i].rat);
			e++;
}
} 
	printf("\n\n\t Press any key for main menu........");
	fclose(sfile);
	getch();
	mainmenu();
}
