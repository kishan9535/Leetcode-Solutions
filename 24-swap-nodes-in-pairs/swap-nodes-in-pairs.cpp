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
    ListNode* swapPairs(ListNode* head) {
        if(!head||!head->next)return head;
      ListNode* curr=head;
      ListNode* prev=head;
    
      curr=curr->next;
      while(curr && prev){
       int p=prev->val;
       prev->val=curr->val;
       curr->val=p;
       if(!curr->next)break;
       prev=curr->next;
       curr=prev->next;
      }
      
      return head;  
    }
};