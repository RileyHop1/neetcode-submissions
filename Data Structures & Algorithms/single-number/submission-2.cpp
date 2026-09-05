#include <unordered_set>
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int c = 0;
        for (const auto& num: nums) {
            c ^= num;

           
        }
        return c;
        
    }
};
