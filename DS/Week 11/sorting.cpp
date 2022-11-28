#include <iostream>
using namespace std;

void bubble(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void selection(int arr[], int n)
{
    int min;
    for (int i = 0; i < n - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            int temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }
    }
}

void insertion(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int partition(int arr[], int low, int high)
{
    int p = arr[low];
    int cnt = 0;
    for (int i = low + 1; i <= high; i++)
    {
        if (arr[i] <= p)
            cnt++;
    }
    int pindex = low + cnt;
    swap(arr[pindex], arr[low]);
    int i = low, j = high;
    while (i < pindex && j > pindex)
    {
        while (arr[i] <= p)
            i++;
        while (arr[j] > p)
            j--;
        if (i < pindex && j > pindex)
            swap(arr[i++], arr[j--]);
    }
    return pindex;
}

void quick(int arr[], int low, int high)
{
    if (low < high)
    {
        int mid = partition(arr, low, high);
        quick(arr, low, mid - 1);
        quick(arr, mid + 1, high);
    }
}

void heapify(int arr[],int n,int i) {
    int largest=i;
    int l=2*i+1;
    int r=2*i+2;
    if (l<n && arr[l]>arr[largest])
        largest=l;
    if (r<n && arr[r]>arr[largest])
        largest=r;
    if (largest!=i) {
        swap(arr[i],arr[largest]);
        heapify(arr,n,largest);
    }
}

void heap(int arr[],int n) {
    for (int i=n/2 -1;i>=0;i--)
        heapify(arr,n,i);
    for (int i=n-1;i>=0;i--) {
        swap(arr[0],arr[i]);
        heapify(arr,i,0);
    }

}

void display(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
}

void merge(int arr[], int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;
    int L[n1], M[n2];
    for (int i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for (int j = 0; j < n2; j++)
        M[j] = arr[q + 1 + j];
    int i, j, k;
    i = 0;
    j = 0;
    k = p;
    while (i < n1 && j < n2) {
        if (L[i] <= M[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = M[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = M[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
  if (l < r) {
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
  }
}

int main()
{
    cout << "Enter number of elements in array" << endl;
    int n;
    cin >> n;
    int arr[n];
    cout << "Enter elements:" << endl;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int ch;
    cout << "1.Bubble Sort\n2.Quick Sort\n3.Insertion Sort\n4.Selection Sort\n5.Heap Sort\n6.Merge Sort\n7.Exit" << endl;
    while (ch!=7)
    {
        cin >> ch;
        switch (ch)
        {
        case 1:
            bubble(arr, n);
            display(arr, n);
            break;
        case 2:
            quick(arr, 0, n - 1);
            display(arr, n);
            break;
        case 3:
            insertion(arr, n);
            display(arr, n);
            break;
        case 4:
            selection(arr, n);
            display(arr, n);
            break;
        case 5:
            heap(arr, n);
            display(arr, n);
            break;
        case 6:
            mergeSort(arr, 0, n);
            display(arr, n);
            break;
        case 7:
            cout << "Exit";
            exit(0);
        }
    }
}