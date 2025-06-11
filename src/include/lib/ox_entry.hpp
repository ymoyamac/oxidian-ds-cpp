#ifndef _OX_BUCKET_H
#define _OX_BUCKET_H

#include <oxidian.hpp>

namespace ox::bucket {

    template<typename K, typename V>
    struct Entry {
        K key;
        V value;
        bool is_taken = false;
        std::unique_ptr<Entry<K, V>> next;
    };

    template<typename K, typename V>
    std::unique_ptr<Entry<K, V>> init() {
        return std::make_unique<Entry<K, V>>();
    }

    template<typename K, typename V>
    std::unique_ptr<Entry<K, V>> init(const K &key,const V &value) {
        std::unique_ptr<Entry<K, V>> bucket_ptr = std::make_unique<Entry<K, V>>();
        bucket_ptr->key = key;
        bucket_ptr->value = value;
        bucket_ptr->is_taken = true;
        bucket_ptr->next = nullptr;
        return bucket_ptr;
    }

    template<typename K, typename V>
    void fmt(const Entry<K, V> &bucket) {
        printf("Entry{ \"%s\": \"%s\" }\n", bucket.key.c_str(), bucket.value.c_str());
    }
}

#endif