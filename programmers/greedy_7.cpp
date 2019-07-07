/*
 * =====================================================================================
 *
 *       Filename:  greedy_7.cpp
 *
 *    Description:  programmers
 *
 *        Version:  1.0
 *        Created:  2019/07/07 10시 47분 34초
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
using namespace std;

int solution(vector<int> weight) {
    int answer = 1;
    sort(weight.begin(),weight.end());
    for(int w=0; w<weight.size(); w++) {
        if(answer < weight[w]) return answer;
        answer+=weight[w];
    }
    return answer;
}
