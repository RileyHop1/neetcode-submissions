#include <unordered_map>

class Solution {
public:

    int climbStairs(int n) {
        unordered_map<int, int> m;
        return paths(n,m);



    }
    int paths(int target, unordered_map<int,int>& number) {
        if (target == 0) return 1;
        if (number.contains(target)) return number[target];

        int right = 0;
        int left = 0;
        

        if (target - 1 >= 0) right = paths(target-1, number);
        if (target - 2 >= 0) left = paths(target-2, number);
        number[target] = right + left;

        return  right + left;


    }

};
