#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int linenumbers;
    int sum;
    char status[15];
} output;

int calculateDivisors(int n);

int main(int argc, char* argv[]){
if (argc!=4){
    printf("Incorrect Input. \n");
    return(1);
}
int arg1=atoi(argv[1]);
int arg2=atoi(argv[2]);
char arg3[3];
strcpy(arg3, argv[3]);
int howMany=(arg2-arg1)+1;
output *theOutput=(output *) calloc(howMany, sizeof(output));
for(int i=0; i<howMany; i++){
    theOutput[i].linenumbers=arg1+i;
    theOutput[i].sum=calculateDivisors(arg1+i);
    if(theOutput[i].sum<(arg1+i)){
        strcpy(theOutput[i].status, "Deficient");
    }
    else if (theOutput[i].sum>(arg1+i)){
        strcpy(theOutput[i].status, "Abundant");     
    }
    else{
        strcpy(theOutput[i].status, "Perfect");         
    }
}
for(int i=0; i<howMany; i++){
    printf("%4d",theOutput[i].linenumbers);
    printf(" is ");
    printf("%-10s  ", theOutput[i].status);
    for(int j=0; j<theOutput[i].sum; j++){
        printf("%s", arg3);
    }
    printf("\n");
}
}

int calculateDivisors(int n){
    int sum=0;
    for(int i=1; i<n; i++){
        if (n%i==0){
            sum+=i;                
        }
    }
    return sum;
}

