class Solution {
private:
    ListNode* reverse(ListNode* head){
        if(!head or !(head->next)) return head;
        ListNode* curr = head, *prev = NULL, *nxt = NULL;
        while(curr){
            nxt = curr->next;
            curr->next = prev;
            prev = curr; curr = nxt;
        }
        return prev;
    }
    ListNode* add(ListNode* a, ListNode* b) {
        if(!a) return b; 
        if(!b) return a;
        int carry = 0;
        ListNode* ans = new ListNode();
        ListNode* tail = ans;

        while(a or b or carry){
            int sum = carry;
            if(a) sum += a->val, a = a->next;
            if(b) sum += b->val, b = b->next;
            carry = sum / 10;
            tail->next = new ListNode(sum % 10);
            tail = tail->next;
        }
        return ans->next;
    }
public:
    ListNode* addTwoNumbers(ListNode* a, ListNode* b) {
        a = reverse(a); b = reverse(b);
        return reverse(add(a, b));
    }
};