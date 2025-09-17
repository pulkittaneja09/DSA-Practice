/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        
        if (!head || !head->next) return head;
        ListNode* slowPtr = head;
        ListNode* fastPtr = head->next;
        while (fastPtr && fastPtr->next) {
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
        }
        ListNode* firstHalf = head;
        ListNode* secondHalf = slowPtr->next;
        slowPtr->next = nullptr;
        firstHalf = sortList(firstHalf);
        secondHalf = sortList(secondHalf);
        ListNode* dummyHead = new ListNode(0);
        ListNode* currentTail = dummyHead;
        while (firstHalf && secondHalf) {
            if (firstHalf->val <= secondHalf->val) {
                currentTail->next = firstHalf;
                firstHalf = firstHalf->next;
            } else {
                currentTail->next = secondHalf;
                secondHalf = secondHalf->next;
            }
            currentTail = currentTail->next;
        }
        if (firstHalf != nullptr) {
            currentTail->next = firstHalf;
        } else {
            currentTail->next = secondHalf;
        }
        ListNode* sortedHead = dummyHead->next;
        delete dummyHead;
        return sortedHead;
    }
};
