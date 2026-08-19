#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

int precedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    }

    if (op == '*' || op == '/') {
        return 2;
    }

    if (op == '^') {
        return 3;
    }

    return 0;
}

string infixToPostfix(string expression) {
    stack<char> operators;
    string result;

    for (char ch : expression) {
        if (isalnum(ch)) {
            result += ch;
        } else if (ch == '(') {
            operators.push(ch);
        } else if (ch == ')') {
            while (!operators.empty() && operators.top() != '(') {
                result += operators.top();
                operators.pop();
            }

            if (!operators.empty()) {
                operators.pop();
            }
        } else {
            while (!operators.empty() &&
                   operators.top() != '(' &&
                   precedence(operators.top()) >= precedence(ch)) {
                result += operators.top();
                operators.pop();
            }

            operators.push(ch);
        }
    }

    while (!operators.empty()) {
        result += operators.top();
        operators.pop();
    }

    return result;
}

int main() {
    string expression = "A+B*C";

    cout << infixToPostfix(expression) << endl;

    return 0;
}