//
//  reader.c
//
//  Created by Donald House on 9/30/19.
//  For CPSC 1070 Lab Project on 3/2/20
//  Clemson University
//

#include <stdio.h>
#include <string.h>
#include <ctype.h>
int carrot, spinach, potato, cauliflower, broccoli, eggplant=0;

void removePunctuation(const char *str, char *cleanstr){
  int i, j;
  char ch;
  
  for(i = 0, j = 0; str[i] != '\0'; i++){
    ch = tolower(str[i]);
    if(isalpha(ch))
      cleanstr[j++] = ch;
  }
  cleanstr[j] = '\0';
}

int main(int argc, char *argv[]){
  FILE *infile;
  char instring[1000];
  char cleanstring[1000];

  if(argc != 2){
    printf("usage: reader <filename>\n");
    return 1;
  }
  
  infile = fopen(argv[1], "r");
  if(infile == NULL){
    printf("cannot open file %s\n", argv[1]);
    return 2;
  }
  
  while(fscanf(infile, "%s", instring) == 1){
    removePunctuation(instring, cleanstring);
    if (strcmp(cleanstring, "carrot")==0){
      carrot++;
    } else if (strcmp(cleanstring, "potato")==0){
      potato++;
    }  else if (strcmp(cleanstring, "spinach")==0){
      spinach++;
    }else if (strcmp(cleanstring, "cauliflower")==0){
      cauliflower++;
    }else if (strcmp(cleanstring, "broccoli")==0){
      broccoli++;
    }else if (strcmp(cleanstring, "eggplant")==0){
      eggplant++;
    }
  }
  printf("%d carrot\n", carrot);
  printf("%d potato\n", potato);
  printf("%d spinach\n", spinach);
  printf("%d cauliflower\n", cauliflower);
  printf("%d broccoli\n", broccoli);
  printf("%d eggplant\n", eggplant); 
  return 0;
}
