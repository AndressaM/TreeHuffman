#ifndef TREEHUFFMAN_H
#define TREEHUFFMAN_H
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
    QString huffmanRepresentation;
public:
    TreeHuffman();
    cell treeHuffmanAT(int pos);
    void setTreeHuffman(int pos, cell nil);
    int getSize();
    void inserction(cell cellNew);
    void bubbleHuffman();
    void swap(cell &prev, cell &next);
    void buildHuffman();
    void printTree(cell* node, int level = 1);
    QString treeRepresetation(cell* node,QString R = "(", bool left=true);


};

#endif // TREEHUFFMAN_H
