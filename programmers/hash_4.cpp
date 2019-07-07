/*
 * =====================================================================================
 *
 *       Filename:  hash_4.cpp
 *
 *    Description:  hash
 *
 *        Version:  1.0
 *        Created:  2019/07/07 10시 42분 57초
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
#include <map>
#include <cstdlib>
#include <cstring>

using namespace std;

map <string,int> m;

vector<int> ans;
vector<pair<int,string> > v;

bool cmp(pair<int,int> p1, pair<int,int> p2){
    if(p1.first==p2.first)
        return p1.second < p2.second;
    return p1.first > p2.first;
}
bool cmp2(pair<int,string> p1, pair<int,string> p2){
    return p1.first > p2.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {

    for(int i=0; i<genres.size(); i++)
        m[genres[i]]+=plays[i];
    for(auto i=m.begin(); i!=m.end(); i++)
        v.push_back(make_pair(i->second,i->first));
    sort(v.begin(),v.end(),cmp2);
    for(int i=0; i<v.size(); i++){
        vector<pair<int,int>> tmp;
        for(int j=0; j<genres.size(); j++)
            if(genres[j]==v[i].second)
                tmp.push_back(make_pair(plays[j],j));
        sort(tmp.begin(),tmp.end(),cmp);
        if(tmp.size()==1){ans.push_back(tmp[0].second); continue;}
        ans.push_back(tmp[0].second);
        ans.push_back(tmp[1].second);
    }
    return ans;
}
