#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <sys/dir.h>

extern  int alphasort();    // built in sorting function

int main(int argc,char **argv) {
   
    int count,  // to count num files in pwd
    i;          // to use in for loop 
    struct direct **fileList;
    
    if(argc != 1) {     // simple shell, no extensions
        printf("Error, no arguments permitted.");
    }

    else {
        count = scandir(".", &fileList, NULL, alphasort);
 
        if (count == 0) {
            printf("No files in current working directory.");
        }

        else if (count < 1) {
            printf("Error, exiting.");
            exit(0);
        }
                
        // printf("Number of files: %d \n", count);

        for (i = 0; i < count; i++) {
            printf("%s      ", fileList[i]->d_name);
        }

        fflush(stdout);

    }
}