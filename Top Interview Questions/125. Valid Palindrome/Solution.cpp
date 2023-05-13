class Solution {
public:
    bool isPalindrome(string s) {
        unsigned int i = 0, j = s.size() - 1;
        while (i < j) {
            if (!(isalpha(s[i]) || isdigit(s[i]))) {
                //if (!(isalpha(s[j]) || isdigit(s[j]))) j--;
                i++;
            } else if (!(isalpha(s[j]) || isdigit(s[j]))) {
                //if (!(isalpha(s[i]) || isdigit(s[i]))) i++;
                j--;
            } else {
                if (tolower(s[i]) != tolower(s[j])) return false;
                i++;
                j--;
            }
        }
        return true;
    }
};