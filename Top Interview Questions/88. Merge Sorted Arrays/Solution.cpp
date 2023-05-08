class Solution {
public:
    void merge(vector<int>& nums1, int n, vector<int>& nums2, int m) {
        if (m == 0) return; //si la llista 2 està buida avortem, ja està conforme toca
        if (n == 0) { //si està buida la primera llista simplement li donem la referència de nums2
            nums1 = nums2;
        } else {
            
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


            //però si del que encara quedaven valors pendents era de num2 llavors 
            //els hem de copiar
            while (i < n) res[k++] = nums1[i++];
            while (j < m) res[k++] = nums2[j++];

            nums1 = res;
        }
    }
