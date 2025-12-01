#include <iostream>
using namespace std;

class BubbleSort {
public:
    void sort(int a[], int n) {
        for(int i=0;i<n;i++){
            for(int j=0;j<n-i-1;j++){
                if(a[j] > a[j+1]){
                    int t=a[j]; a[j]=a[j+1]; a[j+1]=t;
                }
            }
        }
    }
};

int main() {
    int a[100], n;
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    BubbleSort obj;
    obj.sort(a,n);
    for(int i=0;i<n;i++) cout << a[i] << " ";
}
