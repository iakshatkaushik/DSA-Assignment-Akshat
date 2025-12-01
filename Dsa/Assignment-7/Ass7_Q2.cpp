#include <iostream>
using namespace std;

class ImprovedSelection {
public:
    void sort(int a[], int n) {
        int left = 0, right = n - 1;

        while (left < right) {
            int mini = left, maxi = right;

            if (a[mini] > a[maxi]) {
                int t=a[mini]; a[mini]=a[maxi]; a[maxi]=t;
            }

            for (int i = left + 1; i < right; i++) {
                if (a[i] < a[mini]) mini = i;
                if (a[i] > a[maxi]) maxi = i;
            }

            int t=a[left]; a[left]=a[mini]; a[mini]=t;

            if (maxi == left) maxi = mini;

            t=a[right]; a[right]=a[maxi]; a[maxi]=t;

            left++;
            right--;
        }
    }
};

int main() {
    int a[100], n;
    cin >> n;
    for (int i=0;i<n;i++) cin >> a[i];
    ImprovedSelection obj;
    obj.sort(a,n);
    for (int i=0;i<n;i++) cout << a[i] << " ";
}
