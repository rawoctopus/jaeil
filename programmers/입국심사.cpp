/*
 * =====================================================================================
 *
 *       Filename:  입국심사.cpp
 *
 *    Description:  bsearch
 *
 *        Version:  1.0
 *        Created:  2019/07/14 11시 19분 04초
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <climits>

using namespace std;

#define MAX 1000000000
//입국심사 - 프로그래머스

long long solution(int n, vector<int> times) {
    sort(times.begin(),times.end());
    long long answer = times[times.size()-1]*n;
    long long l=1, r=answer, mid=0;
    for(int i=0; i<100; i++) {
        mid = (l+r)/2;
        long long sum=0;
        for(int t=0; t<times.size(); t++)
            sum+=(mid/times[t]);
        if(sum < n){
            l = mid+1;
        } else {
            answer = min(answer,mid);
            r = mid-1;
        }
    }

    return answer;
}

