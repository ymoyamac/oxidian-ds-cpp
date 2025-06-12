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
    std::string value4 = "Mapping";

    cluster::push_back<std::string, std::string>(*container, key, value);
    cluster::push_back<std::string, std::string>(*container, key1, value1);
    cluster::push_back<std::string, std::string>(*container, key2, value2);
    cluster::push_back<std::string, std::string>(*container, key3, value3);

    cluster::fmt<std::string, std::string>(*container);
    auto opt_entry = cluster::get<std::string, std::string>(*container, key2);
    if (opt_entry.has_value()) {
        entry::fmt(*opt_entry.value().first);
    }
    cluster::push_back<std::string, std::string>(*container, key2, value4);
    cluster::fmt<std::string, std::string>(*container);


    auto opt_popped = cluster::pop<std::string, std::string>(*container);
    if (opt_popped.has_value()) {
        entry::fmt<std::string, std::string>(*opt_popped.value().get());
    }
    cluster::fmt<std::string, std::string>(*container);

    cluster::remove<std::string, std::string>(*container, key3);
    cluster::fmt<std::string, std::string>(*container);

    auto not_found = cluster::get<std::string, std::string>(*container, value4);
    if (not_found.has_value()) {
        entry::fmt(*not_found.value().first);
    } else {
        printf(" >> Not found with key {%s}...\n", value4.c_str());
    }
    return 0;   
}