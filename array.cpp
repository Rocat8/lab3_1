#include "array.h"
#include <iostream>

Array::Array(int initialSize, int stepSize)
{
    initialSize_ = initialSize > 1 ? initialSize : 1;
    stepSize_ = stepSize > 1 ? stepSize : 1;
    arrPtr_ = new int[initialSize];
    currentIndex_ = 0;
}

Array::~Array()
{
    delete[] arrPtr_;
}

void Array::showElements()
{
    for (int i = 0; i < currentIndex_; i++)
        //        if (i != currentIndex_)
        std::cout << arrPtr_[i] << " ";
    //        else
    //            std::cout << arrPtr_[i];
    std::cout << std::endl;
}

void Array::expandArray(int size)
{
    int newSize = initialSize_ + size;
    int* temp = new int[newSize];
    for (int i = 0; i < initialSize_; i++)
        temp[i] = arrPtr_[i];
    delete[] arrPtr_;
    arrPtr_ = temp;
    initialSize_ = newSize;
}

int Array::getSize()
{
    return initialSize_;
}

int Array::getElemSize()
{
    return currentIndex_;
}

void Array::setValue(int val)
{
    if (currentIndex_ >= initialSize_)
        expandArray(stepSize_);
    arrPtr_[currentIndex_] = val;
    currentIndex_++;
}

void Array::setArray(int* pArr, int size)
{
    if (size + currentIndex_ > initialSize_)
        expandArray(size);
    //for (int i = 0; i <= currentIndex_; i++)
//    {
//        std::cout << "i = " << i << std::endl << "initialSize_ - i = " << initialSize_ - i << std::endl << "currentIndex_ - i = " << currentIndex_ - i << std::endl;
        //arrPtr_[initialSize_ - 1 - i] = arrPtr_[currentIndex_ - 1 - i];
//    }
    for (int i = currentIndex_; i < initialSize_; i++)
        arrPtr_[i] = pArr[i - currentIndex_];
    currentIndex_ += size;
}