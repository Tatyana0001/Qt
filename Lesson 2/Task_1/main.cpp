#include <QCoreApplication>
#include <QAuthenticator>
#include <QSqlDatabase>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QAuthenticator authenticator;
    QSqlDatabase Database;
    return a.exec();
}
