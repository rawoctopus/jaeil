/*
 * =====================================================================================
 *
 *       Filename:  heap_1.cpp
 *
 *    Description:  heap
 *
 *        Version:  1.0
 *        Created:  2019/07/07 10시 44분 36초
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
#include <queue>
#include <iostream>

using namespace std;

priority_queue<int> PQ; //기본 최대힙 -> 부호 바꾸자

// 합성 매운맛 = 막내매움 + 두번째매움*2
int mix(int first, int second){
    return first + second*2;
}
int solution(vector<int> scoville, int K) {
    int answer = 0;
    for(auto elem : scoville)
        PQ.push(elem*-1);
    while(PQ.size()>1){
        int first = PQ.top()*-1;
        if(first>=K) break;
        PQ.pop();
        int second = PQ.top()*-1;
        PQ.pop();

        int newElem = mix(first,second);
        PQ.push(newElem*-1);
        answer++;
    }
    return (PQ.top()*-1 >= K) ? answer : -1;
}
