#ifndef _OX_BUCKET_H
#define _OX_BUCKET_H

#include <oxidian.hpp>

namespace ox::bucket {

    template<typename K, typename V>
    struct Bucket {
        K key = nullptr;
        V value = nullptr;
        bool is_taken;
        Bucket<K, V>* next = nullptr;
    };

    template<typename K, typename V>
    Bucket<K, V>* init() {
        return (Bucket<K, V>*) std::malloc(sizeof(Bucket<K, V>));
    }

    template<typename K, typename V>
    Bucket<K, V>* init(K &key, V &value) {
        Bucket<K, V>* bucket = (Bucket<K, V>*) std::malloc(sizeof(Bucket<K, V>));
        bucket->key = key;
        bucket->value = value;
        bucket->is_taken = true;
        bucket->next = nullptr;
        return bucket;
    }
}

#endif