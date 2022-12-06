/*
Implement Open hashing and Closed hashing techniques (of integers) (in C/C++). In closed hashing 
if collision occurs use any of the 3 techniques (Linear, quadratic and Double hashing). 
Turn in 2 programs.
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct NODE
{
      int x;
      struct NODE *next;
} NODE;

NODE *a[MAX];

void insert()
{
      int d;
      printf("Enter the element to be inserted : ");
      scanf("%d", &d);
      int x = d % MAX;
      NODE *newnode = (NODE *)malloc(sizeof(NODE));
      newnode->x = d;
      newnode->next = NULL;
      if (a[x] == NULL)
            a[x] = newnode;
      else
      {
            NODE *ptr;
            ptr = a[x];
            int flag = 1;
            while (ptr->next != NULL)
            {
                  if (ptr->x == d)
                        flag = 0;
                  ptr = ptr->next;
            }
            if (ptr->x == d)
                  flag = 0;
            if (flag == 1)
                  ptr->next = newnode;
            else
                  printf("Element already exists !");
      }
}
void search()
{
      printf("Enter the element you want to search :");
      int d;
      scanf("%d", &d);
      int x = d % MAX;
      NODE *ptr = a[x];
      int flag = 0;
      while (ptr != NULL)
      {
            if (ptr->x == d)
                  flag = 1;
            ptr = ptr->next;
      }
      if (flag == 1)
            printf("Element present");
      else
            printf("Element not found");
}
void display()
{
      for (int i = 0; i < MAX; i++)
      {
            NODE *ptr = a[i];
            printf("Index %d - ", i);
            while (ptr != NULL)
            {
                  printf("%d, ", ptr->x);
                  ptr = ptr->next;
            }
            printf("\n");
      }
}
int main()
{
      for (int i = 0; i < MAX; i++)
            a[i] = NULL;
      printf("1. Insert\n2. Search\n3. Display\n4. Exit");
      while (1)
      {
            printf("\nEnter your choice :");
            int ch;
            scanf("%d", &ch);
            switch (ch)
            {
            case 1:
                  insert();
                  break;
            case 2:
                  search();
                  break;
            case 3:
                  display();
                  break;
            case 4:
                  exit(1);
            default:
                  printf("Wrong choice\n");
            }
      }
}
