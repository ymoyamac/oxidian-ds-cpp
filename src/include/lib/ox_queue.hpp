/**
 * ox_queue.h
 * 
 * DOCUMENTATION:
 * 
 *      A queue is a collection of entities that are maintained in a sequence and can be modified by the addition of
 *      entities at one end of the sequence and the removal of entities from the other end of the sequence.
 *      The operations of a queue make it a first-in-first-out (FIFO) data structure. In a FIFO data structure,
 *      the first element added to the queue will be the first one to be removed. 
 * 
 * IDENTIFICATION:
 *      src/include/lib/ox_queue.h
 */
#ifndef _OX_QUEUE_H
#define _OX_QUEUE_H

#include <oxidian.hpp>

namespace ox::queue {

    typedef struct {
        simple_node::node_t* front;
        simple_node::node_t* rear;
        int size;
    } queue_t;

    queue_t* init();
    void enqueue(queue_t* queue, void* data);
    void* to_array(queue_t* queue);
    bool contains(queue_t* queue, void* object);
    void clear(queue_t* queue);

}

#endif