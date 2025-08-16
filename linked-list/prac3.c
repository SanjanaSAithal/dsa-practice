// Program to implement singly linked list
// head will point to the first node 
// functions return pointer to a node

#include <stdio.h>
#include <stdlib.h>

struct node {
    int key;
    struct node *link;
};
typedef struct node node_t;

node_t* insert_end(node_t*, int);
node_t* insert_head(node_t*, int);
node_t* delete_last(node_t*);
node_t* delete_first(node_t*);
void display(node_t*);
node_t* delete_node(node_t*, int);
node_t* delete_pos(node_t*, int);
node_t* insert_pos(node_t*, int, int);

int main() {
    node_t *head = NULL;
    int ch, n, pos;

    while (1) {
        display(head);
        printf("\n\n--- MENU ---");
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
                head = insert_end(head, n);
                break;

            case 2:
                display(head);
                break;

            case 3:
                printf("\nEnter the element to be inserted: ");
                scanf("%d", &n);
                head = insert_head(head, n);
                break;

            case 4:
                head = delete_last(head);
                break;

            case 5:
                head = delete_first(head);
                break;

            case 6:
                printf("\nEnter the element to be deleted: ");
                scanf("%d", &n);
                head = delete_node(head, n);
                break;

            case 7:
                printf("\nEnter the position: ");
                scanf("%d", &n);
                head = delete_pos(head, n);
                break;

            case 8:
                printf("\nEnter the value and position: ");
                scanf("%d %d", &n, &pos);
                head = insert_pos(head, n, pos);
                break;

            case 9:
                exit(0);
        }
    }
}

/* Insert at head */
node_t* insert_head(node_t *ptr, int x) {
    node_t *temp = (node_t*)malloc(sizeof(node_t));
    temp->key = x;
    temp->link = ptr;
    return temp;
}

/* Insert at end */
node_t* insert_end(node_t* ptr, int x) {
    node_t *temp = (node_t*)malloc(sizeof(node_t));
    temp->key = x;
    temp->link = NULL;

    if (ptr == NULL) {
        return temp;
    } else {
        node_t *pres = ptr;
        while (pres->link != NULL)
            pres = pres->link;
        pres->link = temp;
        return ptr;
    }
}

/* Display list */
void display(node_t *ptr) {
    if (ptr == NULL) {
        printf("\nEmpty list");
    } else {
        while (ptr != NULL) {
            printf("%d --> ", ptr->key);
            ptr = ptr->link;
        }
        printf("NULL");
    }
}

/* Delete last node */
node_t* delete_last(node_t *ptr) {
    if (ptr == NULL) {
        printf("Empty list..cannot delete");
        return ptr;
    }

    node_t *pres = ptr, *prev = NULL;

    while (pres->link != NULL) {
        prev = pres;
        pres = pres->link;
    }

    if (prev == NULL) { // only one node
        free(pres);
        return NULL;
    } else {
        prev->link = NULL;
        free(pres);
        return ptr;
    }
}

/* Delete first node */
node_t* delete_first(node_t *ptr) {
    if (ptr == NULL) {
        printf("Empty list..cannot delete");
        return NULL;
    } else {
        node_t *pres = ptr;
        ptr = pres->link;
        free(pres);
        return ptr;
    }
}

/* Delete node by value */
node_t* delete_node(node_t *ptr, int x) {
    if (ptr == NULL) {
        printf("Empty list..cannot delete..");
        return NULL;
    }

    node_t *pres = ptr, *prev = NULL;

    while ((pres != NULL) && (pres->key != x)) {
        prev = pres;
        pres = pres->link;
    }

    if (pres == NULL) {
        printf("Node not found.");
        return ptr;
    } else {
        if (prev == NULL) { // first node
            ptr = pres->link;
        } else {
            prev->link = pres->link;
        }
        free(pres);
        return ptr;
    }
}

/* Delete node by position */
node_t* delete_pos(node_t *ptr, int pos) {
    if (ptr == NULL) {
        printf("Empty list..cannot delete..");
        return NULL;
    }

    node_t *pres = ptr, *prev = NULL;
    int count = 1;

    while ((pres != NULL) && (count < pos)) {
        prev = pres;
        pres = pres->link;
        count++;
    }

    if (pres == NULL) {
        printf("Invalid position");
        return ptr;
    } else {
        if (prev == NULL) {
            ptr = pres->link;
        } else {
            prev->link = pres->link;
        }
        free(pres);
        return ptr;
    }
}

/* Insert node at a position */
node_t* insert_pos(node_t *ptr, int x, int pos) {
    node_t *temp = (node_t*)malloc(sizeof(node_t));
    temp->key = x;
    temp->link = NULL;

    node_t *pres = ptr, *prev = NULL;
    int count = 1;

    while ((pres != NULL) && (count < pos)) {
        prev = pres;
        pres = pres->link;
        count++;
    }

    if (pres != NULL) {
        if (prev == NULL) { // first position
            temp->link = pres;
            ptr = temp;
        } else {
            temp->link = pres;
            prev->link = temp;
        }
    } else {
        if (count == pos) { // insert after last node
            if (prev != NULL)
                prev->link = temp;
            else
                ptr = temp;
        } else {
            printf("Invalid position");
            free(temp);
        }
    }
    return ptr;
}
