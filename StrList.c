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
    }StrList,_StrList;
StrList* StrList_alloc(){
	StrList* p= (StrList*)malloc(sizeof(StrList));
    if (p == NULL){
        printf("eror\n");
        return NULL;
    }
	p-> _head= NULL;
	p->_size= 0;
	return p;
}
    Node* Node_alloc(char data,Node* next) {
	Node* p= (Node*)malloc(sizeof(Node));
    if (p==NULL){
        printf("eror\n");
        return NULL; 
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
void StrList_insertFirst(StrList* list,char data){
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

    Node* current = StrList->_head;
    Node* previous = NULL;
    while (current != NULL) {
        if (strcmp(current->_data, data) == 0) {
            if (previous == NULL) {
                StrList->_head = current->_next;
                
            } else {
                previous->_next = current->_next;
            
            }
            free(current->_data); 
            free(current);
            
        }
       
        previous =previous->_next;
        current = previous->_next;
        StrList->_size--;
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
    free(current->_data);
    free(current);
}


int StrList_isEqual(const StrList* StrList1, const StrList* StrList2){
    Node* p1 = StrList1->_head;
    Node* p2 = StrList2->_head;
    while (p1!=NULL&&p2!=NULL)
    {
        if (strcmp(p1->_data,p2->_data)!=0)return 0;
        p1=p1->_next;
        p2=p2->_next;
    }
    if (p1==NULL&&p2==NULL)return 1;
    return 0;

    
}


StrList* StrList_clone(const StrList* StrList){
    if (StrList==NULL)return NULL;
    _StrList* sp = StrList_alloc();
    Node* p1 = StrList->_head; 
     Node* p2=Node_alloc(p1->_data,NULL);
        if (p2==NULL){
            Node_free(p2);
            StrList_free(sp);
            return NULL;
        }
     sp->_head=p2;
     sp->_size++;
     p1=p1->_next;

     for (int i = 1; i < StrList->_size; i++)
     {
    
        Node* p = Node_alloc(p1->_data,NULL);
        if (p==NULL){
            StrList_free(sp);
            return NULL;
        }
        p2->_next =p;
        sp->_size++;
        p1=p1->_next;
        p2=p2->_next;
        Node_free(p);

     }
     return sp;
}

void StrList_reverse( StrList* StrList){
    Node* head = StrList->_head;
    char** arr = (char**)malloc(sizeof(char*)*(StrList->_size));
    if (arr==NULL)return;
    int i=0;
    while (head!=NULL)
    {
        arr[i]= (char*)malloc(strlen(head->_data)+1);
        if (arr[0]==NULL){
            for (int j = 0; j < i; j++)
            {
               free(arr[j]);
            }
            free(arr);
            return;
            }
        strcpy(arr[i],head->_data);
        head=head->_next;
        i++;      
    }
    head = StrList->_head;
    while (head!=NULL)
    {
        strcpy(head->_data,arr[i]);
        i--;
        head=head->_next;
      
    }
    for (int j = 0; j < StrList->_size; j++)
            {
               free(arr[j]);
            }
    free(arr);
    
    
}

void StrList_sort( StrList* StrList);

int StrList_isSorted(StrList* StrList);