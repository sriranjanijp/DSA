#include <stack>
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool isOperator(char c){
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

string toPostfix(const string &infix){
    string postfix = "";
    stack<char> st;

    for(char c : infix)
    {
        if(isalnum(c)){
            postfix += c;
        }
        else if(c=='('){
            st.push(c);
        }
        else if(c==')'){
            while(!st.empty() && st.top() != '('){
                postfix += st.top();
                st.pop();
            }
            st.pop();
        }
        else if(isOperator(c)){
            while(!st.empty() && st.top() != '(' && precedence(st.top()) >= precedence(c)){
                postfix += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while(!st.empty()){
        postfix+=st.top();
        st.pop();
    }

    return postfix;
}

int main(){
    string infix1 = "a+b*c";
    string post1 = toPostfix(infix1);
    cout << "Infix:   " << infix1 << std::endl;
    cout << "Postfix: " << post1 << std::endl;

    std::string infix2 = "(a+b)*(c-d)";
    std::string post2 = toPostfix(infix2);
    std::cout << "Infix:   " << infix2 << std::endl;
    std::cout << "Postfix: " << post2 << std::endl;

    std::string infix3 = "a+b*c-d/e";
    std::string post3 = toPostfix(infix3);
    std::cout << "Infix:   " << infix3 << std::endl;
    std::cout << "Postfix: " << post3 << std::endl;
}