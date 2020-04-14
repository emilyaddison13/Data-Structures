#inlclude <stdio.h>
int main() {
    int choice = 0;
    Student *SLIST = NULL; //set student list equal to null

    choice = getChoice();

    /*while(choice >= 0) {
        switch(choice) {
            
            case 1 : SLIST = addToList(SLIST); break;
            case 2 : printList(SLIST); break;
            case 3 : printListRR(SLIST); break;
            case 4 : searchList(SLIST); break;
			//case 5 : some function; break;
			//case 6 : some function; break;
			//case 7 : some function; break;
			case 8 : printf("Exit\n"); exit(0);
            default: printf("That is not a valid choice\n");
        }
        choice = getChoice();
    }*/

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
