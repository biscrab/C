#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int data;
    struct ListNode* link;
}listnode;

typedef struct HeadNode {
    listnode* head;
}headnode;

headnode* createListHead(void) {
    headnode* L;
    L = (headnode*)malloc(sizeof(headnode));
    L->head = NULL;
    return L;
}

void print_node(headnode* L) {
    listnode* temp = L->head;
    if (L->head == NULL) {
        printf("empty list...\n");
        return;
    }

```c
printf("head->");
do
{
    printf("%d->", temp->data);
    temp = temp->link;

} while (temp != L->head);
printf("head\n");
```
}

void insert_node(headnode* L, int data) {
    listnode* newnode = (listnode*)malloc(sizeof(listnode));
    newnode->data = data;
    newnode->link = NULL;

```c
listnode* temp = L->head;
listnode* pre = L->head;

if (L->head == NULL) {
    L->head = newnode;
    newnode->link = newnode;
    return;
}

if (L->head->data > data) { 
    while (pre->link != temp) {
        pre = pre->link;
    }
    newnode->link = pre->link;
    pre->link = newnode;
    L->head = newnode;
}
else {
    while (temp->data < data)
    {
        pre = temp;
        temp = temp->link;
        if (temp == L->head) {
            break;
        }
    }
    newnode->link = pre->link;
    pre->link = newnode;
}
```

}

void delete_node(headnode* L, int data) {
    listnode* del = L->head;
    listnode* pre = L->head;

```c
if (L->head == NULL)
{
    printf("error\n");
    return;
}

if (del->data == data && del->link == del) {
    free(del);
    L->head = NULL;
    return;
}

if (del->data == data)
{
    while (pre->link != L->head) {
        pre = pre->link;
    }
    pre->link = del->link;
    L->head = del->link;
    free(del);
}
else {
    while (del->data != data) {
        pre = del;
        del = del->link;
        if (del->link == L->head) {
            printf("해당하는 값이 없습니다.\n");
            return;
        }
    }
    pre->link = del->link;
    free(del);
}
```
}

int main() {
    headnode* L = createListHead();
    print_node(L);
    insert_node(L, 1);
    print_node(L);
    insert_node(L, 5);
    print_node(L);
    insert_node(L, 8);
    print_node(L);
    insert_node(L, 2);
    print_node(L);
    insert_node(L, 7);
    print_node(L);
    insert_node(L, 0);
    print_node(L);
    printf("삭제시작\n");
    delete_node(L, 0);
    print_node(L);
    delete_node(L, 1);
    print_node(L);
    delete_node(L, 2);
    print_node(L);
    delete_node(L, 3);
    print_node(L);
}

