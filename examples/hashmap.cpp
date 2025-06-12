#include <oxidian.hpp>

int main() {
    
    using namespace ox;
    std::string key = "Hello";
    std::string value = "World!";
    std::string key1 = "Bazz";
    std::string value1 = "Buzz";
    std::string key2 = "Ping";
    std::string value2 = "Pong";
    std::string key3 = "Next!";
    std::string value3 = "Node";
    std::string value4 = "Rust";
    std::unique_ptr<hashmap::HashMap<std::string, std::string>> map = hashmap::init<std::string, std::string>();

    hashmap::set<std::string, std::string>(*map, key, value);
    hashmap::set<std::string, std::string>(*map, key1, value1);
    hashmap::set<std::string, std::string>(*map, key2, value2);
    hashmap::set<std::string, std::string>(*map, key3, value3);
    hashmap::set<std::string, std::string>(*map, key2, value4);


    auto res = hashmap::get<std::string, std::string>(*map, key3);
    if (res.has_value()) {
        printf("Value: %s\n", res.value().c_str());
    }

    return 0;   
}