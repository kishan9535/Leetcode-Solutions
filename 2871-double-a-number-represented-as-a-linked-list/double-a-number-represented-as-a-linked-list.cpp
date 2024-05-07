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
    ListNode* doubleIt(ListNode* head) {
      ListNode* curr=head;
      ListNode* prev=NULL;
      while(curr!=NULL){
        int newans=curr->val*2;
        if(newans>=10){
            if(prev!=NULL){
                prev->val+=1;
                curr->val=newans%10;
            }
            else{
               ListNode* newhead=new ListNode(1);
               newhead->next=curr;
               curr->val=newans%10;
               head=newhead;
            }
        }
        else{
            curr->val=newans;
        }
        prev=curr;
        curr=curr->next;
      }
      return head;  
    }
};