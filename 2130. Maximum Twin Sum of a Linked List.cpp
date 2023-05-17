// class Solution {
// public:
//     int pairSum(ListNode* head) {
//         ListNode* slowPtr = head;
//         ListNode* fastPtr = head;
//         ListNode* prevPtr = nullptr;

//         while (fastPtr != nullptr && fastPtr->next != nullptr) {
//             fastPtr = fastPtr->next->next;
//             ListNode* nextNode = slowPtr->next;
//             slowPtr->next = prevPtr;
//             prevPtr = slowPtr;
//             slowPtr = nextNode;
//         }

//         if (fastPtr != nullptr) {
//             slowPtr = slowPtr->next;
//         }

//         int maxSum = INT_MIN;
//         while (slowPtr != nullptr) {
//             maxSum = max(maxSum, slowPtr->val + prevPtr->val);
//             slowPtr = slowPtr->next;
//             prevPtr = prevPtr->next;
//         }
//         return maxSum;
//     }
// };

class Solution {
public:
    int pairSum(ListNode* head) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL); cin.tie(nullptr);
        int n=1; ListNode* temp = head;
        while(temp->next != nullptr){
            n++; temp = temp->next;
        }
        vector<int> v(n); int k=0;
        for(temp=head; temp!=NULL; temp=temp->next){
            v[k++] = (temp->val);
        }
        int i=0; int j=n-1; int ans=0;
        while(i<=j){
            ans=max(ans,v[i++]+v[j--]);
        }
        return ans;
    }
};