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
        if(!head) return head;
        int len=1;
        ListNode* temp = head;
        while(temp->next!=NULL){
            len++;
            temp=temp->next;
        }
        cout<<len;
        temp->next = head;
        len = len-k % len;
       while(len>0){
            temp=temp->next;
            len--;
        }
        head = temp->next;
        temp->next = NULL;
        return head;
    }
};