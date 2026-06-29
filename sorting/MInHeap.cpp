#include <bits/stdc++.h>
using namespace std;

#define MAX 100

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
    {
        largest = l;
    }
    if (r < n && arr[r] > arr[largest])
    {
        largest = r;
    }
    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

void buildMaxHeap(int arr[], int n)
{
    for (int i = n/2 -1; i >= 0; i--)
    {
        heapify(arr,n,i);
    }
    
}
void heapSort(int arr[], int n)
{
    buildMaxHeap(arr, n);

    cout << "Max Heap: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\n";

    int temp[MAX], sz = n;
    for (int i = 0; i < n; i++)
    {
        temp[i] = arr[i];
    }
    cout<< "Sorted:" ;
    while (sz)
    {
        cout<< temp[0] <<" ";
        swap(temp[0], temp[sz-1]);
        sz--;
        heapify(temp, sz, 0);
    }
    
    cout <<'\n';
}


int main() {
    int arr[MAX], n = 0, x;
    while (cin >> x && x != -1)
        arr[n++] = x;

    heapSort(arr, n);
    return 0;
}