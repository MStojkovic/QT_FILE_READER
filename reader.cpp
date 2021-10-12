#include "reader.h"

Reader::Reader(QObject *parent) : QObject(parent)
{

}
Reader::~Reader() {

}

void Reader::readFile(){
    QRegularExpression rx("(([0-2][0-9]|(3)[0-1])(\\.)(((0)[0-9])|((1)[0-2]))(\\.)\\d{4})( )((([A-zčćšđžŠČĆŽĐ])+( )([A-zčćšđžŠČĆŽĐ])+[\n\r]+)|(([A-zčćšđžŠČĆŽĐ])+( )([A-zčćšđžŠČĆŽĐ])+( )([A-zčćšđžŠČĆŽĐ])+( )([A-zčćšđžŠČĆŽĐ])+[\n\r]+)|(([A-zčćšđžŠČĆŽĐ])+(-)([A-zčćšđžŠČĆŽĐ])+( )([A-zčćšđžŠČĆŽĐ])+(-)([A-zčćšđžŠČĆŽĐ])+[\n\r]+))");
    QString output = "";
    QFile file(filename);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Nije pronađena datoteka!";
        return;
    }
    while (!file.atEnd()) {
        QByteArray line = file.readLine();
        QString dataAsString = QString(line);
        //dataAsString = dataAsString.trimmed();
        //qDebug().noquote() << dataAsString;
        QRegularExpressionMatch match = rx.match(dataAsString);
        if (match.hasMatch()) {
            output.append(dataAsString);
            //output += "\n";
        }
    }
    emit finished(output);
}

