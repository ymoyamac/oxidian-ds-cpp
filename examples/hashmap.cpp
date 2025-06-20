#include "oxidian.hpp"

int main() {
    
    ox::hashmap::HashMap<std::string, std::string>* map = ox::hashmap::create_map<std::string, std::string>();

    //In serting new values
    printf("++++++++++++++++++++++++\n");
    ox::hashmap::set<std::string, std::string>(map, "Ror!", "Rar!");
    printf("++++++++++++++++++++++++\n");
    ox::hashmap::set<std::string, std::string>(map, "Ping", "Pong");
    printf("++++++++++++++++++++++++\n");
    ox::hashmap::set<std::string, std::string>(map, "Buzz", "Bass");
    printf("++++++++++++++++++++++++\n");
    ox::hashmap::set<std::string, std::string>(map, "Hello", "World!");
    printf("++++++++++++++++++++++++\n");
    ox::hashmap::set<std::string, std::string>(map, "Hash", "Table");
    printf("++++++++++++++++++++++++\n");

    //Overwriting keys
    printf("++++++++++++++++++++++++\n");
    ox::hashmap::set<std::string, std::string>(map, "Ping", "Bass");
    printf("++++++++++++++++++++++++\n");
    ox::hashmap::set<std::string, std::string>(map, "Ror!", "OmegaRor!");
    printf("++++++++++++++++++++++++\n");

    //Getting the key value
    std::optional<std::string> hello = ox::hashmap::get<std::string, std::string>(map, "Hello");
    if (hello.has_value()) {
        printf("Value: %s\n", hello.value().c_str()); // -> Value: World!
    }

    //Getting the last value inserted
    std::optional<std::string> ping = ox::hashmap::get<std::string, std::string>(map, "Ping");
    if (ping.has_value()) {
        printf("Value: %s\n", ping.value().c_str()); // -> Value: Bass
    }
    
    //Getting hashmap size
    printf("Size: %lu\n", ox::hashmap::size(map));

    std::vector<std::string> keys = ox::hashmap::unorder_keys(map);
    printf("{");
    for (size_t i = 0; i < keys.size(); i++) {
        printf("%s", keys[i].c_str());
        if (i != keys.size() - 1) {
            printf(", ");
        }
    }
    printf("}\n");

    

    return 0;   
}