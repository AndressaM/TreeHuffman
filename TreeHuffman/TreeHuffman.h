#ifndef ARVOREHUFFMAN_H
#define ARVOREHUFFMAN_H
#include <vector>
#include "Cell.h"
#include<QDebug>
#include<QString>
#include<stdio.h>
#include <iostream>
using namespace std;

class TreeHuffman
{
    vector<cell> treeHuffman;
    cell ref;
    int size;
    QString Huffmanrepresentation;
public:
    TreeHuffman();
    cell treeHuffmanAT(int pos);
    void setTreeHuffman(int pos, cell nil);
    int getSize();
    void insertion(cell newCell);
    void bubbleHuffman();
    void swap(cell &prev, cell &next);
    void buildHuffman();
    QString print();
    QString treeRepresetation(cell* node,QString R = "(", bool left=true);
    void printTree(cell* node , int level = 1);


};

#endif // ARVOREHUFFMAN_H
