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
    ListNode* detectCycle(ListNode* head) {

        // Empty list or single node
        if (head == nullptr || head->next == nullptr) {
            return nullptr;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        // Phase 1: Detect cycle
        while (fast != nullptr && fast->next != nullptr) {

            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {

                // Phase 2: Find starting node of cycle
                slow = head;

                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }

                return slow;
            }
        }

        return nullptr;
    }
};

int main() {

    Solution obj;

    // Create linked list:
    // 1 -> 2 -> 3 -> 4 -> 5
    //           ^         |
    //           |_________|

    ListNode* head = new ListNode(1);
    ListNode* second = new ListNode(2);
    ListNode* third = new ListNode(3);
    ListNode* fourth = new ListNode(4);
    ListNode* fifth = new ListNode(5);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    // Create cycle
    fifth->next = third;

    ListNode* ans = obj.detectCycle(head);

    if (ans != nullptr)
        cout << "Cycle starts at node: " << ans->val << endl;
    else
        cout << "No Cycle" << endl;

    // Memory is not freed because the list contains a cycle.
    // Break the cycle before deleting nodes in a real application.

    return 0;
}