#include <stdlib.h>
#include<StrList.h>
#include<stdio.h>



typedef struct  Node{
    char _data;
    struct _node * _next;
} Node;

struct _StrList {
    StrList* _head;
    size_t _size;
};
StrList* StrList_alloc(){
	StrList* p= (StrList*)malloc(sizeof(StrList));
	p-> _head= NULL;
	p->_size= 0;
	return p;
}
Node* Node_alloc(char data,Node* next) {
	Node* p= (Node*)malloc(sizeof(Node));
	p-> _data= data;
	p->_next= next;
	return p;
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


void Node_free(Node* Node){
free(Node);
}
size_t StrList_size(const StrList* StrList){
    return StrList ->_size;
}



void StrList_insertLast(StrList* StrList,const char* data){
      	if (StrList==NULL) {
          Node*  p4 =Node_alloc(*data,NULL);
          StrList ->_head =p4;
          
        }
        else{
	Node* p1= StrList->_head;
	Node* p2;
	while(p1) {
		p2= p1;
		p1= p1->_next;
		
    }
    Node*  p4 =Node_alloc(*data,NULL);
    p2 ->_next =p4;
	}
}


void StrList_insertAt(StrList* StrList,
	const char* data,int index);


char* StrList_firstData(const StrList* StrList);


void StrList_print(const StrList* StrList);

void StrList_printAt(const StrList* Strlist,int index);

int StrList_printLen(const StrList* Strlist);


int StrList_count(StrList* StrList, const char* data);


void StrList_remove(StrList* StrList, const char* data);


void StrList_removeAt(StrList* StrList, int index);

int StrList_isEqual(const StrList* StrList1, const StrList* StrList2);


StrList* StrList_clone(const StrList* StrList);

void StrList_reverse( StrList* StrList);

void StrList_sort( StrList* StrList);

int StrList_isSorted(StrList* StrList);