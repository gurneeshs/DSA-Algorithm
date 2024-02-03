
// *******************************************************************************
// 1. mid = (start + end)/2 fails if start = INT_MAX and end = INT_MAX
// 2. complexity : log(n)
// *******************************************************************************
#include <iostream>
#include <vector>
using namespace std;

void binarySearch(int arr[][3], int row, int col, int key){
    int start = 0;
    int end = (row*col)- 1;

    int mid  = start + ((end - start)/2);

    while (start<=end)
    {
        int element = arr[mid/col][mid%col];
        if(element == key){
            cout<<"Element Found"<<endl;
            return ;
        }
        else if(key > element){
            start = mid + 1;
        }
        else{
            end =mid - 1;
        }
        mid  = start + ((end - start)/2);

    }
    cout<<"Element not found"<<endl;
    return ;
    
}
int main(){
    int row, col,el;
    int arr[3][3];

    cout<<"Enter Array Elements:";

    for(int i = 0;i<3;i++){
        for(int j = 0;j<3;j++){
            cin>>arr[i][j];
        }
    }
    cout<<"Enter Element to Search";
    cin>>el;
    binarySearch(arr,3,3,el);
    return 0;
}
