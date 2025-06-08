#ifndef _OX_HASH_MAP_H
#define _OX_HASH_MAP_H

#include <oxidian.hpp>

namespace ox::hashmap {

    const uint INITIAL_CAPACITY = 5;
    const double LOAD_FACTOR = 0.75;
    
    template<typename K, typename V>
    struct HashMap {
        std::array<ox::container::Container<K, V>*, INITIAL_CAPACITY> container;
        size_t capacity = INITIAL_CAPACITY;
        size_t size = 0;
    };

    size_t fbv1a(const std::string &key);

    template<typename K>
    size_t hash(const K &key) {
        return fbv1a(key) % INITIAL_CAPACITY;
    }

    template<typename K, typename V>
    HashMap<K, V>* create_map() {
        HashMap<K, V>* map = (HashMap<K, V>*) std::malloc(sizeof(HashMap<K, V>));
        for (int i = 0; i <= map->capacity; i++) {
            map->container[i] = nullptr;
        }
        return map;
    }

    template<typename K, typename V>
    size_t size(HashMap<K, V>* map) {
        return map->size;
    }

    template<typename K, typename V>
    void set(HashMap<K, V>* map, K key, V value) {
        size_t index = hash(key);

        if (map->container[index] == nullptr) {
            ox::container::Container<K, V>* new_container = ox::container::init<K, V>();
            ox::container::push_back(new_container, key, value);
            map->container[index] = new_container;
            ox::container::fmt(map->container[index], index);
        } else {
            std::pair<ox::bucket::Bucket<K, V>*, int> bucket = ox::container::get(map->container[index], key);
            if (bucket.first->key == key) {
                ox::container::remove(map->container[index], key, bucket.second);
                ox::container::push_back(map->container[index], key, value);
                ox::container::fmt(map->container[index], index);
                return;
            }
            ox::container::push_back(map->container[index], key, value);
            ox::container::fmt(map->container[index], index);
        }
        map->size += 1;

    }

    template<typename K, typename V>
    std::optional<V> get(HashMap<K, V>* map, K key) {
        size_t index = hash(key);
        printf("Searching: (%lu) %s\n", index, key.c_str());

        if (map->container[index] == nullptr) {
            printf("There is no element for this key...\n");
            return {};
        }

        std::pair<ox::bucket::Bucket<K, V>*, int> bucket = ox::container::get(map->container[index], key);
        V value = bucket.first->value;
        return std::optional<V>{value};
    }

    template<typename K, typename V>
    void remove(HashMap<K, V>* map, K key) {
        size_t index = hash(key);
        printf("Searching: (%lu) %s\n", index, key.c_str());

        if (map->container[index] == nullptr) {
            printf("There is no element for this key...\n");
        } else {
            if (ox::container::size(map->container[index]) == 1) {
                ox::container::remove(map->container[index], key, 0);
                free(map->container[index]);
            } else {
                int idx = ox::container::get_index(map->container[index], key);
                ox::container::remove(map->container[index], key, idx);
            }
        }

        map->size -= 1;
    }
    
    
}

#endif