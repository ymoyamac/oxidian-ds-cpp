#ifndef _OX_CLUSTER_H
#define _OX_CLUSTER_H

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
        return std::make_unique<Cluster<K, V>>();
    }

    template<typename K, typename V>
    int size(Cluster<K, V> &cluster) {
        return cluster.size;
    }

    template<typename K, typename V>
    void fmt(Cluster<K, V> &cluster) {
        entry::Entry<K, V>* iter = cluster.head.get();
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
    void push_back(Cluster<K, V> &cluster, const K &key, const V &value) {
        printf(" >> Pushing...\n");

        if (cluster.size > 1) {
            std::optional<std::pair<const entry::Entry<K, V>*, int>> opt_entry = get(cluster, key);
            if (opt_entry.has_value()) {
                remove(cluster, key);
            }
        }
        
        std::unique_ptr<entry::Entry<K, V>> new_entry = entry::init<K, V>(key, value);
        
        if (cluster.head == nullptr && cluster.tail == nullptr) {
            cluster.head = std::move(new_entry);
            cluster.tail = cluster.head.get();
        } else {
            cluster.tail->next = std::move(new_entry);
            cluster.tail = cluster.tail->next.get();
        }

        cluster.size++;

    }
    
    template<typename K, typename V>
    std::optional<std::pair<const entry::Entry<K, V>*, int>> get(Cluster<K, V> &cluster, const K &key) {
        printf(" >> Getting...\n");
        int counter = 0;
        const entry::Entry<K, V>* iter = cluster.head.get();
        while (iter->next != nullptr && iter->key != key) {
            counter++;
            iter = iter->next.get();
        }
        if (iter-> key != key) {
            return {};
        }
        return std::optional{std::pair{iter, counter}};
    }

    template<typename K, typename V>
    std::optional<std::unique_ptr<entry::Entry<K, V>>> pop(Cluster<K, V> &cluster) {
        printf(" >> Pop...\n");

        if (!cluster.head) {
            printf(" >> The list is empty...\n");
            return {};
        }
        std::unique_ptr<entry::Entry<K, V>> popped_entry = std::move(cluster.head);
        cluster.head = std::move(popped_entry->next);

        if (!cluster.head) {
            cluster.tail = nullptr;
        }
    
        cluster.size--;
        popped_entry->next = nullptr;
        return std::make_optional(std::move(popped_entry));

    }
    
    template<typename K, typename V>
    void remove(Cluster<K, V> &cluster, const K &key) {
        printf(" >> Removing...\n");

        if (!cluster.head) {
            printf(" >> The list is empty...\n");
            return;
        }

        if (cluster.head->key == key) {
            printf(" >> Removing at index 0...\n");
            pop(cluster);
        }

        entry::Entry<K, V>* iter = cluster.head.get();
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
            cluster.tail = iter;
        }
        cluster.size--;
    }
}

#endif