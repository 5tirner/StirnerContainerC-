#include <cstdlib>
#include <iostream>

template <typename _data>
class stirner
{
    private:
        typedef struct containerZ
        {
            _data val;
            struct containerZ *next;
        } cntz;

        void addBack(cntz **self, _data val)
        {
            cntz *copy = new cntz();
            if (!copy)
                throw "Bad Memory";
            copy->val = val;
            copy->next = NULL;
            if (!(*self))
                *self = copy;
            else
            {
                cntz *save = *self;
                while ((*self)->next)
                    *self = (*self)->next;
                (*self)->next = copy;
                *self = save;
            }
        }

        void    addFront(cntz **self, _data val)
        {
            cntz *copy = new cntz();
            if (!copy)
                throw "Bad Memory";
            copy->val = val;
            copy->next = NULL;
            if (!(*self))
                *self = copy;
            else
            {
                copy->next = *self;
                *self = copy;
            }
        }

        void    deleteOne(cntz **self, int indexToRemove)
        {
            cntz *backUp = NULL;
            int i = 0;
            while (*self)
            {
                cntz *save = *self;
                if (i != indexToRemove)
                    addBack(&backUp, (*self)->val);
                *self = (*self)->next, i++;
                delete save;
            }
            *self = backUp;
        }

        _data   getData(cntz *self, int pos)
        {
            int i = 0;
            while (self)
            {
                if (pos == i)
                    return (self->val);
                self = self->next;
                i++;
            }
            return (self->val);
        }

        void    printAll(cntz *self)
        {
            int i = 0;
            std::cout << "[ ";
            while (self)
            {
                if (i != 0)
                    std::cout << ", ";
                std::cout << self->val;
                self = self->next;
                i++;
            }
            std::cout << " ]" << std::endl;
        }
        cntz    *linkedList;
        int     size;

    public:

        stirner()
        {
            this->size = 0;
            this->linkedList= NULL;
        }
        ~stirner(){}
        void    addAtEnd(_data val)
        {
            try
            {
                this->addBack(&this->linkedList, val);
                this->size++;
            }
            catch(...)
            {
                std::cerr << "Memory Allocation Failed." << std::endl;
            }
        }

        void    addAtBegin(_data val)
        {
            try
            {
                this->addFront(&this->linkedList, val);
                this->size++;
            }
            catch(...)
            {
                std::cerr << "Memory Allocation Failed." << std::endl;
            }
        }

        void    removePosition(int Index)
        {
            if (!this->linkedList || Index < 0 || Index >= this->size)
                throw "Failed To Remove It.";
            this->deleteOne(&this->linkedList, Index);
        }

        _data   getContentOfPosiotion(int Pos)
        {
            if (Pos < 0 || Pos >= this->size || !this->linkedList)
                throw "Failed To Get Content.";
            return (this->getData(this->linkedList, Pos));
        }

        void    showMyStirner()
        {
            this->printAll(this->linkedList);
        }

        int getSize() {return (this->size);}
};

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
        std::cout << "Size: " << obj.getSize() << std::endl;
        std::cout << "Content Of Pos 5 Is: " << obj.getContentOfPosiotion(5) << std::endl;
        std::cout << "Describe The Container: " << std::endl;
        obj.showMyStirner();
        std::cout << "Remove Index Number 4: " << std::endl;
        obj.removePosition(4);
        std::cout << "Describe The Container Again: " << std::endl;
        obj.showMyStirner();
        obj.addAtBegin(0);
        std::cout << "Size: " << obj.getSize() << std::endl;
        obj.showMyStirner();
    }
    catch (const char *err)
    {
        std::cout << err << std::endl;
    }
}