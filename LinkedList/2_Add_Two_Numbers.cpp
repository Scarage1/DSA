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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        // Dummy node for the result list
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;

        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry) {

            int sum = 0;

            // Add value from first list
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }

            // Add value from second list
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }

            // Add carry
            sum += carry;

            // Update carry
            carry = sum / 10;

            // Create new node
            ListNode* node = new ListNode(sum % 10);

            temp->next = node;
            temp = temp->next;
        }

        ListNode* ans = dummy->next;
        delete dummy;

        return ans;
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

    // Number 342
    // 2 -> 4 -> 3

    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    // Number 465
    // 5 -> 6 -> 4

    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    cout << "List 1:\n";
    printList(l1);

    cout << "\nList 2:\n";
    printList(l2);

    Solution obj;

    ListNode* ans = obj.addTwoNumbers(l1, l2);

    cout << "\nSum List:\n";
    printList(ans);

    // Free result list
    while (ans != nullptr) {
        ListNode* temp = ans;
        ans = ans->next;
        delete temp;
    }

    // Free List 1
    while (l1 != nullptr) {
        ListNode* temp = l1;
        l1 = l1->next;
        delete temp;
    }

    // Free List 2
    while (l2 != nullptr) {
        ListNode* temp = l2;
        l2 = l2->next;
        delete temp;
    }

    return 0;
}