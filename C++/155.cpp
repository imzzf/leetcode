#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class MinStack {
   public:
    stack<int> p;
    stack<int> minstack;
    MinStack() {
        minstack.push(INT_MAX);
    }

    void push(int x) {
        p.push(x);
        minstack.push(min(minstack.top(), x));
    }

    void pop() {
        p.pop();
        minstack.pop();
    }

    int top() {
        return p.top();
    }

    int getMin() {
        return minstack.top();
    }
};

int main() {
    return 0;
}