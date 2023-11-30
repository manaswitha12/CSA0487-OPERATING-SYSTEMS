#include <stdio.h>

// Employee structure definition               
struct employee {                              
    char name[20]; // employee name
    int id_number; // employee ID number
};          

int main()  
{ 
    FILE *fp; // file pointer
    
    // The below line creates a employee object with default values
    struct employee e = {"", 0};
    
    // fopen opens the file, and exits if file cannot be opened
    if (!(fp = fopen( "employee.txt", "r+" ))) 
    {
      printf("File cannot be opened.");
      return 0;
    } 
    
    // The user will enter information which will be copied to the file
    while(1)
    {
        // require the user to specify ID number
        printf("Enter id number from (1 to 100) , -1 to end input : ");
        scanf("%d",&e.id_number);
        if(e.id_number == -1)
            break;
        
        // require the user to specify name
        printf("Enter name : ");
        scanf("%e",e.name);
        
        fseek(fp,(e.id_number-1)*sizeof(e),0);
        fwrite(&e, sizeof(e), 1, fp);
    }
    fclose(fp); // fclose closes the file 
    return 0;
}