class Solution {
public:
    string addBinary(string a, string b) {
        if (a.size() == 0) return b;
        if (b.size() == 0) return a;

        int i = a.length() - 1, j = b.length() - 1;
        short int acumulat = 0, suma;
        string res = "";

        while(i >= 0 && j >= 0) {

            suma = int(a[i] - '0') + int(b[j] - '0') + acumulat;

            if (suma == 2) {
                res.insert(0,1,'0');
                acumulat = 1;
            }
            else if (suma == 3) {
                res.insert(0,1,'1');
                acumulat = 1;
            }  
            else {
                res.insert(0,1,char(suma) + '0'); //suma haurà de ser 0 o 1, aleshores ho passem a caràcter però això serà
                                                  //el caràcter del codi ASCII del 0 i l'1 aleshores cal sumar-li el 0 i ho concatenem 
                acumulat = 0;
            }

            i--;
            j--;
        }      

        //ara falta mirar si alguna de les dos cadenes era més llarga que l'altra i acabar de recórrer-la

        while (i >= 0) {
            suma = int(a[i] - '0') + acumulat;

            if (suma == 2) {
                res.insert(0,1,'0');
                acumulat = 1;
            }
            else if (suma == 3) {
                res.insert(0,1,'1');
                acumulat = 1;
            }  
            else {
                res.insert(0,1,char(suma) + '0'); //suma haurà de ser 0 o 1, aleshores ho passem a caràcter però això serà
                                                  //el caràcter del codi ASCII del 0 i l'1 aleshores cal sumar-li el 0 i ho concatenem 
                acumulat = 0;
            }

            i--;
        }


        while (j >= 0) {
            suma = int(b[j] - '0') + acumulat;

            if (suma == 2) {
                res.insert(0,1,'0');
                acumulat = 1;
            }
            else if (suma == 3) {
                res.insert(0,1,'1');
                acumulat = 1;
            }  
            else {
                res.insert(0,1,char(suma) + '0'); //suma haurà de ser 0 o 1, aleshores ho passem a caràcter però això serà
                                                  //el caràcter del codi ASCII del 0 i l'1 aleshores cal sumar-li el 0 i ho concatenem 
                acumulat = 0;
            }

            j--;
        }

        //per si quedava encara algun acumulat en l'última posició
        if (acumulat) res.insert(0,1,'1');


        return res;
    }
};