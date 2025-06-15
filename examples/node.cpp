#include <oxidian.hpp>

int main() {

    int first = 10;
    void* data = &first;
    ox::simple_node::node_t* nn = ox::simple_node::init(data);

    printf("Data: %i", *(int*)nn->get_data(nn));

    return 0;
}