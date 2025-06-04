#include <oxidian.hpp>

int main() {

    
    ox::hashmap::HashMap<std::string, std::string>* map = ox::hashmap::create_map<std::string, std::string>();

    ox::hashmap::set<std::string, std::string>(map, "aaabc", "Rar!");
    ox::hashmap::set<std::string, std::string>(map, "Hola", "Mundo");
    ox::hashmap::set<std::string, std::string>(map, "Holaa", "Mundo");

    std::optional<std::string> value_opt = ox::hashmap::get<std::string, std::string>(map, "aaabc");
    std::optional<std::string> value_two_opt = ox::hashmap::get<std::string, std::string>(map, "Hola");


    return 0;   
}