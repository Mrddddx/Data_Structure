#include <iostream>
#include <cmath>
using namespace std;
struct tree{
    int data;
    int left,right;
} T;
tree a[100];
void Disp(tree a[], int n)
{
    for (int i = 1; i < n; i++)
        cout << a[i].data << ' ';
    cout << a[n].data << endl;
}
void heapify(tree a[], int n, int i) {
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= n && a[left].data > a[largest].data)
        largest = left;

    if (right <= n && a[right].data > a[largest].data)
        largest = right;

    if (largest != i) {
        swap(a[i], a[largest]);
        heapify(a, n, largest);
    }
}

void buildHeap(tree a[], int n) {
    for (int i = n / 2; i >= 1; i--) {
        heapify(a, n, i);
    }
}

void heapSort(tree a[], int n) {
    buildHeap(a, n);

    for (int i = n; i > 1; i--) {
        swap(a[1], a[i]);
        heapify(a, i - 1, 1);

    }
}

int main() {
    int n;
    cin >> n;

    tree a[100];

    for (int i = 1; i <= n; i++) {
        cin >> a[i].data;
        a[i].left = a[i].right = 0;
    }

    heapSort(a, n);
    Disp(a, n);
    return 0;
}
