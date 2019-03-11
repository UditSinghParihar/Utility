#include<iostream>

int main() {
    using namespace std;
    unsigned int size;
    cout<<"Enter size of the array : ";
    cin>>size;
    int array[size]; // Dynamically Allocating Memory
    cout<<"\nEnter the elements of the array\n";
    // Reading Elements
    for (int i = 0; i < size; i++) {
        cout<<" :";
        cin>>array[i];
    }
    // Displaying Elements
    cout<<"\nThere are total "<<size<<" elements, as listed below.";
    for (int j = 0; j < size; j++) {
        cout<<endl<<array[j]<<endl;
    }
    return 0;
}