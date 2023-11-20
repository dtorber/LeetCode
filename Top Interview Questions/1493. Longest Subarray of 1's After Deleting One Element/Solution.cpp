class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        unsigned short int p = 0;
        unsigned int cont[2], cont_max = 0, suma, i = 0;
        cont[0] = cont[1] = 0;
        //avancem fins al primer 1
        while (i < nums.size() && nums[i] == 0) i++;

        while(i < nums.size()) {
            if (nums[i]) {
                cont[p]++;
            } else if (i + 1 < nums.size()) {
                //es 0, ara falta descobrir si ve mes d'un zero
                if (nums[i + 1]) {
                    if (p == 0) {
                        //aleshores estava mirant la primera sequencia encara, llavors cal que canviem a la segona sequencia
                        p = 1;
                    } else {
                        //ara ja estava en la segona sequencia aleshores cal que sume els valors i el que abans
                        //era la suma de la segona sequencia ara es la primera
                        suma = cont[0] + cont[1];
                        if (suma > cont_max) cont_max = suma;
                        cont[0] = cont[1];
                        cont[1] = 0;
                    }
                } else {
                    //si haguera vingut mes d'un zero aleshores cal començar des de zero tot perque lo anterior no te 
                    //cap interes
                    suma = cont[0] + cont[1];
                    if (suma > cont_max) cont_max = suma;
                    p = 0;
                    cont[0] = cont[1] = 0;
                    //cal que ara ens llevem tots els zeros
                    while (i + 1 < nums.size() && !nums[i + 1]) i++;
                }
            }
            i++;
        }
        //per si de cas l'última posicio te un 1
        suma = cont[0] + cont[1];
        if (suma > cont_max) cont_max = suma;
        if (cont_max == nums.size()) cont_max--; //si son tot uns cal que llevem un de tots els uns
        return cont_max;
    }
};