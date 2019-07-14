/*
 * =====================================================================================
 *
 *       Filename:  추석트래픽.cpp
 *
 *    Description:  string
 *
 *        Version:  1.0
 *        Created:  2019/07/14 11시 16분 16초
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

using namespace std;

struct window
{
    long begin;
    long end;
    void Parse(string s)
    {
        long hour = stol(s.substr(11));
        long min = stol(s.substr(14));
        long msec = (long)(stod(s.substr(17)) * 1000.0);
        long time = (long)(stod(s.substr(24)) * 1000.0);

        end = (hour * 60 + min) * 60 * 1000 + msec;
        begin = end - time + 1;
    }
    bool isOverlap(window w)
    {
        if(end < w.begin || begin > w.end)
            return false;
        return true;
    }
};


int solution(vector<string> lines) {
    int answer = 0;

    vector<window> vec;
    for(auto it = lines.begin(); it != lines.end(); it++)
    {
        window w;
        w.Parse(*it);
        vec.push_back(w);
    }

    for(auto it = vec.begin(); it != vec.end(); it++)
    {
        int cntLeft = 0, cntRight = 0;
        window left, right;
        left.begin = it->begin - 999;
        left.end = it->begin;
        right.begin = it->end;
        right.end = it->end + 999;

        for(auto it0 = vec.begin(); it0 != vec.end(); it0++)
        {
            if(left.isOverlap(*it0))
                cntLeft++;
            if(right.isOverlap(*it0))
                cntRight++;
        }
        answer = max(answer, max(cntLeft, cntRight));
    }

    return answer;
}

