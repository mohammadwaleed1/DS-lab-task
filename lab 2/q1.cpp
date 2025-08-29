#include <iostream>
using namespace std;
//resize function made globally
int **resize(int **array, int nrows,int oldrows,int newcol,int oldcol)
    {
        if (nrows == oldrows && newcol==oldcol)
        {
            return array;
        }
            
        // allocate new matrix
        int**newarr=new int*[nrows];
        for(int i=0;i<nrows;i++){
            newarr[i]=new int[newcol];
        }
    // copy overlapping data
    int rowLimit = (oldrows < nrows) ? oldrows : nrows;
    int colLimit = (oldcol < newcol) ? oldcol : newcol; 
    for (int i = 0; i < rowLimit; i++) {
        for (int j = 0; j < colLimit; j++) {
            newarr[i][j] = array[i][j];
        }
    }
    for(int i=0;i<oldrows;i++){
        delete[]array[i];
    }
    delete[]array;
    return newarr;
}
//display
void printmatrix(int**array,int r,int c){ 
for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){
        cout<<array[i][j]<<" ";
    }
    cout<<endl;
}
}
void Transpose(int **arr, int r, int c) {
    for (int j = 0; j < c; j++) {
        for (int i = 0; i < r; i++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    int r, c, newr,newc;
    cin >> r >> c;
    int **arr = new int *[r];
    for (int i = 0; i < r; i++)
    {
        arr[i] = new int[c];
    };
    cout<<"enter elements:\n";
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>arr[i][j];
        }
    }
    cout<<"original matrix:\n";
    printmatrix(arr, r,c);
cout<<"enter new size i.e rows and cols"<<endl;
cin>> newr >> newc;
arr= resize(arr,newr,r,newc,c);
if (newr>r || newc>c){
    for(int i = 0; i < newr; i++){
    for(int j = 0; j < newc; j++){
        if (i >= r || j >= c) {  
            arr[i][j] = 2;
        }
    }
}
}
for(int i=0;i<newr;i++){
    for(int j=0;j<newc;j++){
        if((i+j)%2==0)
        arr[i][j]+=2;
    }
}
cout<<"matrix after addind 2:\n";
printmatrix(arr,newr,newc);
Transpose(arr,newr,newc);
for (int i = 0; i < newr; i++) {
    delete[] arr[i];
}
delete[] arr;
};