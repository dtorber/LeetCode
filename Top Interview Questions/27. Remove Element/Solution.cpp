class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.size() == 0) return 0;
        unsigned int i, ultimaPos = 0, k = 0;
        for (i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[ultimaPos++] = nums[i];
                k++;
            }
        }
        return k;
    }
};