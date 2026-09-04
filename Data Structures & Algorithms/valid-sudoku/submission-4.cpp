#include <unordered_set>
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        auto board_size = board.size();
        unordered_set<char> row;
        vector<unordered_set<char>> columns(9);//Default constructing all the columns, empty.
        vector<unordered_set<char>> squares(9);

        for(unsigned int i{0}; i < board_size; ++i) {
            for (unsigned int j{0}; j < board[i].size(); ++j) {
                auto cha = board[i][j];

                if (cha == '.') continue;

                int brick =(i/3)*3+ j/3;

                if (
                    !row.insert(cha).second ||
                    !columns[j].insert(cha).second ||
                    !squares[brick].insert(cha).second
                ) return false;
            }
            row.clear();
        }



        return true; //Default
        
    }
};
