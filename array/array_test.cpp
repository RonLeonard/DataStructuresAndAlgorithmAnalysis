#include <iostream>
#include "my_array.h"


bool merge_arr(CMyArray* pCMyArray1, CMyArray* pCMyArray2,
    CMyArray* pCMyArray_merge)
{
    int len1 = pCMyArray1->getLength();
    int len2 = pCMyArray2->getLength();
    if ((len1 < 1) || (len2 < 1))
        return false;
    int i = 0, j = 0, idx = 0;
    int val1 = 0, val2 = 0;
    while ((i < len1) && (j < len2))
    {
        pCMyArray1->getValOfSpecifiedIdx(i, val1);
        pCMyArray2->getValOfSpecifiedIdx(j, val2);
        if (val1 <= val2)
        {
            pCMyArray_merge->insertElem(val1, idx);
            i++;
            idx++;
        }
        else
        {
            pCMyArray_merge->insertElem(val2, idx);
            j++;
            idx++;
        }
    }
    if (i != len1)
    {
        for (int tmp = i; tmp < len1; tmp++)
        {
            pCMyArray1->getValOfSpecifiedIdx(tmp, val1);
            pCMyArray_merge->insertElem(val1, idx);
            idx++;
        }
    }
    if (j != len2)
    {
        for (int tmp = j; tmp < len2; tmp++)
        {
            pCMyArray2->getValOfSpecifiedIdx(tmp, val2);
            pCMyArray_merge->insertElem(val2, idx);
            idx++;
        }
    }
    return true;
}


int main(int argc, int argv)
{
    CMyArray* pCMyArray1 = new CMyArray();
    CMyArray* pCMyArray2 = new CMyArray();
    CMyArray* pCMyArray_merge = new CMyArray(10);
    pCMyArray1->insertElem(1, 0);
    pCMyArray1->insertElem(4, 1);
    pCMyArray1->insertElem(6, 2);
    pCMyArray1->insertElem(7, 3);
    pCMyArray1->insertElem(8, 4);
    pCMyArray1->insertElem(10, 5);
    std::cout << " the array is:" << std::endl;
    pCMyArray1->printElem();
    
    pCMyArray1->deleteElemOfSpecifiedIdx(4);
    std::cout << " the array is:" << std::endl;
    pCMyArray1->printElem();

    pCMyArray1->deleteElemOfSpecifiedIdx(0);
    std::cout << " the array is:" << std::endl;
    pCMyArray1->printElem();


    pCMyArray2->insertElem(2, 0);
    pCMyArray2->insertElem(3, 1);
    pCMyArray2->insertElem(5, 2);
    pCMyArray2->insertElem(7, 3);
    pCMyArray2->insertElem(9, 4);
    pCMyArray2->insertElem(11, 5);
    std::cout << " the array is:" << std::endl;
    pCMyArray2->printElem();



    merge_arr(pCMyArray1, pCMyArray2, pCMyArray_merge);

    std::cout << " the array is:" << std::endl;
    pCMyArray_merge->printElem();
    delete pCMyArray1;
    delete pCMyArray2;
    delete pCMyArray_merge;
    return 0;
}

