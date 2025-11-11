#ifndef STACK_CPP
#define STACK_CPP

#include <iostream>

class Stack {
private:
    int top;
    int maxSize;
    int* stackArray;
public:
    Stack(int size) {
        maxSize = size;
        stackArray = new int[maxSize];
        top = -1;
    }

    void push(int value) {
        if (top == maxSize - 1) {
            std::cout << "Stack overflow" << std::endl;
            return;
        }
        stackArray[++top] = value;
    }

    int pop() {
        if (top == -1) {
            std::cout << "Stack underflow" << std::endl;
            return -1;
        }
        return stackArray[top--];
    }

    int peek() {
        if (top == -1) {
            std::cout << "Stack is empty" << std::endl;
            return -1;
        }
        return stackArray[top];
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isBalanced(std::string str) {
        // "if(a[0] == '{')"
        bool isInQuotes = false;
        for (char& c : str) {
            if (c == '\'' || c == '\"') {
                isInQuotes = !isInQuotes;
            }
            if (isInQuotes) continue;

            if (c == '(' || c == '[' || c == '{') {
                this->push(c);
            } else if (c == ')' || c == ']' || c == '}') {
                if (this->isEmpty()) return false;
                char top = this->pop();
                if (!isMatchingPair(top, c)) return false;
            }
        }
        return this->isEmpty();
    }

    bool isMatchingPair(char open, char close) {
        return (open == '(' && close == ')') ||
               (open == '[' && close == ']') ||
               (open == '{' && close == '}');
    }

    ~Stack() {
        delete[] stackArray;
    }
};
#endif
