class Solution {
public:
    ListNode* addTwoNumbers(ListNode* A, ListNode* B) {
        if(A == NULL){return B;} 
        else if(B == NULL){return A;}
        
        ListNode* currA = A;
        ListNode* currB = B;
        
        ListNode* ans = NULL;
        ListNode* head;
        int sum, carry = 0, value;
        while(currA && currB){
            sum = currA->val + currB->val + carry;
            carry = sum/10;
            value = sum%10;
            
            ListNode* store = new ListNode(value);
            
            if(!ans){
                ans = store;
                head = ans;
            }else{
                ans->next = store;
                ans = store;
            }
            
            currA = currA->next;
            currB = currB->next;            
        }
        if(!currA){
            while(currB){
                sum = currB->val + carry;
                carry = sum/10;
                value = sum%10;
                
                ListNode* store = new ListNode(value);
                
                ans->next = store;
                ans = store;
                
                currB = currB->next;
            }
        }
        else if(!currB){
            while(currA){
                sum = currA->val + carry;
                carry = sum/10;
                value = sum%10;
                
                ListNode* store = new ListNode(value);
                
                ans->next = store;
                ans = store;
                
                currA = currA->next;
            }
        }
        if(carry){
            ListNode* store = new ListNode(carry);
            
            ans->next = store;
            ans = store;
        }
        return head;
        
    }
};