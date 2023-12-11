#include <iostream>
using namespace std;

void RadixSort(int a[], int exp, int n) {
    const int k = 10; 
    int b[1010] = {0};
    int t[1010];

    for (int i = 1; i <= n; i++) {
        b[(a[i] / exp) % k]++;
    }

    for (int i = 1; i < k; i++) {
        b[i] += b[i - 1];
    }

    for (int i = n; i >= 1; i--) {
        t[b[(a[i] / exp) % k]--] = a[i];
    }

    for (int i = 1; i <= n; i++) {
        a[i] = t[i];
    }
}

int main() {
    int n;
    int a[1010];
    int maxn = 0;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] > maxn)
            maxn = a[i];
    }

    int radix = 1;

    while (maxn >= radix) {
        RadixSort(a, radix, n);
        radix *= 10;
    }

    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }

    return 0;
}
