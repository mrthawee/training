#ifndef __NODE_H__
#define __NODE_H__

struct node {
   int          data;
   struct node *next;
};

struct node* BuildOneTwoThree();

#endif
