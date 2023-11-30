#include "linear.h"

int main() {
    SqList *list;  // Declare a pointer to SqList
    ElemType arr[] = {1, 2, 3, 4, 5};  // Sample array

    // Initialize the list
    InitList(list);

    // Create a list from the array
    CreateList(list, arr, 5);

    // Display the initial list
    printf("Initial List:\n");
    DispList(list);

    // Insert an element at position 3
    ListInsert(list, 3, 10);

    // Display the list after insertion
    printf("\nList after insertion at position 3:\n");
    DispList(list);

    // Delete an element at position 2
    ElemType deletedElement;
    ListDelete(list, 2, deletedElement);

    // Display the list after deletion
    printf("\nList after deletion at position 2:\n");
    DispList(list);

    // Get the length of the list
    ListLength(list);

    // Locate the position of element 4
    LocateElem(list, 4);

    // Clean up and destroy the list
    DestoryList(list);
    system("pause");
    return 0;
}