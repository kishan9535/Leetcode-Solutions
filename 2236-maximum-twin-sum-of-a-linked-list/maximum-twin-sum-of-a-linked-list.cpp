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
    int pairSum(ListNode* head) {
      vector<int> ans;
      while(head){
          ans.push_back(head->val);
          head=head->next;
      }
      int maxi=INT_MIN;
      int n=ans.size();
      int i=0,j=n-1;
      while(i<j){
        int a=ans[i]+ans[j];
        maxi=max(maxi,a);
        i++;
        j--;
      }
      return maxi;
    }
};