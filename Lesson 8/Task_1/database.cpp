#include "database.h"

DataBase::DataBase(QObject *parent)
    : QObject{parent}
{

    dataBase = new QSqlDatabase();
    query_model = new QSqlQueryModel();

}

DataBase::~DataBase()
{
    delete dataBase;
    delete query_model;
    delete table_model;
}

/*!
 * \brief Метод добавляет БД к экземпляру класса QSqlDataBase
 * \param driver драйвер БД
 * \param nameDB имя БД (Если отсутствует Qt задает имя по умолчанию)
 */
void DataBase::AddDataBase(QString driver, QString nameDB)
{

    *dataBase = QSqlDatabase::addDatabase(driver, nameDB);

}

/*!
 * \brief Метод подключается к БД
 * \param для удобства передаем контейнер с данными необходимыми для подключения
 * \return возвращает тип ошибки
 */
void DataBase::ConnectToDataBase(QVector<QString> data)
{

    dataBase->setHostName(data[hostName]);
    dataBase->setDatabaseName(data[dbName]);
    dataBase->setUserName(data[login]);
    dataBase->setPassword(data[pass]);
    dataBase->setPort(data[port].toInt());


    bool status;
    status = dataBase->open( );
    emit sig_SendStatusConnection(status);

}
/*!
 * \brief Метод производит отключение от БД
 * \param Имя БД
 */
void DataBase::DisconnectFromDataBase(QString nameDb)
{

    *dataBase = QSqlDatabase::database(nameDb);
    dataBase->close();

}
/*!
 * \brief Метод формирует запрос к БД.
 * \param request - SQL запрос
 * \return
 */
void DataBase::RequestToDB(QString request, QTableView *view, int requestType)
{
    if(!dataBase->isOpen()){
        emit sig_SendStatusConnection(false);
    }
    switch (requestType) {
    case 0:{
        table_model = new QSqlTableModel(nullptr, *dataBase);
        table_model->setTable("film");
        table_model->select();
        table_model->setHeaderData(0, Qt::Horizontal, tr("Id фильма"));
        table_model->setHeaderData(1, Qt::Horizontal, tr("Название фильма"));
        table_model->setHeaderData(2, Qt::Horizontal, tr("Описание"));
        emit sig_SendDataFromDB(table_model, requestType);
        break;
    }
    case 1:
    case 2:{
        query_model->setQuery(request, *dataBase);
        query_model->setHeaderData(0, Qt::Horizontal, tr("Название фильма"));
        query_model->setHeaderData(1, Qt::Horizontal, tr("Описание фильма"));
        query_model->setHeaderData(2, Qt::Horizontal, tr("Жанр"));
        emit sig_SendDataFromDB(query_model, requestType);
        break; 
    }
    default:
        break;
    }
}

/*!
 * @brief Метод возвращает последнюю ошибку БД
 */
QSqlError DataBase::GetLastError(){
    return dataBase->lastError();
}