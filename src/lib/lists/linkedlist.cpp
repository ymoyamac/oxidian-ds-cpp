#include "oxidian.h"
#define SIZE 3

namespace linked_list {
    
    linkedlist_t* init() {
        linkedlist_t* ptr_ll = (linkedlist_t*) std::malloc(sizeof(linkedlist_t));
        /** If ‘malloc’ cannot allocate the memory it returns ‘NULL’.*/
        if (ptr_ll == nullptr) {
            fprintf(stderr, "Error could not allocate memory in the system\n");
            return nullptr;
        }
        /** The nodes that are part of the linked list are initialized. */
        ptr_ll->head = nullptr;
        ptr_ll->tail = nullptr;
        ptr_ll->size = 0;
        return ptr_ll;
    }

    /**
     * Frees the memory of a `linked-list` and its `nodes`.
     */
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

    /** Returns the size of the `linked-list` */
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
        /** A new node is created with the data to be stored. */
        simple_node::node_t* new_node = simple_node::init(data);
        /**
         * If the list is empty, then head and tail points to new_node
         *
         * Head, Tail
         * +-------+--------+
         * | data  |  next  +--->
         * +-------+--------+
         */
        if (list->head == nullptr && list->tail == nullptr) {
            list->head = new_node;
            list->tail = new_node;
        } else {
            /**
             * Otherwise, the value in the next of the new node will be assigned the value in
             * the `Tail->next` node indicating that this new node is at the end of the linked list.
             *
             * Head                  Tail                  NewNode
             * +-------+--------+    +-------+--------+    +-------+--------+
             * | data  |  next  +--->| data  |  next  +--->| data  |  next  +--->
             * +-------+--------+    +-------+--------+    +-------+--------+
             */
            list->tail->next = new_node;
            /**
             * Now the new Tail becomes the new node
             * Head                                        Tail
             * +-------+--------+    +-------+--------+    +-------+--------+
             * | data  |  next  +--->| data  |  next  +--->| data  |  next  +--->
             * +-------+--------+    +-------+--------+    +-------+--------+
             */
            list->tail = new_node;         
        }
        /** Increase the size of the list */
        list->size++;
    }

    void push_front(linkedlist_t* list, void* data) {
        /** A new node is created with the data to be stored. */
        simple_node::node_t* new_node = simple_node::init(data);
        /**
         * If the list is empty, then head and tail points to new_node
         *
         * Head, Tail
         * +-------+--------+
         * | data  |  next  +------->
         * +-------+--------+
         */
        if (list->head == nullptr && list->tail == nullptr) {
            list->head = new_node;
            list->tail = new_node;
        } else {
            /**
             * Otherwise the value in the next of the new node will be assigned the value in the head node,
             * that is, the content of the whole list.
             * 
             * Head
             * +-------+--------+
             * | data  |  next  +---> (...)
             * +-------+--------+
             *
             * NewNode               Head
             * +-------+--------+    +-------+--------+
             * | data  |  next  +--->| data  |  next  +---> (...)
             * +-------+--------+    +-------+--------+
             */
            new_node->next = list->head;
            /**
             * The Head node returns to being the first node.
             *
             * Head                  NewNode
             * +-------+--------+    +-------+--------+
             * | data  |  next  +--->| data  |  next  +---> (...)
             * +-------+--------+    +-------+--------+
             */
            list->head = new_node;
        }
        /** Increase the size of the list */
        list->size++;
    }

    void push_at(linkedlist_t* list, void* data, int at) {
        /** If the position is greater than `size`, then the execution ends. */
        if (at < list->size && at > list->size) {
            fprintf(stderr, "Error position not valid\n");
            return;
        }
        /** If the position is equals zero, then calls `push_front()`. */
        if (at == 0) {
            push_front(list, data);
            list->size++;
            return;
        }
        int index = 0;
        simple_node::node_t* new_node = simple_node::init(data);
        /** A new node is created to iterate over the list. */
        simple_node::node_t* iter = simple_node::init(0);
        simple_node::node_t* temp = simple_node::init(0);
        /**
         * The node starts at the beginning of the list, it is assigned the node of head.
         * 
         * Iter, Head
         * +-------+--------+
         * | data  |  next  +---> (...)
         * +-------+--------+
         *
         */
        iter = list->head;
        while(iter->next != nullptr) {
            if (at - 1 == index) {
                /**
                 * If the index is equal to the position minus one, then the temporary node is assigned the right part of the list.
                 * 
                 * Linkedlist
                 * Left                                           Right
                 * +----------------------------------------------+----------------------------------------------+
                 * |  Head                  Iter                  |  Temp                  Tail
                 * |  +-------+--------+    +-------+--------+    |  +-------+--------+    +-------+--------+
                 * |  | data  |  next  +--->| data  |  next  +--->|  | data  |  next  +--->| data  |  next  +--->
                 * |  +-------+--------+    +-------+--------+    |  +-------+--------+    +-------+--------+
                 * +---------------------------------------------------------------------------------------------+
                 */
                temp = iter->next;
                /**
                 * Now the end of the list on the left side is the iterator node. The next node of Iter is assigned the new node and
                 * the new node is assigned the right side of the list.
                 * 
                 * Linkedlist
                 * +--------------------------------------------------------------------------------------------------------------------+
                 * |  Head                  Iter                                               Temp                      Tail
                 * |  +-------+--------+    +-------+--------+                               +-------+--------+    +-------+--------+
                 * |  | data  |  next  +--->| data  |  next  +---+                       +-->| data  |  next  +--->| data  |  next  +--->
                 * |  +-------+--------+    +-------+--------+   |                       |   +-------+--------+    +-------+--------+
                 * +---------------------------------------------|-----------------------|----------------------------------------------+
                 *                                               |                       |
                 *                                               |   +-------+--------+  |
                 *                                               +-->| data  |  next  +--+
                 *                                                   +-------+--------+
                 */
                iter->next = new_node;
                new_node->next = temp;
                break;
            } else {
                /** Otherwise, iterate over the list */
                iter = iter->next;
                index++;
            }
        }
        list->size++;
    }

    void* pop(linkedlist_t* list) {
        /** the data to be removed from the list is obtained in a pointer `(void*)`. */
        void* dropped = list->tail->next->data;
        /** A new node is created to iterate over the list. */
        simple_node::node_t* iter = simple_node::init(0);
        /**
         * The iteration starts at the beginning of the list, the iter node is assigned the head node.
         * 
         * Iter, Head
         * +-------+--------+
         * | data  |  next  +---> (...)
         * +-------+--------+
         *
         */
        iter = list->head;
        int index = 0;
        while(iter->next != nullptr) {
            /** The list is iterated over until the Iter node is in the penultimate position. */
            if (index == list->size - 2) {
                /**
                 * Once the Iter node is in the penultimate position in the list, it is assigned to the tail node.
                 * 
                 * Linkedlist
                 * +------------------------------------------------------------------------------------------+
                 * |  Head                                        Iter                  Tail
                 * |  +-------+--------+    +-------+--------+    +-------+--------+    +-------+--------+
                 * |  | data  |  next  +--->| data  |  next  +--->| data  |  next  +--->| data  |  next  +--->
                 * |  +-------+--------+    +-------+--------+    +-------+--------+    +-------+--------+
                 * +------------------------------------------------------------------------------------------+
                 * 
                 * Once the Iter node is in the penultimate position in the list, it is assigned to the tail node.
                 * 
                 * Linkedlist
                 * +------------------------------------------------------------------------------------------+
                 * |  Head                                        Iter, Tail           
                 * |  +-------+--------+    +-------+--------+    +-------+--------+    +-------+--------+
                 * |  | data  |  next  +--->| data  |  next  +--->| data  |  next  +--->| data  |  next  +--->
                 * |  +-------+--------+    +-------+--------+    +-------+--------+    +-------+--------+
                 * +------------------------------------------------------------------------------------------+
                 */
                list->tail = iter;
                /**
                 * Finally the `Tail-next` node is assigned the value of `NULL`
                 * 
                 * Linkedlist
                 * +--------------------------------------------------------------------+
                 * |  Head                                        Tail           
                 * |  +-------+--------+    +-------+--------+    +-------+--------+    
                 * |  | data  |  next  +--->| data  |  next  +--->| data  |  next  +--->
                 * |  +-------+--------+    +-------+--------+    +-------+--------+    
                 * +--------------------------------------------------------------------+
                 */
                list->tail->next = nullptr;
                break;
            }
            /** Otherwise, iterate over the list */
            iter = iter->next;
            index++;
        }
        /** The size of the list is reduced by minus one element and the memory of the Iter node is freed. */
        list->size--;
        free(iter);
        iter = nullptr;
        return dropped;
    }

    void* get(linkedlist_t* list, int index) {
        /** If the index is greater than or equal to the list size, `NULL` is returned. */
        if (!list || index >= list->size) {
            return nullptr;
        }
        simple_node::node_t* iter = list->head;
        /** The list is traversed until the position in the list is reached and the data is returned. */
        for (size_t i = 0; i < index; i++) {
            iter = iter->next;
        }
        return iter->data;
    }

    void* remove(linkedlist_t* list, int at) {
        /** If the index is greater than or equal to the list size, `NULL` is returned. */
        if (!list || at < 0 || at >= list->size) {
            fprintf(stderr, "Error position not valid\n");
            return nullptr;
        }
        void* data;
        simple_node::node_t* iter = simple_node::init(0);
        simple_node::node_t* temp = simple_node::init(0);
        if (at == 0 && list->size == 1) {
            list->head = nullptr;
            list->tail = nullptr;
            free(iter);
            free(temp);
            iter = nullptr;
            temp = nullptr;
            list->size--;
            return data;
        }
        if (at == 0) {
            list->head = list->head->next;
            data = list->head->data;
            free(iter);
            free(temp);
            iter = nullptr;
            temp = nullptr;
            list->size--;
            return data;
        } else {
            iter = list->head;
            for (size_t i = 0; i < at - 1; i++) {
                iter = iter->next;
            }
            /**
             * Iterate over the list until the index minus one is reached, obtain the data of the node to be removed,
             * and assign to the iterator node the value of the temporary node which contains the rest of the list.
             * 
             * Linkedlist
             * +-------------------------------------------------------------------------------------------+
             * |  Head                  Iter                                         Temp, Tail
             * |  +-------+--------+    +-------+--------+    +-------+--------+     +-------+--------+
             * |  | data  |  next  +--->| data  |  next  +-+  | data  |  next  |  +->| data  |  next  +--->
             * |  +-------+--------+    +-------+--------+ |  +-------+--------+  |  +-------+--------+
             * +-------------------------------------------|----------------------|------------------------+
             *                                             +----------------------+
             */
            data = iter->next->data;
            temp = iter->next->next;
            iter->next = temp;
            if (at == list->size - 1) {
                list->tail = temp;
            }
        }
        list->size--;
        return data;
    }

}
