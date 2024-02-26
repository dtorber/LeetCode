class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        pila = list()
        for num in nums:
            heappush(pila, -num)
        for _ in range(k - 1):
            heappop(pila)
        return -heappop(pila)