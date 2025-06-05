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
    void set(HashMap<K, V>* map, K key, V value) {
        size_t index = hash(key);
        ox::container::Container<K, V>* on_use = map->container[index];

        if (on_use == nullptr) {
            printf(" >> Hashmap is empty...\n");
            printf("%lu: { \"%s\": \"%s\" }\n", index, key.c_str(), value.c_str());
            ox::container::Container<K, V>* new_container = ox::container::init<K, V>();
            ox::container::push_back(new_container, key, value);
            map->container[index] = new_container;
            return;
        } else {
            ox::bucket::Bucket<K, V>* bucket = ox::container::get(map->container[index], key);
            
            if (bucket->key == key) {
                printf(" >> There is one more...\n");
                printf("%lu: { \"%s\": \"%s\" }\n", index, key.c_str(), value.c_str());
                ox::container::remove(map->container[index], key);
                ox::container::push_back(map->container[index], key, value);
                return;
            }

            printf(" >> Appending new element...\n");
            printf("%lu: { \"%s\": \"%s\" }\n", index, key.c_str(), value.c_str());
            ox::container::push_back(on_use, key, value);
            return;
        }

    }

    template<typename K, typename V>
    std::optional<V> get(HashMap<K, V>* map, K key) {
        size_t index = hash(key);
        printf("Searching: (%lu) %s\n", index, key.c_str());

        if (map->container[index] == NULL) {
            printf("There is no element for this key...\n");
            return {};
        }

        ox::bucket::Bucket<K, V>* bucket = ox::container::get(map->container[index], key);
        V value = bucket->value;
        return std::optional<V>{value};

        //ox::bucket::Bucket<K, V>* bucket = map->container[index];
        
    }
    
}

#endif