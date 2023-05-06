class Solution {
    public int reverse(int x) {
        boolean signe = x < 0;
        String pre_s = Integer.toString(x);
        if (signe) pre_s = pre_s.substring(1);
        StringBuilder s = new StringBuilder(pre_s);

        int i = 0, j = s.length() - 1;
        while (i < j) {
            char aux = s.charAt(i);
            s.setCharAt(i, s.charAt(j));
            s.setCharAt(j, aux);
            i++;
            j--;
        }
        //no pot gastar-se long com a mesura auxiliar, conforme especifica l'enunciat per això capturem l'excepció
        try {
            int res = Integer.parseInt(s.toString());
            if (signe) res = -res;
            return res;
        } catch (Exception e) {
            return 0;
        }
    }
}