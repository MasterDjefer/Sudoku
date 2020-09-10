#ifndef FILE_H
#define FILE_H
#include <QFile>
#include <QTextStream>
#include <QVector>

class File//read sudoku map(numbers) from file
{
public:
    File();
    QVector<QString> getUnChangeAbleNumbers();

private:
    QFile mFile;
    QTextStream mTextStream;
    QVector<QString> mNumber;
};

#endif // FILE_H
