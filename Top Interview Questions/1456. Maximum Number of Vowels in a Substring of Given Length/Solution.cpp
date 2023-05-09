#include <string>
#include <stdio.h>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxVowels(std::string s, int k) {
        int cont = 0, i, max;
        for (i = 0; i < k; i++) {
            if (isVowel(s[i])) cont++;
        }

        max = cont;

        for (i = k; i < s.length(); i++) {
            if (isVowel(s[i])) cont++;
            if (isVowel(s[i - k])) cont--;
            if (cont > max) max = cont;
        }
        return max;
    }

    bool isVowel (char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};
