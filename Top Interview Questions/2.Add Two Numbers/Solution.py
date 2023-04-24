# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        n1 = self.convertirNodeANum(l1)
        n2 = self.convertirNodeANum(l2)
        res = str(n1 + n2)
        primer = ListNode(int(res[0]))
        for i in range(1, len(res)):
            primer = ListNode(res[i], primer)
        return primer
    def convertirNodeANum(self, l: [ListNode]) -> int:
        if l == None:
            return 0
        return l.val + 10 * self.convertirNodeANum(l.next)