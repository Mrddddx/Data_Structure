#include <iostream>
#include <cmath>
using namespace std;

void Disp(int a[], int n)
{
    for (int i = 1; i < n; i++)
        cout << a[i] << ' ';
    cout << a[n] << endl;
}

void QuickSort(int a[],int l,int r)
{
    int q=a[(l+r)/2];
    int i=l,j=r;
    int t;
    while(i<=j)
    {
        while(a[i]<q) i++;
        while(a[j]>q) j--;
        if(i<=j)
        {
            t=a[i];a[i]=a[j];a[j]=t;
            i++;j--;
        }
    }
    if(i<r) QuickSort(a,i,r);
    if(l<j) QuickSort(a,l,j);
}

int main()
{
    int n;
    cin >> n;
    int a[100];
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    QuickSort(a,1,n);

    Disp(a, n);

    return 0;
}
