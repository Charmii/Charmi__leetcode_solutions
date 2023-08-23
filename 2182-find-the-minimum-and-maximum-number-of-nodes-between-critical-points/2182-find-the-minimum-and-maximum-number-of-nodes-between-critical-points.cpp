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
        vector<int> ans = {-1,-1};
        if(!head || !head->next || !head->next->next) return ans;
        ListNode* left=head, *right=head, *prev = head, *curr=head;
        int min =INT_MAX;
        int flag = 1;
        int right_flag = 1;
        while (curr->next->next) {
            if((curr->val < curr->next->val && curr->next->val > curr->next->next->val) || 
            (curr->val > curr->next->val && curr->next->val < curr->next->next->val)){
                if(flag) {
                    flag=0;
                    left=curr->next;
                    right = curr->next;
                    prev = left;
                }
                else if (right_flag){
                    right_flag=0;
                    prev = left;
                    right=curr->next;
                    if((right-prev)/2 <min) min = (right-prev)/2;
                }
                else if(!right_flag){
                    prev=right;
                    right=curr->next;
                    if((right-prev)/2 <min) min = (right-prev)/2;
                }
                
            }
            curr = curr->next;
        }
        cout<<left->val<<right->val;
        ans[0] = min;
        ans[1] = (right-left)/2;
        if(ans[0] == INT_MAX) ans[0] = -1;
        if(ans[1] == 0) ans[1] = -1;
        return ans;
    }
};