class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1:
            return s
        strings = ["" for _ in range(numRows)]

        current_row = 0
        zig_zag = False
        for c in s:
            strings[current_row] += c  
            if zig_zag:
                if current_row == 0:
                    zig_zag = False
                    current_row += 1
                else:
                    current_row -= 1
            else:
                if current_row + 1 == numRows:
                    zig_zag = True
                    current_row -= 1
                else:
                    current_row += 1
        
        res = ""
        for string in strings:
            res += string

        return res 