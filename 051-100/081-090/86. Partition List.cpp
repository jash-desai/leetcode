class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(!head or !head->next) return head;
        ListNode *head1 = NULL, *head2 = NULL;
        ListNode *curr = head, *temp1, *temp2;
        while(curr){
            if(curr->val < x){
                //for the list with smaller than number
                if(!head1){
                    //checking condition if the first element of this list
                    head1=curr;
                    curr=curr->next;
                    temp1=head1;
                }else{
                    temp1->next=curr;
                    curr=curr->next;
                    temp1=temp1->next;
                }
            }else{
                //for the list with greater than or equal to number
                if(head2 == NULL){
                    //checking condition if the first element of this list
                    head2=curr;
                    curr=curr->next;
                    temp2=head2;
                    temp2->next=NULL;
                }else{
                    temp2->next=curr;
                    curr=curr->next;
                    temp2=temp2->next;
                    temp2->next=NULL;
                }
            }
        }
        if(head1){
            temp1->next = head2;
            return head1;
        }else return head2;
    }
};