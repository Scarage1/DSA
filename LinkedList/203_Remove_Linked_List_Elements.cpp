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
    ListNode* removeElements(ListNode* head, int val) {

        // Remove matching nodes from the beginning
        while (head != nullptr && head->val == val) {
            head = head->next;
        }

        // If list becomes empty
        if (head == nullptr)
            return nullptr;

        ListNode* prev = head;
        ListNode* temp = head->next;

        while (temp != nullptr) {

            if (temp->val == val) {
                prev->next = temp->next;
                temp = prev->next;
            }
            else {
                prev = temp;
                temp = temp->next;
            }
        }

        return head;
    }
};

// Print Linked List
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

    // Create:
    // 1 -> 2 -> 6 -> 3 -> 4 -> 5 -> 6

    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(6);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next->next = new ListNode(6);

    cout << "Original List:" << endl;
    printList(head);

    Solution obj;

    head = obj.removeElements(head, 6);

    cout << "After Removing 6:" << endl;
    printList(head);

    return 0;
}