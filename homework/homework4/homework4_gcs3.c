#include <stdio.h>
#include <stdlib.h>

int num_count(char *filename);
void load_nums(char *filename, int *nums, int n);
void decode(int *nums, int n, char *s);

//close files
int main(int argc, char* argv[]){
        if(argc!=2){
            printf("Invalid command! Should be: cmd in-filename.\n");
            return (1);
        }
        int count=num_count(argv[1]);
        int *arrayPtr= (int *) calloc(count, sizeof(int));
        if(arrayPtr==NULL){
            printf("Unable to allocate memory for numbers.\n");
            return(1);
        }
        load_nums(argv[1], arrayPtr, count);
        char *stringPtr=(char *) calloc(count, sizeof(char));
        if(stringPtr==NULL){
            printf("Unable to allocate memory for message.\n");
            return(1);
        }        
        decode(arrayPtr, count, stringPtr);
        free(arrayPtr);
        free(stringPtr);
        return(0);
}

int num_count(char *filename){
    FILE *fpp;
    fpp=fopen(filename, "r");
    int count=0;
    int array[100000];  
    if (fpp != NULL){
        while(!feof(fpp)){
            fscanf(fpp, "%d", &array[count]);
            count++;
        }
    }
    else{
        printf("Unable to open input file x.txt! \n");
    }
    fclose(fpp);
    return count;
}

void load_nums(char *filename, int *nums, int n){
    FILE *fp;
    fp=fopen(filename, "r");
    for (int i=0; i<n; i++){
        fscanf(fp, "%d", &nums[i]);
    }
    fclose(fp);
}

void decode(int *nums, int n, char *s){
    for (int i=0; i<n; i++){
        s[i]=(nums[i]+nums[n-1]);
        n--;
        printf("%c", s[i]);
    }
    printf("\n");
}




