#include <iostream>
#include <iomanip>

using namespace std;

void Create(int* a, const int size, const int Low, const int High, int i)
{
    a[i] = Low + rand() % (High - Low + 1);
    if (i < size - 1)
        Create(a, size, Low, High, i + 1);
}

void Print(int* a, const int size, int i)
{
    cout << "a[" << setw(2) << i << " ] = " << setw(4) << a[i] << endl;
    if (i < size - 1)
        Print(a, size, i + 1);
}

template <typename T>
void TCreate(T* a, const int size, const T Low, const T High, T i)
{
    a[i] = Low + rand() % (High - Low + 1);
    if (i < size - 1)
        Create(a, size, Low, High, i + 1);
}

template <typename T>
void TPrint(T* a, const T size, T i)
{
    cout << "a[" << setw(2) << i << " ] = " << setw(4) << a[i] << endl;
    if (i < size - 1)
        TPrint(a, size, i + 1);
}

int Sum(int* a, const int size, int i)
{
    if (i < size)
        return a[i] + Sum(a, size, i + 1);
    else
        return 0;
}

int main()
{
    const int n = 8;
    int a[n];
    int Low = -4;
    int High = 8;

    // Create and print the first table
    Create(a, n, Low, High, 0);
    cout << "Table 1:" << endl;
    Print(a, n, 0);
    cout << "S = " << Sum(a, n, 0) << endl;

    // Create and print the second table
    TCreate(a, n, Low, High, 0);
    cout << "Table 2:" << endl;
    TPrint(a, n, 0);

    return 0;
}
