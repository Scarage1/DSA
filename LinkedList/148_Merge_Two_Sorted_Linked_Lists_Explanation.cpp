#include <iostream>
using namespace std;

// Definition of ListNode
struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};

// Function to merge two sorted linked lists
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

    // Dummy node
    ListNode* dummyNode = new ListNode(-1);

    // Pointer used to build the merged list
    ListNode* temp = dummyNode;

    while (list1 != nullptr && list2 != nullptr) {

        if (list1->val < list2->val) {

            temp->next = list1;
            temp = list1;
            list1 = list1->next;
        }
        else {

            temp->next = list2;
            temp = list2;
            list2 = list2->next;
        }
    }

    // Attach remaining nodes
    if (list1 != nullptr)
        temp->next = list1;
    else
        temp->next = list2;

    ListNode* ans = dummyNode->next;
    delete dummyNode;

    return ans;
}

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

    // First Sorted List
    // 1 -> 4 -> 7

    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(4);
    list1->next->next = new ListNode(7);

    // Second Sorted List
    // 2 -> 3 -> 8

    ListNode* list2 = new ListNode(2);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(8);

    cout << "List 1:\n";
    printList(list1);

    cout << "\nList 2:\n";
    printList(list2);

    ListNode* merged = mergeTwoLists(list1, list2);

    cout << "\nMerged List:\n";
    printList(merged);

    // Free memory
    while (merged != nullptr) {
        ListNode* temp = merged;
        merged = merged->next;
        delete temp;
    }

    return 0;
}