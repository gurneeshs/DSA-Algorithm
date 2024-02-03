// ****************************************************************************
// 
// BEST TIME COMPLEXITY: O(n logn)
// WORST TIME COMPLEXITY: O(n logn)
// USE CASE:-
// ****************************************************************************

#include <iostream>
#include<vector>
using namespace std;


void merge(vector<int>& arr, int st,int mid, int end){
    int n1 = mid - st+1;
    int n2 = end-mid;

    vector<int> leftarr(n1);
    vector<int> rightarr(n2);
    for(int i=0;i<n1;i++){
        leftarr[i] = arr[st + i];
    }    
    for(int i=0;i<n2;i++){
        rightarr[i] =arr[mid+1+i];
    }

    int i=0;
    int j = 0;
    int k = st;
    while(i<n1 && j<n2){
        if(leftarr[i]<=rightarr[j]){
            arr[k] = leftarr[i];
            i++;
        }
        else{
            arr[k] = rightarr[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k] = leftarr[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k] = rightarr[j];
        j++;
        k++;
    }
}
void mergeSort(vector<int>& arr, int st, int end){

    if(st<end){
        int mid = st + ((end-st)/2);

        mergeSort(arr, st, mid);
        mergeSort(arr,mid+1,end);
        merge(arr,st,mid,end);
    }

}
void printArray(vector<int> arr, int siz){
    for (int i=0;i<siz;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){

    vector<int> arr;
    arr = {9,8,7,1,2};
    cout<<"Befor Sorting";
    printArray(arr,5);

    mergeSort(arr,0, 4);

    cout<<"After Sorting";
    printArray(arr,5);
    return 0;
}
