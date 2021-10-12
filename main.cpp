#include <QThread>
#include <reader.h>
#include <QDebug>

using namespace std;

void printResult(QString temp) {
  qDebug().noquote() << temp;
  //cout << temp.toStdString() << std::endl;
}

int main(int argc, char *argv[])
{
    QThread thread;
    Reader reader;

    reader.moveToThread(&thread);

    if (argc != 2 )
    {
        qDebug() << "Nije odabrana datoteka!";
        return 0;
    }
    else
    {
        reader.setFile(argv[1]);
        QObject::connect(&reader, &Reader::finished, printResult);
        reader.readFile();
    }
    return 0;
}
