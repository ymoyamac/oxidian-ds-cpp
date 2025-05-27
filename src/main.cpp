#include <oxidian.h>

int main() {

    std::string key = "refe";
    size_t h = collection::hash(key);
    printf("Hash: %lu\n", h);

    return 0;   
}