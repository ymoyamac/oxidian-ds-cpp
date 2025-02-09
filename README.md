linked_list::linkedlist_t* ll = linked_list::init();

    int numbers[] = {1, 2, 3, 4, 5, 6};

    for (size_t i = 0; i < 6; i++) {
        linked_list::push_back(ll, &numbers[i]);

    }
    
    linked_list::rprint_list(ll);
    

    printf("Size: %i\n", linked_list::size(ll));
    linked_list::drop(ll);