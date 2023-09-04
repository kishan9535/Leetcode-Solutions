/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *h1;
        h1=head;
        ListNode *h2;
          h2=head;
        while(h2!=NULL && h2->next!=NULL){
            h1=h1->next;
            h2=h2->next->next;
        
        if(h1==h2) return true;
        }

        return false;

    }
};