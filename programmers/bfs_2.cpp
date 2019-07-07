/*
 * =====================================================================================
 *
 *       Filename:  bfs_2.cpp
 *
 *    Description:  programmers
 *
 *        Version:  1.0
 *        Created:  2019/07/07 10시 50분 20초
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
#define MAX 200

bool visited[MAX];

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;

    for(int i=0; i<n; i++){
        if(visited[i]) continue;
        queue<int> Q;
        Q.push(i);
        visited[i]=true;
        answer++;
        while (Q.size()){
            int cur = Q.front();
            Q.pop();
            for(int next=0; next<computers[cur].size(); next++)
                if(computers[cur][next]){
                    if(visited[next]) continue;
                    Q.push(next);
                    visited[next] = true;
                }
        }
    }

    return answer;
}
