#ifndef _OX_CONTAINER_H
#define _OX_CONTAINER_H

#include <oxidian.hpp>

namespace ox::cluster {

    template<typename K, typename V>
    struct Cluster {
        std::unique_ptr<entry::Entry<K, V>> head = nullptr;
        entry::Entry<K, V>* tail = nullptr;
        int size = 0;
    };

    template<typename K, typename V>
    std::unique_ptr<Cluster<K, V>> init() {
        std::unique_ptr<Cluster<K, V>> container_ptr = std::make_unique<Cluster<K, V>>();
        return container_ptr;
    }

    template<typename K, typename V>
    int size(Cluster<K, V> &container) {
        return container.size;
    }

    template<typename K, typename V>
    void fmt(Cluster<K, V> &container) {
        entry::Entry<K, V>* iter = container.head.get();
        printf("Cluster{ \n");
        while (iter) {
            printf("  Entry{ \"%s\": \"%s\" }", iter->key.c_str(), iter->value.c_str());
            if (iter->next != nullptr) {
                printf("\n");
            }
            iter = iter->next.get();
        }
        delete iter;
        printf("\n}\n");
    }

    template<typename K, typename V>
    void push_back(Cluster<K, V> &container, const K &key, const V &value) {
        
        std::unique_ptr<entry::Entry<K, V>> new_bucket = entry::init<K, V>(key, value);
        
        if (container.head == nullptr && container.tail == nullptr) {
            printf(" >> The list is empty...\n");
            container.head = std::move(new_bucket);
            container.tail = container.head.get();
        } else {
            printf(" >> Pushing...\n");
            container.tail->next = std::move(new_bucket);
            container.tail = container.tail->next.get();
        }

        container.size++;

    }
    
    template<typename K, typename V>
    std::pair<const entry::Entry<K, V>*, int> get(Cluster<K, V> &container, const K &key) {

        int counter = 0;
        const entry::Entry<K, V>* iter = container.head.get();
        while (iter->next != nullptr && iter->key != key) {
            counter++;
            iter = iter->next.get();
        }
        return std::pair{iter, counter};
    }

    template<typename K, typename V>
    std::optional<std::unique_ptr<entry::Entry<K, V>>> pop(Cluster<K, V> &container) {

        if (!container.head) {
            printf(" >> The list is empty...\n");
            return {};
        }
        std::unique_ptr<entry::Entry<K, V>> popped_bucket = std::move(container.head);
        container.head = std::move(popped_bucket->next);

        if (!container.head) {
            container.tail = nullptr;
        }
    
        container.size--;
        popped_bucket->next = nullptr;
        return std::make_optional(std::move(popped_bucket));

    }
    
    template<typename K, typename V>
    void remove(Cluster<K, V> &container, const K &key) {
        printf(" >> Removing...\n");

        if (!container.head) {
            printf(" >> The list is empty...\n");
            return;
        }

        if (container.head->key == key) {
            printf(" >> Removing at index 0...\n");
            pop(container);
        }

        entry::Entry<K, V>* iter = container.head.get();
        while (iter->next != nullptr && iter->next->key != key) {
            iter = iter->next.get();
        }
        if (!iter->next) {
            printf(">> Key not found...\n");
            return;
        }
        std::unique_ptr<entry::Entry<K, V>> node_to_remove = std::move(iter->next);
        iter->next = std::move(node_to_remove->next);
        if (!iter->next) {
            container.tail = iter;
        }
        container.size--;
    }
}

#endif