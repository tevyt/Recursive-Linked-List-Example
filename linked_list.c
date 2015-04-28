#include<stdio.h>
#include<stdlib.h>
struct node{
    int val;
    struct node *next;
};

void insert(struct node **head , int val){
    if((*head) == NULL){
        (*head) = malloc(sizeof(struct node));
        (*head)->val = val;
        (*head)->next = NULL;
    }
    else
         insert(&((*head)->next) , val);
}

void print(struct node *head){
    if(head == NULL)
        printf("NULL\n");
    else{
        printf("%d->" ,head->val);
        print(head->next);
    }

}

int delete(struct node *head, int val){
    struct node *current = head->next;
    if(current == NULL)
        return -1;
    else if(current->val == val){
        head->next = current->next;
        free(current);
        return val;
    }
    else
        return delete(current , val);
}

int update(struct node *head, int old , int new){
    if(head == NULL)
        return -1;
    else if(head->val == old){
        head->val = new;
        return old;
    }
    else
        return update(head->next , old , new);
}


int main(){
    struct node* head = malloc(sizeof(struct node));
    head->val = 1;
    head->next = NULL;
    print(head);
    insert(&head , 2);
    insert(&head, 3);
    insert(&head, 5);
    insert(&head, 12);
    print(head);
    delete(head , 5);
    print(head);
    update(head , 12 , 4);
    print(head);
}


