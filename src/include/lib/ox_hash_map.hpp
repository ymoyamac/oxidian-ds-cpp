#ifndef _OX_HASH_MAP_H
#define _OX_HASH_MAP_H

#include <oxidian.hpp>

namespace ox::hashmap {

    const uint INITIAL_CAPACITY = 5;
    const double LOAD_FACTOR = 0.75;
    
    template<typename K, typename V>
    struct HashMap {
        std::array<ox::bucket::Bucket<K, V>*, INITIAL_CAPACITY> buckets;
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

        if (map->buckets[index] != NULL) {

            

            return;
            
        }
        
        ox::bucket::Bucket<K, V>* bucket = ox::bucket::create_bucket(index, key, value);
       
        map->buckets[index] = bucket;
        map->size += 1;
    }

    template<typename K, typename V>
    std::optional<V> get(HashMap<K, V>* map, K key) {
        size_t index = hash(key);
        printf("Searching: %lu\n", index);

        if (map->buckets[index] == NULL) {
            printf("No such element...\n");
            return {};
        }
        ox::bucket::Bucket<K, V>* bucket = map->buckets[index];
        V value = bucket->value;
        return std::optional<V>{value};
    }
    
}

#endif