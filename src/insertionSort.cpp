#include <vector>
#include <algorithm>
using ll = long long;

void insertionSort(std::vector<int> &arr, int l, int r, ll &comparisons)
{
    for (int i = l + 1; i <= r; i++)
    {
        for (int j = i - 1; j >= l; j--)
        {
            comparisons++;
            if (arr[j + 1] < arr[j])
                std::swap(arr[j + 1], arr[j]);
            else
                break;
        }
    }
}
