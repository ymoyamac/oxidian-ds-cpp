#ifndef _OX_HASH_MAP_H
#define _OX_HASH_MAP_H

#define CAPACITY 69;
#define LOAD_FACTOR 0.75;

#include <oxidian.h>

namespace collection {

    template<typename Key, typename Value>
    struct Bucket {
        Key key;
        Value value;
    };
    
    template<typename K, typename V>
    struct HashMap {
        std::vector< Bucket<K, V> > buckets;
        size_t capacity;
        size_t size;
    };

    size_t fbv1a(const std::string &key);

    template<typename K>
    size_t hash(const K &key) {
        return fbv1a(key) % CAPACITY;
    }
    
}

#endif