#include <oxidian.hpp>

int main() {

    int first = 10;
    void* data = &first;
    node::node_t* nn = node::init(data);

    printf("Data: %i", *(int*)nn->get_data(nn));

    return 0;
}