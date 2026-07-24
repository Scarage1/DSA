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
    ListNode* middleNode(ListNode* head) {

        ListNode* temp = head;
        int count = 0;

        // Count total nodes
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }

        // Reset temp to head
        temp = head;

        int mid = count / 2;
        int i = 0;

        // Move to the middle node
        while (i < mid) {
            temp = temp->next;
            i++;
        }

        return temp;
    }
};

// Function to print the linked list from a given node
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

    // Create linked list:
    // 1 -> 2 -> 3 -> 4 -> 5

    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original List:" << endl;
    printList(head);

    Solution obj;

    ListNode* middle = obj.middleNode(head);

    cout << "\nMiddle Node onwards:" << endl;
    printList(middle);

    // Free memory
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}