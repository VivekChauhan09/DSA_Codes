// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr != nullptr) {
            ListNode* next = curr->next; // save next
            curr->next = prev;           // reverse link
            prev = curr;                 // move prev ahead
            curr = next;                 // move curr ahead
        }

        return prev; // new head
    }
};


//Using recursion
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // Base case: if head is NULL or only one node
        if (head == nullptr || head->next == nullptr) 
            return head;

        // Reverse the rest of the list
        ListNode* newHead = reverseList(head->next);

        // Put current node at the end
        head->next->next = head;
        head->next = nullptr;

        return newHead;
    }
};
