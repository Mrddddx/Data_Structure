#include <iostream>
#include "link_list.h"
int main() {
    // 测试单链表
    LinkNode *singleList = nullptr;
    ElemType singleListData[] = {3, 1, 4, 1, 5, 9};
    int singleListSize = sizeof(singleListData) / sizeof(singleListData[0]);
    InitList(singleList);
    // 头插法创建单链表
    CreateListF(singleList, singleListData, singleListSize);
    std::cout << "Single Linked List (created using head insertion): ";
    DispList(singleList);

    // 尾插法创建单链表
    LinkNode *singleListTail = nullptr;
    CreateListR(singleListTail, singleListData, singleListSize);
    std::cout << "Single Linked List (created using tail insertion): ";
    DispList(singleListTail);

    // 操作测试
    std::cout << "Is the single linked list empty? " << (ListEmpty(singleList) ? "Yes" : "No") << std::endl;
    std::cout << "Length of the single linked list: " << ListLength(singleList) << std::endl;

    ElemType getElement;
    GetElem(singleList, 3, getElement);
    std::cout << "Element at position 3 in the single linked list: " << getElement << std::endl;

    ListInsert(singleList, 2, 7);
    std::cout << "Single Linked List after inserting 7 at position 2: ";
    DispList(singleList);

    ElemType deletedElement;
    ListDelete(singleList, 4, deletedElement);
    std::cout << "Deleted element at position 4: " << deletedElement << std::endl;
    std::cout << "Single Linked List after deleting element at position 4: ";
    DispList(singleList);

    delmaxnode(singleList);
    std::cout << "Single Linked List after deleting the maximum element: ";
    DispList(singleList);

    sort(singleList);
    std::cout << "Single Linked List after sorting: ";
    DispList(singleList);

    // 测试双链表
    DLinkNode *doubleList = nullptr;
    ElemType doubleListData[] = {6, 5, 4, 3, 2, 1};
    int doubleListSize = sizeof(doubleListData) / sizeof(doubleListData[0]);

    // 头插法创建双链表
    DCreateListF(doubleList, doubleListData, doubleListSize);
    std::cout << "Double Linked List (created using head insertion): ";
    DispDList(doubleList);

    // 尾插法创建双链表
    DLinkNode *doubleListTail = nullptr;
    DCreateListR(doubleListTail, doubleListData, doubleListSize);
    std::cout << "Double Linked List (created using tail insertion): ";
    DispDList(doubleListTail);

    // 操作测试
    DListInsert(doubleList, 2, 8);
    std::cout << "Double Linked List after inserting 8 at position 2: ";
    DispDList(doubleList);

    DListDelete(doubleList, 4, deletedElement);
    std::cout << "Deleted element at position 4: " << deletedElement << std::endl;
    std::cout << "Double Linked List after deleting element at position 4: ";
    DispDList(doubleList);

    reverse(doubleList);
    std::cout << "Double Linked List after reversing: ";
    DispDList(doubleList);

    // 释放内存
    // ...
    system("pause");
    return 0;
}
