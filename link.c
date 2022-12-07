// C implementation of Linked List of integers
#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} LIST;

LIST *head;

void makenull()
{
    head = NULL;
}
void insert(int x)
{
    LIST *p, *q, *newNode;
    p = q = head;

    newNode = (LIST *)((malloc(sizeof(LIST))));
    newNode->data = x;
    while (p != NULL && x > p->data)
    {
        q = p;
        p = p->next;
    }
    if (p == head) // first element
        head = newNode;
    else
        q->next = newNode;
    newNode->next = p;
}
void del(int x)
{
    LIST *p, *q;
    p = q = head;
    while (p != NULL && p->data != x)
    {
        q = p;
        p = p->next;
    }
    if (p == NULL)
    {
        printf("Not found.");
        getch();
    }
    else
    {
        if (p == head) // if first element
            head = p->next;
        else
            q->next = p->next;
        free(p);
    }
}
void display()
{
    LIST *p;
    int i = 1;
    p = head;
    system("cls");
    printf("The list contains...\n");
    while (p != NULL)
    {
        printf("%d.) %d\n", i++, p->data);
        p = p->next;
    }
    system("pause");
}
int menu()
{
    int op;
    system("cls");
    printf("Menu\n");
    printf("1. Insert\n");
    printf("2. Delete\n");
    printf("3. Display\n");
    printf("4. Exit\n");
    printf("Select(1-4): ");
    scanf("%d", &op);
    return (op);
}
int main()
{
    int x;
    makenull(); // initialize the list L
    while (1)
    {
        switch (menu())
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
            printf("1 to 4 only.");
            getch();
        }
    }
}
