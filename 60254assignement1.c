/*
Emily Addison
104553525
*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct post { //structure for posts
   int Date;
   int likes;
   int length;
   int comments;
   char name[40];
   char userpost [140];
   struct post *next, *current, *prev;
};
typedef struct post Post;

//function prototypes
int getChoice();
Post *addtolist(Post *List);
void printList(Post *List);
void printfirst(Post *List);
void length(Post *List);
Post *deleteAPost(Post *List);
Post *deletealllist(Post *List);
int sortlist(Post *List);
void insertSort(Post *Likes, Post *insert, int choice );

int main() {
    int choice = 0;
    Post *SLIST = NULL; //set post list equal to null

    choice = getChoice();

    while(choice >= 0) {
        switch(choice) {
            
			//cases for running functions
            case 1 : printList(SLIST); break;
            case 2 : printfirst(SLIST); break;		
			case 3 : length(SLIST); break;
			case 4 : SLIST = addtolist(SLIST); break;
			case 5 : SLIST = deleteAPost(SLIST); break;
			case 6 : SLIST = deletealllist(SLIST); break;
			case 7 : sortlist(SLIST); break;
			case 8 : printf("Exit\n"); exit(0);
            default: printf("That is not a valid choice\n");
        
        
		}
		choice = getChoice();

    
	}
	if(SLIST) free(SLIST);
    return 0;
}
//Purpose: To get users choice
int getChoice() {
    int choice = 0;

    printf("\n****** MENU ******\n");
    printf("1. Display the Stored Post.\n");
    printf("2. Display the first post.\n");
    printf("3. Display the Current Total Number of Posts.\n");
    printf("4. Store the Data of a New Post.\n");
	printf("5. Delete a post by: .\n");
	printf("6. Delete the Stored Post.\n");
	printf("7. Store the Post Based on: .\n");
    printf("8. Exit.\n");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);//ask user for choice and scan choice 

    return choice;
}
//add stuff to the struct
Post *addtolist(Post *List){
	Post *aPost = (Post *) malloc(sizeof(Post));
	 printf("Enter Post: ");//ask for user input
    scanf("%s", &(aPost->userpost));
    printf("Enter your name: ");
    scanf(" %[^\n]s", aPost->name);
	printf("Enter the Date: ");
	scanf("%d", &(aPost->Date));
	printf("Enter the amount of likes: ");
	scanf("%d", &(aPost->likes));
	printf("Enter the amount of comments: ");
	scanf("%d", &(aPost->comments));
	
	
	
	aPost->next = NULL;
    if (List == NULL) return aPost; //if the list is null return pointer 

    Post *tPost = List; //set pointer equal to a list 

    while(tPost->next != NULL) //while the next element in the list is not empty 
        tPost = tPost->next;//continue moving through the list 

    tPost->next = aPost; //

    return List;//return the list 
	
}
//print out the items in the list
void printList(Post *List) {
	
    while(List != NULL) { //while list is not empty 
        printf("%s %s %d %d %d\n", List->userpost, List->name, List->Date, List->likes,List->comments);//print student info 
		List = List->next;
		}
    
	return;
}
//print based off what you want 
void printfirst(Post *List) {
	int choice, d, l;
	char nme[40];
	printf("What would you like to search for, \n 1. name\n 2. Date\n 3.Likes");
	scanf("%d",&choice);
	if (choice == 1){
		printf("Enter the name you would like to search for: ");
		scanf("%s", nme);
		
	
		while(List != NULL) { 
			if (!strcmp(nme, List->name)){
				printf("%s %s %d %d %d\n", List->userpost, List->name, List->Date, List->likes,List->comments);//print student info 
		
		
    
				return;
			}
			List = List->next;
}
	}
	else if(choice ==2){
		printf("Enter the date you would like to search for: ");
		scanf("%d", &d);
	
		while(List != NULL){
			if ((d == List->Date)){
				printf("%s %s %d %d %d\n", List->userpost, List->name, List->Date, List->likes,List->comments);//print student info 
				return;
			}		
			List = List -> next;	
		}
	}
	else if (choice == 3){
		printf("Enter the amount of likes you would like to search for: ");
		scanf("%d", &l);
		
		while(List !=NULL){
			if (l == List->likes){
				printf("%s %s %d %d %d\n", List->userpost, List->name, List->Date, List->likes,List->comments);//print student info 
				return;
			}
			List = List -> next;
		}
	}
	
	}

//Determine the length of the list
void length(Post *List)
{
    //Post aPost = List->next;
    int r = 0;
    while(List != NULL)
    {
       
        List = List->next;
		r++;
    }
    printf("\n%d items were entered to the list", r);
    return ;
}
//Delete items in a post based off of what you want
Post *deleteAPost(Post *List)
{
    int choice = 0, pdate;
    char pname[40];
	Post *aPost = List, *prev = NULL;
	
    printf("Delete a post by:\n1. Author\n2. Date\n");
    scanf(" %d",&choice);
   
    if (choice == 1){
        printf("Enter post author: ");
		scanf("%s", pname);
 
        
 
        if (aPost != NULL && !strcmp(pname, aPost->name))
        {
            List = aPost->next;  
            free(aPost);              
            return List;
        }

        while (aPost != NULL && strcmp(pname, aPost->name))
        {
            prev = aPost;
			aPost = aPost->next;
			prev->next = aPost->next;
			free(aPost);
        }
 
        
		if(aPost == NULL) return List;
    }
        return List;
    if (choice == 2){
        printf("Enter post date: ");
        scanf("%d", &pdate);
        
 
        if (aPost != NULL && (aPost->Date == pdate))
        {
            List = aPost->next;  
            free(aPost);              
            return List;
        }
	}
 
    

return List;
}
//delete entire list
Post *deletealllist(Post *List)
{
	

   //Post *aPost = List->next, *prev = List;
   //Post *next;
   //struct Node* next;
   Post *aPost = List;
   Post *temp = NULL;
 
   while (aPost != NULL) 
   {
	    temp = aPost;
	   
		aPost = aPost->next; 
		free(temp);
   }
    
   return NULL;
   
   
   
}
//Picks what choice you want for sort
int sortlist(Post *List)
{
	int choice;
	printf("How would you like to sort the list: \n1. Date\n");
	scanf("%d",&choice);
	
	Post *final = NULL;
    Post *temp = List;
 
    while(temp!=NULL){
        Post *next = temp->next;
        insertSort(final, temp, choice);
        temp = next;
    }
   
    List = final;
    return 0;
	
}
//Sorts based off of what was stated 
void insertSort(Post *List, Post *insert, int choice ){
	if(choice == 1)
	{
		 if(List == NULL || List->Date >= insert->Date){
                insert->next = List;
                List = insert;
            }
           
            else{
                Post *temp;
                temp = List;
               
                while(temp->next != NULL && temp->next->Date < insert->Date){
                    temp = temp->next;
                }
                insert->next = temp->next;
                temp->next = insert;
            }
		
	}
	
}