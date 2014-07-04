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
void TreeHuffman::inserction(cell cellNew)
{
    if(cellNew.getSize()!=0 && (int)cellNew.getElement()!=10)
    {
        size++;
        treeHuffman[size] = cellNew;
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
    this->inserction(ref);
}
void TreeHuffman::buildHuffman()
{
    while(size>1)
    {
        this->bubbleHuffman();
    }
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
QString TreeHuffman:: treeRepresetation(cell* node,QString R , bool left)
{
    QString returnRepresentation;
    if(node->leaf != true)
    {
        returnRepresentation.append(QString("("));
        //retorno.append(QString().setNum(node->getSize()));
        returnRepresentation.append(QString(","));
        returnRepresentation.append(treeRepresetation(node->left,returnRepresentation));
        returnRepresentation.append(QString(","));
        returnRepresentation.append(treeRepresetation(node->right,returnRepresentation,false));
        if(left==false)
            returnRepresentation.append(QString(")"));
    }

    else
    {
        returnRepresentation.append(QString(node->getElement()));
        if(left==false)
            returnRepresentation.append(QString(")"));
    }
    return returnRepresentation;

}

