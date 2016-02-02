/*
Simple Betting Game
"Jack, Queen, King" - computer shuffles these cards
player has to guess the postion of queen.
if he wins, he takes 3*bet
if he looses, he looses the bet amount
player has $100 initially
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int cash = 100;

void Play(int bet)
{
   char C[3] = { 'J', 'Q', 'K' };

   printf("Shuffling ...\n");
   srand(time(NULL)); // seeding random number generator
   for (int i=0; i<5; i++)
   {
      int x = rand() % 3;
      int y = rand() % 3;
      int tmp = C[x];
      C[x] = C[y];
      C[y] = tmp;
      printf("x=%d y=%d\n", x, y);
   } 

   int playerGuess;
   printf("What's the postion of Queen - 1, 2, or 3 ? : ");
   scanf("%d", &playerGuess);

   if (C[playerGuess - 1] == 'Q')
   {
      cash += 3*bet;
      printf("You win! Result - %c %c %c Total cash = %d\n", 
         C[0], C[1], C[2], cash);
   }
   else
   {
      cash -= bet;
      printf("You Loose! Result - %c %c %c Total cash = %d\n", 
         C[0], C[1], C[2], cash);
   }
}


int main ()
{
   int bet;

   printf("Welcome to the virual casino\n");
   printf("Total cash = %d\n", cash);

   while (cash > 0)
   {
      printf("What's your bet? $");
      scanf("%d", &bet);
      
      if (bet == 0 || bet > cash)
         break;  // terminate

      Play(bet);
   }
   
   return 0;
}
