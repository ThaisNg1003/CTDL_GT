#include <iostream>
#include <stack>
#include <string>
#include <cctype> 
#include <sstream> 

using namespace std;


int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}


int applyOperation(int a, int b, char op, bool &divideByZero) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': 
            if (b == 0) {
                divideByZero = true;
                return 0;
            }
            return a / b;
    }
    return 0;
}


int evaluateInfix(const string &expression, bool &divideByZero) {
    stack<int> values; 
    stack<char> ops; 

    for (int i = 0; i < expression.length(); i++) {
        if (expression[i] == ' ') continue; 

 
        if (expression[i] == '(') {
            ops.push(expression[i]);
        }
 
        else if (isdigit(expression[i])) {
            int val = 0;
            while (i < expression.length() && isdigit(expression[i])) {
                val = (val * 10) + (expression[i] - '0');
                i++;
            }
            values.push(val);
            i--; 
        }

        else if (expression[i] == ')') {
            while (!ops.empty() && ops.top() != '(') {
                int val2 = values.top(); values.pop();
                int val1 = values.top(); values.pop();
                char op = ops.top(); ops.pop();
                values.push(applyOperation(val1, val2, op, divideByZero));
                if (divideByZero) return 0;
            }
            ops.pop(); 
        }
 
        else {
            while (!ops.empty() && precedence(ops.top()) >= precedence(expression[i])) {
                int val2 = values.top(); values.pop();
                int val1 = values.top(); values.pop();
                char op = ops.top(); ops.pop();
                values.push(applyOperation(val1, val2, op, divideByZero));
                if (divideByZero) return 0;
            }
            ops.push(expression[i]);
        }
    }

    while (!ops.empty()) {
        int val2 = values.top(); values.pop();
        int val1 = values.top(); values.pop();
        char op = ops.top(); ops.pop();
        values.push(applyOperation(val1, val2, op, divideByZero));
        if (divideByZero) return 0;
    }

    return values.top();
}

int main() {
int T;
    cin >> T;
    cin.ignore(); 

    for (int i = 0; i < T; ++i) {
        string expression;
        getline(cin, expression);
        bool divideByZero = false;
        int result = evaluateInfix(expression, divideByZero);
        if (divideByZero) {
            cout << "0" << endl;
        } else {
            cout << result << endl;
        }
    }
    return 0;
}