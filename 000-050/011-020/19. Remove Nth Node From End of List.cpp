class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *slow = new(ListNode), *fast = new(ListNode);
        slow -> next = head;
        fast -> next = head;
        while(n--) fast = fast -> next; 
        while(fast -> next != nullptr) {
            fast = fast -> next;
            slow = slow -> next;
        }
        if(slow -> next == head) { //means n == sz;
            return head -> next;
        }
        slow -> next = slow -> next -> next;
        return head;
    }
};