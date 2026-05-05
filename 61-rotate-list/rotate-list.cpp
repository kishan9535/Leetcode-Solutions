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
    ListNode* rotateRight(ListNode* head, int k) {

     int n=1;
     ListNode* last=head;

     if(!head || !head->next)return head;

      while(last->next){
        last=last->next;
        n++;
     }
     
     k=k%n;

     if(k==0)return head;

     last->next=head;

     if(!head || k==0 || !head->next)return head;
    
    ListNode* tail=head;

    int r=n-k;

    for(int i=1;i<r;i++){
        tail=tail->next;
    }
    ListNode* newhead=tail->next;
    tail->next=NULL;
    return newhead;

    }
};