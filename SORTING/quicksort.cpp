// ****************************************************************************
// 
// BEST TIME COMPLEXITY: O(n logn)
// WORST TIME COMPLEXITY: O(n^2)
// USE CASE:-
// ****************************************************************************
/*
ALGORITHM:

1. Find Pivot element
2. Arrange the element as elements less than pivot are in left of pivot and
   element greater than pivot are in right of pivot
3. Place the pivot at its correct position and return the index p
4. Call the quicksort method for (start,p-1) and (p+1,end)

*/
#include <iostream>
#include<vector>
using namespace std;

void printArray(int *arr, int siz){
    for (int i=0;i<siz;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int partition(int *arr, int s, int e){
    int pivot = arr[s];

    int cnt=0;
    for (int i=s+1;i<=e;i++){
        if(arr[i]<=pivot){
            cnt++;
        }
    }
    // Pivot index
    int pivotindex = s+cnt;
    swap(arr[s],arr[pivotindex]);
    int i=s,j=e;

    while(i<pivotindex && j>pivotindex){
        if(arr[i]>=pivot && arr[j]<=pivot){
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
        else if(arr[i]>pivot && arr[j]>pivot){
            j--;
        }
        else if(arr[i]<pivot && arr[j]<pivot){
            i++;
        }
        else{
            i++;
            j--;
        }
    }
    return pivotindex;
}

void quickSort(int *arr, int s, int e){
    if(s<e){
        // partition
        int p = partition(arr, s, e);
        printArray(arr,8);
       
        // left sub-part
        quickSort(arr,s,p-1);
        
        // right sub-part
        quickSort(arr,p+1,e);
    }
}


int main(){
    int arr[8] = {6,6,-6,-2,-4,-6,2,-6};
       cout<<"Befor Sorting";
    printArray(arr,8);

    quickSort(arr,0, 7);

    cout<<"After Sorting";
    printArray(arr,8);

    return 0;
}