#include <stdio.h>

typedef struct list_t {
    int value;
    struct list_t *next;
} *list_p;

// prints the elements of the list
void print_list(list_p list) {
    printf("list: ");
    while (list != NULL) {
        printf("%d ", list->value);
        list = list->next;
    }
    printf("\n");
}

// inserts a new element with the specified value 
// after some existing element and returns the head of the list
list_p insert_node(list_p *head, int value, list_p node) {
    if (*head == NULL) { // empty list
        *head = (list_p) malloc(sizeof(struct list_t));
        (*head)->value = value;
        (*head)->next = NULL;
    } else {
        list_p cur = *head;
        while (cur->next != NULL && cur != node) {
            cur = cur->next;
        }
        if (cur != node) {
            printf("Failed to insert a node: no existing element!\n");
            return;
        }
        list_p tmp = cur->next;
        cur->next = (list_p) malloc(sizeof(struct list_t));
        cur->next->next = tmp;
        cur->next->value = value;
    }
}

// deletes the specified element
list_p delete_node(list_p *head, list_p node) {
    if (node == NULL) {
        printf("Failed to delete a node: the node is NULL!\n");
        return;
    }
    if (*head == NULL) { // empty list
        printf("Failed to delete a node: the list is empty!\n");
        return;
    } else if (*head == node) { // delete head
        list_p tmp = *head;
        *head = (*head)->next;
        free(tmp);
    } else {
        list_p cur = *head;
        while (cur->next != NULL && cur->next != node) {
            cur = cur->next;
        }
        if (cur->next != node) {
            printf("Failed to delete a node: no such node!\n");
            return;
        }
        list_p tmp = cur->next;
        cur->next = cur->next->next;
        free(tmp);
    }
}

int main() {
    list_p head = NULL; // empty list
    print_list(head);
    insert_node(&head, 1, NULL); // the first element can be added with any 3rd argument
    print_list(head);
    insert_node(&head, 2, NULL); // but otherwise it is forbidden
    print_list(head);
    insert_node(&head, 2, head); // inserting the element after the head (the first element)
    print_list(head);
    insert_node(&head, 3, head); // inserting the element after the head but before the last element
    print_list(head);
    delete_node(&head, head->next); // delete the middle element
    print_list(head);
    delete_node(&head, head); // delete the first element
    print_list(head); 
    delete_node(&head, head); // delete the only element
    print_list(head);
    delete_node(&head, head); // error: empty list
    print_list(head);
    return 0;
}