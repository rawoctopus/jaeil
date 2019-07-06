/*
 * =====================================================================================
 *
 *       Filename:  stack.cpp
 *
 *    Description:  stack
 *
 *        Version:  1.0
 *        Created:  2019/06/29 19시 18분 05초
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (lji), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>

using namespace std;
#define MAX 10000

int Stack[MAX];
int top = -1;

void push(int input) {
    Stack[++top] = input;
}
int pop() {
    return Stack[top--];
}
bool isEmpty(){
    return top == -1;
}


int main(int argc, char** argv) {
    for(int i=0; i<5; i++)
        push(i);
    for(int i=0; i<5; i++)
        cout << pop() << endl;
    cout << isEmpty() << endl;
    return 0;
}
