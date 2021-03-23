// merge_sort.cpp
// 
// Driver Program to test merge_sort()
//
// Author: Rohit Mehta
//------------------------------------------------------------------------------------

#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

using namespace std;

static const int MAX = 100;

void merge_sort(int*, const int, const int);        // Defined in merge.cpp

int main()
{
    srand( time(NULL) );
    int test_arr[MAX];

    for(int i = 0; i < MAX; i++)
        test_arr[i] = rand() % 1000 + 1;

    cout << "\nRandom Array generated: \n";
    for(int i = 0; i < MAX; i++)
        cout << "\t" << setw(5) << right << test_arr[i] << endl;

    merge_sort(test_arr, 0, MAX-1);

    cout << "\nArray After sorting through Divide-&-Conquer:\n";
    for(int i = 0; i < MAX; i++)
        cout << "\t" << setw(5) << right << test_arr[i] << endl;

    return 0;
}


///////////////////////////////////////////////////////////////////////////
// Merge sort implementation.
///////////////////////////////////////////////////////////////////////////
// >.>>>>>>>>>>>>>>>>>>>>>>>>> NOTE: p, q, and r are the indices of the elements
//                                  in the respective array.
void merge(int* arr, const int p, const int q, const int r)
{
    // p <= q < r
    // in the array arr, subarray arr[p ... q] and arr[q+1 ... r] is sorted already.
    int    n1 = q - p + 1;
    int    n2 = r - q;

    int left[n1], right[n2];
    for(int i=0; i < n1; i++)
        left[i] = arr[p + i];       // copy the sorted subarray arr[p ... q] into left

    for(int i=0; i < n2; i++)
        right[i] = arr[q + 1 + i];  //copy the sorted subarray arr[q+1 ... r] into right

    // now merge the left and right into arr.
    int i = 0, j = 0, k = p;
    while(i < n1 && j < n2){

        if( left[i] <= right[j] ){
            arr[k] = left[i];
            i++;
        }else{
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    // copy remaining of elements into arr
    while( i < n1){
        arr[k] = left[i];
        i++;
        k++;
    }
    while( j < n2){
        arr[k] = right[j];
        j++;
        k++;
    }
}
// This function divides & conquers(sorts) the array
// the arr[a ... b] is sorted
void merge_sort(int *arr, const int a, const int b)
{
    if ( a < b){    
        int q = (a+b)/2;    // divide the arr

        merge_sort(arr, a, q);  // left subarray to be sorted
        merge_sort(arr, q+1, b);    // right subarray to be sorted

        merge(arr, a, q, b);    // now merge them.
    }
}