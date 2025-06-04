#include <oxidian.hpp>

namespace ox::queue {

    queue_t* init() {
        queue_t* ptr_queue = (queue_t*) std::malloc(sizeof(queue_t));
        /** If ‘malloc’ cannot allocate the memory it returns ‘NULL’.*/
        if (ptr_queue == nullptr) {
            fprintf(stderr, "Error could not allocate memory in the system\n");
            return nullptr;
        }
        ptr_queue->front = nullptr;
        ptr_queue->rear = nullptr;
        ptr_queue->size = 0;
        return ptr_queue;
    }

    void enqueue(queue_t* queue, void* data) {
        node::node_t* new_node = node::init(data);
        if (queue->front == nullptr && queue->rear == nullptr) {
            printf("Queue is empty\n");
            queue->front = new_node;
            queue->rear = new_node;
        } else {
            new_node->next = queue->front;
            queue->front = new_node;
        }
        queue->size++;
    }
}
