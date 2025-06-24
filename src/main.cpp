#include "oxidian.hpp"

int main() {

    using namespace ox;

    std::unique_ptr<tree::BinaryTree<int>> binary_tree = tree::init<int>();

    tree::insert<int>(*binary_tree, 11);
    tree::insert<int>(*binary_tree, 6);
    tree::insert<int>(*binary_tree, 27);
    tree::insert<int>(*binary_tree, 10);
    tree::insert<int>(*binary_tree, 1);
    tree::insert<int>(*binary_tree, 8);
    tree::insert<int>(*binary_tree, 19);
    tree::insert<int>(*binary_tree, -2);
    tree::insert<int>(*binary_tree, 5);
    tree::insert<int>(*binary_tree, 3);
    tree::insert<int>(*binary_tree, 43);
    tree::insert<int>(*binary_tree, 21);
    tree::insert<int>(*binary_tree, 34);

    tree::fmt<int>(*binary_tree);
        
    return 0;
}