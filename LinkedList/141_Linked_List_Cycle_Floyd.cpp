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
    bool hasCycle(ListNode* head) {

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {

            // Move slow by 1 step
            slow = slow->next;

            // Move fast by 2 steps
            fast = fast->next->next;

            // If both meet, cycle exists
            if (slow == fast) {
                return true;
            }
        }

        return false;
    }
};

int main() {

    Solution obj;

    // Create linked list:
    // 1 -> 2 -> 3 -> 4
    //      ^         |
    //      |_________|

    ListNode* head = new ListNode(1);
    ListNode* second = new ListNode(2);
    ListNode* third = new ListNode(3);
    ListNode* fourth = new ListNode(4);

    head->next = second;
    second->next = third;
    third->next = fourth;

    // Create a cycle
    fourth->next = second;

    if (obj.hasCycle(head))
        cout << "Cycle Detected" << endl;
    else
        cout << "No Cycle" << endl;

    // Memory is not freed because the list contains a cycle.
    // Break the cycle before deleting nodes in a real program.

    return 0;
}