#include <stdio.h>
#include <stdlib.h>

struct node {
    int key;
    struct node *link;
};
typedef struct node node_t;

void insert_end(node_t **, int);
void insert_head(node_t **, int);
void delete_last(node_t **);
void delete_first(node_t **);
void display(node_t *);
void delete_node(node_t **, int);
void delete_pos(node_t **, int);
void insert_pos(node_t **, int, int);

int main() {
    int ch, n, pos;
    node_t *head = NULL;

    while (1) {
        display(head);
        printf("\n1. Insert at end");
        printf("\n2. Display");
        printf("\n3. Insert at head");
        printf("\n4. Delete last");
        printf("\n5. Delete first");
        printf("\n6. Delete node by value");
        printf("\n7. Delete by position");
        printf("\n8. Insert at a position");
        printf("\n9. Exit\n");

        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("\nEnter the element to be inserted: ");
                scanf("%d", &n);
                insert_end(&head, n);
                break;

            case 2:
                display(head);
                break;

            case 3:
                printf("\nEnter the element to be inserted: ");
                scanf("%d", &n);
                insert_head(&head, n);
                break;

            case 4:
                delete_last(&head);
                break;

            case 5:
                delete_first(&head);
                break;

            case 6:
                printf("\nEnter the element to be deleted: ");
                scanf("%d", &n);
                delete_node(&head, n);
                break;

            case 7:
                printf("\nEnter the position: ");
                scanf("%d", &n);
                delete_pos(&head, n);
                break;

            case 8:
                printf("\nEnter the value and position: ");
                scanf("%d %d", &n, &pos);
                insert_pos(&head, n, pos);
                break;

            case 9:
                exit(0);
        }
    }
}

void insert_head(node_t **ptr, int x){
    node_t *temp;
    temp=(node_t*)malloc(sizeof(node_t));
    temp->key=x;
    temp->link=NULL;
    if(*ptr==NULL){
        *ptr=temp;
    }
    else{
        temp->link=*ptr;
        *ptr=temp;
    }
}

void insert_end(node_t **ptr, int x){
    node_t *temp, *pres;
    temp=(node_t*)malloc(sizeof(node_t));
    temp->key=x;
    temp->link=NULL;
    if(*ptr==NULL){
        *ptr=temp;
    }
    else{
        pres=*ptr;
        while(pres->link!=NULL){
            pres=pres->link;
        }
        pres->link=temp;
    }
}
void delete_last(node_t **ptr){
    node_t *pres, *prev;
    if(*ptr==NULL){
        printf("Empty list");
    }
    else{
        pres=*ptr;
        prev=NULL;
        while(pres->link!=NULL){
            prev=pres;
            pres=pres->link;
        }
        if(prev==NULL){
            *ptr=NULL;
        }
        else{
            prev->link=NULL;
        }
        free(pres);
    }
}
void delete_first(node_t **ptr){
    node_t *pres;
    if(*ptr=NULL){
        printf("EMpty list");
    }
    else{
        pres=*ptr;
        *ptr=pres->link;
        free(pres);
    }
}
void delete_node(node_t **ptr, int x){
    node_t *pres, *prev;
    if(*ptr==NULL){
        printf("Empty list");
    }
    else{
        prev=NULL;
        pres=*ptr;
        while((pres!=NULL)&&(pres->key!=x)){
            prev=pres;
            pres=pres->link;
        }
        if(pres==NULL){
            printf("Invalid element");
        }
        else{
            if(prev==NULL){
                *ptr=pres->link;
            }
            else{
                prev->link=pres->link;
            }
            free(pres);
        }
    }
}

void delete_pos(node_t **ptr, int pos){
    node_t *pres, *prev;
    int count;
    if(*ptr==NULL){
        printf("Empty list");
    }
    else{
        prev=NULL;
        pres=*ptr;
        count=1;
        while((pres!=NULL)&& (count<pos)){
            prev=pres;
            pres=pres->link;
            count++;
        }
        if(pres==NULL){
            printf("Invalid position");
        }
        else{
            if(prev==NULL){
                *ptr=pres->link;
            }
            else{
                prev->link=pres->link;
            }
            free(pres);
        }
    }
}

void insert_pos(node_t **ptr, int x, int pos){
    node_t *temp, *pres, *prev;
    int count;
    temp=(node_t*)malloc(sizeof(node_t));
    temp->key=x;
    temp->link=NULL;
    
    prev=NULL;
    pres=*ptr;
    count=1;
    while((pres!=NULL)&& (count<pos)){
        prev=pres;
        pres=pres->link;
        count++;
    }
    if(pres!=NULL){
        if(prev==NULL){
            temp->link=pres;
            *ptr=temp;
        }
        else{
            temp->link=pres;
            prev->link=temp;
        }
    }
    else{
        if(count==pos){
            prev->link=temp;
        }
        else{
            printf("Invalid position");
        }
    }
}

void display(node_t *ptr){
    node_t *pres;
    if(ptr==NULL){
        printf("Empty list");
    }
    else{
        pres=ptr;
        while(pres!=NULL){
            printf("%d --> ", pres->key);
            pres=pres->link;
        }
    }
}