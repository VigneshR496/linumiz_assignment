#include "main.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Usage: %s <string>\n", argv[0]);
    return 1;
  }

  LinkedList str_list;
  initializeLinkedList(&str_list);

  saveStrInLinkedList(argv[1], &str_list);
  printReverseStrLinkedList(&str_list);

  return 0;
}

Node *createNode(char data) {
  Node *new_node = (Node *)malloc(sizeof(Node));

  new_node->data = data;
  new_node->next = NULL;

  return new_node;
}

void insertAtTail(LinkedList *list, char data) {
  Node *new_node = createNode(data);

  if (list->head == NULL) {
    list->head = new_node;
  } else {
    Node *temp = list->head;
    while (temp->next) {
      temp = temp->next;
    }

    temp->next = new_node;
  }
}

void initializeLinkedList(LinkedList *list) { list->head = NULL; }

void saveStrInLinkedList(char *in_str, LinkedList *list) {
  while (*in_str != '\0') {
    insertAtTail(list, *in_str);
    in_str++;
  }
}

void printWordReverse(Node *word_strt, Node *word_end) {
  if (word_strt == NULL || word_strt == word_end) {
    return;
  }

  printWordReverse(word_strt->next, word_end);

  printf("%c", word_strt->data);
}

void printReverseStrLinkedList(LinkedList *list) {
  Node *word_strt = list->head;
  Node *word_end = word_strt;

  while (word_end != NULL) {
    while (word_end != NULL && word_end->data != ' ') {
      word_end = word_end->next;
    }

    printWordReverse(word_strt, word_end);

    if (word_end) {
      printf(" ");
      word_strt = word_end->next;
      word_end = word_strt;
    }
  }
  printf("\n");
}
