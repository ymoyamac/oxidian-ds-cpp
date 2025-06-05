#include <oxidian.hpp>

int main() {

    
    ox::hashmap::HashMap<std::string, std::string>* map = ox::hashmap::create_map<std::string, std::string>();

    printf("++++++++++++++++++++++++\n");
    ox::hashmap::set<std::string, std::string>(map, "Ror!", "Rar!");
    printf("++++++++++++++++++++++++\n");
    ox::hashmap::set<std::string, std::string>(map, "Ping", "Pong");
    printf("++++++++++++++++++++++++\n");
    ox::hashmap::set<std::string, std::string>(map, "Ping", "Bass");
    //ox::hashmap::set<std::string, std::string>(map, "Hello", "Bass");
    //ox::hashmap::set<std::string, std::string>(map, "Hello", "World!");
    printf("++++++++++++++++++++++++\n");

    std::optional<std::string> word = ox::hashmap::get<std::string, std::string>(map, "Ping");
    //std::optional<std::string> word = ox::hashmap::get<std::string, std::string>(map, "Hello");

    if (word.has_value()) {
        printf("Value: %s\n", word.value().c_str());
    }

    return 0;   
}