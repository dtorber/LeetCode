# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        res = ListNode()
        end = res
        while list1 is not None and list2 is not None:
            if list1.val < list2.val:
                end.next = list1
                end = list1
                list1 = list1.next
            else:
                end.next = list2
                end = list2
                list2 = list2.next
        
        if list1 is not None:
            end.next = list1
        
        if list2 is not None:
            end.next = list2

        return res.next