/*
 * =====================================================================================
 *
 *       Filename:  queue.cpp
 *
 *    Description:  queue
 *
 *        Version:  1.0
 *        Created:  2019/06/29 19시 42분 55초
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <cstdlib>

using namespace std;

#define INIT_SIZE 10

struct Queue{
private:
    int* queue;
    int back;
    int front;
    bool isFull(){
        return sizeof(queue) == (back-front) * sizeof(int);
    }
    void makeDouble(){
        queue = (int*)realloc(queue,sizeof(queue)*2);
    }
public:
    Queue(){
        back = front = -1;
        queue = (int*)malloc(sizeof(int)*INIT_SIZE);
    }
    void push_back(int input){
        if(isFull()) makeDouble();
        queue[++back] = input;
    }
    void pop_back(){
        ++front;
    }
    bool isEmpty(){
        return back == front;
    }
    int size(){
        return back-front;
    }
};


Queue Q;

int main(int argc, char** argv) {
    for(int i=0; i<20; i++)
        Q.push_back(i);
    cout<< Q.size() << endl;
    for(int i=0; i<20; i++)
        Q.pop_back();
    cout<< Q.size() << endl;
    return 0;
}
