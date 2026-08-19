#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isMatching(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}');
}

bool isBalanced(string expression) {
    stack<char> s;

    for (char ch : expression) {
        if (ch == '(' || ch == '[' || ch == '{') {
            s.push(ch);
        } else if (ch == ')' || ch == ']' || ch == '}') {
            if (s.empty() || !isMatching(s.top(), ch)) {
                return false;
            }

            s.pop();
        }
    }

    return s.empty();
}

int main() {
    string expression = "{[()]}";

    if (isBalanced(expression)) {
        cout << "Balanced" << endl;
    } else {
        cout << "Not balanced" << endl;
    }

    return 0;
}