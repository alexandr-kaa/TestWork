#ifndef FILEREADER_HPP
#define FILEREADER_HPP
#include <QString>
#include <QThread>
#include <QTextStream>
#include <QFile>

namespace Helper{
class FileReader : public QThread{
    Q_OBJECT
public:
    explicit FileReader(const QString & fileName, QObject * parent=nullptr);
    qint64 init();
signals:
    void readNumber(qint64 number);
    void done(qint64);
    void error(QString);
private:
    void run() override;
    QString m_fileName;
    QTextStream m_stream;
    QFile m_file;
};
}
#endif
