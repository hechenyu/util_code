#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "unordered_map_extern_c.h"

void print_key_value(const unordered_map_key_t *key, unordered_map_value_t val)
{
    printf("%*.*s: %d\n", (int) key->len, (int) key->len, (char *) key->key, *(int *) val);
}

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("usage: test file\n");
        exit(1);
    }

    char *filename = argv[1];

    FILE *file;
    char buf[256];
    if ((file = fopen(filename, "r")) == NULL) {
        perror("open file fail");
        exit(1);
    }

    unordered_map_t *map;
    map = unordered_map_create(1000);

    unordered_map_key_t key;
    unordered_map_value_t val;

    char separators[ ] = " \t\n.:?!\";/[]{}()1234567890\\=,+-'%*#<>";
    char *start = NULL, *end = NULL;
    char *word;
    while (fgets(buf, sizeof(buf), file) != NULL) {
        start = buf;
        while ( ( end = strpbrk( start, separators ) ) != NULL ) {
            if ( end != start ) // If the separator wasn't the first character,
                { // then save a word in an array.
                    word = malloc(end - start + 1);
                    strncpy( word, start, end - start );
                    word[end - start] = '\0'; // And terminate it.
                    key.key = word;
                    key.len = end - start;
                    if ((val = unordered_map_find(map, &key)) == NULL) {
                        val = malloc(sizeof(int));
                        *(int *) val = 1;
                        unordered_map_insert(map, &key, val);
                    } else {
                        *(int *) val += 1;
                    }
                }
            start = end + 1; // Next strpbrk call starts with
        } // the character after this separator.
    }

    unordered_map_foreach(map, print_key_value);

    fclose(file);

    return 0;
}
