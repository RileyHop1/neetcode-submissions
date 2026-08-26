class Solution {
public:
    bool isAnagram(string s, string t) {

        std::map<char, int> anagrams;

        for (char a: s) {

            anagrams[a]++;
            
        } for (char a: t) {
            anagrams[a]--;
            if(anagrams[a] == 0) {
                anagrams.erase(a);
            }
        }

        if (anagrams.empty()) {
            return true;
        } else {
            return false;
        }
        
    }
};
