#include <unordered_map>
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> con;
        int longest = 0;

        for (const auto num: nums) {
            if(!con[num]) {
                con[num] = con[num-1] + con[num+1] + 1;
                con[num - con[num - 1]] = con[num];
                con[num + con[num + 1]] = con[num];
                longest = max(longest, con[num]);
            }
        }

        return longest;
   
    }
};
