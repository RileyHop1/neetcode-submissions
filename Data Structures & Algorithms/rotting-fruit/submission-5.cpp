#include <list>

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        list<pair<int,int>> q;
        int total_time = 0;

        for (int i{0}; i < grid.size(); ++i ) {
            for (int j{0}; j < grid[i].size(); ++j) {
                if (grid[i][j] != 2) continue;
                q.push_back({i, j});
                //This is the current amount of items in the Q for a turn 
                int te = 1;
                //This is the amount of turns that have happened
                int elap = 0;

                while (!q.empty()) {
                    if (te == 0)  {
                        te = q.size();
                        elap++;
                        std::cout << elap << std::endl;

                    }
                    int current_time = elap + 10;
                    auto [ l, k ] = q.front();
                    if (l > 0 && grid[l-1][k] != 0 
                        && (grid[l-1][k] > current_time + 1 
                        || grid[l-1][k] == 1) ) {
                        q.push_back({l-1,k});
                    } if (l < grid.size()-1 
                        && (grid[l+1][k] > current_time + 1 
                        || grid[l+1][k] == 1) ) {
                        q.push_back({l+1,k});
                    } if (k > 0 
                        && (grid[l][k-1] > current_time + 1 
                        || grid[l][k-1] == 1) ) {
                        q.push_back({l,k-1});
                    } if (k < grid[l].size()-1 
                        && (grid[l][k+1] > current_time + 1 
                        || grid[l][k+1] == 1) ) {
                        q.push_back({l,k+1});
                    }
                    q.pop_front();
                    te--;
                    grid[l][k] = elap + 10;

                }

            }
        }

        for (int i{0}; i < grid.size(); ++i ) {
            for (int j{0}; j < grid[i].size(); ++j) {
                if (grid[i][j] == 1) return -1; 
                total_time = max(grid[i][j]-10,total_time);
            }
        }
        return total_time;

        
    }
};
