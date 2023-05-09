class Solution {
public:
    void merge(vector<int>& nums1, int n, vector<int>& nums2, int m) {
        vector<int> res(n + m);
        int i = 0, j = 0, k = 0;
        while (i < n && j < m) {
            if (nums1[i] < nums2[j]) {
                res[k] = nums1[i++];
            } else {
                res[k] = nums2[j++];
            }
            k++;
        }

        //copiem els valors que estan en res i han canviat a nums1
        //i així després els que pertanyen a nums1 ja no els hem de tocar
        for (k = 0; k < i + j; k++) {
            nums1[k] = res[k];
        }

        //però si del que encara quedaven valors pendents era de num2 llavors 
        //els hem de copiar
        while (j < m) nums1[k++] = nums2[j++];
    }
};