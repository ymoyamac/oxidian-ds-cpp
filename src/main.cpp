#include <oxidian.hpp>

int main() {

    
    ox::hashmap::HashMap<std::string, std::string>* map = ox::hashmap::create_map<std::string, std::string>();

    ox::hashmap::set<std::string, std::string>(map, "Ror!", "Rar!");
    ox::hashmap::set<std::string, std::string>(map, "Ping", "Pong");
    ox::hashmap::set<std::string, std::string>(map, "Buzz", "Bass");

    std::optional<std::string> word = ox::hashmap::get<std::string, std::string>(map, "Buzz");

    printf("Value: %s\n", word.value().c_str());


    return 0;   
}