/* By Garett Loghry
   02/15/2024

   Flags to Implement:
      -h    display [h]elp message.

      -a    [a]dd a player to the "database" (its just a file)/
            Adding player info should be supplied in this format:

            Player_Name PC_Name Platinum Gold Electrum Silver Copper

      -d    make a [d]epost
            Depositing should be done by one of two ways. First, is by
            using either the players real name, or the PC name, followed
            by a string of 5 integers. If less than 5 are supplied, a warning
            should be supplied to the DM and no changes will occur. Second,
            using the players real name or the PC name, we will parse an
            input in the form of %d[denomination]. For example, 10g would be
            10 Gold added to the player. If player or PC name not found, or
            if the denomination isn't correct, exit. Uppercase like 10P will
            be converted to lowercase to match DB.

            -d [Player_Name || PC_Name] Platinum Gold Electrum Silver Copper
            OR
            -d [Player_Name || PC_Name] %dp %dg %de %ds %dc

      -D    [D]elete a player
            Remove a player from the bank. Should take either a real name,
            or a PC name.

            -D [Player_Name || PC_Name]

      -x    same as -D

            -x [Player_Name || PC_Name]

      -c    [c]hange the interest rate
            Two possible formats, one is by using %, like 10%, another is
            by using a float style 0.10. Using a raw int shouldn't change
            anything, and the program will exit.

            -c 10%
            OR
            -c 0.10

      -i    add [i]nterest for that session
            Add the current interest for that session to each players bank
            total.

      -f    select a different [f]ilename other than std

            -f filename

      -o    change [o]utput file from being default or specified with -f
            -o filename

      The order we should look for flags is
         hfadDxio

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
   printf("Usage: %s [OPTION]... \n", progName);
   printf("Interact with the Bank\n");
}

void pBankStats(FILE *stream) {
   char str[BUFF_SIZE], *status;

   do {
      status = fgets(str, BUFF_SIZE, stream);
      if (status != NULL) printf("%s", str);
   } while (status != NULL);

}

void pError(char *errmsg) {
   printf("ERROR: ");
   printf("%s\n\n", errmsg);
   pUsage();
}

int main(int argc, char *argv[]) {
   progName = argv[0];
   FILE *stream = NULL;
   int optind;

   /* No arguments supplied
      Print the database if it exists
      Then exit regardless */
   if (argc == 1) {
      if (access(filename, F_OK) == 0) {
         if ((stream = fopen(filename, "r")) != NULL) {
            pBankStats(stream);
            fclose(stream);
         } else {
            pError("Couldn't open the file. Make sure we have permission.");
         }
      } else {
         pError("Cannot print the database as it doesn't exist yet.");
      }
      
      return 0;
   } 

   /* Process the flags that were given
      See legal arguments above */
   //while ((optind = getopt(argc, argv, 
}
