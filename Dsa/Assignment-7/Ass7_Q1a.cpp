#include <iostream>
using namespace std;

class SelectionSort {
public:
    void sort(int a[], int n) {
        for(int i=0;i<n-1;i++){
            int mini=i;
            for(int j=i+1;j<n;j++){
                if(a[j] < a[mini]) mini=j;
            }
            int t=a[i]; a[i]=a[mini]; a[mini]=t;
        }
    }
};

int main() {
    int a[100], n;
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    SelectionSort s;
    s.sort(a,n);
    for(int i=0;i<n;i++) cout << a[i] << " ";
}
