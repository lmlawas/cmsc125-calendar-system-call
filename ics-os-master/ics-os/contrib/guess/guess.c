

#include "../../sdk/dexsdk.h"

int main() 
{
   int num_input, num_random;
   FILE *fp;
   char *s;

   srand(100);

   num_random = rand() % 101;

   do{
   	printf("\nGuess number from 0-100: ");
   	fgets(s, 3, stdin);
   	num_input = atoi(s);

   	if( num_input == num_random ) break;
   	else printf("\nTry again.");

   }while( num_input != num_random );
   return 0;
}