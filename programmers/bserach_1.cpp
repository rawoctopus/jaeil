/*
 * =====================================================================================
 *
 *       Filename:  bserach_1.cpp
 *
 *    Description:  programmers
 *
 *        Version:  1.0
 *        Created:  2019/07/07 10시 49분 38초
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

int solution(vector<int> budgets, int M) {
    int answer = 0;
    sort(budgets.begin(), budgets.end());
    if ((budgets.back() * budgets.size()) <= M) return budgets.back();
    int l = 1, r = budgets.back();
    int mid = 0;
    while (l <= r) {
        mid = (l + r) / 2;
        long long sum = 0;
        for (int i=0; i < budgets.size(); i++) {
            if (budgets[i] < mid) sum += budgets[i];
            else{
                sum += (mid * (budgets.size() - i));
                break;
            }
        }
        if (sum <= M) {
            answer = (answer >= mid)? answer : mid;
            l = mid + 1;
        }
        else 
            r = mid - 1;
    }
    return answer;
}
