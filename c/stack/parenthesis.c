#include <stdio.h>

char open_ch[] = { '(', '{', '[' };
char close_ch[] = { ')', '}', ']' };

int isOpenCh(char c)
{
   printf("In isOpenChar() c = %c", c);
   char open_ch[] = { '(', '{', '[' };

   for (int i=0; i<3; i++)
   {
      if (c == open_ch[i])
      {
         printf(" : returning %d\n", i);
         return i;
      }
   }

   printf(" : returning -1\n");
   return -1;
}

int isCloseCh(char c)
{
   printf("In isCloseChar() c = %c", c);
   char close_ch[] = { ')', '}', ']' };

   for (int i=0; i<3; i++)
   {
      if (c == close_ch[i])
      {
         printf(" : returning %d\n", i);
         return i;
      }
   }

   printf(" : returning -1\n");
   return -1;
}

int CheckBalancedParenthesis(char* s)
{
   int st[10] = { 0};
   int currIdx = -1;

   //int n = 0;

   printf("In CheckBalancedParenthesis : s = %s\n", s);

   while (*s != '\0')
   {
      int r = isOpenCh(*s);
      int x = isCloseCh(*s);

      printf("r=%d  x=%d\n", r, x);      


      if (r > -1) 
      {
         st[++currIdx] = r;     // push to stack
      }
      else if (x > -1)
      {
         if (st[currIdx] == x)
         {
            st[currIdx--] = 0;  // pop stack
         }
         else
         {
            printf(" imbalanced : currIdx = %d\n", currIdx);
            return -1;
         }
      }

      s++;
//      if ((n++) > 5)
//         break;
   }

   printf(" eos : currIdx = %d\n", currIdx);
   if (currIdx == -1)
   {
      printf("balanced!  ");
      return 0;
   }
   else
   {
      printf("Imbalanced! ");
      return -1;
   }
}

int main()
{
   char str[10] = "[]";

   printf("Please enter a string : ");
   scanf("%s", str);
   
   printf("str = %s\n", str);

   int result = CheckBalancedParenthesis(str);
   printf("result = %d\n", result);
}
