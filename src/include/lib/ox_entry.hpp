#ifndef _OX_ENTRY_H
#define _OX_ENTRY_H

#include <oxidian.hpp>

namespace ox::entry {

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
        std::unique_ptr<Entry<K, V>> entry_ptr = std::make_unique<Entry<K, V>>();
        entry_ptr->key = key;
        entry_ptr->value = value;
        entry_ptr->is_taken = true;
        entry_ptr->next = nullptr;
        return entry_ptr;
    }

    template<typename K, typename V>
    void fmt(const Entry<K, V> &entry) {
        printf("Entry{ \"%s\": \"%s\" }\n", entry.key.c_str(), entry.value.c_str());
    }
}

#endif