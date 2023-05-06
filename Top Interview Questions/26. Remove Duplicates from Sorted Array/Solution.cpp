class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        unsigned int i, ultimVal = nums[0], ultimaPos = 1, k = 1;
        for (i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                nums[ultimaPos++] = nums[i];
                k++;
            }
        }
        return k;
    }
};