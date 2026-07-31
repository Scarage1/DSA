#include <iostream>
using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};

class Solution {
public:

    ListNode* deleteMiddle(ListNode* head) {

        // Empty list or single node
        if (head == nullptr || head->next == nullptr) {
            delete head;
            return nullptr;
        }

        ListNode* slow = head;
        ListNode* fast = head->next->next;

        // Find the node before the middle
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Delete the middle node
        ListNode* middle = slow->next;
        slow->next = slow->next->next;
        delete middle;

        return head;
    }
};

// Function to print linked list
void printList(ListNode* head) {

    while (head != nullptr) {
        cout << head->val;

        if (head->next != nullptr)
            cout << " -> ";

        head = head->next;
    }

    cout << " -> NULL" << endl;
}

int main() {

    // Create:
    // 1 -> 3 -> 4 -> 7 -> 1 -> 2 -> 6

    ListNode* head = new ListNode(1);
    head->next = new ListNode(3);
    head->next->next = new ListNode(4);
    head->next->next->next = new ListNode(7);
    head->next->next->next->next = new ListNode(1);
    head->next->next->next->next->next = new ListNode(2);
    head->next->next->next->next->next->next = new ListNode(6);

    cout << "Original Linked List:\n";
    printList(head);

    Solution obj;

    head = obj.deleteMiddle(head);

    cout << "\nAfter Deleting Middle Node:\n";
    printList(head);

    // Free remaining memory
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}