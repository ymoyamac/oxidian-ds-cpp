#include <oxidian.hpp>

int main() {

    using namespace ox;
    
    std::unique_ptr<set::Cluster<std::string, std::string>> container = set::init<std::string, std::string>();
    printf("Address: %p\n", &container);

    std::string key = "Hello";
    std::string value = "World!";
    std::string key1 = "Bizz";
    std::string value1 = "Buzz";
    std::string key2 = "Ping";
    std::string value2 = "Pong";
    std::string key3 = "Next";
    std::string value3 = "Node";

    set::push_back<std::string, std::string>(*container, key, value);
    set::push_back<std::string, std::string>(*container, key1, value1);
    set::push_back<std::string, std::string>(*container, key2, value2);
    set::push_back<std::string, std::string>(*container, key3, value3);

    set::fmt<std::string, std::string>(*container);
    auto pair = set::get<std::string, std::string>(*container, key2);
    bucket::fmt(*pair.first);
    set::push_back<std::string, std::string>(*container, key2, value2);
    set::fmt<std::string, std::string>(*container);


    auto opt_popped = set::pop<std::string, std::string>(*container);
    printf(" >> Pop...\n");
    if (opt_popped.has_value()) {
        bucket::fmt<std::string, std::string>(*opt_popped.value().get());
    }
    set::fmt<std::string, std::string>(*container);

    set::remove<std::string, std::string>(*container, key3);
    set::fmt<std::string, std::string>(*container);


    return 0;   
}