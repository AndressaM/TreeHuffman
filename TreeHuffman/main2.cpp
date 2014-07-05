#include "File.cpp"
#include<QDebug>
#include<QString>
#include"Cell.h"
#include "TreeHuffman.h"
#include<stdio.h>
#include <iostream>
#include <unistd.h>
#include<BitVector.h>

using namespace std;

int main()
{
    char file[100] = "/home/pedro/ArvoreHuffman/pedro";
    TreeHuffman treeHuffman = TreeHuffman();
    File* fileObjectInput =new File(file);
    std::ofstream fileObjectOutput;
    double oldPercentage=0;
    for(int i=0; i<256; i++)
    {
        cell new_cell=cell(fileObjectInput->bitToChar(i),fileObjectInput->bitFrequency(i));
        treeHuffman.insertion(new_cell);
    }
    treeHuffman.buildHuffman();
    cell rootTreeHuffman=treeHuffman.treeHuffmanAT(1);
    QString tree=treeHuffman.treeRepresetation(&rootTreeHuffman).remove(',').remove(0,1);
    tree.remove(tree.size()-1,1);
    fileObjectInput->buildCodification(&rootTreeHuffman);
    BitVector bitVector=BitVector();
    bitVector.setbit(QString().setNum(fileObjectInput->trashCalculation(),2),3);
    bitVector.setbit(QString().setNum(tree.size(),2),13);
    fileObjectInput->setFileName(QString("pedro.txt"));
    bitVector.setbit(QString().setNum(fileObjectInput->getFileName().size(),2),8);

    fileObjectOutput.open("/home/pedro/ArvoreHuffman/pedro.huff",std::ios::binary);
    for(int i=0; i<bitVector.getQbitarray().size()-1;i++)
    {
        fileObjectOutput<<bitVector.getQbitarray().at(i).toLatin1();
    }

    fileObjectOutput<<fileObjectInput->getFileName().toStdString();
    fileObjectOutput<<tree.toStdString();
    bitVector.clearBitVector();
    fileObjectInput->clearPosition();
    int sizeTemp;
    while(!fileObjectInput->isEnd())
    {
        QString bucked = fileObjectInput->getfile();
        sizeTemp+=bucked.size();
        for(int i=0;i<bucked.size();i++)
        {
            bitVector.setbit(fileObjectInput->huffmanRepresentation(fileObjectInput->charToBit(bucked.at(i).toLatin1())));
           }
        for(int y=0; y<bitVector.getQbitarray(false).size();y++)
        {
                fileObjectOutput<<bitVector.getQbitarray(false).at(y).toLatin1();
        }
        bitVector.resize();
        if(int(double(sizeTemp)/fileObjectInput->fileSize()*100)>int(oldPercentage))
        qDebug()<<int(oldPercentage)<<"%";
        oldPercentage=double(sizeTemp)/fileObjectInput->fileSize()*100;
    }
    if(fileObjectInput->trashCalculation()!=0)
    {
        fileObjectOutput<<bitVector.getQbitarray().at(0).toLatin1();
    }
    qDebug()<<"100 %";
}

