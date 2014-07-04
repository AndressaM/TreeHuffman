//#include "File.cpp"
//#include<QDebug>
//#include<QString>
//#include"Cell.h"
//#include "Heap.h"
//#include<stdio.h>
//#include <iostream>
//#include <unistd.h>

//using namespace std;
//void printTree(cell* node, int level = 1)
//{
//    if(node->leaf != true)
//    {
//        printTree(node->left, level +1);
//        cout << qPrintable(QString("\t").repeated(level)) << node->getSize() <<endl;
//        printTree(node->right,level +1);
//    }
//    if(node->leaf)
//    {
//        cout << qPrintable(QString("\t").repeated(level)) << node->getElement() <<endl;
//    }
//}
//void Tree(cell* node, int level = 1)
//{
//    if(node->leaf != true)
//    {
//        Tree(node->left, level*10);
//        Tree(node->right,level*10+1);
//    }
//    if(node->leaf)
//    {
//        node->setHuffmanRepresentation(level);

//        //qDebug() << "\n" <<node->getHuffmanRepresentation();
//    }
//}
//QString TreeRepresetation(cell* node,QString R = "(", bool left=true)
//{
//    QString retorno;
//    if(node->leaf != true)
//    {
//        retorno.append(QString("("));
//        retorno.append(QString().setNum(node->getSize()));
//        retorno.append(QString(","));
//        retorno.append(TreeRepresetation(node->left,retorno));
//        retorno.append(QString(","));
//        retorno.append(TreeRepresetation(node->right,retorno,false));
//        if(left==false)
//            retorno.append(QString(")"));
//        qDebug()<< retorno;
//        //usleep(1000000);
//    }

//    else
//    {
//        retorno.append(QString(node->getElement()));
//        if(left==false)
//            retorno.append(QString(")"));
//    }
//    return retorno;


//}




//int main()
//{
//    char file[100] = "/home/alunoic/Área de Trabalho/Pasta sem título/ArvoreHuffman/pedro";
//    Heap heap = Heap();
//    File* arquivo =new File(file);
//    for(int i=0; i<256; i++)
//    {
//        cell new_cell=cell(arquivo->BitToChar(i),arquivo->BitFrequency(i));
//        heap.insert(new_cell);
//    }
//    int size=heap.size();
//    cell* delete1;
//    cell* delete2;
//    for(int i=1; i<size;i++)
//    {
//        delete1=heap.removefirst();
//        delete2=heap.removefirst();
//        cell result=cell(delete1->getSize()+delete2->getSize(),delete1,delete2);
//        heap.insert(result);
//    }
//    Tree(heap.getCellPonteiro(1));
//    //find(heap.getCellPonteiro(1),'u');
//    arquivo->BuildCodification(heap.getCellPonteiro(1));
////    for(int i=0; i<arquivo->FileSize()-1;i++)
////    {
////        qDebug()<<arquivo->HuffmanRepresentation(arquivo->CharToBit(arquivo->file[i]));
////    }
//    printTree(heap.getCellPonteiro(1));
//    qDebug()<< TreeRepresetation(heap.getCellPonteiro(1));

//}
