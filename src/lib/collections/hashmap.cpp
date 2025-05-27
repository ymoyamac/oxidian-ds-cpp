#include <oxidian.h>

namespace collection {

    size_t fbv1a(const std::string &key) {
        printf("key: %s\n", key.c_str());
        const size_t FNV_OFFSET = 14695981039346656037ull;
        const size_t FNV_PRIME = 1099511628211ull;
        size_t hash = FNV_OFFSET;

        for (size_t i = 0; i < key.length(); ++i) {
            hash ^= static_cast<size_t>(key[i]);
            hash *= FNV_PRIME;
        }

        printf("Hashing... %lu\n", hash);
        
        return hash;
    }


}