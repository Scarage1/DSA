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
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {

        ListNode* temp1 = headA;
        ListNode* temp2 = headB;

        while (temp1 != temp2) {

            if (temp1 == nullptr)
                temp1 = headB;
            else
                temp1 = temp1->next;

            if (temp2 == nullptr)
                temp2 = headA;
            else
                temp2 = temp2->next;
        }

        return temp1;
    }
};

// Function to print a linked list
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

    // Common part
    ListNode* common = new ListNode(8);
    common->next = new ListNode(4);
    common->next->next = new ListNode(5);

    // List A
    ListNode* headA = new ListNode(4);
    headA->next = new ListNode(1);
    headA->next->next = common;

    // List B
    ListNode* headB = new ListNode(5);
    headB->next = new ListNode(6);
    headB->next->next = new ListNode(1);
    headB->next->next->next = common;

    cout << "List A:\n";
    printList(headA);

    cout << "\nList B:\n";
    printList(headB);

    Solution obj;

    ListNode* ans = obj.getIntersectionNode(headA, headB);

    if (ans != nullptr)
        cout << "\nIntersection Node: " << ans->val << endl;
    else
        cout << "\nNo Intersection\n";

    // Free unique nodes of A
    delete headA->next;
    delete headA;

    // Free unique nodes of B
    delete headB->next->next;
    delete headB->next;
    delete headB;

    // Free common nodes
    while (common != nullptr) {
        ListNode* temp = common;
        common = common->next;
        delete temp;
    }

    return 0;
}