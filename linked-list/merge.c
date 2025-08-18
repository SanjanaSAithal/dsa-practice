#include <stdio.h>
#include <stdlib.h>

struct node
{
    int key;
    struct node *link;
};

typedef struct node node_t;

struct list
{
    node_t *head;
};

typedef struct list list_t;

void init_list(list_t *);
void insert_order(list_t *, int);
void display(list_t *);
void create_list(list_t *);
void merge(list_t *, list_t *, list_t *);
void insert_end(list_t *, int);

int main()
{
    list_t l1, l2, l3;
    init_list(&l1);
    init_list(&l2);
    init_list(&l3);

    printf("\nCreating List one..\n");
    create_list(&l1);
    printf("displaying List one..\n");
    display(&l1);
    printf("\nCreating List Two..\n");
    create_list(&l2);
    printf("displaying List Two..\n");
    display(&l2);
    printf("\nMerging both the Lists..\n");
    merge(&l1, &l2, &l3);
    printf("\ndisplaying merged list..\n");
    display(&l3);
}  

void init_list(list_t *ptr_list)
{
    ptr_list->head = NULL;
}

void insert_order(list_t *ptr_list, int x)
{
    node_t *temp, *pres, *prev;
    temp = (node_t *)malloc(sizeof(node_t));
    temp->key = x;
    temp->link = NULL;

    if (ptr_list->head == NULL)
    {
        ptr_list->head = temp;
    }
    else
    {
        pres = ptr_list->head;
        prev = NULL;
        while ((pres != NULL) && (x > pres->key))
        {
            prev = pres;
            pres = pres->link;
        }
        if (pres == NULL)
        {
            prev->link = temp;
        }
        else
        {
            if (prev == NULL)
            {
                temp->link = pres;
                ptr_list->head = temp;
            }
            else
            {
                temp->link = pres;
                prev->link = temp;
            }
        }
    }
}

void display(list_t *ptr_list)
{
    node_t *pres;
    if (ptr_list->head == NULL)
    {
        printf("Empty List..\n");
    }
    else
    {
        pres = ptr_list->head;
        while (pres != NULL)
        {
            printf("%d-> ", pres->key);
            pres = pres->link;
        }
    }
}

void create_list(list_t *ptr_list)
{
    int x;
    while (1)
    {
        printf("\nEnter the Element..");
        scanf("%d", &x);
        if (x == 0)
        {
            break;
        }
        insert_order(ptr_list, x);
    }
}

void merge(list_t *ptr_list1, list_t *ptr_list2, list_t *ptr_list3)
{
    node_t *p, *q;

    p = ptr_list1->head;
    q = ptr_list2->head;

    while ((p != NULL) && (q != NULL))
    {
        if (p->key < q->key)
        {
            insert_end(ptr_list3, p->key);
            p = p->link;
        }
        else
        {
            insert_end(ptr_list3, q->key);
            q = q->link;
        }
    }
    if (p == NULL)
    {
        while (q != NULL)
        {
            insert_end(ptr_list3, q->key);
            q = q->link;
        }
    }
    else
    {
        while (p != NULL)
        {
            insert_end(ptr_list3, p->key);
            p = p->link;
        }
    }
}

void insert_end(list_t *ptr_list, int data)
{
    node_t *pres, *temp;
    temp = (node_t *)malloc(sizeof(node_t));
    temp->key = data;
    temp->link = NULL;

    if (ptr_list->head == NULL)
    {
        ptr_list->head = temp;
    }
    else
    {
        pres = ptr_list->head;
        while (pres->link != NULL)
        {
            pres = pres->link;
        }
        pres->link = temp;
    }
}