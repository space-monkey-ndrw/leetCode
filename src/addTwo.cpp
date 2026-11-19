#include <iostream>
#include <vector>


/*
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    /* recursive solution
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // base case
        if (l1 == nullptr && l2 == nullptr) {
            return nullptr;
        }

        // recursive case
        if (l1 && l2) {
            if (l1 == nullptr) {
                return addTwoNumbers(nullptr, l2);
            }
            if (l2 == nullptr) {
                return addTwoNumbers(l1, nullptr);
            }
            if (l1 && l2) {
                return new ListNode((l1->val + l2->val), addTwoNumbers(l1->next, l2->next));
            }
        }
    }
    */

    /* non-recursive solution, needs way to store original result pointer, and to build & add new nodes to original's next field */
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode head(0);
        ListNode* tail = &head;
        bool carry {false};

        while (l1 || l2 || carry) {
            int tempSum = 0;
            if (carry) {
                tempSum++;
                carry = false;
            }

            if (l1) {
                tempSum += l1->val;
            }
            if (l2) {
                tempSum += l2->val;
            }

            if (tempSum >= 10) {
                carry = true;
                tempSum -= 10;
            }

            tail->next = new ListNode(tempSum);
            tail = tail->next;

            l1 = (l1 ? l1->next : nullptr);
            l2 = (l2 ? l2->next : nullptr);
        }

        return head.next;
    }
};

// Builds a linked list from a vector. Each value becomes one node.
ListNode* buildList(const std::vector<int>& values) {
    ListNode head(0);
    ListNode* tail = &head;
    for (int v : values) {
        tail->next = new ListNode(v);
        tail = tail->next;
    }
    return head.next;
}

// Prints the value of each node, from first to last.
void printList(const ListNode* node) {
    while (node) {
        std::cout << node->val << " ";
        node = node->next;
    }
    std::cout << std::endl;
}

// Deletes each node of a list. This frees the memory from "new".
void freeList(ListNode* node) {
    while (node) {
        ListNode* next = node->next;
        delete node;
        node = next;
    }
}

int main() {
    ListNode* l1 = buildList({2, 4, 3});   // represents 342
    ListNode* l2 = buildList({5, 6, 4});   // represents 465

    Solution s;
    ListNode* result = s.addTwoNumbers(l1, l2);
    printList(result);                     // expected output: 7 0 8

    freeList(l1);
    freeList(l2);
    freeList(result);
    return 0;
}