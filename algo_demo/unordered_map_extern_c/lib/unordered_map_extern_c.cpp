#include "unordered_map_extern_c.h"
#include "hash_function.h"
#include <cstring>
#include <utility>
#include <unordered_map>

namespace {

inline 
int default_equal_func(unordered_map_key_t *key1, unordered_map_key_t *key2)
{
    size_t len = std::min(key1->len, key2->len);
    return memcmp(key1->key, key2->key, len) == 0 && key1->len == key2->len;
}

struct key_equal {
    equal_func *comp;

    key_equal(): comp(default_equal_func) {}
    key_equal(equal_func *f): comp(f) {}

    bool operator ()(unordered_map_key_t key1, unordered_map_key_t key2)
    {
        return comp(&key1, &key2) == 0;
    }
};

inline
size_t default_hash_func(unordered_map_key_t *key)
{
    return hash_function::hash(key->key, key->len);
}

struct hasher {
    hash_func *hash;

    hasher(): hash(default_hash_func) {}
    hasher(hash_func *f): hash(f) {}

    size_t operator ()(unordered_map_key_t key)
    {
        return hash(&key);
    }
};

}   // namespace {

#if 0
struct unordered_map_s {
    std::unordered_map<unordered_map_key_t, unordered_map_value_t, hasher, key_equal>
};
#endif
