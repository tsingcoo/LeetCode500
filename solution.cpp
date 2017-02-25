//
// Created by 王青龙 on 2017/2/25.
//

#include <unordered_set>
#include <string>
#include "solution.h"

std::vector<std::string> Solution::findWords(std::vector<std::string> &words) {
    std::unordered_set<char> row1 = {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p'};
    std::unordered_set<char> row2 = {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l'};
    std::unordered_set<char> row3 = {'z', 'x', 'c', 'v', 'b', 'n', 'm'};
    std::vector<std::unordered_set<char>> rows = {row1, row2, row3};
    std::vector<std::string> validWords;
    for (int i = 0; i < words.size(); ++i) {
        int row = 0;
        for (int j = 0; j < rows.size(); ++j) {
            if (rows[j].count((char) tolower(words[i][0])) > 0) {
                row = j;
            }
        }
        validWords.push_back(words[i]);
        for (int k = 1; k < words[i].size(); ++k) {//这里从1开始，因为开头的字母已经判断过了
            if (rows[row].count((char) tolower(words[i][k])) == 0) {
                validWords.pop_back();
                break;
            }
        }
    }
    return validWords;
}