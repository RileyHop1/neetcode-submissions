#include <list>
class Solution {
public:
    bool isValid(string s) {

        if (s.size() % 2 == 1) return false;
        list<char> st;
        

        for (const auto &c: s) {
            if (
                c == '(' ||
                c == '{' ||
                c == '['
            ) {
                st.push_back(c);
                continue;
            }
            auto sf = st.back();
            if (
                sf == '(' && c == ')' ||
                sf == '{' && c == '}' ||
                sf == '[' && c == ']'
            ) {
                st.pop_back();
            } else {
                return false;
            }
        }

        if (!st.empty()) return false;
        
        return true;

        
    }
};
