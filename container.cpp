#include "stirner.hpp"

int main()
{
    stirner<int> obj;
    obj.addAtEnd(1);
    obj.addAtEnd(2);
    obj.addAtEnd(3);
    obj.addAtEnd(4);
    obj.addAtEnd(5);
    obj.addAtEnd(6);
    obj.addAtEnd(7);
    obj.addAtEnd(8);
    obj.addAtEnd(9);
    try
    {
        std::cout << "Size At Start = " << obj.getSize() << std::endl;
        std::cout << "Content Of Pos 5 Is: " << obj.getContentOfPosiotion(5) << std::endl;
        std::cout << "Describe The Container: " << std::endl;
        obj.showMyStirner();
        std::cout << "Remove Index Number 4." << std::endl;
        obj.removePosition(4);
        std::cout << "Size After Remove Index 4 = " << obj.getSize() << std::endl;
        std::cout << "Describe The Container Again: " << std::endl;
        obj.showMyStirner();
        std::cout << "Add 0 At Begin." << std::endl;
        obj.addAtBegin(0);
        std::cout << "Size After Add 0 At Begin = " << obj.getSize() << std::endl;
        std::cout << "Describe The Container Again: " << std::endl;
        obj.showMyStirner();
        std::cout << "Remove Elements From 0 To 3: " << std::endl;
        obj.removeRange(0, 3);
        std::cout << "Size After Delete The Range = " << obj.getSize() << std::endl;
        std::cout << "Describe The Container Again: " << std::endl;
        obj.showMyStirner();
        std::cout << "Value Of Index 1 Is: " << obj[1] << std::endl;
        obj[1] = 10;
        std::cout << "Describe The Container Again: " << std::endl;
        obj.showMyStirner();
    }
    catch (const char *err)
    {
        std::cout << err << std::endl;
    }
}