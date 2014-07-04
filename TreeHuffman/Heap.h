#include"Cell.h"
#include<QDebug>
#include <vector>

using namespace std;
class Heap
{
    int maxsize; // Maximum size of the content
    int n; // Number of elements now in the heap
    vector<cell> content;
    void heapfy(int pos)
    {
        int heap;
        bool keep=false;
        if(content[pos].IsMore(content[this->left(pos)]) || content[pos].IsMore(content[this->right(pos)]))
        {

            if(this->right(pos)<=n)
            {
                if(content[this->right(pos)].IsMore(content[this->left(pos)]) && this->left(pos)<=n)
                {
                    swap(content[pos],content[this->left(pos)]);
                    heap=this->left(pos);
                    heapfy(heap);
                    keep=true;
                }
            }
            if(this->left(pos)==n && this->right(pos)>n && content[pos].IsMore(content[this->left(pos)]))
            {
                swap(content[pos],content[this->left(pos)]);
                heap=this->left(pos);
                heapfy(this->parent(heap));
                keep=true;
            }
            if(content[this->left(pos)].IsMore(content[this->right(pos)])&& this->right(pos)<=n && keep==false)
            {
                swap(content[pos], content[this->right(pos)]);
                heap=this->right(pos);
                heapfy(heap);
            }
        }
    }

public:
    void heapfy2(int pos)
    {
        heapfy(pos);
    }
    cell getCell(int pos)
    {
        return content[pos];
    }
    cell* getCellPonteiro(int pos)
    {
        return &content[pos];
    }

    Heap()
    {
        content.reserve(258);
        n=0;
    }

    void swap(cell &prev, cell &next)
    {
        cell aux= prev;
        prev=next;
        next=aux;
    }

    int size() const
    {
        return n;
    }
    bool isLeaf(int pos) const
    {
        if(pos*2>n || pos*2+1>n)
        {
            return true;
        }
        return false;
    }
    int left(int pos) const
    {
        return pos*2;
    }
    int right(int pos) const
    {
        return pos*2+1;
    }
    int parent(int pos) const
    {
        return pos/2;
    }
    void buildMinHeap()
    {
        for(int i=this->parent(n);i > 0; i--)
        {
            heapfy(i);
        }
    }

    virtual void insert(cell& it)
    {
        if(it.getSize()!=0 && (int)it.getElement()!=10)
        {
            n++;
            content[n]=it;
            this->buildMinHeap();
        }
    }

    cell* removefirst()
    {
        swap(content[1],content[n]);
        //content[n]=0;
        cell* Delete= new cell();
        *Delete=content[n];
        n--;
        heapfy(1);
        return Delete;
    }


};
