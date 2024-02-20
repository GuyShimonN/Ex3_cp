#include <stdio.h>
#include <stdlib.h>
#include "StrList.h"
#define false 0
#define true 1
int main() {
    int number = 0;
    scanf("%d", &number);
    StrList *list = StrList_alloc();

    while (number != 0) {
        if (number == 1) {
            
            int temp = 0;
            scanf("%d", &temp);
            for (int i = 0; i < temp; i++) {
                
                char *data = (char *)malloc(sizeof(char) * 21);
                scanf("%s", data);
                StrList_insertLast(list, data);
            }
        } else if (number == 2) {
            int temp = 0;
            scanf("%d", &temp);
            char *data = (char *)malloc(sizeof(char) * 100);
            scanf("%s", data);
            StrList_insertAt(list, data, temp);
        } else if (number == 3) {
            StrList_print(list);
        
        } else if (number == 4) {
           printf( "%d\n",(int)StrList_size(list));
        } else if (number == 5) {
            int index = 0;
            scanf("%d", &index);
            StrList_printAt(list, index);
        } else if (number == 6) {
            int i =StrList_printLen(list);
            printf("%d\n", i);
        } else if (number == 7) {
            char *data = (char *)malloc(sizeof(char) * 100);
            scanf("%s", data);
           int y=  StrList_count(list, data);
           printf("%d\n",y);
            free(data);
        } else if (number == 8) {
            char *data = (char *)malloc(sizeof(char) * 100);
            scanf("%s", data);
            StrList_remove(list, data);
            free(data);
        } else if (number == 9) {
            int index = 0;
            scanf("%d", &index);
            StrList_removeAt(list, index);
        } else if (number == 10) {
            StrList_reverse(list);
        } else if (number == 11) {
            StrList_free1(list);
           // return 0;
        } else if (number == 12) {
            StrList_sort(list);
        } else if (number == 13) {
            if (StrList_isSorted(list)) {
                printf("true \n");
            } else {
                printf("false \n");
            }
            // int i =StrList_isSorted(list);
            // printf("%d",i);
        }
        scanf("%d", &number); // Read next number for the next iteration
    }
    free(list);
    return 0;
}