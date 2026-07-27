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
    ListNode* reverseList(ListNode* head) {

        if (head == nullptr) {
            return nullptr;
        }

        ListNode* temp = head;
        ListNode* prev = nullptr;

        while (temp != nullptr) {

            // Store the next node
            ListNode* front = temp->next;

            // Reverse the link
            temp->next = prev;

            // Move prev forward
            prev = temp;

            // Move temp forward
            temp = front;
        }

        return prev;
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

    // Create linked list:
    // 1 -> 2 -> 3 -> 4 -> 5

    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original Linked List:" << endl;
    printList(head);

    Solution obj;

    head = obj.reverseList(head);

    cout << "\nReversed Linked List:" << endl;
    printList(head);

    // Free memory
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}