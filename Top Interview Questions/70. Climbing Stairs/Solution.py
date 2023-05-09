R = dict()
R[0] = 1
R[1] = 1
R[2] = 2
R[3] = 3
R[4] = 5
R[5] = 8
R[6] = 12
class Solution:
    def climbStairs(self, n: int) -> int:  
        if n in R:
            return R[n]
        acc1 = R[n - 1] if (n - 1) in R else self.climbStairs(n - 1)            
        acc2 = R[n - 2] if (n - 2) in R else self.climbStairs(n - 2)            
        R[n] = acc1 + acc2

        return R[n]