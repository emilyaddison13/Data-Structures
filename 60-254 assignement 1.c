#inlclude <stdio.h>
int main() {
    int choice = 0;
    Student *SLIST = NULL; //set student list equal to null

    choice = getChoice();

    while(choice >= 0) {
        switch(choice) {
            case 0 : printf("Exit\n"); exit(0);
            case 1 : SLIST = addToList(SLIST); break;
            case 2 : printList(SLIST); break;
            case 3 : printListRR(SLIST); break;
            case 4 : searchList(SLIST); break;
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
    printf("1. Add a student to list.\n");
    printf("2. Print the list, beginning to end.\n");
    printf("3. Print the student list starting from the end.\n");
    printf("4. Search the list for a student.\n");
    printf("0. Exit.\n");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);//ask user for choice and scan choice 

    return choice;
}
