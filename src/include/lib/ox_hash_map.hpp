#ifndef _OX_HASH_MAP_H
#define _OX_HASH_MAP_H

#include <oxidian.hpp>

namespace ox::hashmap {

    const uint INITIAL_CAPACITY = 64;
    const double LOAD_FACTOR = 0.75;
    
    template<typename K, typename V>
    struct HashMap {
        std::array<std::unique_ptr<cluster::Cluster<K, V>>, INITIAL_CAPACITY> containers;
        size_t capacity = INITIAL_CAPACITY;
        size_t size = 0;
    };

    template<typename K, typename V>
    std::unique_ptr<HashMap<K, V>> init() {
        return std::make_unique<HashMap<K, V>>();
    }

    size_t fbv1a(const std::string &key);

    template<typename K>
    size_t hash(const K &key) {
        return fbv1a(key) % INITIAL_CAPACITY;
    }

    template<typename K, typename V>
    void set(HashMap<K, V> &hashmap, const K &key, const V &value) {
        size_t index = hash(key);
        if (!hashmap.containers[index]) {
            hashmap.containers[index] = cluster::init<K, V>();
        }
        cluster::push_back<K, V>(*hashmap.containers[index], key, value);

    }

    template<typename K, typename V>
    std::optional<V> get(HashMap<K, V> &hashmap, const K &key) {
        size_t index = hash(key);

        auto opt_entry = cluster::get<K, V>(*hashmap.containers[index], key);
        if (!opt_entry) {
            return std::nullopt;
        }
        const auto& [entry, _] = *opt_entry;
        return entry->value;
    }
    
}

#endif