#include <iostream>
#include <string>
using namespace std;
  
template <typename T>
// A function to implement bubble sort
void bubbleSort(T a[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = n - 1; i < j; j--)
            if (a[j] < a[j - 1])
  
        // calls template function
        swap(a[j], a[j - 1]);
}
  
template <typename X>
  
// A Function to perform swapping
void swap(X &a, X &b) {
    X temp = a;
    a = b;
    b = temp;
}

template <typename Y>

Y divide(Y a, Y b){
    Y result = a/b;
    return result;
}

// Driver Code
int main() {
    int a[5] = {10, 50, 30, 40, 20};
    int n = sizeof(a) / sizeof(a[0]);
   
    char st[5] = {'z', 'e', 'b', 'a' ,'d'};
    int n_c = sizeof(st) / sizeof(st[0]);
    // calls template function 
    bubbleSort<int>(a, 5);
    bubbleSort<char>(st, 5);
  
    cout << " Sorted array : ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
    for (int i =0 ; i < n_c; i++)
         cout << st[i] << " ";

    cout << endl << "integer:- " <<divide<int>(5.0,2.0) << endl;
    cout << "double:- " << divide<double>(5,2) << endl;
  return 0;
}
