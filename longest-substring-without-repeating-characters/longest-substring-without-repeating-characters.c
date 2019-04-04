// https://leetcode.com/problems/longest-substring-without-repeating-characters/
#include <assert.h>
#include <stdlib.h>
#include <string.h>

/**
 * Implementation of a hash table.
 */
typedef struct hash_entry {
    int key;
    int value;
    struct hash_entry *next;
} hash_entry_t;

typedef struct hash_table {
    int size;
    hash_entry_t **entries;
} hash_table_t;

hash_table_t *hash_table_create(int size)
{
    hash_table_t *table = NULL;
    int i;

    if (size < 1) {
        return NULL;
    }

    table = (hash_table_t *) malloc(sizeof(hash_table_t));
    table->entries = (hash_entry_t **) malloc(sizeof(hash_entry_t *) * size);

    for (i = 0; i < size; i++) {
        table->entries[i] = NULL;
    }

    table->size = size;

    return table;
}

unsigned int hash_table_hash(hash_table_t *table, int key)
{
    int hash = key % table->size;
    return hash >= 0 ? hash : hash + table->size;
}

hash_entry_t *hash_table_new_entry(int key, int value)
{
    hash_entry_t *entry;

    entry = (hash_entry_t *) malloc(sizeof(hash_entry_t));
    entry->key = key;
    entry->value = value;
    entry->next = NULL;

    return entry;
}

void hash_table_insert(hash_table_t *table, int key, int value)
{
    unsigned int hash = hash_table_hash(table, key);
    hash_entry_t *last;
    hash_entry_t *next;
    hash_entry_t *new_entry;

    next = table->entries[hash];

    if (next == NULL) {
        new_entry = hash_table_new_entry(key, value);
        table->entries[hash] = new_entry;
        return;
    }

    while (next != NULL) {
        if (next->key == key) {
            next->value = value;
            return;
        }

        last = next;
        next = next->next;
    }

    new_entry = hash_table_new_entry(key, value);
    last->next = new_entry;
}

hash_entry_t *hash_table_get(hash_table_t *table, int key)
{
    unsigned int hash = hash_table_hash(table, key);
    hash_entry_t *next;

    next = table->entries[hash];

    while (next != NULL) {
        if (next->key == key) {
            return next;
        }

        next = next->next;
    }

    return NULL;
}

void hash_table_destroy(hash_table_t *table)
{
    hash_entry_t *entry;
    hash_entry_t *next;
    int i;

    for (i = 0; i < table->size; i++) {
        entry = table->entries[i];

        if (entry == NULL) {
            continue;
        }

        while (entry != NULL) {
            next = entry->next;
            free(entry);
            entry = next;
        }
    }

    free(table->entries);
    free(table);
}

int lengthOfLongestSubstring(char *s)
{
    hash_table_t *table;
    size_t len;
    size_t i;
    int max_len = 0;
    int start = 0;

    table = hash_table_create(32);
    len = strlen(s);

    for (i = 0; i < len; i++) {
        hash_entry_t *entry;
        entry = hash_table_get(table, (int) s[i]);

        if (entry == NULL) {
            hash_table_insert(table, (int) s[i], i);
            continue;
        }

        if (entry->value >= start) {
            if (i - start > max_len) {
                max_len = i - start;
            }

            start = entry->value + 1;
        }

        entry->value = i;
    }

    if (i - start > max_len) {
        max_len = i - start;
    }

    hash_table_destroy(table);
    return max_len;
}

/**
 * Test code.
 */
void test1()
{
    char *input = "abcabcbb";
    int result;

    result = lengthOfLongestSubstring(input);
    assert(result == 3);
}

void test2()
{
    char *input = "bbbbb";
    int result;

    result = lengthOfLongestSubstring(input);
    assert(result == 1);
}

void test3()
{
    char *input = "pwwkew";
    int result;

    result = lengthOfLongestSubstring(input);
    assert(result == 3);
}

void test4()
{
    char *input = "abba";
    int result;

    result = lengthOfLongestSubstring(input);
    assert(result == 2);
}

int main()
{
    test1();
    test2();
    test3();
    test4();
    return 0;
}
