/*
 * =====================================================================================
 *
 *       Filename:  sort_1.cpp
 *
 *    Description:  programmers
 *
 *        Version:  1.0
 *        Created:  2019/07/07 10시 45분 15초
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (jaeil), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for(int cmd=0; cmd<commands.size(); cmd++) {
        int begin = commands[cmd][0] - 1;
        int end = commands[cmd][1];
        int k = commands[cmd][2] - 1;
        vector<int> piece(array.begin()+begin,array.begin()+end);
        
        sort(piece.begin(),piece.end());
        answer.push_back(piece[k]);
    }
    return answer;
}
