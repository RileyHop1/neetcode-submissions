class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::vector<int>returned;
        std::map<int, int>numbers;

        for (int i = 0; i < nums.size(); i++) {
            int x = target - nums.at(i);
            if(numbers.find(x) == numbers.end()) {
                numbers[nums.at(i)] = i;


            } else {
                returned.push_back(numbers[x]);
                returned.push_back(i);
            }


        }

        return returned;
        

    }
};
