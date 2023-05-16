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
        if(!head or !head->next) return head;
        ListNode* a = head;
        ListNode* b = head->next;
        if(b->next == nullptr){
            b->next = a;
            a->next = nullptr;
            return b;
        }
        a->next = swapPairs(b->next);
        b->next = a;
        return b;
    }
};