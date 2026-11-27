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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL) return head;
        ListNode* temp = head;
        ListNode* temp1 = head->next;
        while(temp1){
            if(temp->val==temp1->val){
                ListNode* node = temp1;
                temp->next=temp1->next;
                temp1= temp1->next;
                delete node;
            }
            else{
                temp=temp->next;
                temp1=temp1->next;
            }
            
        }
        return head;

    }
};