#include <iostream>
#include <cstdlib>
#include "sqstack.h"
int main() {
    SqStack *stack = nullptr;
    InitStack(stack);

    std::cout << "Is the stack empty? " << (stack->top == -1 ? "Yes" : "No") << std::endl;

    // Push elements onto the stack
    Push(stack, 1);
    Push(stack, 2);
    Push(stack, 3);

    std::cout << "Is the stack empty after pushing elements? " << (stack->top == -1 ? "Yes" : "No") << std::endl;
    std::cout << "Top element of the stack: " << stack->data[stack->top] << std::endl;

    // Pop elements from the stack
    ElemType poppedElement;
    Pop(stack, poppedElement);
    std::cout << "Popped element from the stack: " << poppedElement << std::endl;

    std::cout << "Is the stack empty after popping an element? " << (stack->top == -1 ? "Yes" : "No") << std::endl;

    // Get top element without popping
    ElemType topElement;
    GetTop(stack, topElement);
    std::cout << "Top element of the stack without popping: " << topElement << std::endl;

    DestroyStack(stack);
    system("pause");
    return 0;
}
