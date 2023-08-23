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
    int mx = 0;
    ListNode* solve(ListNode* node){
        if(!node) return node;
        node->next = solve(node->next);
        mx = max(mx, node->val);
        if(node->val < mx){
            return node->next;
        }
        return node;
    }
    ListNode* removeNodes(ListNode* head) {
        return solve(head);
    }
};