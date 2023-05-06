class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        unsigned int i;

        for (i = digits.size() - 1; i > 0; i--) {
            digits[i]++;
            if (digits[i] == 10) {
                digits[i] = 0;
            } else {
                break;
            }
        }

        if (i == 0) {
            digits[i]++;
            if (digits[i] == 10) {
                digits[i] = 1;
                digits.push_back(0);
            }
        }
        
        return digits;

    }
};