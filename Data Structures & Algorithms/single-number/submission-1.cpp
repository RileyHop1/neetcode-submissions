#include <unordered_set>
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> seen; 

        for (const auto& num: nums) {
            if (!seen.insert(num).second) {
                seen.erase(num);
            }

        }
        return *seen.begin();
        
    }
};
