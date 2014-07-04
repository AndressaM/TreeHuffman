#include "BitVector.h"
#include<QDebug>
BitVector::BitVector()
{
    this->biTvector.resize(2000);
    size=0;
}
void BitVector::setbit(int pos, int value)
{
    bool boolReturn;
    if(value == 0)
    {
        boolReturn = false;
    }
    else
    {
        boolReturn = true;
    }

    biTvector.setBit(pos,boolReturn);
    if(pos>size)
    {
        size=pos;
    }
}
void BitVector::setbit(QString value, int sizemax, int pos )
{
    if(sizemax==0)
    {
        sizemax=value.size();
    }
    if(pos == -1)
    {
        pos = size;
    }
    int i=sizemax-value.size();
    int j;
    for(j = 0; j < value.size();j++)
    {
        if(value.at(j)=='0')
        {
            biTvector[pos+i+j] = false;
        }
        if(value.at(j)=='1')
        {
            biTvector[pos+i+j] = true;
        }
    }
    size=pos+i+j;
}

int BitVector::bitvectorAt(int pos)
{
    int boolReturn;
    if(biTvector.at(pos))
    {
        boolReturn = 1;
    }
    else
    {
        boolReturn = 0;
    }
    return boolReturn;
}
QString BitVector::getQbitarray(bool WithTrash)
{
    unsigned int bit;
    QString returnBit=QString();
    int i= 0;
    while(size-i>=8)
    {
        bit = 0x0000;
        for(int j= 0; j<8;j++ )
        {
            if (biTvector[i+j])
            {
                bit = (bit<<1)|1;

            }
            else
            {
                bit = bit<<1;
            }

        }
        i=i+8;
        //qDebug()<<"bit numero "<<i<<" :"<<QString().setNum(bit,2);
        returnBit.append(bit);

    }
    if(WithTrash)
    {


    bit= 0;
    for(int j= 0; j<size-i;j++ )
    {
        if (biTvector[i+j])
        {
            bit = (bit<<1)|1;

        }
        else
        {
            bit = bit<<1;
        }

    }
    bit = bit<<(8-(size-i));

    returnBit.append(bit);
    //qDebug()<<QString().setNum(bit,10);
    //retornobit.remove(retornobit.size()-1,1);
    }
    return returnBit;



}

void BitVector::clearbitvector()
{
    biTvector.clear();
    this->biTvector.resize(2000);
    size=0;
}

int BitVector::getSize()
{
    return this->size;
}

