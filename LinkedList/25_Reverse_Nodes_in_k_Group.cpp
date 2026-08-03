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

    // Reverse a linked list
    ListNode* reverseLinkedList(ListNode* head) {

        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr != nullptr) {

            ListNode* front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
        }

        return prev;
    }

    // Returns the kth node from temp
    ListNode* getKthNode(ListNode* temp, int k) {

        k--;

        while (temp != nullptr && k > 0) {
            temp = temp->next;
            k--;
        }

        return temp;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* temp = head;
        ListNode* prevLast = nullptr;

        while (temp != nullptr) {

            // Find kth node
            ListNode* kthNode = getKthNode(temp, k);

            // Less than k nodes remain
            if (kthNode == nullptr) {

                if (prevLast != nullptr)
                    prevLast->next = temp;

                break;
            }

            // Save next group's starting node
            ListNode* nextNode = kthNode->next;

            // Detach current group
            kthNode->next = nullptr;

            // Reverse current group
            reverseLinkedList(temp);

            // First group
            if (temp == head)
                head = kthNode;
            else
                prevLast->next = kthNode;

            // Current group's last node
            prevLast = temp;

            // Move to next group
            temp = nextNode;
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

    cout << " -> NULL" << endl;
}

int main() {

    // 1 -> 2 -> 3 -> 4 -> 5

    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int k = 2;

    cout << "Original Linked List:\n";
    printList(head);

    Solution obj;

    head = obj.reverseKGroup(head, k);

    cout << "\nAfter Reversing Every " << k << " Nodes:\n";
    printList(head);

    // Free memory
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}