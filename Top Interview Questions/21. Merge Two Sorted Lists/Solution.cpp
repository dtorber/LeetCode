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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1) return list2;
        if (!list2) return list1;
        ListNode *res = new ListNode();
        ListNode *end = res;
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                end->next = new ListNode(list1->val);
                list1 = list1->next;

            } else {
                end->next = new ListNode(list2->val);
                list2 = list2->next;
            }
            end = end->next;
        }

        while (list1 != nullptr) {
            end->next = new ListNode(list1->val);
            list1 = list1->next;
            end = end->next;
        }
        
        while (list2 != nullptr) {
            end->next = new ListNode(list2->val);
            list2 = list2->next;
            end = end->next;
        }

        // //Millora: simplement agafar el que quede en l1 o l2:
        // if (list1 != nullptr) {
        //     end -> next = list1;
        // } else {
        //     end -> next = list2;
        // }

        return res->next;
    }
};