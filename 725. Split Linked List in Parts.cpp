class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = 0; ListNode* curr = head;
        while(curr) n++, curr = curr->next;
        vector<ListNode*> ans(k, NULL); int p = n%k, l = n/k;
        ListNode* node = head, *prev = NULL;
        for(int i = 0; node and i < k; i++, p--) {
            ans[i] = node;
            for(int j = 0; j < l + (p > 0); j++) {
                prev = node; node = node->next;
            }
            prev->next = NULL;
        }
        return ans;
    }
};