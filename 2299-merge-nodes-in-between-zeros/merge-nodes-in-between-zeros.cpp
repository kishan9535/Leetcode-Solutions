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
    ListNode* mergeNodes(ListNode* head) {
        if(head==NULL ||head->next==NULL)return head;

     ListNode * newh=new ListNode(0);
     ListNode* res=newh;
     int sum=0;
     while(head){
         if(head->val==0){
             newh->next =new ListNode(sum);
             newh=newh->next;
             sum=0;
         }
         else{
             sum+=head->val;
         }
         head=head->next;
     }
     return res->next->next;

    }
};