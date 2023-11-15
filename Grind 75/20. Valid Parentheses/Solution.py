class Solution:
    def is_close(self, symbol):
        return symbol == ')' or symbol == ']' or symbol == '}'

    def isValid(self, s: str) -> bool:
        equivalence = {
            ')': '(',
            ']': '[',
            '}': '{',
        }

        stack = deque(list())

        for symbol in s:
            if self.is_close(symbol):
                if len(stack) == 0: return False
                pendent = stack.pop()
                if equivalence[symbol] != pendent:
                    return False
            else:
                stack.append(symbol)
        return len(stack) == 0