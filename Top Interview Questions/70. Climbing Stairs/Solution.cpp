class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;
        int aux, prev1 = 1, prev2 = 2, p = 2;
        while (p < n) {
            aux = prev1 + prev2;
            prev1 = prev2;
            prev2 = aux;
            p++;
        }

        return prev2;
    }
};