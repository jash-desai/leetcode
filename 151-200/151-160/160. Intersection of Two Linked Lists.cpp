class Solution {
public:
    ListNode *getIntersectionNode(ListNode *a, ListNode *b){
        if(!a or !b) return NULL;
        ListNode* aCurr = a, *bCurr = b; int na = 0, nb = 0;
        while(aCurr){ na++; aCurr = aCurr->next; } aCurr = a;
        while(bCurr){ nb++; bCurr = bCurr->next; } bCurr = b;
        if(na>nb){
            int t = (na-nb);
            while(t--) aCurr = aCurr->next;
        }else{
            int t = (nb-na);
            while(t--) bCurr = bCurr->next;
        }
        while(aCurr and bCurr){
            if(aCurr==bCurr) return aCurr;
            aCurr = aCurr->next;
            bCurr = bCurr->next;
        }
        return NULL;
    }
};