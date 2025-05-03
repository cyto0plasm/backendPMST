#include "DBConnection.h"

SQLiteConnection^ DBConnection::GetConnection()
{
    SQLiteConnection^ conn = gcnew SQLiteConnection(connectionString);
    return conn;
}







//#include "DBConnection.h"
//
//MySqlConnection^ DBConnection::GetConnection()
//{
//    MySqlConnection^ conn = gcnew MySqlConnection(connectionString);
//    return conn;
//}
