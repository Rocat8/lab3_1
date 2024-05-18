#ifndef ARRAY_H_INCLUDED
#define ARRAY_H_INCLUDED

class Array
{
private:
    int initialSize_;
    int stepSize_;
    int* arrPtr_;
    int currentIndex_;

public:
    Array(int initialSize = 1, int stepSize = 1);
    ~Array();
    void showElements();
    void expandArray(int);
    int getSize();
    int getElemSize();
    void setValue(int);
    void setArray(int*, int);
};

#endif
