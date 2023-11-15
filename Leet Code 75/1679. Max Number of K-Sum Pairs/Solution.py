class Solution:
    def maxOperations(self, nums: List[int], k: int) -> int:
        contador = defaultdict(int)
        parelles = 0
        for num in nums:
            contador[num] += 1
        
        for num, aparicions in contador.items():
            dif = k - num
            if dif == num:
                if aparicions > 1:
                    parelles += aparicions // 2 
            elif dif in contador:
                aparicions_dif = contador[dif]
                if aparicions > 0 and aparicions_dif > 0:
                    noves_parelles = min(aparicions, aparicions_dif)
                    contador[num] -= noves_parelles
                    contador[dif] -= noves_parelles
                    parelles += noves_parelles

        return parelles