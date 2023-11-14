class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head or !(head->next)) return 0;
        ListNode* s = head, *f = head;
        do{
            s = s->next;
            f = f->next->next;
            if(!f or !f->next) return 0;
        }while(s!=f and f and f->next);
        return 1;
    }
};