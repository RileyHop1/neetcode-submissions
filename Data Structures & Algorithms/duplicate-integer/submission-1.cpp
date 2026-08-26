#include <unordered_set>
#include <algorithm>
class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> o{};

        for(const auto& num: nums) 
            if (!o.insert(num).second) return true;

        return false;
        

        
    }
};