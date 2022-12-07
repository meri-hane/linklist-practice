/*
Implement Open hashing and Closed hashing techniques (of integers) (in C/C++). In closed hashing
if collision occurs use any of the 3 techniques (Linear, quadratic and Double hashing).
Turn in 2 programs.
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct node
{
      int data;
      struct node *next;
} NODE;

NODE *chain[MAX];

void init()
{
      for (int i = 0; i < MAX; i++)
            chain[i] = NULL;
}

void insert(int value)
{
      int key = value % MAX;
      NODE *p, *q, *newNode;
      p = q = chain[key];
      newNode = (NODE *)malloc(sizeof(NODE));
      newNode->data = value;
      newNode->next = NULL;

      while (p != NULL && value > p->data)
      {
            q = p;
            p = p->next;
      }
      // check if chain[key] is empty
      if (p == chain[key])
            chain[key] = newNode;
      // collision
      else
      {
            // add the node at the end of chain[key].
            NODE *temp = chain[key];
            while (temp->next)
            {
                  temp = temp->next;
            }

            temp->next = newNode;
      }
}

/*
 * return 1, successful delete
 * return 0, value not found
 */
int del(int value)
{
      int key = value % MAX;
      NODE *p, *q;
      p = q = chain[key];

      if (p != NULL)
      {
            if (chain[key]->data == value)
            {
                  p = chain[key];
                  chain[key] = chain[key]->next;
                  free(p);
                  return 1;
            }
            else
            {
                  while (chain[key]->next)
                  {
                        if (chain[key]->next->data == value)
                        {
                              p = chain[key]->next;
                              chain[key]->next = chain[key]->next->next;
                              free(p);
                              return 1;
                        }
                        chain[key] = chain[key]->next;
                  }
            }
      }

      printf("Not found.\n");

      system("pause");
}

void display()
{
      printf("\n Key\t   Value\n");
      for (int i = 0; i < MAX; i++)
      {
            NODE *temp = chain[i];

            printf("Bucket %d - ", i);
            while (temp != NULL)
            {
                  printf("%d-->", temp->data);
                  temp = temp->next;
            }
            printf("NULL\n");
      }
}

int main()
{
      // init array of list to NULL
      int x;
      init();
      printf("1. Insert\n2. Search\n3. Display\n4. Exit");
      while (1)
      {
            printf("\nEnter your choice: ");
            int ch;
            scanf("%d", &ch);
            switch (ch)
            {
            case 1:
                  system("cls");
                  printf("Insert Mode\n");
                  printf("Input x: ");
                  scanf("%d", &x);
                  insert(x);
                  break;
            case 2:
                  system("cls");
                  printf("Delete Mode\n");
                  printf("Input x: ");
                  scanf("%d", &x);
                  del(x);
                  break;
            case 3:
                  display();
                  break;
            case 4:
                  exit(0);
            default:
                  printf("Invalid\n");
            }
      }
}
