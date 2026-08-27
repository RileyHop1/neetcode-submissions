class Solution {
public:
    int search(vector<int>& nums, int target) {
        int front = 0;
        int back = nums.size() - 1;
        
        while(front <= back) {
            
            int middle = (back + front)/2;
            if(target == nums[middle]) return middle;
            else if (target > nums[middle]) front = middle + 1;
            else back = middle - 1;
            
        }

        return -1;
        
    }
};
