#include <iostream>
#include "array.h"

int main()
{
    Array arr;
    arr.setValue(6);
    arr.setValue(60);
    arr.setValue(40);
    arr.expandArray(1);
    arr.setValue(50);
    //arr.showElements();
    int arr2[3] = { 2, 3, 64 };
    arr.setArray(arr2, 3);
    arr.showElements();
    std::cout << arr.getElemSize() << " " << arr.getSize() << " " << std::endl;
    arr.showElements();
    return 0;
}
