class Solution {
public:
    bool isPalindrome(string s) {
        auto front = s.begin();
        auto back = s.end();
      
        while (front < back) {
            auto s1 = *front;
            auto s2 = *back;
            if (!(isalpha(s1) || isdigit(s1))) {
                front++;
                continue;
            } if (!(isalpha(s2) || isdigit(s2))) {
                back--;
                continue;
            }
            if (toupper(s1) != toupper(s2)) return false;
            front++;
            back--;
        }
        return true;
        

        
    }
};
