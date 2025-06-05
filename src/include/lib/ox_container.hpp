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
            container->head = new_bucket;
            container->tail = new_bucket;
        } else {
            container->tail->next = new_bucket;
            container->tail = new_bucket;
        }
        container->size += 1;
    }

    template<typename K, typename V>
    ox::bucket::Bucket<K, V>* get(Container<K, V>* container, K &key) {
        printf(" >> Get element...\n");
        ox::bucket::Bucket<K, V>* iter = ox::bucket::init<K, V>();
        iter = container->head;
        while (iter->next != nullptr && iter->key != key) {
            iter = iter->next;
        }
        //Devuelve el iterador donde se quedo
        printf(" >> Iter { \"%s\": \"%s\" }\n", iter->key.c_str(), iter->value.c_str());
        return iter;
    }

    template<typename K, typename V>
    ox::bucket::Bucket<K, V>* get_first(Container<K, V>* container) {
        ox::bucket::Bucket<K, V>* tmp = container->head;
        tmp->next = nullptr;
        return tmp;
    }

    template<typename K, typename V>
    void remove(Container<K, V>* container, K &key) {
        printf(" >> Removing element...\n");
        ox::bucket::Bucket<K, V>* tmp = ox::bucket::init<K, V>();
        ox::bucket::Bucket<K, V>* iter = container->head;
        while (iter->next != nullptr && iter->next->key != key) {
            iter = iter->next;
        }
        //En este punto iter vale lo que vale el bucket que estamos buscando por la llave
        //menos uno
        tmp = iter->next->next;
        iter->next = tmp;
        container->size -= 1;

    }
}

#endif