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
    void deleteNode(ListNode* node) {

        // Save the next node
        ListNode* temp = node->next;

        // Copy the next node's value
        node->val = temp->val;

        // Skip the next node
        node->next = temp->next;

        // Free memory
        delete temp;
    }
};

// Function to print the linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;

        if (head->next != nullptr)
            cout << " -> ";

        head = head->next;
    }

    cout << endl;
}

int main() {

    // Create the linked list
    // 4 -> 5 -> 1 -> 9

    ListNode* head = new ListNode(4);
    head->next = new ListNode(5);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(9);

    cout << "Original List:" << endl;
    printList(head);

    Solution obj;

    // Delete node with value 5
    obj.deleteNode(head->next);

    cout << "After Deleting 5:" << endl;
    printList(head);

    // Free remaining memory
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}