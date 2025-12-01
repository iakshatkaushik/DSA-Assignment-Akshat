#include <iostream>
using namespace std;

class MergeSort {
public:
    void merge(int a[], int l, int m, int r) {
        int n1=m-l+1, n2=r-m;
        int left[100], right[100];
        for(int i=0;i<n1;i++) left[i]=a[l+i];
        for(int i=0;i<n2;i++) right[i]=a[m+1+i];

        int i=0,j=0,k=l;
        while(i<n1 && j<n2) {
            if(left[i] <= right[j]) a[k++] = left[i++];
            else a[k++] = right[j++];
        }
        while(i<n1) a[k++] = left[i++];
        while(j<n2) a[k++] = right[j++];
    }

    void mergeSort(int a[], int l, int r) {
        if(l >= r) return;
        int m = (l+r)/2;
        mergeSort(a,l,m);
        mergeSort(a,m+1,r);
        merge(a,l,m,r);
    }
};

int main() {
    int a[100], n;
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    MergeSort obj;
    obj.mergeSort(a,0,n-1);
    for(int i=0;i<n;i++) cout << a[i] << " ";
}
