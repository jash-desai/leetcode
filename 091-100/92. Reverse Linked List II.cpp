class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int a, int b) {
        ListNode* l = NULL, *r = NULL, *curr = head;
        ListNode* prevL = NULL, *prevR = NULL;
        int idx = 1;
        while(curr){
            if(idx == a and !l) l = curr;
            if(idx+1 == a and !l and !prevL){
                l = curr->next;
                prevL = curr;
            }else if(idx == b and !r and !prevR){
                r = curr;
                prevR = curr->next;
            }
            ++idx; curr = curr->next;
        }
        // if(l) cout << "l " << l->val << '\n';
        // if(r) cout << " r " << r->val << '\n';
        // if(prevL) cout << " prevL " << prevL->val << '\n';
        // if(prevR) cout << " prevR " << prevR->val << '\n';
        curr = l; ListNode* prev = prevR, *nxt = NULL;
        while(curr!=prevR){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        if(prevL) prevL->next = prev;
        return prevL ? head : prev;
    }
};