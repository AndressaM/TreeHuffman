#include"File.h"
#include<string>
#include<QDebug>

#define MAX_SIZE_BUCKED 5;
File::File(char FileName[])
{
    for(int i=0; i<255; i++)
    {
        frequency[i]=0;
    }
    inputFile.open(FileName,std::ios::binary);
    if(inputFile.is_open())
    {
        inputFile.seekg(0,inputFile.end);
        size=inputFile.tellg();
        inputFile.seekg(0, inputFile.beg);
    }
    this->position=0;
    while(!this->isEnd())
    {
        this->grabBucked();
    }
}
void File::grabBucked()
{
    int read;
    inputFile.seekg(this->position);
    if(size-position>5)
    {
        this->position+=MAX_SIZE_BUCKED;
        read=MAX_SIZE_BUCKED;
        this->isEndBool=false;
    }
    else
    {
        read=size-position;
        this->isEndBool=true;
    }
    fileCount(read);
}

void File::readFile()
{
    if(inputFile.is_open())
    {
        inputFile.seekg(this->position,inputFile.end);
        size=inputFile.tellg();
        inputFile.seekg(this->position);
    }
    file=new char[size];
    inputFile.read(file,size);
    fileCount(size);
}
int File::fileSize()
{

    return size;
}
void File::fileCount(int size)
{
    char file[size];
    inputFile.read(file,size);
    for(int i=0; i<size; i++)
    {
        if(file[i]!=10)frequency[int(file[i])+128]++;
    }
}
int File::bitFrequency(int Bit)
{
    return frequency[Bit];
}
char File::bitToChar(int Bit)
{
    return char(Bit-128);
}
int File::charToBit(char Char)
{
    return int(Char+128);
}
QString File::huffmanRepresentation(int Char)
{
    return this->huffmanRepresentationArray[Char];
}
void File::buildCodification(cell* node, int level = 1)
{
        if(node->leaf != true)
        {
            buildCodification(node->left, level*10);
            buildCodification(node->right,level*10+1);
        }
        if(node->leaf)
        {
            node->setHuffmanRepresentation(level);
            this->huffmanRepresentationArray[this->charToBit(node->getElement())]=node->getHuffmanRepresentation();
            //qDebug() << "\n" <<node->getHuffmanRepresentation();
        }
    }
int File::trashCalculation()
{
    int trash;
    int numberBits=0;
    for(int i=0;i<256;i++)    {
        numberBits += this->huffmanRepresentationArray[i].size() * this->frequency[i];
    }
    trash=8-(numberBits%8);
    if(trash==8)
        trash=0;
    return trash;
}

void File::setFileName(QString fileName)
{
    this->fileName=fileName;
}

QString File::getFileName()
{
    return this->fileName;
}
void File::clearPosition()
{
    this->position=0;
    this->isEndBool=false;
}

QString File::getfile()
{
        int read;
        inputFile.seekg(this->position);
        if(size-position>5)
        {
            this->position+=MAX_SIZE_BUCKED;
            read=MAX_SIZE_BUCKED;
            this->isEndBool=false;
        }
        else
        {
            read=size-position;
            this->isEndBool=true;
        }
        QString file;
        char buff;
        for(int i=0;i<read;i++)
        {
            inputFile.get(buff);
            file.append(buff);
        }
        return file;
}
int File::getBucked()
{
    return MAX_SIZE_BUCKED;
}

bool File::isEnd()
{
return this->isEndBool;
}

