class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head or !(head->next)) return 0;
        ListNode* s = head, *f = head;
        do{
            s = s->next;
            f = f->next->next;
        }while(s!=f and f and f->next);
        return (s==f) ? 1 : 0;
    }
};