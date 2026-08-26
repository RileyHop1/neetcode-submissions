class Solution {
public:
    bool isPalindrome(string s) {
        auto front = s.begin();
        auto back = s.end();
      
        while (front < back) {
            auto s1 = *front;
            auto s2 = *back;
            if (!(isalnum(s1))) {
                front++;
                continue;
            } if (!(isalnum(s2))) {
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
