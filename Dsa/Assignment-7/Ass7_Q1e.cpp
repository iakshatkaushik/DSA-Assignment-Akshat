#include <iostream>
using namespace std;

class QuickSort {
public:
    int partitionIndex(int a[], int low, int high) {
        int pivot = a[high];
        int i = low;
        for(int j=low;j<high;j++){
            if(a[j] < pivot){
                int t=a[i]; a[i]=a[j]; a[j]=t;
                i++;
            }
        }
        int t=a[i]; a[i]=a[high]; a[high]=t;
        return i;
    }

    void quickSort(int a[], int low, int high) {
        if(low < high){
            int p = partitionIndex(a,low,high);
            quickSort(a,low,p-1);
            quickSort(a,p+1,high);
        }
    }
};

int main() {
    int a[100], n;
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    QuickSort obj;
    obj.quickSort(a,0,n-1);
    for(int i=0;i<n;i++) cout << a[i] << " ";
}
