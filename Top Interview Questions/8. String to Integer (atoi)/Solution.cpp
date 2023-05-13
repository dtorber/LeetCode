class Solution {
public:
    int myAtoi(string s) {
      int MAX_POSITIU = (int) (pow(2, 31) - 1);
      int MAX_NEGATIU = (int) (-pow(2, 31));
       if (s == "" || s == " ") return 0;
       unsigned int i = 0;
       int n = 0;
       bool negatiu = false;
       while (i  < s.size() && s[i] == ' ') i++;
       if (s[i] == '+') i++;
       else if (s[i] == '-') {
           negatiu = true;
           i++;
       }
       if (!isdigit(s[i])) return 0;


      if (negatiu) {
        while (i < s.size() && isdigit(s[i])) {
          if (n < (MAX_NEGATIU + (s[i] - '0')) / 10) {
            n = MAX_NEGATIU;
            break;
          }
          n = n * 10 - (s[i] - '0');
          i++;
        }
      } else {
        while (i < s.size() && isdigit(s[i])) {
          if (n > (MAX_POSITIU - (s[i] - '0')) / 10) {
            n = MAX_POSITIU;
            break;
          }
          n = n * 10 + (s[i] - '0');
          i++;
        }
      }
       return n;
    }
};