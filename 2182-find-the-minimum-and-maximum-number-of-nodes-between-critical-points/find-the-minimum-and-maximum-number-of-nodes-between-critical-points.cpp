#include <vector>
#include <limits.h>
using namespace std;

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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (!head || !head->next || !head->next->next) {
            return {-1, -1};
        }
        
        ListNode* prev = head;
        ListNode* curr = head->next;
        ListNode* next = curr->next;
        int i = 1;
        int prev_critical_position = -1;
        int first_critical_pos = -1;

        int min_distance = INT_MAX;
        int max_distance = 0;

        while (next) {
            if ((curr->val > prev->val && curr->val > next->val) ||
                (curr->val < prev->val && curr->val < next->val)) {
                
                if (first_critical_pos == -1) {
                    first_critical_pos = i;
                    prev_critical_position = i;
                } else {
                    min_distance = min(min_distance, i - prev_critical_position);
                    max_distance = i - first_critical_pos;
                    prev_critical_position = i;
                }
            }
            prev = curr;
            curr = next;
            next = next->next;
            i++;
        }

        if (min_distance == INT_MAX) {
            return {-1, -1};
        }

        return {min_distance, max_distance};
    }
};
