#include <bits/stdc++.h>
using namespace std;

void rotate(int **arr, int d, int n)
{
    int *arr_new = new int[n];
    for (int i = 0; i < n; i++)
         arr_new[i] = *(*arr + (i+d) % n);
    *arr = arr_new;
}

void printArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        cout << *(arr + i) << " ";
    cout << endl;
}

int main()
{
    int n {};
    cout << "Enter number of elements: ";
    cin >> n;

    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter a number: ";
        cin >> arr[i];
    }

    cout << "Enter rotation number: ";
    int d {};
    cin >> d;

    cout << endl;
    cout << "Original array: ";
    printArray(arr, n);

    rotate(&arr, d, n);
    cout << "Rotated array: ";
    printArray(arr, n);
}
