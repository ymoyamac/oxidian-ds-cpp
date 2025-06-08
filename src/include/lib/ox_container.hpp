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
    size_t size(Container<K, V>* container) {
        return container->size;
    }

    template<typename K, typename V>
    size_t is_empty(Container<K, V>* container) {
        return container->size == 0;
    }

    template<typename K, typename V>
    int get_index(Container<K, V>* container, K key) {

        if (container == nullptr) {
            printf("Por aquí paso...\n");
            return -1;
        }
        int index = 0;
        ox::bucket::Bucket<K, V>* iter = ox::bucket::init<K, V>();
        iter = container->head;
        while (iter->key != key) {
            iter = iter->next;
            index++;
        }
        free(iter);
        iter = nullptr;
        return index;
    }

    template<typename K, typename V>
    void fmt(Container<K, V>* container, int index) {
        ox::bucket::Bucket<K, V>* iter = ox::bucket::init<K, V>();
        iter = container->head;
        printf("(%i) Container{ \n", index);
        while (iter) {
            printf("  Bucket{ \"%s\": \"%s\" }", iter->key.c_str(), iter->value.c_str());
            if (iter->next != nullptr) {
                printf("\n");
            }
            iter = iter->next;
        }
        free(iter);
        iter = nullptr;
        printf("\n}\n");
    }

    template<typename K, typename V>
    void push_back(Container<K, V>* container, K &key, V &value) {
        ox::bucket::Bucket<K, V>* new_bucket = ox::bucket::init<K, V>(key, value);
        printf(" >> Pushing{ \"%s\": \"%s\" }\n", key.c_str(), value.c_str());
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
    std::pair<ox::bucket::Bucket<K, V>*, int> get(Container<K, V>* container, K &key) {
        ox::bucket::Bucket<K, V>* iter = ox::bucket::init<K, V>();
        int counter = 0;
        iter = container->head;
        while (iter->next != nullptr && iter->key != key) {
            iter = iter->next;
            counter++;
        }
        //Devuelve el iterador donde se quedo
        return std::pair{iter, counter};
    }

    template<typename K, typename V>
    ox::bucket::Bucket<K, V>* get_first(Container<K, V>* container) {
        ox::bucket::Bucket<K, V>* tmp = container->head;
        tmp->next = nullptr;
        return tmp;
    }

    template<typename K, typename V>
    void remove(Container<K, V>* container, K &key, int index) {
        
        if (!container || index < 0 || index >= container->size) {
            fprintf(stderr, "Error position not valid\n");
            return;
        }

        printf(" >> Removing [\"%s\"] at pos (%i)...\n", key.c_str(), index);
        if (index == 0 && container->size == 1) {
            container->head = nullptr;
            container->tail = nullptr;
            container->size = 0;
            return;
        }
        ox::bucket::Bucket<K, V>* iter = ox::bucket::init<K, V>();
        ox::bucket::Bucket<K, V>* tmp = ox::bucket::init<K, V>();
        if (index == 0) {
            container->head = container->head->next;
            free(iter);
            free(tmp);
            iter = nullptr;
            tmp = nullptr;
            return;
        } else {
            iter = container->head;
            for (size_t i = 0; i < index - 1; i++)
            {
                iter = iter->next;
            }
            tmp = iter->next->next;
            iter->next = tmp;
            container->size -= 1;
            if (index == container->size - 1) {
                container->tail = tmp;
            }
            container->size -= 1;
            return;
        }
    }
}

#endif