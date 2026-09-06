#include <unordered_map>
#include <math.h>


class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        unordered_map<int, int> ptcp;
        int min = dfs(cost, -1, ptcp);
        for (auto p: ptcp) {
            
        }
        return min;
        
    }

    int dfs(vector<int>& cost, int i, unordered_map<int,int>& ptcp) {
        if (i == cost.size() -1 ) return cost[i];
        if (ptcp.contains(i)) return ptcp[i];

        int left = 0;
        int right = 0;


        if (i + 1 < cost.size()) {
            left = dfs(cost, i + 1, ptcp);
        } if (i + 2 < cost.size()) {
            right = dfs(cost, i + 2, ptcp);
        } 

     


        int mi = min(left,right);

        if (i == -1) return mi;

        ptcp[i] =  mi + cost[i];
        return ptcp[i];



    }
};
