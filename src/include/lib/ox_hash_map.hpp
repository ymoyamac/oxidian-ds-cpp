#ifndef _OX_HASH_MAP_H
#define _OX_HASH_MAP_H

#include <oxidian.hpp>

namespace ox::hashmap {

    const uint INITIAL_CAPACITY = 5;
    const double LOAD_FACTOR = 0.75;
    
    template<typename K, typename V>
    struct HashMap {
        std::array<ox::set::Cluster<K, V>*, INITIAL_CAPACITY> containers;
        size_t capacity = INITIAL_CAPACITY;
        size_t size = 0;
    };

    size_t fbv1a(const std::string &key);

    template<typename K>
    size_t hash(const K &key) {
        return fbv1a(key) % INITIAL_CAPACITY;
    }

    
}

#endif