#ifndef _OX_CONTAINER_H
#define _OX_CONTAINER_H

#include <oxidian.hpp>

namespace ox::container {

    template<typename K, typename V>
    struct Container {
        ox::bucket::Bucket<K, V>* head = nullptr;
        ox::bucket::Bucket<K, V>* tail = nullptr;
        int size;
    };
    
}

#endif