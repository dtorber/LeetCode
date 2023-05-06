#include <string>
#include <stdio.h>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxVowels(std::string s, int k) {
        int inici = 0, max = 0, posPrimeraVocal = 0, cont, i;
        while (inici < s.length()) {
            std::cout << inici << std::endl;
            cont = 0;
            posPrimeraVocal = 0;
            for (i = 0; i < k && i + inici < s.length(); i++) {
                if (isVowel(s[inici + i])) {
                    cont++;
                    if (posPrimeraVocal == 0) posPrimeraVocal = i; //no m'interessa que siga la 1a posició, vull la següent
                }
            }
            if (cont == k) return k; //si ja s'ha arribat a k vocals hem acabat, ja no se pot millorar
            if (cont > max) max = cont;
            
            if (cont == 0 || posPrimeraVocal == 0) inici += k;
            else inici += posPrimeraVocal;
        }
        return max;
    }

    bool isVowel (char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};

int main( int argc, char *argv[]) {
    Solution mySol;
    int res = mySol.maxVowels("bycmhbeqagorwcaydnguqwmxzbrr", 5);
    std::cout << "Solucio: " << res << endl;
}
