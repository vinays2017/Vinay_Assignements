#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#pragma warning (disable:4996)

struct node
{
    int data;
    struct node* next;
    struct node* prev;
};
struct node* start;
void insertbegin()
{
    struct node* ptr;
    int data;
    ptr = (struct node*)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("memory leak");
    }
    else {

        printf("enter the element\n");
        scanf("%d", &data);
        if (start == NULL)
        {
            ptr->next = NULL;
            ptr->prev = NULL;
            ptr->data = data;
            start = ptr;
        }
        else{
            ptr->data = data;
            ptr->next = start;
            ptr->prev = NULL;
            //start->prev = ptr;
            start = ptr;
        }
        
    }
}
void insertend()
{
    struct node* ptr;
    struct node* temp;
    int data;
    ptr = (struct node*)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("memory leak");
    }
    else {

        printf("enter the element\n");
        scanf("%d", &data);
        ptr->data = data;
        if (start == NULL)
        {
            ptr->next = NULL;
            ptr->prev = NULL;
            start = ptr;
        }
        else {
            temp = start;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = ptr;
            ptr->prev = temp;
            ptr->next = NULL;
        }

    }
}
void insertmiddle()
{
    struct node* ptr, * temp;
    int item, loc, i;
    ptr = (struct node*)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("\n OVERFLOW");
    }
    else
    {
        temp = start;
        printf("Enter the location");
        scanf("%d", &loc);
        for (i = 0; i < loc; i++)
        {
            temp = temp->next;
            if (temp == NULL)
            {
                printf("\n There are less than %d elements", loc);
                return;
            }
        }
        printf("Enter value");
        scanf("%d", &item);
        ptr->data = item;
        ptr->next = temp->next;
        ptr->prev = temp;
        temp->next = ptr;
        temp->next->prev = ptr;
        printf("\nnode inserted\n");
    }
}
void deletebegin()
{
    struct node* ptr;
    if (start == NULL)
    {
        printf("\n UNDERFLOW");
    }
    else if (start->next == NULL)
    {
        start = NULL;
        free(start);
        printf("\nnode deleted\n");
    }
    else
    {
        ptr = start;
        start = start->next;
        start->prev = NULL;
        free(ptr);
        printf("\nnode deleted\n");
    }
}
void deleteend()
{
    struct node* ptr;
    if (start == NULL)
    {
        printf("\n UNDERFLOW");
    }
    else if (start->next == NULL)
    {
        start = NULL;
        free(start);
        printf("\nnode deleted\n");
    }
    else
    {
        ptr = start;
        if (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->prev->next = NULL;
        free(ptr);
        printf("\nnode deleted\n");
    }
}
void deletemiddle()
{
    struct node* ptr, * temp;
    int val;
    printf("\n Enter the data after which the node is to be deleted : ");
    scanf("%d", &val);
    ptr = start;
    while (ptr->data != val)
        ptr = ptr->next;
    if (ptr->next == NULL)
    {
        printf("\nCan't delete\n");
    }
    else if (ptr->next->next == NULL)
    {
        ptr->next = NULL;
    }
    else
    {
        temp = ptr->next;
        ptr->next = temp->next;
        temp->next->prev = ptr;
        free(temp);
        printf("\nnode deleted\n");
    }
}
void display()
{
    struct node* temp;
    if (start == NULL)
    {
        printf("no elements found\n");
    }
    else
    {
        temp = start;
        while(temp!= NULL)
        {
            printf("elements are %d->",temp->data);
            temp = temp->next;
        }
    }
}
int main()
{
    int choice = 0;
    while (1) {
        printf("select the choice from the list\n");
        printf("1.insert at begin\n2.insert at end\n3.insert at middle\n4.delete from begin\n5.delete from end\n6.delete from middle\n7.display data\n8.Quit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insertbegin();
            break;
        case 2:
            insertend();
            break;
        case 3:
            insertmiddle();
            break;
        case 4:
            deletebegin();
            break;
        case 5:
            deleteend();
            break;
        case 6:
            deletemiddle();
            break;
        case 7:
            display();
            break;
        case 8:
            exit(0);
            break;
        default:
            printf("Please enter valid choice..");
        }
    }
}
