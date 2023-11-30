#include <iostream>
#include "linkstack.h"
int main() {
    LinkSNode *stack = nullptr;
    InitStack(stack);

    std::cout << "Is the stack empty? " << (StackEmpty(stack) ? "Yes" : "No") << std::endl;

    // Push elements onto the stack
    Push(stack, 1);
    Push(stack, 2);
    Push(stack, 3);

    std::cout << "Is the stack empty after pushing elements? " << (StackEmpty(stack) ? "Yes" : "No") << std::endl;
    
    // Get top element without popping
    ElemType topElement;
    GetTop(stack, topElement);
    std::cout << "Top element of the stack without popping: " << topElement << std::endl;

    // Pop elements from the stack
    ElemType poppedElement;
    Pop(stack, poppedElement);
    std::cout << "Popped element from the stack: " << poppedElement << std::endl;

    std::cout << "Is the stack empty after popping an element? " << (StackEmpty(stack) ? "Yes" : "No") << std::endl;

    DestroyStack(stack);
    system("pause");
    return 0;
}
