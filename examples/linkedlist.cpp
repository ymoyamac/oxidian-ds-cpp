#include "oxidian.hpp"

int main() {
    
    ox::linked_list::linkedlist_t* ll = ox::linked_list::init();

    ox::linked_list::init();

    int nums[10] = {1, 5, 7, 13, 18, 21, 29};

    for (int i = 0; i < 10; i++)
    {
        void* data = &nums[i];
        ox::linked_list::push_back(ll, data);
    }
    
    ox::linked_list::fmt(ll); // -> $ 1, 5, 7, 13, 18, 21, 29, 0, 0, 0
    ox::linked_list::remove(ll, 2);
    ox::linked_list::remove(ll, 2);
    ox::linked_list::remove(ll, 4);
    ox::linked_list::fmt(ll); // -> $ 1, 5, 18, 21, 0, 0, 0
    int first = 105;
    ox::linked_list::push_front(ll, &first);
    ox::linked_list::fmt(ll); // -> $ 105, 1, 5, 18, 21, 0, 0, 0
    int second = 203;
    ox::linked_list::push_at(ll, &second, 6);
    ox::linked_list::fmt(ll); // -> $ 105, 1, 5, 18, 21, 0, 203, 0, 0
    return 0;   
}