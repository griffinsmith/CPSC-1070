#include <stdio.h>

int main()

{

   int values[10] = {-1, 14, -24, 6, 9, 2, -3, 4, 7, 3};

   char word[35] = {'T', 'h', 'i', 's', ' ', 'i', 's', ' ','g', 'o','i','n', 'g',' ', 't', 'o', ' ', 'b', 'e', ' ', 'a',' ', 'g', 'r', 'e', 'a','t', ' ','c', 'l', 'a','s', 's', '!'};

   int i = 0;

   int *pv0 = values;

   printf("*%i\n", *pv0);

   int *pv1 = pv0 + 3;

   printf("*%i\n", *pv1);

 

   char*pv2;

   pv2 = word;

   printf("%c\n", *pv2);

   printf("%c\n", *(pv2 + 3));

 

   char *pv4 = word;

   for (i=0; i<3; i++) {

      printf("%c", *pv4);

      pv4 += 3;

   }

   printf("\n%s\n", word);

 

   return(0);

}

