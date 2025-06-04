#ifndef _OX_BUCKET_H
#define _OX_BUCKET_H

#include <oxidian.hpp>

namespace ox::bucket {

    template<typename K, typename V>
    struct Bucket {
        size_t index;
        K key;
        V value;
        bool is_taken;
        Bucket<K, V>* next = nullptr;
    };

    template<typename K, typename V>
    Bucket<K, V>* create_bucket(size_t index, K &key, V &value) {
        Bucket<K, V>* bucket = (Bucket<K, V>*) std::malloc(sizeof(Bucket<K, V>));
        bucket->index = index;
        bucket->key = key;
        bucket->value = value;
        bucket->is_taken = true;
        bucket->next = nullptr;
        return bucket;
    }
}

#endif