/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        //Base condition
        if (head == NULL){
            return head;
        }
        ListNode* temp = head;
        int count = 0;
        while(temp != NULL){
            count++;
            temp = temp->next;
        }
        if (count == 1){
            head = NULL;
            return head;
        }
        temp = head;
        for(int i = 1; i < count/2; i++){
            temp = temp->next;
        }
        ListNode* temp2 = temp->next;
        temp->next = temp2->next;
        temp2->next = NULL;
        
        return head;
    }
};
