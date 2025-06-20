#ifndef _OX_DOUBLE_NODE_H
#define _OX_DOUBLE_NODE_H

#include "oxidian.hpp"

namespace ox::double_node {

    template<typename T>
    struct DNode {
        std::unique_ptr<DNode<T>> left;
        std::unique_ptr<DNode<T>> right;
        T data;
        bool is_leaf = true;
    };

    template<typename T>
    std::unique_ptr<DNode<T>> init() {
        return std::make_unique<DNode<T>>();
    }

    template<typename T>
    std::unique_ptr<DNode<T>> init(const T& data) {
        std::unique_ptr<DNode<T>> node = std::make_unique<DNode<T>>();
        node->left = nullptr;
        node->right = nullptr;
        node->data = data;
        return node;
    }

    template<typename T>
    void fmt(DNode<T>& node) {
        
    }
}

#endif