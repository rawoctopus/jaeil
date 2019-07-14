/*
 * =====================================================================================
 *
 *       Filename:  쇠막대기.cpp
 *
 *    Description:  stack
 *
 *        Version:  1.0
 *        Created:  2019/07/14 11시 17분 13초
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;
#define MAX 100000


int solution(string arrangement) {
    int answer = 0;
    if(!arrangement.size()) return 0;
    stack<char> stk;

    char prev = arrangement[0];
    stk.push(prev);
    for(int i=1; i<arrangement.size(); i++) {
        char cur = arrangement[i];
        if(prev=='('&&cur==')'){
            stk.pop();
            answer += stk.size();
        } else if(cur == '('){
            stk.push(cur);
        } else if(cur == ')'){
            stk.pop();
            answer++;
        }
        prev = cur;
    }

    return answer;
}

