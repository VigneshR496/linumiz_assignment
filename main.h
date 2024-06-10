#ifndef MAIN_H
#define MAIN_H

typedef struct Node {
  char data;
  struct Node *next;
} Node;

typedef struct {
  Node *head;
} LinkedList;

/**
 * @brief Creates a new node using the input data
 *
 * @param data Character data to be stored in the node
 * @return Pointer to the created node
 */
Node *createNode(char data);

/**
 * @brief Inserts a new node at the tail of linked list
 *
 * @param list Pointer to the linked list
 * @param data Character data to be inserted in the new node
 */
void insertAtTail(LinkedList *list, char data);

/**
 * @brief Initializes a linked list
 *
 * @param list Pointer to the linked list
 */
void initializeLinkedList(LinkedList *list);

/**
 * @brief Saves the string in the character linked List
 *
 * @param in_str Pointer to the input string
 * @param list Pointer to the linked list
 */
void saveStrInLinkedList(char *in_str, LinkedList *list);

/**
 * @brief Prints the word in reverse
 *
 * @param in_str Pointer to start node of word
 * @param list Pointer to end node of word
 */
void printWordReverse(Node *word_strt, Node *word_end);

/**
 * @brief Prints the words of a string stored in a linked list in reverse order.
 *
 * @param list Pointer to the linked list
 */
void printReverseStrLinkedList(LinkedList *list);

#endif /* MAIN_H */