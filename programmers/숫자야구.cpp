/*
 * =====================================================================================
 *
 *       Filename:  숫자야구.cpp
 *
 *    Description:  simulation
 *
 *        Version:  1.0
 *        Created:  2019/07/14 11시 17분 56초
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

vector<int> cands;

void init(){
    for(int i=123; i<=987; i++){
        int a= i%10, b=(i/10)%10, c=(i/100)%10;
        if(a==0 || b==0 || c==0) continue;
        if(a==b || a==c || b==c) continue;
        cands.push_back(i);
    }
}
void query(int target, int scnt, int bcnt){
    for(int cand=0; cand<cands.size();){
        vector<int> cur;
        vector<int> t;
        int div = 1;
        for(int i=0; i<3; i++){
            cur.push_back((cands[cand]/div)%10);
            t.push_back((target/div)%10);
            div*=10;
        }
        int exist=0, equal=0;
        for(int i=0; i<3; i++)
            for(int j=0; j<3; j++)
                if(cur[i]==t[j]) exist++;
        for(int i=0; i<3; i++)
            if(cur[i]==t[i]) equal++;
        if(equal==scnt && bcnt == exist - equal)
            cand++;
        else
            cands.erase(cands.begin()+cand);
    }
}

int solution(vector<vector<int>> baseball) {
    int answer = 0;
    init();

    for(int b=0; b<baseball.size(); b++)
        query(baseball[b][0],baseball[b][1],baseball[b][2]);

    answer = cands.size();
    return answer;
}
