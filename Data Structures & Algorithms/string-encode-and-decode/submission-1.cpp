#include <string>



class Solution {
public:

    string encode(vector<string>& strs) {
        string output;
        
        
        for(const auto& str: strs) {
            for (const auto& c: str) {
                int value = int(c);
                output += to_string(value);
                output += ";";

            }
            output += ".";
        }        
        cout << output ;
        return output;

    }

    vector<string> decode(string s) {
        vector<string> strings;

        int amount_strings{0};
        int ch{0};
        auto front = s.begin();

        
        while(front != s.end()) {

            string word{};
            while(*front != '.') {
                if (*front == ';') {
                    front++;
                    continue;
                } 
                if(*front == 'e') break;
                string c;
                
                while(*front != ';') {
                    c += *front;
                    front++;
                }
                

                word += (char)stoi(c);
                front++;
            }
            if (front == s.end()) break;

            front++;
            strings.push_back(word);          
        }

        return strings;

    }
};
