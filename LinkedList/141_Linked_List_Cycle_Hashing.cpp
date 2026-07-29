#include <iostream>
#include <map>
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

        map<ListNode*, int> mpp;

        ListNode* temp = head;

        while (temp != nullptr) {

            // Node already visited
            if (mpp.find(temp) != mpp.end()) {
                return true;
            }

            // Mark current node as visited
            mpp[temp] = 1;

            temp = temp->next;
        }

        return false;
    }
};

int main() {

    Solution obj;

    // Create Linked List:
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
    // In a real application, break the cycle before deleting nodes.

    return 0;
}