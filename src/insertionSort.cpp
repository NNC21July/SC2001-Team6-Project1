#include <vector>
#include <algorithm>
#include <iostream>
#define ll long long
using namespace std;

void insertionSort(vector<int> &arr, int l, int r, ll &comparisons)
{
    for (int i = l + 1; i <= r; i++)
    {
        for (int j = i - 1; j >= l; j--)
        {
            comparisons++;
            if (arr[j + 1] < arr[j])
                swap(arr[j + 1], arr[j]);
            else
                break;
        }
    }
}

int main()
{
    vector<int> sample = {3, 6, 1, 7, 9, 8, 0, 2};
    ll comparisons;

    insertionSort(sample, 0, sample.size() - 1, comparisons);

    for (int num : sample)
        cout << num << " ";
    cout << endl
         << comparisons;

    return 0;
}