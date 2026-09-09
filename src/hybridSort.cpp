#include <vector>
#include "mergeSort.hpp"
#include "insertionSort.hpp"
using ll = long long;

void hybridSort(std::vector<int> &arr, int l, int r, ll &comparisons, int s)
{
    if (l >= r)
        return;

    if (r - l + 1 <= s)
        insertionSort(arr, l, r, comparisons);
    else
    {
        int m = (l + r) / 2;
        hybridSort(arr, l, m, comparisons, s);
        hybridSort(arr, m + 1, r, comparisons, s);

        mergeSortedArrs(arr, l, m, m + 1, r, comparisons);
    }
}