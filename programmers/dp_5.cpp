/*
 * =====================================================================================
 *
 *       Filename:  dp_5.cpp
 *
 *    Description:  programmers
 *
 *        Version:  1.0
 *        Created:  2019/07/07 10시 48분 16초
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

#define MAX 2002

vector<int> L;
vector<int> R;

bool used[MAX][MAX];
int dp[MAX][MAX];

int card(int l, int r){
    if(l>=L.size() || r>=R.size()) return 0; 
    if(used[l][r]) return dp[l][r];
    if(L[l]>R[r])
        dp[l][r] = R[r] + card(l,r+1);
    else
        dp[l][r] = max(card(l+1,r),card(l+1,r+1));
    used[l][r] = true;
    return dp[l][r];
}

int solution(vector<int> left, vector<int> right) {
    int answer = 0;
    L=left; R=right;
    answer = card(0,0);
    return answer;
}
