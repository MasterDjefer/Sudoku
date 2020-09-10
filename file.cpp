#include "file.h"

File::File()
{
    QFile file("maps.txt");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream out(&file);

    for (int i = 0; i < 9; ++i)
    {
        QString s = out.readLine();
        for (int j = 0; j < s.size(); ++j)
        {
            if (s.at(j) == '0')
            {
                mNumber.push_back("");
            }
            else
            {
                mNumber.push_back(QString(s.at(j)));
            }
        }
    }

}

QVector<QString> File::getUnChangeAbleNumbers()
{
    return mNumber;
}
