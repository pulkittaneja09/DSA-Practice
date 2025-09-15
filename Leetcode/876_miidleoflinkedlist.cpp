// LeetCode 876. Middle of the Linked List
// https://leetcode.com/problems/middle-of-the-linked-list/
// Given the head of a singly linked list, return the middle node of the list.
// If there are two middle nodes, return the second one.
#include<iostream>
#include<vector>
using namespace std;
class ListNode{
    public:
    int val;
    ListNode *next;
    ListNode(int val){
        this->val=val;
        this->next=nullptr;
    }
    ListNode(int val,ListNode* next){
        this->val=val;
        this->next=next;
    }

};
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL&&fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
        
    }
};