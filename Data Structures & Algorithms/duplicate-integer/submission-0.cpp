class Solution {
public:


    bool hasDuplicate(vector<int>& nums) {
        map<int, int> helper;
        int mapSize = 0;

        for (auto num: nums){

            if (helper.count(num)) {
                return true;
            } else {
                helper.insert({num, 1});
            }
            
        }
        return false;




        
    }
};