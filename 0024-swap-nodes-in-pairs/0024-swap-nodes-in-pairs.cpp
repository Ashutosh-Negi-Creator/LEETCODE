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
    ListNode* rev(ListNode* head){
        if(head == nullptr || head->next == nullptr) return head;
        ListNode* first = head;
        ListNode* second = head->next;
        ListNode* temp = second->next;
        second->next = first;
        first->next = rev(temp);
        return second;
    }
    ListNode* swapPairs(ListNode* head) {
        return rev(head);
    }
};