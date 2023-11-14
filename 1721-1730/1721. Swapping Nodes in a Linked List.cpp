/*
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* a=head; ListNode* b=head;
        int n=0;
        while(b->next != nullptr){
            n++;
            b = b->next;
        }
        b=head;
        int t = n-k+1;
        while(t--){
            b=b->next;
        }
        while(k>1){
            a=a->next;
            k--;
        }
        t = a->val;
        a->val = b->val;
        b->val = t;
        return head;
    }
};
*/
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *left_ptr = head, *right_ptr = head;
        for (int i = 0; i < k-1; i++) {
            right_ptr = right_ptr->next;
        }
        
        ListNode *end_ptr = right_ptr;
        while (right_ptr->next) {
            left_ptr = left_ptr->next;
            right_ptr = right_ptr->next;
        }
        
        swap(end_ptr->val, left_ptr->val);
        
        return head;
    }
};