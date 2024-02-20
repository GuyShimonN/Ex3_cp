#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "StrList.h"

typedef struct _Node {
    char* _data;
    struct _Node* _next;
} Node;

typedef struct _StrList {
    Node* _head;
    size_t _size;
} StrList,_StrList;

StrList* StrList_alloc() {
    StrList* p = (StrList*)malloc(sizeof(StrList));
    if (p == NULL) {
        printf("Error: Memory allocation failed\n");
        return NULL;
    }
    p->_head = NULL;
    p->_size = 0;
    return p;
}

Node* Node_alloc(const char* data, Node* next) {
    Node* p = (Node*)malloc(sizeof(Node));
    if (p == NULL) {
        printf("Error: Memory allocation failed\n");
        return NULL;
    }
    p->_data = strdup(data); // Allocate memory for data and copy string
    if (p->_data == NULL) {
        free(p);
        printf("Error: Memory allocation failed\n");
        return NULL;
    }
    p->_next = next;
    return p;
}

void Node_free(Node* node) {
    if (node == NULL) return;
    free(node->_data); // Free data first
    free(node);
}

void StrList_free1(StrList* StrList){
      
    if (StrList->_head == NULL) return;
    Node* p1 = StrList->_head;
    Node* p2;
    while (p1 != NULL) {
     
        p2 = p1;
        p1 = p1->_next;
        Node_free(p2);
    }
    StrList->_head=NULL;
        StrList->_size=0;

   
}
void StrList_free(StrList* StrList){
    	if (StrList==NULL) return;
	Node* p1= StrList->_head;
	Node* p2;
	while(p1) {
		p2= p1;
		p1= p1->_next;
		Node_free(p2);
	}
	free(StrList);
}

size_t StrList_size(const StrList* StrList) {
    return StrList->_size;
}

void StrList_insertLast(StrList* StrList, const char* data) {
    if (StrList == NULL) {
        printf("Error: StrList is NULL\n");
        return;
    }
    if (StrList->_head == NULL) {
        StrList->_head = Node_alloc(data, NULL);
        StrList->_size = 1;
        return;
    }
    Node* p1 = StrList->_head;
    while (p1->_next != NULL) {
        p1 = p1->_next;
    }
    p1->_next = Node_alloc(data, NULL);
    StrList->_size++;
}

void StrList_insertFirst(StrList* StrList, const char* data) {
    if (StrList == NULL) {
        printf("Error: StrList is NULL\n");
        return;
    }
    StrList->_head = Node_alloc(data, StrList->_head);
    StrList->_size++;
}

void StrList_insertAt(StrList* StrList, const char* data, int index) {
    if (StrList == NULL) {
        printf("Error: StrList is NULL\n");
        return;
    }
    if (index < 0 || index > StrList->_size) {
        printf("Error: Invalid index\n");
        return;
    }
    if (index == 0) {
        StrList_insertFirst(StrList, data);
        return;
    }
    Node* p1 = StrList->_head;
    for (int i = 0; i < index - 1; i++) {
        p1 = p1->_next;
    }
    p1->_next = Node_alloc(data, p1->_next);
    StrList->_size++;
}

char* StrList_firstData(const StrList* StrList) {
    if (StrList == NULL || StrList->_head == NULL) {
        printf("Error: StrList is empty\n");
        return NULL;
    }
    return StrList->_head->_data;
}

void StrList_print(const StrList* StrList) {
    if (StrList== NULL) {
        printf("Error: StrList is NULL\n");
        return;
        
    }
    Node* p1 = StrList->_head;
    while (p1 != NULL) {
        printf("%s ", p1->_data);
        p1 = p1->_next;
    }
    printf("\n");
}

void StrList_printAt(const StrList* StrList, int index) {
    if (StrList == NULL) {
        printf("Error: StrList is NULL\n");
        return;
    }
    if (index < 0 || index >= StrList->_size) {
        printf("Error: Invalid index\n");
        return;
    }
    Node* p1 = StrList->_head;
    for (int i = 0; i < index; i++) {
        p1 = p1->_next;
    }
    printf("%s\n", p1->_data);
}

int StrList_printLen(const StrList* Strlist) {
    int x = 0;
    Node* p1 = Strlist->_head;
    for (int i = 0; i < Strlist->_size; i++) {
        x += strlen(p1->_data);
        p1 = p1->_next;
    }
    return x;
}
int StrList_count(StrList* StrList, const char* data) {
    int y = 0, x = 0;
    Node* p1 = StrList->_head;
    for (int i = 0; i < StrList->_size; i++) {
        x = strcmp(data, p1->_data);
        if (x == 0) {
            y++;
        }
        p1 = p1->_next;
    }
    return y;
}

void StrList_remove(StrList* StrList, const char* data) {
    Node* current = StrList->_head;
    Node* previous = NULL;
    while (current != NULL) {
        if (strcmp(current->_data, data) == 0) {
            if (previous == NULL) {
                StrList->_head = current->_next;
               
            } else {
                previous->_next = current->_next;
            }
            Node* temp = current;
            current = current->_next;
            Node_free(temp);
            StrList->_size--;
        } else {
            previous = current;
            current = current->_next;
        }
    }
}
void StrList_removeAt(StrList* StrList, int index){
    if (index<0)return;
    Node* current = StrList->_head;
    Node* previous = NULL;
    int y=0;
    while (current!=NULL&&y<index)
    {
     previous=current;
     current=current->_next; 
     y++;
    }
    if (current==NULL)return;
    if (previous==NULL){StrList->_head=current->_next;
    StrList->_size--;}
    else{
        previous->_next=current->_next;
        StrList->_size--;
    }
    Node_free(current);
  
}

int StrList_isEqual(const StrList* StrList1, const StrList* StrList2) {
    Node* p1 = StrList1->_head;
    Node* p2 = StrList2->_head;
    while (p1 != NULL && p2 != NULL) {
        if (strcmp(p1->_data, p2->_data) != 0) {
            return 0;
        }
        p1 = p1->_next;
        p2 = p2->_next;
    }
    return p1 == NULL && p2 == NULL;
}

StrList* StrList_clone(const StrList* StrList) {
    if (StrList == NULL) return NULL;
    _StrList* sp = StrList_alloc();
    Node* p1 = StrList->_head;
    Node* p2 = NULL;
    while (p1 != NULL) {
        Node* p = Node_alloc(p1->_data, NULL);
        if (p == NULL) {
            StrList_free(sp);
            return NULL;
        }
        if (sp->_head == NULL) {
            sp->_head = p;
            p2 = p;
        } else {
            p2->_next = p;
            p2 = p2->_next;
        }
        sp->_size++;
        p1 = p1->_next;
    }
    return sp;
}

void StrList_reverse(StrList* StrList) {
    if (StrList == NULL || StrList->_head == NULL || StrList->_size == 1) {
        return; // Nothing to reverse
    }
    
    Node* current = StrList->_head;
    Node* prev = NULL;
    Node* next = NULL;

    while (current != NULL) {
        next = current->_next;
        current->_next = prev;
        prev = current;
        current = next;
    }

    StrList->_head = prev;
}
void StrList_sort(StrList* StrList) {
    if (StrList == NULL || StrList->_head == NULL || StrList->_size == 1) {
        return; // Nothing to sort
    }

    // Bubble sort algorithm
    int swapped;
    Node* ptr1;
    Node* lptr = NULL;

    do {
        swapped = 0;
        ptr1 = StrList->_head;

        while (ptr1->_next != lptr) {
            if (strcmp(ptr1->_data, ptr1->_next->_data) > 0) {
                // Swap data of adjacent nodes
                char* temp = ptr1->_data;
                ptr1->_data = ptr1->_next->_data;
                ptr1->_next->_data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->_next;
        }
        lptr = ptr1;
    } while (swapped);
}

int StrList_isSorted( StrList* StrList) {
    if (StrList == NULL || StrList->_head == NULL || StrList->_size == 1) {
        return 1; // List is considered sorted if it is empty or has only one element
    }

    Node* current = StrList->_head;
    while (current->_next != NULL) {
        if (strcmp(current->_data, current->_next->_data) > 0) {
            return 0; // List is not sorted
        }
        current = current->_next;
    }

    return 1; // List is sorted
}
