#include"File.h"
#include<string>
#include<QDebug>
#define MAX_SIZE_BUCKED 200;
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
        inputFile.seekg(0);
    }
    this->position=0;
}
void File::grabBucked()
{
    int read;
    inputFile.seekg(this->position);
    if(size-position>200)
    {
        this->position+=MAX_SIZE_BUCKED;
        read=MAX_SIZE_BUCKED;
        this->isEndBool=false;
    }
    else
    {
        read=size-position-1;
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
    int totalbit=0;
    for(int i=0;i<256;i++)    {
        totalbit += this->huffmanRepresentationArray[i].size() * this->frequency[i];
    }
    lixo=8-(totalbit%8);
    if(lixo==8)
        lixo=0;
    return lixo;
}

void File::setFileName(QString FileName)
{
    this->fileName=FileName;
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

char* File::getfile()
{
        int read;
        inputFile.seekg(this->position);
        if(size-position>200)
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
        file=new char[size];
        inputFile.read(file,read);
        return file;
}

bool File::isEnd()
{
return this->isEndBool;
}

