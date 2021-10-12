#ifndef READER_H
#define READER_H

#include <QObject>
#include <QFile>
#include <QRegularExpressionMatch>
#include <QDebug>

class Reader : public QObject {
    Q_OBJECT
  public:
    explicit Reader(QObject *parent = nullptr);
    ~Reader();

  public: void setFile(const QString& f) {
    filename = f;
  }

  public: void readFile();

  signals:
  void finished(QString);

  private:
  QString filename;
};

#endif // READER_H
