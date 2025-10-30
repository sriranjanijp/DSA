#include <iostream>
#include <stack>   // The STL stack library
#include <string>
#include <cctype>  // For std::isalnum()

/**
 * @brief Helper function to check if a character is an operator.
 */
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

/**
 * @brief Helper function to get operator precedence.
 * Higher number means higher precedence.
 */
int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0; // For non-operators
}

/**
 * @brief Converts an infix expression string to a postfix (RPN) string.
 * @param infix The infix expression (e.g., "a+b*c-d/e").
 * @return The equivalent postfix expression (e.g., "abc*+de/-").
 */
std::string infixToPostfix(const std::string& infix) {
    std::string postfix = "";
    std::stack<char> operatorStack; // Stack to hold operators and parentheses

    for (char c : infix) {
        
        // 1. If it's an operand (a-z, A-Z, 0-9), add it to the output.
        if (std::isalnum(c)) {
            postfix += c;
        } 
        // 2. If it's an opening parenthesis, push it onto the stack.
        else if (c == '(') {
            operatorStack.push(c);
        }
        // 3. If it's a closing parenthesis
        else if (c == ')') {
            // Pop and append from the stack until the matching '(' is found
            while (!operatorStack.empty() && operatorStack.top() != '(') {
                postfix += operatorStack.top();
                operatorStack.pop();
            }
            operatorStack.pop(); // Pop the '(' itself
        }
        // 4. If it's an operator
        else if (isOperator(c)) {
            // Pop operators from the stack that have higher or equal precedence
            // than the current operator, and append them to the postfix string.
            while (!operatorStack.empty() && operatorStack.top() != '(' &&
                   precedence(operatorStack.top()) >= precedence(c)) {
                postfix += operatorStack.top();
                operatorStack.pop();
            }
            // Push the current operator onto the stack
            operatorStack.push(c);
        }
    }

    // 5. After iterating, pop any remaining operators from the stack
    // and append them to the postfix string.
    while (!operatorStack.empty()) {
        postfix += operatorStack.top();
        operatorStack.pop();
    }

    return postfix;
}

// --- Main function to test the converter ---
int main() {
    // Test 1: Simple with precedence
    std::string infix1 = "a+b*c";
    std::string post1 = infixToPostfix(infix1);
    std::cout << "Infix:   " << infix1 << std::endl;
    std::cout << "Postfix: " << post1 << std::endl; // Output: abc*+

    std::cout << "--------------------" << std::endl;

    // Test 2: Full expression with parentheses
    std::string infix2 = "(a+b)*(c-d)";
    std::string post2 = infixToPostfix(infix2);
    std::cout << "Infix:   " << infix2 << std::endl;
    std::cout << "Postfix: " << post2 << std::endl; // Output: ab+cd-*

    std::cout << "--------------------" << std::endl;

    // Test 3: Complex expression from previous example
    std::string infix3 = "a+b*c-d/e";
    std::string post3 = infixToPostfix(infix3);
    std::cout << "Infix:   " << infix3 << std::endl;
    std::cout << "Postfix: " << post3 << std::endl; // Output: abc*+de/-

    return 0;
}
