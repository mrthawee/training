#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "util.h"

int main() {
   struct node *list = BuildOneTwoThree();

   PrintList(list, "OneTwoThree");
}
