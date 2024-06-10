    #include<stdio.h>
    #include<stdlib.h>

    typedef struct Node{
        char data;
        struct Node *next;
    }Node;

    typedef struct {
        Node *head;
    }LinkedList;

    Node* createNode(char data){
        Node* new_node = (Node*)malloc(sizeof(Node));

        new_node->data = data;
        new_node->next = NULL;

        return new_node;
    }

    void insertAtTail(LinkedList *list, char data) {
        Node* new_node = createNode(data);

        if(list->head == NULL){
            list->head = new_node;
        }
        else {
            Node* temp = list->head;
            while(temp->next){
                temp = temp->next;
            }

            temp->next = new_node;
        }
    }

    void saveStrInLinkedList(char* in_str, LinkedList* list){
        while(*in_str != '\0'){
            insertAtTail(list, *in_str);
            in_str++;
        }
    }

    void printLinkedList(LinkedList* list){
        Node* temp = list->head;
        while(temp){
            printf("%c", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }

    void initializeLinkedList(LinkedList* list) {
        list->head = NULL;
    }

    int main(int argc, char *argv[]) {
        if (argc < 2) {
            printf("Usage: %s <string>\n", argv[0]);
            return 1;
        }

        LinkedList str_list;
        initializeLinkedList(&str_list);

        saveStrInLinkedList(argv[1], &str_list);
        printLinkedList(&str_list);

        return 0;
    }
