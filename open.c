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

NODE *head[MAX];

void insert();
void search();
void display();

void insert()
{
      int d;
      printf("Enter the element to be inserted: ");
      scanf("%d", &d);
      int x = d % MAX;
      NODE *newnode = (NODE *)malloc(sizeof(NODE));
      newnode->data = d;
      newnode->next = NULL;
      if (head[x] == NULL)
            head[x] = newnode;
      else
      {
            NODE *ptr;
            ptr = head[x];
            int flag = 1;
            while (ptr->next != NULL)
            {
                  if (ptr->data == d)
                        flag = 0;
                  ptr = ptr->next;
            }
            if (ptr->data == d)
                  flag = 0;
            if (flag == 1)
                  ptr->next = newnode;
            else
                  printf("Element already exists!");
      }
}

void search()
{
      printf("Enter the element you want to search: ");
      int d;
      scanf("%d", &d);
      int x = d % MAX;
      NODE *ptr = head[x];
      int flag = 0;
      while (ptr != NULL)
      {
            if (ptr->data == d)
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
      printf("\n");
      for (int i = 0; i < MAX; i++)
      {
            NODE *ptr = head[i];
            printf("Bucket %d - ", i);
            while (ptr != NULL)
            {
                  printf("%d, ", ptr->data);
                  ptr = ptr->next;
            }
            printf("\n");
      }
}
int main()
{
      for (int i = 0; i < MAX; i++)
            head[i] = NULL;
      printf("1. Insert\n2. Search\n3. Display\n4. Exit");
      while (1)
      {
            printf("\nEnter your choice: ");
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
                  printf("Invalid\n");
            }
      }
}
