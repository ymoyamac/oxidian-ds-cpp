#include "oxidian.h"
/**
 * 
 */

#include <cassert>

#define SIZE 3

namespace linked_list {
    
    linkedlist_t* init() {
        linkedlist_t* ptr_ll = (linkedlist_t*) std::malloc(sizeof(linkedlist_t));
        if (ptr_ll == NULL) {
            fprintf(stderr, "Error could not allocate memory in the system\n");
            exit(EXIT_FAILURE);
        }        
        ptr_ll->head = nullptr;
        ptr_ll->tail = nullptr;
        ptr_ll->size = 0;
        return ptr_ll;
    }

    linkedlist_t* init(int* val) {
        linkedlist_t* ptr_ll = (linkedlist_t*) std::malloc(sizeof(linkedlist_t));
        if (ptr_ll == NULL) {
            fprintf(stderr, "Error could not allocate memory in the system\n");
            exit(EXIT_FAILURE);
        }        
        ptr_ll->head = nullptr;
        ptr_ll->tail = nullptr;
        ptr_ll->size = 0;
        return ptr_ll;
    }

    void drop(linkedlist_t* list) {
        simple_node::node_t* tmp;

        while (list->head != nullptr) {
            tmp = list->head;
            list->head = list->head->next;
            free(tmp);
        }

        free(list);
        list = nullptr;
        tmp = nullptr;
    }

    int size(linkedlist_t* list) {
        return list->size;
    }

    void rprint_list(linkedlist_t* list) {
        int index = 0;
        simple_node::node_t* iter = simple_node::init(0);
        iter = list->head;
        printf("$ ");
        while (iter) {
            printf("%i", *(int*)get(list, index));
            if (iter->next != nullptr) {
                printf(", ");
            }
            iter = iter->next;
            index++;
        }
        free(iter);
        iter = nullptr;
        printf("\n");
    }

    void push_back(linkedlist_t* list, void* data) {
        simple_node::node_t* new_node = simple_node::init(data);
        if (list->head == nullptr && list->tail == nullptr) {
            list->head = new_node;
            list->tail = new_node;
        } else {
            list->tail->next = new_node;
            list->tail = new_node;         
        }
        list->size++;
    }

    void push_front(linkedlist_t* list, void* data) {
        simple_node::node_t* new_node = simple_node::init(data);
        if (list->head == nullptr && list->tail == nullptr) {
            list->head = new_node;
            list->tail = new_node;
        } else {
            new_node->next = list->head;
            list->head = new_node;
        }
        list->size++;
    }

    void push_at(linkedlist_t* list, void* data, int position) {
        if (position < list->size && position > list->size) {
            fprintf(stderr, "Error position not valid\n");
            exit(EXIT_FAILURE);
        }
        int index = 0;
        if (position == 0) {
            push_front(list, data);
            list->size++;
            return;
        }
        simple_node::node_t* new_node = simple_node::init(data);
        simple_node::node_t* iter = simple_node::init(0);
        simple_node::node_t* temp = simple_node::init(0);
        iter = list->head;
        while(iter->next != nullptr) {
            if (position - 1 == index) {
                temp = iter->next;
                iter->next = new_node;
                new_node->next = temp;
                break;
            } else {
                iter = iter->next;
                index++;
            }
        }
        list->size++;
    }

    void* pop(linkedlist_t* list) {
        int index = 0;
        void* dropped = list->tail->next->data;
        simple_node::node_t* iter = simple_node::init(0);
        iter = list->head;
        while(iter->next != nullptr) {
            if (index == list->size - 2) {
                list->tail = iter;
                list->tail->next = nullptr;
                break;
            }
            iter = iter->next;
            index++;
        }
        list->size--;
        free(iter);
        iter = nullptr;
        return dropped;
    }

    void* get(linkedlist_t* list, int index) {
        if (!list || index >= list->size) return NULL;
        simple_node::node_t* current = list->head;
        for (size_t i = 0; i < index; i++) {
            current = current->next;
        }
        return current->data;
    }

    simple_node::node_t* remove(linkedlist_t* list, int at) {


        return nullptr;
    }

}
