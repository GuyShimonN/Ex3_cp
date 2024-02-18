#include <stdlib.h>
#include<StrList.h>
#include<stdio.h>



typedef struct _StrList StrList{
    char _data;
    struct _node * _next;
} Node;

struct _StrList {
    StrList* _head;
    size_t _size;
};
StrList* Node_alloc(char data,StrList* next) {
	StrList* p= (StrList*)malloc(sizeof(_trList));
	p->_data= data;
	p->_next= next;
	return p;
}
