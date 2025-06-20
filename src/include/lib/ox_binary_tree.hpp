#ifndef _OX_BINARY_TREE_H
#define _OX_BINARY_TREE_H

#include "oxidian.hpp"

namespace ox::tree {
    
    template<typename T>
    struct BinaryTree {
        std::unique_ptr<double_node::DNode<T>> root;
        uint8_t levels;
    };

    
    template<typename T>
    std::unique_ptr<BinaryTree<T>> init() {
        std::unique_ptr<BinaryTree<T>> tree = std::make_unique<BinaryTree<T>>();
        tree->root = nullptr;
        tree->levels = 0;
        return tree;
    }

    template<typename T>
    void insert_into(double_node::DNode<T>* iter, const T& data) {
        std::unique_ptr<double_node::DNode<T>> new_node = double_node::init(data);
        if (data == iter->data) {
            printf("    >> This data already exists...\n");
            return;
        }
        if (data < iter->data) {
            printf("    >> Left...\n");
            //left side
            if (iter->left == nullptr) {
                iter->left = std::move(new_node);
                return;
            } else {
                iter = iter->left.get();
                printf("    >> Another one...\n");
                insert_into<T>(iter, data);
            }
        } else {
            printf("    >> Right...\n");
            //right side
            if (iter->right == nullptr) {
                iter->right = std::move(new_node);
                return;
            } else {
                iter = iter->right.get();
                printf("    >> Another one...\n");
                insert_into<T>(iter, data);
            }
        }
        
        
    }

    template<typename T>
    void insert(BinaryTree<T>& tree, const T& data) {
        printf("[Data]: %i...\n", data);
        if (tree.root == nullptr) {
            printf("    >> Tree is empty...\n");
            tree.root = std::move(double_node::init(data));
            return;
        }

        insert_into<T>(tree.root.get(), data);
        
        
    }

    

} // namespace tree

#endif