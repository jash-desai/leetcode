class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head or !(head->next) or !k) return head;
        ListNode* curr = head; int n{1}, t{0}; ListNode* tail = head; 
        while(curr->next){ curr = curr->next; n++; } curr = head;
        k = k%n; if(!k){ return head;} t = k; while(t--) curr = curr->next;
        while(curr->next){ curr=curr->next; tail=tail->next; }
        ListNode* newHead = tail->next; tail->next = NULL;
        curr->next = head; return newHead;
    }
};