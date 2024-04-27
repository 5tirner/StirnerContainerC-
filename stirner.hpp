#ifndef STIRNER_HPP
# define STIRNER_HPP

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

        _data   &getData(cntz *self, int pos)
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

        void    deleteRange(cntz **self, int from, int until)
        {
            cntz *copy = NULL;
            int i = 0;
            while ((*self))
            {
                cntz *save = *self;
                if (i < from || i >= until)
                    addBack(&copy, (*self)->val);
                i++;
                (*self) = (*self)->next;
                delete save;
            }
            *self = copy;
        }

        int     findElement(cntz *self, _data val)
        {
            int i = 0;
            while (self)
            {
                if (self->val == val)
                    return (i);
                i++;
                self = self->next;
            }
            return (-1);
        }

        void    addAt(cntz **self, int pos, _data newVal)
        {
            int i = 0;
            cntz *copy = NULL;
            while (*self)
            {
                cntz *save = *self;
                if (i == pos)
                    addBack(&copy, newVal);
                addBack(&copy, (*self)->val);
                (*self) = (*self)->next;
                i++;
                delete save;
            }
            *self = copy;
        }

        cntz    *linkedList;
        int     size;

    public:

        stirner()
        {
            this->size = 0;
            this->linkedList= NULL;
        }
        ~stirner()
        {
            while (this->linkedList)
            {
                cntz *save = this->linkedList;
                this->linkedList = this->linkedList->next;
                delete(save);
            }
        }
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
            this->size--;
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

        void    removeRange(int From, int Until)
        {
            if (From > Until || From < 0 || Until > this->size || !this->linkedList)
                throw "Failed To Remove A Range.";
            deleteRange(&this->linkedList, From, Until);
            this->size -= Until - From;
        }

        _data&operator[](int index)
        {
            if (index < 0 || index >= this->size || !this->linkedList)
                throw "Failed To Access To An Index.";
            return (getData(this->linkedList, index));
        }
        int getSize() {return (this->size);}

        int    search(_data needle)
        {
            if (!this->linkedList)
                throw "Failed Search For Element.";
            int save = this->findElement(this->linkedList, needle);
            if (save == -1)
                throw "Failed Search For Element.";
            return (save);  
        }

        void    insertInPosition(int pos, _data val)
        {
            if (pos < 0 || pos > this->size || !this->linkedList)
                throw "Failed To Add Element In Specified Position";
            if (pos == this->size)
                this->addBack(&this->linkedList, val);
            else
                this->addAt(&this->linkedList, pos, val);
            this->size++;
        }

        void    cleanStirner()
        {
            while (this->linkedList)
            {
                cntz *save = this->linkedList;
                this->linkedList = this->linkedList->next;
                delete save;
            }
            this->linkedList = NULL;
        }
};

#endif