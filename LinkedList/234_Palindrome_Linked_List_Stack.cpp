#include <iostream>
#include <stack>
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
    bool isPalindrome(ListNode* head) {

        stack<int> st;

        ListNode* temp = head;

        // Push all node values into the stack
        while (temp != nullptr) {
            st.push(temp->val);
            temp = temp->next;
        }

        temp = head;

        // Compare stack values with linked list values
        while (temp != nullptr) {

            if (temp->val != st.top()) {
                return false;
            }

            st.pop();
            temp = temp->next;
        }

        return true;
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

    // Create Linked List:
    // 1 -> 2 -> 2 -> 1

    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);

    cout << "Linked List:" << endl;
    printList(head);

    Solution obj;

    if (obj.isPalindrome(head))
        cout << "\nPalindrome Linked List" << endl;
    else
        cout << "\nNot a Palindrome Linked List" << endl;

    // Free memory
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}