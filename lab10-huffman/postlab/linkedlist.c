/*
Name: Tho Nguyen
Email ID: tnn7yc
File name:
Date: 11/30/18
*/
#include <stdio.h>
#include <stdlib.h>

struct list_item{
  int x;
  struct list_item* next;
};

int main(){
  int n;
  struct list_item* list= malloc(sizeof(struct list_item));
  struct list_item* tmp= list;
  printf("Enter how many values to input: ");
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    printf ("Enter value %d: ", i+1);
    tmp->next = malloc(sizeof(struct list_item));
    scanf("%d", &tmp->x);
    tmp= tmp->next;
  }
  tmp= list;
  for (int i = 0; i < n; i++) {
    printf("%d \n", tmp->x);
    tmp = tmp->next;
  }
  tmp= list->next;
  for (int i = 0; i < n; i++) {
    free(list);
    tmp= tmp->next;
    list= tmp;
  }
  
  return 0;
}
