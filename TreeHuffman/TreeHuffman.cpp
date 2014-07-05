#include "TreeHuffman.h"

TreeHuffman::TreeHuffman()
{
    treeHuffman.reserve(258);
    size = 0;
}


cell TreeHuffman::treeHuffmanAT(int pos)
{
    return treeHuffman[pos];
}
void TreeHuffman::setTreeHuffman(int pos, cell nil)
{
    treeHuffman[pos] = nil;
}
int TreeHuffman::getSize()
{
  return size;
}
void TreeHuffman::insertion(cell newCell)
{
    if(newCell.getSize()!=0 && (int)newCell.getElement()!=10)
    {
        size++;
        treeHuffman[size] = newCell;
    }
}
void TreeHuffman::swap(cell &prev, cell &next)
{
    cell aux= prev;
    prev=next;
    next=aux;
}
void TreeHuffman::bubbleHuffman()
{
    for(int i = 1;i<=size;i++)
    {
        for(int j = 1; j<size;j++)
        {
            if(treeHuffman[j+1].isMore(treeHuffman[j]))
            {
                swap(treeHuffman[j],treeHuffman[j+1]);
            }
        }
    }
    cell* left =new cell();
    *left=treeHuffman[size];
    cell* right= new cell();
    *right=treeHuffman[size-1];
    size = size-2;
    ref= cell(left->getSize()+right->getSize(),left,right);
    this->insertion(ref);
}
void TreeHuffman::buildHuffman()
{
    while(size>1)
    {
        this->bubbleHuffman();
    }
}

QString TreeHuffman::print()
{
    return Huffmanrepresentation;
}
QString TreeHuffman::treeRepresetation(cell* node,QString R , bool left)
{
    QString returnRepresetation;
    if(node->leaf != true)
    {
        returnRepresetation.append(QString("("));
        //retorno.append(QString().setNum(node->getSize()));
        //retorno.append(QString(","));
        returnRepresetation.append(treeRepresetation(node->left,returnRepresetation));
        //retorno.append(QString(","));
        returnRepresetation.append(treeRepresetation(node->right,returnRepresetation,false));
        if(left==false)
            returnRepresetation.append(QString(")"));
    }

    else
    {
        if(node->getElement()=='(' || node->getElement()== '-' || node->getElement() == ')')

            returnRepresetation.append(QString("-"));
            returnRepresetation.append(QString(node->getElement()));
        if(left==false)
            returnRepresetation.append(QString(")"));
    }
    return returnRepresetation;
}

void TreeHuffman::printTree(cell* node , int level )
{
    if(node->leaf != true)
    {
        printTree(node->left, level +1);
        cout << qPrintable(QString("\t").repeated(level)) << node->getSize() <<endl;
        printTree(node->right,level +1);
    }
    if(node->leaf)
    {
        cout << qPrintable(QString("\t").repeated(level)) << node->getElement() <<endl;
    }

}
