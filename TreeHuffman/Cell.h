#ifndef CELLL_H
#define CELLL_H
#include<QString>

class cell
{    int size;
     char element;
     char huffmanRepresentation[15];

public:
    bool leaf;
    cell* left;
    cell* right;
    cell();
    cell(int size, cell* left, cell* right);                 //constructor das nó que não e folha
    cell(char element, int size);   //constructor das folhas
    bool isMore(cell cell);
    int getSize();
    char getElement();
    void setHuffmanRepresentation(int huffman);
    QString getHuffmanRepresentation();

};

#endif // CELLL_H
