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
    char file[100] = "C:/Users/Andressa/Documents/ArvoreHuffman/pedro";
    TreeHuffman treeHuffman = TreeHuffman();
    BitVector bitVector=BitVector();
    File* fileObjectInput =new File(file);
    std::ofstream fileObjectOutput;
    while(!fileObjectInput->isEnd())
    {
        fileObjectInput->grabBucked();
    }

//    arquivo->ReadFile();
    for(int i=0; i<256; i++)
    {
        cell new_cell=cell(fileObjectInput->bitToChar(i),fileObjectInput->bitFrequency(i));
        treeHuffman.inserction(new_cell);
    }
    treeHuffman.buildHuffman();
    for(int i = 1;i<=treeHuffman.getSize();i++)
    {
        //qDebug()<<vetor.arvoredehuffmanAT(i).getSize();
    }
    cell ref=treeHuffman.treeHuffmanAT(1);
    QString tree=treeHuffman.treeRepresetation(&ref).remove(',').remove(0,1);
    tree.remove(tree.size()-1,1);

    fileObjectInput->buildCodification(&ref);

//    qDebug()<<QString().setNum(tree.remove(tree.size()-1,1).size(),2);
//    qDebug()<<tree;
    treeHuffman.printTree(&ref);
    qDebug()<<QString().setNum(fileObjectInput->trashCalculation(),2);
    bitVector.setbit(QString().setNum(fileObjectInput->trashCalculation(),2),3);
    bitVector.setbit(QString().setNum(tree.size(),2),13);
    fileObjectInput->setFileName(QString("pedro.txt"));
    bitVector.setbit(QString().setNum(fileObjectInput->getFileName().size(),2),8);
    fileObjectOutput.open("/Users/Andressa/Documents/ArvoreHuffman/pedro.huff",std::ios::binary);
    for(int i = 0; i< bitVector.getQbitarray(false).size();i++)
    {
       fileObjectOutput<<bitVector.getQbitarray().at(i).toLatin1();
    }
    fileObjectOutput<<fileObjectInput->getFileName().toStdString();
    fileObjectOutput<<tree.toStdString();
    bitVector.clearbitvector();
    fileObjectInput->clearPosition();



}

