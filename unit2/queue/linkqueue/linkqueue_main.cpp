#include <iostream>
#include "linkqueue.h"
int main() {
    LinkQuNode *queue = nullptr;
    InitQueue(queue);

    std::cout << "Is the queue empty? " << (QueueEmpty(queue) ? "Yes" : "No") << std::endl;

    // Enqueue elements
    enQueue(queue, 1);
    enQueue(queue, 2);
    enQueue(queue, 3);

    std::cout << "Is the queue empty after enqueuing elements? " << (QueueEmpty(queue) ? "Yes" : "No") << std::endl;

    // Dequeue elements
    ElemType dequeuedElement;
    deQueue(queue, dequeuedElement);
    std::cout << "Dequeued element from the queue: " << dequeuedElement << std::endl;

    std::cout << "Is the queue empty after dequeuing an element? " << (QueueEmpty(queue) ? "Yes" : "No") << std::endl;

    DestroyQueue(queue);
    system("pause");
    return 0;
}
