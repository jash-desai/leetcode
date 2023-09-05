/* class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return head;
       Node* temp = head;
        while (temp) {
            Node* nextNode = temp->next;
            Node* newNode = new Node(temp->val);
            temp->next = newNode;
            newNode->next = nextNode;
            temp = nextNode;
        }
        temp = head;
        while (temp) {
            if (temp->random) temp->next->random = temp->random->next;
            temp = temp->next->next;
        }
        temp = head;
        Node* newHead = head->next;
        Node* newCurrent = newHead;
        while (temp) {
            temp->next = temp->next->next;
            if (newCurrent->next) newCurrent->next = newCurrent->next->next;
            temp = temp->next;
            newCurrent = newCurrent->next;
        }
        return newHead;
    }
}; */

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        unordered_map<Node*, Node*> mpp;
        Node* x = new Node(head->val); mpp[head] = x;
        Node* temp = head->next; Node* temp1 = x;
        while (temp) {
            temp1->next = new Node(temp->val);
            temp1 = temp1->next;
            mpp[temp] = temp1; temp = temp->next;
        }
        temp = head; temp1 = x;
        while (temp) {
            if (temp->random) temp1->random = mpp[temp->random];
            temp = temp->next; temp1 = temp1->next;
        }
        return x;
    }
};