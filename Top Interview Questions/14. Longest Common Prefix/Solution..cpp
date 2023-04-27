class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        unsigned int i, j;
        bool coincidencia;
        string res = "";
        string cadenaMesCurta = strs[0];
        
        for (i = 1; i < strs.size(); i++) {
            if (strs[i].length() < cadenaMesCurta.length()) {
                cadenaMesCurta = strs[i];
            }
        }

        for (i = 0; i < cadenaMesCurta.length(); i++) {
            coincidencia = true;
            for (j = 0; j < strs.size(); j++) {
                if (cadenaMesCurta[i] != strs[j][i]) {
                    coincidencia = false;
                    break;
                }
            }
            if (coincidencia) {
                res += cadenaMesCurta[i];
            } else {
                break;
            }
        }
        return res;
    }
};