#include <oxidian.hpp>

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
    ox::hashmap::set<std::string, std::string>(map, "Buzz", "World!");
    printf("++++++++++++++++++++++++\n");

    ox::hashmap::fmt(map);


    printf("++++++++++++++++++++++++\n");
    ox::hashmap::remove<std::string, std::string>(map, "Ror!");
    printf("++++++++++++++++++++++++\n");

    ox::hashmap::fmt(map);
    
    printf("Size: %lu\n", ox::hashmap::size(map));

    return 0;   
}