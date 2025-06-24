#ifndef _OX_BINARY_TREE_H
#define _OX_BINARY_TREE_H

#include "oxidian.hpp"

namespace ox::tree {
    
    template<typename T>
    struct BinaryTree {
        std::unique_ptr<node::DNode<T>> root;
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
    int height(const std::unique_ptr<node::DNode<T>>& node) {
        if (!node) return 0;
        int left_height = height(node->left);
        int right_height = height(node->right);
        return 1 + std::max(left_height, right_height);
    }

    template<typename T>
    void fmt(const BinaryTree<T>& tree) {
        if (!tree.root) {
            std::cout << "Tree is empty.\n";
            return;
        }

        using NodePtr = node::DNode<T>*;

        std::queue<NodePtr> queue;
        queue.push(tree.root.get());

        int h = height(tree.root);
        int max_nodes = std::pow(2, h) - 1;
        int level = 0;

        while (!queue.empty() && level < h) {
            int nodes_in_level = std::pow(2, level);
            int spacing = std::pow(2, h - level);

            std::cout << std::setw(spacing / 2) << "";

            for (int i = 0; i < nodes_in_level; ++i) {
                NodePtr current = queue.front();
                queue.pop();

                if (current) {
                    std::cout << current->data;
                    queue.push(current->left.get());
                    queue.push(current->right.get());
                } else {
                    std::cout << " ";
                    queue.push(nullptr);
                    queue.push(nullptr);
                }

                std::cout << std::setw(spacing) << "";
            }

            std::cout << "\n";
            ++level;
        }
    }

    template<typename T>
    void insert_into(std::unique_ptr<node::DNode<T>>& iter, const T& data) {
        if (!iter) {
            iter = node::init(data);
            return;
        }

        if (data == iter->data) {
            printf("    >> This data already exists...\n");
            return;
        }
        if (data < iter->data) {
            printf("    >> Left...\n");
            insert_into(iter->left, data);
        } else {
            printf("    >> Right...\n");
            insert_into(iter->right, data);
        }
    }

    template<typename T>
    void insert(BinaryTree<T>& tree, const T& data) {
        printf("[Data]: %i...\n", data);
        if (tree.root == nullptr) {
            printf("    >> Tree is empty...\n");
            tree.root = node::init(data);
            tree.levels = 1; // levels = 1
            return;
        }

        insert_into<T>(tree.root, data);
        
    }

    

} // namespace tree

#endif