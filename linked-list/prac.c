#include <stdio.h>
#include<stdlib.h>

struct node{
    int key;
    struct node *link;
};
typedef struct node node_t;

struct list{
    node_t *head;
};
typedef struct list list_t;

// Function Prototypes
void init_list(list_t*);
void insert_end(list_t*, int);
void insert_head(list_t*, int);
void delete_last(list_t*);
void delete_first(list_t*);
void display(list_t*);
void delete_node(list_t *,int);
void delete_pos(list_t * , int);
void insert_pos(list_t * , int,int);

int main()
{
    list_t l;
    int ch, n, pos;
    init_list(&l);
    //l.head=NULL;

    while(1)
    {
        display(&l);
        printf("\n\n1. Insert at end");
        printf("\n2. Display");
        printf("\n3. Insert at head");
        printf("\n4. Delete last");
        printf("\n5. Delete first");
        printf("\n6. Delete a specific node");
        printf("\n7. Delete from a position");
        printf("\n8. Insert at a position");
        printf("\n9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                printf("\nEnter the element to be inserted: ");
                scanf("%d", &n);
                insert_end(&l, n);
                break;

            case 2:
                display(&l);
                break;

            case 3:
                printf("\nEnter the element to be inserted: ");
                scanf("%d", &n);
                insert_head(&l, n);
                break;

            case 4:
                delete_last(&l);
                break;

            case 5:
                delete_first(&l);
                break;

            case 6:
                printf("\nEnter the element to be deleted: ");
                scanf("%d", &n);
                delete_node(&l, n);
                break;

            case 7:
                printf("\nEnter the position: ");
                scanf("%d", &n);
                delete_pos(&l, n);
                break;

            case 8:
                printf("\nEnter the value and position: ");
                scanf("%d %d", &n, &pos);
                insert_pos(&l, n, pos);
                break;

            case 9:
                exit(0);
            
            default:
                printf("\nInvalid choice! Please try again.");
                break;
        }
    }
    return 0; // Good practice to have a return statement
}

void init_list(list_t *ptr_list){
    ptr_list->head= NULL;
}

void insert_head(list_t *ptr_list, int x){
    node_t *temp;
    temp=(node_t*)malloc(sizeof(node_t));
    temp->key=x;
    temp->link=NULL;
    if(ptr_list->head==NULL){
        ptr_list->head=temp;
    }
    else{
        temp->link=ptr_list->head;
        ptr_list->head=temp;
    }
}

void insert_end(list_t *ptr_list, int x){
    node_t *temp, *pres;
    temp=(node_t*)malloc(sizeof(node_t));
    temp->key=x;
    temp->link=NULL;
    if(ptr_list->head==NULL){
        ptr_list->head=temp;
    }
    else{
        pres=ptr_list->head;

        while(pres->link!=NULL){
            pres=pres->link;
        }
        pres->link=temp;
    }
}

void delete_last(list_t *ptr_list){
    node_t *pres, *prev;
    if(ptr_list->head==NULL){
        printf("Empt list");
    }
    else{
        pres=ptr_list->head;
        prev=NULL;
        while(pres->link!=NULL){
            prev=pres;
            pres=pres->link;
        }
        if(prev==NULL){
            ptr_list->head=NULL;
        }
        else{
            prev->link=NULL;
        }
        free(pres);
    }
}
void delete_first(list_t *ptr_list){
    node_t *pres;
    if(ptr_list->head==NULL){
        printf("Empty list");
    }
    else{
        pres=ptr_list->head;
        ptr_list->head=pres->link;
        free(pres);
    }
}
void display(list_t *ptr_list){
    node_t *pres;
    if(ptr_list->head==NULL){
        printf("List is empty");
    }
    else{
        pres=ptr_list->head;
        while(pres!=NULL){
            printf("%d -->", pres->key);
            pres=pres->link;
        }
        printf("NULL");
    }
}

void delete_node(list_t *ptr_list, int x){
    node_t *pres, *prev;
    if(ptr_list->head==NULL){
        printf("empty list");
    }
    else{
        pres=ptr_list->head;
        prev=NULL;
        while((pres!=NULL) &&(pres->key !=x)){
            prev=pres;
            pres=pres->link;
        }
        if(pres==NULL){
            printf("elemnt not found");
        }
        else{
            if(prev==NULL){
                ptr_list->head=NULL;
            }
            else{
                prev->link=pres->link;
            }
            free(pres);
        }       
    }
}
void delete_pos(list_t *ptr_list, int pos){
    node_t *pres, *prev;
    int count;
    if(ptr_list->head==NULL){
        printf("Empty list");
    }
    else{
        pres=ptr_list->head;
        prev=NULL;
        count=1;
        while((pres!=NULL) &&(count<pos)){
            prev=pres;
            pres=pres->link;
            count++;
        }
        if(pres==NULL){
            printf("Invalid position");
        }
        else{
            if(prev==NULL){
                ptr_list->head=pres->link;
            }
            else{
                prev->link=pres->link;
            }
            free(pres);
        }
    }
}

void insert_pos(list_t *ptr_list,int x, int pos){
    node_t *temp, *pres, *prev;
    int count;
    temp=(node_t*)malloc(sizeof(node_t));
    temp->key=x;
    temp->link=NULL;
    count=1;
    prev=NULL;
    pres=ptr_list->head;

    while((pres!=NULL)&&(count<pos)){
        prev=pres;    
        pres=pres->link;
        count++;
    }
    if(pos<=0 || pos> count+1){
        printf("Invalid position");
        free(temp);
        return;
    }

    if(prev==NULL){
        temp->link=ptr_list->head;
        ptr_list->head=temp;
    }
    else{
        temp->link=pres->link;
        pres->link=temp;
    }
        
}

