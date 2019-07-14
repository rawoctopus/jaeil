/*
 * =====================================================================================
 *
 *       Filename:  컬러링북.cpp
 *
 *    Description:  bfs
 *
 *        Version:  1.0
 *        Created:  2019/07/14 11시 14분 27초
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
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cstring>

using namespace std;
#define MAX 101
//m*n 크기

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int dr[4] = {1,-1,0,0};
    int dc[4] = {0,0,1,-1};

    int number_of_area = 0;
    int max_size_of_one_area = 0;
    int visited[MAX][MAX];
    memset(visited,0,sizeof(int)*MAX*MAX);

    for(int r=0; r<m; r++)
        for(int c=0; c<n; c++){
            if(!picture[r][c]) continue;
            if(visited[r][c]) continue;
            queue<pair<int,int> > Q;
            Q.push(make_pair(r,c));
            visited[r][c] = 1;
            number_of_area++;
            int curSize=1;
            while(Q.size()){
                int curR = Q.front().first;
                int curC = Q.front().second;
                Q.pop();
                for(int i=0; i<4; i++){
                    int nr = curR +dr[i];
                    int nc = curC + dc[i];
                    if(nr<0 || nr>=m || nc<0 || nc>=n) continue;
                    if(!picture[nr][nc]) continue;
                    if(visited[nr][nc]) continue;
                    if(picture[nr][nc] != picture[curR][curC]) continue;
                    visited[nr][nc] = 1;
                    curSize++;
                    Q.push(make_pair(nr,nc));
                }
            }
            max_size_of_one_area = max(max_size_of_one_area,curSize);
        }

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}

