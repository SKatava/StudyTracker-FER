#include <backend/sqlite/Database.h> 

#include <backend/sqlite/Schema.h> 

#include <stdexcept>
#include <fstream>
#include <sstream>
#include <filesystem>


//Object construction, destruction and movement--------------------------------------------------

//Database contructor - open the database
Database::Database() {
    std::string file = GetUserDatabasePath();
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
void Database::InitializeSchema() {
    for (const auto& stmt : Schema::GetTables()) {
        ExecSQL(stmt);
    }
}

//Private functions------------------------------------------------------------------------------

//Execute the sql querry on the current database
void Database::ExecSQL(const std::string& querry) const {
    char* errMsg = nullptr;
    if(sqlite3_exec(m_db, querry.c_str(), nullptr, nullptr, &errMsg) != SQLITE_OK) {
        std::string error = errMsg;
        sqlite3_free(errMsg);
        throw std::runtime_error("Can't execute SQL querry: " + error);
    }
}

//Get the location of the database based on OS
std::string Database::GetUserDatabasePath() {
    std::filesystem::path path;

#ifdef _WIN32
    char* appData = std::getenv("APPDATA");
    path = appData ? appData : ".";
    path /= "study-tracker";
#elif __APPLE__
    char* home = std::getenv("HOME");
    path = home ? home : ".";
    path /= "Library/Application Support/study-tracker";
#else // Linux
    char* home = std::getenv("HOME");
    path = home ? home : ".";
    path /= ".local/share/study-tracker";
#endif

    std::filesystem::create_directories(path); // ensure folder exists
    path /= "study-tracker.db"; // final DB file
    return path.string();
}
