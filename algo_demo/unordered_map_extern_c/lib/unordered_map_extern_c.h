#ifndef __unordered_map_extern_c_h
#define __unordered_map_extern_c_h

#include <stddef.h>

struct unordered_map_s;
typedef struct unordered_map_s unordered_map_t;

typedef struct unordered_map_key_s {
    const void *key;        // 指向key所在内存的指针
    size_t len;             // key的长度
} unordered_map_key_t;

typedef void *unordered_map_value_t;

#ifdef __cplusplus
extern "C" {
#endif

// 如果两个key相等, 返回0, 其他返回非0
typedef int equal_func(unordered_map_key_t *, unordered_map_key_t *);

typedef size_t hash_func(unordered_map_key_t *);

// 创建一个unordered_map
unordered_map_t *unordered_map_create(size_t n);

// 释放一个unordered_map
void unordered_map_destroy(unordered_map_t *map);

// 向hash表里插入一项
// 如果成功, 返回0,
// 如果已经存在相同key的项, 返回非0
int unordered_map_insert(unordered_map_t *map, unordered_map_key_t *key, unordered_map_value_t *value);

// 从hash表里查找一项
// 如果没有符合的项, 返回NULL
unordered_map_value_t *unordered_map_find(unordered_map_t *map, unordered_map_key_t *key);

// 从hash表里删除一项
// 如果没有符合的项, 返回NULL
unordered_map_value_t *unordered_map_delete(unordered_map_t *map, unordered_map_key_t *key);

#ifdef __cplusplus
}   // extern "C" {
#endif

#endif

