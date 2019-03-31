// https://leetcode.com/problems/two-sum/
#include <assert.h>
#include <stdlib.h>

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

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *twoSum(int *nums, int numsSize, int target)
{
    int *result;
    hash_table_t *table;
    hash_entry_t *entry;
    int remain;
    int i;

    result = (int *) malloc(sizeof(int) * 2);
    table = hash_table_create(64);

    for (i = 0; i < numsSize; i++) {
        remain = target - nums[i];
        entry = hash_table_get(table, remain);

        if (entry != NULL) {
            result[0] = entry->value;
            result[1] = i;
            hash_table_destroy(table);
            return result;
        }

        hash_table_insert(table, nums[i], i);
    }

    hash_table_destroy(table);
    return result;
}

void test1()
{
    int nums[4] = {2, 7, 11, 15};
    int target = 9;
    int *result;

    result = twoSum(nums, 4, target);
    assert(result[0] != result[1]);
    assert(nums[result[0]] + nums[result[1]] == target);
    free(result);
}

void test2()
{
    int nums[4] = {0, 4, 3, 0};
    int target = 0;
    int *result;

    result = twoSum(nums, 4, target);
    assert(result[0] != result[1]);
    assert(nums[result[0]] + nums[result[1]] == target);
    free(result);
}

int main()
{
    test1();
    test2();
    return 0;
}
