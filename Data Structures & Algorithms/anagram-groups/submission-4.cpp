#include <unordered_map>
#include <algorithm>
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string, vector<string>> sets;
        vector<vector<string>> output;

        for(const auto &s : strs) {
            auto sorted = s;
            sort(sorted.begin(), sorted.end());
            sets[sorted].emplace_back(s);
        }

        for (const auto &s: sets) output.emplace_back(s.second);
        return output;


    }
};
