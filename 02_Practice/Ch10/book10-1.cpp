#include <iostream>
using namespace std;

template <class T>
T biggest(T arr[], int size) {
    if(size <= 0)
        return 0;
    
    T max = arr[0];
    for(int i=1 ; i<size ; i++)
        if(max < arr[i])
            max = arr[i];
    return max;
}

int main(){
    int x[] = {1, 10, 100, 5, 4};
    cout << biggest(x, 5) << endl;
}