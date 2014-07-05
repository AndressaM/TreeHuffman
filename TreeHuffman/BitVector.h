#ifndef BITVECTOR_H
#define BITVECTOR_H
#include <QBitArray>
#include<QString>

class BitVector
{
    QBitArray biTvector;
    int size;
public:
    BitVector();
    void setbit(int pos, int value);
    void setbit(QString value, int sizemax=0, int pos=-1);
    int bitVectorAt(int pos);
    QString getQbitarray(bool WithTrash=true);
    void clearBitVector();
    int getSize();
    void resize();

};

#endif // BITVECTOR_H
