import java.util.Map;
import java.util.HashMap;
class Solution {
    Map<Character,Integer> equivalenciaRomaEnters = new HashMap<> ();
    public int romanToInt(String s) {
        this.equivalenciaRomaEnters.put('I', 1);
        this.equivalenciaRomaEnters.put('V', 5);
        this.equivalenciaRomaEnters.put('X', 10);
        this.equivalenciaRomaEnters.put('L', 50);
        this.equivalenciaRomaEnters.put('C', 100);
        this.equivalenciaRomaEnters.put('D', 500);
        this.equivalenciaRomaEnters.put('M', 1000);
        int count = 0, i = 0;
        char act, seg;

        while (i < s.length() - 1) {
            act = s.charAt(i);
            seg = s.charAt(i + 1);
            if (act == 'I') {
                if (seg == 'V' || seg == 'X') count--;
                else count++; 
            } else if (act == 'X') {
                if (seg == 'L' || seg == 'C') count -= 10;
                else count += 10; 
            } else if (act == 'C') {
                if (seg == 'D' || seg == 'M') count -= 100;
                else count += 100;
            } else {
                count += this.retornarValorEnter(act);
            }
            ++i;
        }

        act = s.charAt(s.length() - 1);
        count += this.retornarValorEnter(act);



        return count;
    }

    public int retornarValorEnter (char valorRoma) {
        // Integer res = this.equivalenciaRomaEnters.get(valorRoma);
        // if (res == null) return 0;
        // else return res;
        if (valorRoma == 'I') return 1;
        if (valorRoma == 'V') return 5;
        if (valorRoma == 'X') return 10;
        if (valorRoma == 'L') return 50;
        if (valorRoma == 'C') return 100;
        if (valorRoma == 'D') return 500;
        if (valorRoma == 'M') return 1000;
        return 0;
    }
}