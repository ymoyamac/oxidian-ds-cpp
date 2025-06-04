#ifndef _OX_CONTAINER_H
#define _OX_CONTAINER_H

#include <oxidian.hpp>

namespace ox::container {

    template<typename K, typename V>
    struct Container {
        ox::bucket::Bucket<K, V>* head = nullptr;
        ox::bucket::Bucket<K, V>* tail = nullptr;
        int size;
    };

    template<typename K, typename V>
    Container<K, V>* init() {

        Container<K, V>* container = (Container<K, V>*) std::malloc(sizeof(Container<K, V>));
        if (container == nullptr) {
            fprintf(stderr, "Error could not allocate memory in the system\n");
            return nullptr;
        }
        container->head = nullptr;
        container->tail = nullptr;
        container->size = 0;
        return container;

    }

    template<typename K, typename V>
    void push_back(Container<K, V>* container, K &key, V &value) {

        ox::bucket::Bucket<K, V>* new_bucket = ox::bucket::init<K, V>(key, value);

        if (container->head == nullptr && container->tail == nullptr) {
            printf("Container is empty...\n");
            container->head = new_bucket;
            container->tail = new_bucket;
        } else {
            printf("Appending new bucket...\n");
            container->tail->next = new_bucket;
            container->tail = new_bucket;
        }
        container->size += 1;
    }

    template<typename K, typename V>
    ox::bucket::Bucket<K, V>* get(Container<K, V>* container, K &key) {
        ox::bucket::Bucket<K, V>* iter = ox::bucket::init<K, V>();
        iter = container->head;
        while (iter->key != key) {
            printf("Iterating... { \"%s\": \"%s\" }\n", iter->key.c_str(), iter->value.c_str());
            iter = iter->next;
        }
        //Devuelve el iterador donde se quedo
        return iter;
    }
    
}

#endif