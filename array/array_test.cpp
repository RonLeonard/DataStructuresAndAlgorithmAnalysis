#include <iostream>
#include "my_array.h"


int main(int argc, int argv)
{
    CMyArray* pCMyArray = new CMyArray();

    pCMyArray->insertElem(1, 0);
    pCMyArray->insertElem(2, 1);
    pCMyArray->insertElem(3, 2);
    pCMyArray->insertElem(4, 3);
    std::cout << " the array is:" << std::endl;
    pCMyArray->printElem();
    
    pCMyArray->deleteElemOfSpecifiedIdx(3);
    std::cout << " the array is:" << std::endl;
    pCMyArray->printElem();

    pCMyArray->deleteElemOfSpecifiedIdx(0);
    std::cout << " the array is:" << std::endl;
    pCMyArray->printElem();
    delete pCMyArray;
    system("pause");
    return 0;
}

