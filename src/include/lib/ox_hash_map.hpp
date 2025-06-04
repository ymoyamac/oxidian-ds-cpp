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
        return (HashMap<K, V>*) std::malloc(sizeof(HashMap<K, V>));
    }

    template<typename K, typename V>
    void set(HashMap<K, V>* map, K key, V value) {
        size_t index = hash(key);
        printf("%lu: { \"%s\": \"%s\" }\n", index, key.c_str(), value.c_str());

        if (map->container[index] == NULL) {
            ox::container::Container<K, V>* container = ox::container::init<K, V>();
            ox::container::push_back(container, key, value);
            map->container[index] = container;
            return;
        }
        
        if (map->container[index] != NULL) {
            ox::container::Container<K, V>* on_use = map->container[index];
            ox::container::push_back(on_use, key, value);
            return;
        }

    }

    template<typename K, typename V>
    std::optional<V> get(HashMap<K, V>* map, K key) {
        size_t index = hash(key);
        printf("Searching: %lu\n", index);

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