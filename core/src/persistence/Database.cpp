#include <core/persistence/Database.h>

#include <stdexcept>
#include <fstream>
#include <sstream>

//Object construction, destruction and movement--------------------------------------------------

//Database contructor - open the database
Database::Database(const std::string& file) {
    if(sqlite3_open(file.c_str(), &m_db) != SQLITE_OK) {
        std::string error = sqlite3_errmsg(m_db);
        sqlite3_close(m_db);
        throw std::runtime_error("Failed to open database: " + error);
    }
    ExecSQL("PRAGMA foreign_keys = ON;");
}

//Database destructor - close the database
Database::~Database() {
    if(m_db) {
        sqlite3_close(m_db);
        m_db  = nullptr;
    }
}


//Getter and setters-----------------------------------------------------------------------------

sqlite3* Database::Get() const noexcept {
    return m_db;
}


//Core functions---------------------------------------------------------------------------------

//Create a database schema(if it doesn't exist)
void Database::InitializeScheme() {
    ExecSQL(LoadSQLFile("../sql/001_create_tables.sql"));
}

//Private functions------------------------------------------------------------------------------

//Load the .sql file as a string
std::string Database::LoadSQLFile(const std::string& path) const {
    std::fstream file(path);
    if(!file) {
        throw std::runtime_error("Failed to open SQL file: " + path);
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

//Execute the sql querry on the current database
void Database::ExecSQL(const std::string& querry) const {
    char* errMsg = nullptr;
    if(sqlite3_exec(m_db, querry.c_str(), nullptr, nullptr, &errMsg) != SQLITE_OK) {
        std::string error = errMsg;
        sqlite3_free(errMsg);
        throw std::runtime_error("Can't execute SQL querry: " + error);
    }
}
