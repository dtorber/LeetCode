class Solution {
public:
    bool isValid(string s) {
        stack<char> pila;
        bool esValid = true;
        unsigned int i = 0;
        while (esValid && i < s.length()) {
            if (esObert(s[i])) {
                pila.push(s[i]);
            } else {
                if (pila.empty()) esValid = false;
                else {
                    if (!coincidents(pila.top(), s[i])) esValid = false;
                    else pila.pop();
                }
            }
            i++;
        }

        return esValid && pila.empty();
    }

    bool esObert (char c) {
        return c == '(' || c == '[' || c == '{';
    }

    bool esTancat (char c) {
        return c == ')' || c == ']' || c == '}';
    }

    bool coincidents (char c1, char c2) {
        return (c1 == '(' && c2 == ')') || (c1 == '[' && c2 == ']') || (c1 == '{' && c2 == '}');
    }
};