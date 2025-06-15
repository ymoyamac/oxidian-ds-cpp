#include "oxidian.hpp"

namespace ox::double_node {

    template<typename T>
    struct DNode {
        std::unique_ptr<DNode<T>> left;
        std::unique_ptr<DNode<T>> rigth;
        T value;
        bool is_leaf = true;
    };

    template<typename T>
    std::unique_ptr<DNode<T>> init() {
        return std::make_unique<DNode<T>>();
    }

    template<typename T>
    std::unique_ptr<DNode<T>> init(const T& value) {
        std::unique_ptr<DNode<T>> node = std::make_unique<DNode<T>>();
        node->left = nullptr;
        node->rigth = nullptr;
        node->value = value;
        return node;
    }

    template<typename T>
    void fmt(DNode<T>& node) {
        printf("  Node{ \"%s\": \"%s\" }", iter->key.c_str(), iter->value.c_str());
    }
}