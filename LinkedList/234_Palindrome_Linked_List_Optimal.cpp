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

    // Reverse a linked list recursively
    ListNode* reverseLinkedList(ListNode* head) {

        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode* newHead = reverseLinkedList(head->next);

        ListNode* front = head->next;
        front->next = head;
        head->next = nullptr;

        return newHead;
    }

    bool isPalindrome(ListNode* head) {

        if (head == nullptr || head->next == nullptr)
            return true;

        // Find middle
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse second half
        ListNode* newHead = reverseLinkedList(slow->next);

        // Compare first and second halves
        ListNode* first = head;
        ListNode* second = newHead;

        while (second != nullptr) {

            if (first->val != second->val) {

                // Restore original list
                slow->next = reverseLinkedList(newHead);

                return false;
            }

            first = first->next;
            second = second->next;
        }

        // Restore original list
        slow->next = reverseLinkedList(newHead);

        return true;
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

    cout << " -> NULL" << endl;
}

int main() {

    // 1 -> 2 -> 3 -> 2 -> 1

    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(1);

    cout << "Original Linked List:\n";
    printList(head);

    Solution obj;

    if (obj.isPalindrome(head))
        cout << "\nPalindrome Linked List\n";
    else
        cout << "\nNot a Palindrome Linked List\n";

    cout << "\nLinked List After Function Call:\n";
    printList(head);

    // Free memory
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}