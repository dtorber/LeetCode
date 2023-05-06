class Solution {
private:
    static vector<int> preBoyerMoore (string P, string T, int size) {
        int pLength = P.length();
        int last = pLength - 1;
        vector<int> R(size);
        unsigned int i;
        for (i = 0; i < size; i++) R[i] = pLength;
        for (i = 0; i < last; i++) R[P[i]] = last - i;
        return R;
    }

public:
    int strStr(string haystack, string needle) {
        string P = needle;
        string T = haystack;
        int offset = 0;
        int scan = 0;
        int last = P.length() - 1;
        int maxoffset = T.length() - P.length();
        vector<int> R = preBoyerMoore(P, T, 256);
        while (offset <= maxoffset) {
            for (scan = last; P[scan] == T[scan + offset]; scan--) {
                if (scan == 0) return offset;
            }
            offset += R[T[offset + last]];
        }
        //no trobat
        return -1;
    }
};