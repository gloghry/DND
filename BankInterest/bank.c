/* By Garett Loghry
   02/15/2024

   Flags to Implement:
      -h    display [h]elp message
      -a    [a]dd a player to the "database" (its just a file)
      -d    make a [d]epost
      -D    [D]elete a player
      -x    same as -D
      -c    [c]hange the interest rate
      -i    add [i]nterest for that session
      -f    select a different [f]ilename other than std
      -o    change [o]utput file from being default or specified with -f

   Standard interest is set to 1% or 0.001
*/

#include <stdio.h>
#include <unistd.h>

#define BUFF_SIZE 4096
#define DEFAULT_DB_NAME "bankDatabase.txt"
#define DEFAULT_INTEREST 0.001

#ifndef true
#define true 1
#endif

#ifndef false
#define false 0
#endif

// No reason not to store this here, it's a pain to send to each func
// Should always be initalized because it's set first thing in prog
char *progName;
char *filename = DEFAULT_DB_NAME;
double interest = DEFAULT_INTEREST;

void pUsage(void) {
   printf("Usage: %s [OPTION]...]\n", progName);
   printf("Interact with the Bank\n");
}

void pBankStats(FILE *stream) {
   char str[BUFF_SIZE], *status;

   do {
      status = fgets(str, BUFF_SIZE, stream);
      if (status != NULL) printf("%s", str);
   } while (status != NULL);

}

int main(int argc, char *argv[]) {
   progName = argv[0];

   /* No arguments supplied
      Print the database if it exists
      Then exit regardless */
   if (argc == 1) {
      if (access(filename, F_OK) == 0) printf("File exists\n");
      else printf("File does not exit\n");
   } 
}
