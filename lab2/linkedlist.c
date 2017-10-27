#include <stdio.h>
#include <stdlib.h>

struct element {
  struct element *next;
  int data;
};

struct linked_list {
  struct element* head;
};

void append_int(struct linked_list *list, int element) {
  struct element *elem = malloc(sizeof(struct element));
  elem->data = element;
  elem->next = NULL;

  if (list->head == NULL) {
    list->head = elem;
  }
  else {
    struct element *ptr = list->head;
    while (ptr->next != NULL) {
      ptr = ptr->next;
    }
    ptr->next = elem;
  }
}

int remove_head(struct linked_list *list) {
  if (list->head == NULL) {
    return NULL;
  }
  else {
    int temp = list->head->data;
    struct element *old_head = list->head;
    list->head = list->head->next;

    free(old_head);

    return temp;
  }
}

void insert_head(struct linked_list *list, int element) {
  struct element *elem = malloc(sizeof(struct element));
  elem->data = element;
  elem->next = NULL;

  if (list->head == NULL) {
    list->head = elem;
  }
  else {
    struct element* old_head = list->head;
    elem->next = old_head;
    list->head = elem;
  }
}

