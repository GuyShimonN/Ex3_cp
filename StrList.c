#include <stdlib.h>
#include<StrList.h>
#include<stdio.h>
#include<string.h>




typedef struct  _Node{
    char* _data;
    struct _node * _next;
    } Node;

 typedef struct _StrList {
    Node* _head;
    size_t _size;
    }StrList;
StrList* StrList_alloc(){
	StrList* p= (StrList*)malloc(sizeof(StrList));
    if (p == NULL){
        printf("eror\n");
        return -1;
    }
	p-> _head= NULL;
	p->_size= 0;
	return p;
}
Node* Node_alloc(char data,Node* next) {
	Node* p= (Node*)malloc(sizeof(Node));
    if (p==NULL){
        printf("eror\n");
        return -1; 
    }
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
    free(Node->_data);
    free(Node);
    
    }

    
size_t StrList_size(const StrList* StrList){
    return StrList ->_size;
}



void StrList_insertLast(StrList* StrLis,const char* data){
      	if (StrLis==NULL) {
          StrList* pp = StrList_alloc();
          Node*  p4 =Node_alloc(*data,NULL);
          StrLis ->_head =p4;
          StrLis->_size=1;
        }
        else{
	Node* p1= StrLis->_head;
	Node* p2;
	while(p1) {
		p2= p1;
		p1= p1->_next;
		
    }
    Node*  p4 =Node_alloc(*data,NULL);
    p2 ->_next =p4;
    StrLis->_size++;
	}
}


void StrList_insertAt(StrList* StrList,const char* data,int index){
    if (index>StrList->_size){
          printf("eror\n");
        return; 
    }
    if (index==0){
        StrList_insertFirst(StrList,*data);
    }
    Node* p1= StrList->_head;
	Node* p2;
    for (int i=0;i<index;i++){
    p2= p1;
		p1= p1->_next;
        }
        p2->_next =Node_alloc(data,p1);
        StrList->_size++;
    

}
void StrList_insertFirst(StrList* list,char* data){
	list->_head= Node_alloc(data,list->_head);
	++(list->_size);
}


char* StrList_firstData(const StrList* StrList){
    return StrList->_head->_data;
}


void StrList_print(const StrList* StrList){
    Node* p1 = StrList->_head;
    for(int i=0;i<StrList->_size;i++){
        printf("%s ",p1->_data);
        p1=p1->_next;
    }

}

void StrList_printAt(const StrList* Strlist,int index){
    if (index>=Strlist->_size){
        printf("index out of bouns");
        return;
    }
     Node* p1 = Strlist->_head;
    for (int i = 0; i < index; i++)
    {
       p1 =p1->_next; 
    }
    printf("%s ",p1->_data);
}

int StrList_printLen(const StrList* Strlist){
    int x=0;
    Node* p1 = Strlist->_head;
   for(int i=0;i<Strlist->_size;i++){
      x+= strlen(p1->_data);
        p1=p1->_next;
    }
}


int StrList_count(StrList* StrList, const char* data){
       int y,x=0;
    Node* p1 = StrList->_head;
   for(int i=0;i<StrList->_size;i++){
     x= strcmp(data,p1->_data);
     if (x!=0){
        y++;
     }
        p1=p1->_next;
    }
    return y;
}


void StrList_remove(StrList* StrList, const char* data){
    int x=0;
      Node* p1 = StrList->_head;
      Node* p2=p1;
      if (strcmp(data,p1->_data)){
        StrList->_head=p1->_next;
        p1=p1->_next;
        p2=StrList->_head;
        StrList->_size--;
      }
   for(int i=0;i<StrList->_size;i++){
    p1=p1->_next
     x= strcmp(data,p1->_data);
     if (x!=0){
        if (p1->_next!=NULL){
            p2=p1;
            
        }
     }
}

}
void StrList_removeAt(StrList* StrList, int index);

int StrList_isEqual(const StrList* StrList1, const StrList* StrList2);


StrList* StrList_clone(const StrList* StrList);

void StrList_reverse( StrList* StrList);

void StrList_sort( StrList* StrList);

int StrList_isSorted(StrList* StrList);