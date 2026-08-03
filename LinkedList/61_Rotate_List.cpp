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
    ListNode* rotateRight(ListNode* head, int k) {

        // Edge cases
        if (head == nullptr || head->next == nullptr || k == 0)
            return head;

        ListNode* tail = head;
        int length = 1;

        // Find length and last node
        while (tail->next != nullptr) {
            tail = tail->next;
            length++;
        }

        // Reduce unnecessary rotations
        k %= length;

        if (k == 0)
            return head;

        // Find new tail
        int steps = length - k - 1;

        ListNode* temp = head;

        while (steps--) {
            temp = temp->next;
        }

        // New head
        ListNode* newHead = temp->next;

        // Make circular
        tail->next = head;

        // Break the circle
        temp->next = nullptr;

        return newHead;
    }
};

// Print linked list
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
    // 1 -> 2 -> 3 -> 4 -> 5

    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int k = 2;

    cout << "Original List:\n";
    printList(head);

    Solution obj;

    head = obj.rotateRight(head, k);

    cout << "\nAfter Rotating Right by " << k << ":\n";
    printList(head);

    // Free memory
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}