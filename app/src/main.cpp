#include <actionsexecutor.hpp>

#include <QCoreApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    try {
        QCoreApplication a(argc, argv);

        if (argc < 2)
        {
            qDebug() << u8"Type filename after app name";
            return 1;
        }

        ActionsExecutor executor(argv[1]);

        a.connect(&executor, &ActionsExecutor::error, []() {throw std::runtime_error("Application error"); });
       
        executor.init();

        executor.run();
        
        executor.wait();

        qDebug() << u8"Sum" << executor.getSum();
        qDebug() << u8"Sub" << executor.getSub();
        qDebug() << u8"Xor" << executor.getXor();

        a.quit();

        return 0;
    }
    catch (std::exception ex)
    {
        qWarning() << QString::fromStdString(ex.what());
        return 1;
    }

}
