#include<fstream>
#include"Cell.h"
#include<QString>
class File
{
    std::ifstream inputFile;
    int size;
    int frequency[256];
    QString huffmanRepresentationArray[256];
    char* file;
    QString fileName;
    int position;
    bool isEndBool;

public:
    File(char file[]);
    int fileSize();
    void fileCount(int size);
    int bitFrequency(int Bit);
    char bitToChar(int Bit);
    int charToBit(char Char);
    QString huffmanRepresentation(int Char);
    void buildCodification(cell *node, int level);
    int trashCalculation();
    void setFileName(QString fileName);
    QString getFileName();
    QString getfile();
    void readFile();
    void grabBucked();
    bool isEnd();
    void clearPosition();
    int getBucked();
};

