#include <unordered_set>
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        auto board_size = board.size();
        unordered_set<char> row;
        vector<unordered_set<char>> columns(board_size);//Default constructing all the columns, empty.
        vector<unordered_set<char>> squares(3);

        for(unsigned int i{0}; i < board_size; ++i) {
            if (i%3 == 0) {
                for (auto& s: squares) {
                    s.clear();
                }
            }
            for (unsigned int j{0}; j < board[i].size(); ++j) {
                auto cha = board[i][j];

                if (cha == '.') continue;

                int brick = j/3;
                
                auto row_size = row.size();
                auto column_size = columns[j].size();
                auto square_size = squares[brick].size();

                row.insert(cha);
                columns[j].insert(cha);
                squares[brick].insert(cha);

                if (
                    row.size() == row_size || 
                    columns[j].size() == column_size ||
                    squares[brick].size() == square_size
                ) return false;
            }
            row.clear();
        }



        return true; //Default
        
    }
};
