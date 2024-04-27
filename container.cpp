#include "stirner.hpp"

int main()
{
    stirner<int> test1;
    stirner<std::string> test2;
    test1.addAtEnd(1);
    test1.addAtEnd(2);
    test1.addAtEnd(3);
    test1.addAtEnd(4);
    test1.addAtEnd(5);
    test1.addAtEnd(6);
    test1.addAtEnd(7);
    test1.addAtEnd(8);
    test1.addAtEnd(9);
    test2.addAtBegin("Hello");
    test2.addAtBegin("- ");
    test2.addAtEnd(" World!");
    try
    {
        std::cout << "Test With Integers: " << std::endl;
        std::cout << "Size At Start = " << test1.getSize() << std::endl;
        std::cout << "Content Of Pos 5 Is: " << test1.getContentOfPosiotion(5) << std::endl;
        std::cout << "Describe The Container: " << std::endl;
        test1.showMyStirner();
        std::cout << "Remove Index Number 4." << std::endl;
        test1.removePosition(4);
        std::cout << "Size After Remove Index 4 = " << test1.getSize() << std::endl;
        std::cout << "Describe The Container Again: " << std::endl;
        test1.showMyStirner();
        std::cout << "Add 0 At Begin." << std::endl;
        test1.addAtBegin(0);
        std::cout << "Size After Add 0 At Begin = " << test1.getSize() << std::endl;
        std::cout << "Describe The Container Again: " << std::endl;
        test1.showMyStirner();
        std::cout << "Remove Elements From 0 To 3: " << std::endl;
        test1.removeRange(0, 3);
        std::cout << "Size After Delete The Range = " << test1.getSize() << std::endl;
        std::cout << "Describe The Container Again: " << std::endl;
        test1.showMyStirner();
        std::cout << "Value Of Index 1 Is: " << test1[1] << std::endl;
        test1[1] = 10;
        std::cout << "Describe The Container Again: " << std::endl;
        test1.showMyStirner();
        std::cout << "Index Of Number 9 Is: " << test1.search(9) << std::endl;
        std::cout << "---------------------------------------------" << std::endl;
        std::cout << "Test With Strings: " << std::endl;
        std::cout << "Size At Start = " << test2.getSize() << std::endl;
        std::cout << "Content Of Pos 1 Is: " << test2.getContentOfPosiotion(1) << std::endl;
        std::cout << "Describe The Container: " << std::endl;
        test2.showMyStirner();
        std::cout << "Remove Index Number 0." << std::endl;
        test2.removePosition(0);
        std::cout << "Size After Remove Index 0 = " << test2.getSize() << std::endl;
        std::cout << "Describe The Container Again: " << std::endl;
        test2.showMyStirner();
        std::cout << "Add `*` At Begin." << std::endl;
        test2.addAtBegin("* ");
        std::cout << "Size After Add `*` At Begin = " << test2.getSize() << std::endl;
        std::cout << "Describe The Container Again: " << std::endl;
        test2.showMyStirner();
        std::cout << "Remove Elements From 0 To 2: " << std::endl;
        test2.removeRange(0, 2);
        std::cout << "Size After Delete The Range = " << test2.getSize() << std::endl;
        std::cout << "Describe The Container Again: " << std::endl;
        test2.showMyStirner();
        std::cout << "Value Of Index 0 Is: " << test2[0] << std::endl;
        test2[0] = "Good Man";
        std::cout << "Describe The Container Again: " << std::endl;
        test2.showMyStirner();
        std::cout << "Index Of The Value `Hi` Is: " << test2.search("Hi") << std::endl;

    }
    catch (const char *err)
    {
        std::cout << err << std::endl;
    }
}