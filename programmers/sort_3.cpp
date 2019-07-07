/*
 * =====================================================================================
 *
 *       Filename:  sort_3.cpp
 *
 *    Description:  programmers
 *
 *        Version:  1.0
 *        Created:  2019/07/07 10시 46분 07초
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

// h번이상 - h편 이상
// 나머지 - h번 이하

int solution(vector<int> citations) {
    int answer = 0;
    vector<int> arr = citations;
    int size = arr.size();
    sort(arr.begin(),arr.end());
    if(!arr[size-1]) return 0;
    for(int idx=0; idx<size; idx++)
        if(arr[idx] >= size-idx) return size-idx;
    return answer;
}
