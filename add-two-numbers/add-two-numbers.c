// https://leetcode.com/problems/add-two-numbers/
#include <assert.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *list_init(int val)
{
    struct ListNode *list;

    list = (struct ListNode *) malloc(sizeof(struct ListNode));
    list->val = val;
    list->next = NULL;

    return list;
}

struct ListNode *list_insert(struct ListNode *list, int val)
{
    struct ListNode *node;
    struct ListNode *new_node;

    if (list == NULL) {
        return NULL;
    }

    node = list;

    while (node->next != NULL) {
        node = node->next;
    }

    new_node = (struct ListNode *) malloc(sizeof(struct ListNode));
    new_node->val = val;
    new_node->next = NULL;
    node->next = new_node;

    return new_node;
}

void list_destroy(struct ListNode *list)
{
    struct ListNode *node;
    struct ListNode *next;

    node = list;

    while (node != NULL) {
        next = node->next;
        free(node);
        node = next;
    }
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
    struct ListNode *result;
    struct ListNode *node;
    struct ListNode *node1 = l1;
    struct ListNode *node2 = l2;
    int sum;

    sum = node1->val + node2->val;
    result = list_init(sum % 10);
    node = result;
    sum /= 10;
    node1 = node1->next;
    node2 = node2->next;

    while (sum > 0 || node1 != NULL || node2 != NULL) {
        if (node1 != NULL) {
            sum += node1->val;
            node1 = node1->next;
        }

        if (node2 != NULL) {
            sum += node2->val;
            node2 = node2->next;
        }

        node = list_insert(node, sum % 10);
        sum /= 10;
    }

    return result;
}

static struct ListNode *list_from_array(const int *array, const int size)
{
    struct ListNode *list;
    struct ListNode *node;
    int i;

    if (size <= 0) {
        return NULL;
    }

    list = list_init(array[0]);
    node = list;

    for (i = 1; i < size; i++) {
        node = list_insert(node, array[i]);
    }

    return list;
}

void test1()
{
    int num1[3] = {2, 4, 3};
    int num2[3] = {5, 6, 4};
    struct ListNode *input1 = list_from_array(num1, 3);
    struct ListNode *input2 = list_from_array(num2, 3);
    struct ListNode *result;

    result = addTwoNumbers(input1, input2);
    assert(result->val == 7 && result->next != NULL);
    assert(result->next->val == 0 && result->next->next != NULL);
    assert(result->next->next->val == 8 && result->next->next->next == NULL);

    list_destroy(result);
    list_destroy(input2);
    list_destroy(input1);
}

int main()
{
    test1();
    return 0;
}
