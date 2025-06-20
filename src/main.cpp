#include "oxidian.hpp"

int main() {

    using namespace ox;

    std::unique_ptr<tree::BinaryTree<int>> binary_tree = tree::init<int>();

    tree::insert<int>(*binary_tree, 11);
    tree::insert<int>(*binary_tree, 9);
    tree::insert<int>(*binary_tree, 6);
    tree::insert<int>(*binary_tree, 14);


    return 0;
}