#include <oxidian.hpp>

int main() {

    using namespace ox;
    
    std::unique_ptr<cluster::Cluster<std::string, std::string>> container = cluster::init<std::string, std::string>();
    printf("Address: %p\n", &container);

    std::string key = "Hello";
    std::string value = "World!";
    std::string key1 = "Bizz";
    std::string value1 = "Buzz";
    std::string key2 = "Ping";
    std::string value2 = "Pong";
    std::string key3 = "Next";
    std::string value3 = "Node";

    cluster::push_back<std::string, std::string>(*container, key, value);
    cluster::push_back<std::string, std::string>(*container, key1, value1);
    cluster::push_back<std::string, std::string>(*container, key2, value2);
    cluster::push_back<std::string, std::string>(*container, key3, value3);

    cluster::fmt<std::string, std::string>(*container);
    auto pair = cluster::get<std::string, std::string>(*container, key2);
    entry::fmt(*pair.first);
    cluster::push_back<std::string, std::string>(*container, key2, value2);
    cluster::fmt<std::string, std::string>(*container);


    auto opt_popped = cluster::pop<std::string, std::string>(*container);
    printf(" >> Pop...\n");
    if (opt_popped.has_value()) {
        entry::fmt<std::string, std::string>(*opt_popped.value().get());
    }
    cluster::fmt<std::string, std::string>(*container);

    cluster::remove<std::string, std::string>(*container, key3);
    cluster::fmt<std::string, std::string>(*container);


    return 0;   
}