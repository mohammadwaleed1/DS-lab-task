#include <iostream>
using namespace std;
void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
void print(int arr[],int n){
        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
void insertionsort(int arr[],int n)
    {
        for (int i = 0; i < n; i++)
        {
            int curr = arr[i];
            int pre = i - 1;
            while (pre >= 0 && arr[pre] > curr)
            {
                swap(arr, pre, pre + 1);
                pre--;
            }
            arr[pre + 1] = curr;
        }
    }
    int search(int arr[],int key ,int n){  // binary search
        int st=0;
        int end=n-1;
        while(st<=end){
            int mid=(st+end)/2;
            if(arr[mid]==key)
                return mid;
            else if(arr[mid]<key)
                st=mid+1;
            else 
                end=mid-1;
        }
        return -1;
        }

int main()
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout<< "Original array: ";
    print(arr, n);
    insertionsort(arr, n);

    cout << "Sorted array: ";
    print(arr, n);

    int key;
    cout << "Enter element to search: ";
    cin >> key;

    int idx = search(arr, key, n);
    if (idx != -1)
        cout << "Element found at index " << idx << endl;
    else
        cout << "Element not found" << endl;

};