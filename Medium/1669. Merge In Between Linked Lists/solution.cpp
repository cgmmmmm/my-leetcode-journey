/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        int counter = 0;
        ListNode* start = list1;
        ListNode* end = list1;
        ListNode* curr = list1;

        while (curr)
        {
            if (counter + 1 == a) start = curr;
            if (counter == b + 1) end = curr;
            curr = curr->next;
            counter++;
        }

        start->next = list2;
        
        while (list2->next) list2 = list2->next;
        list2->next = end;

        return list1;
    }
};