#ifndef DATABASE_CLASS_H
#define DATABASE_CLASS_H

#include <sqlite3.h>

#include <string>

class Database {
    public:
        
        //Object construction, destruction and movement--------------------------------------------------

        explicit Database(const std::string& file);

        Database(const Database&) = delete;
        Database& operator=(const Database&) = delete;

        Database(Database&& other) noexcept = delete;
        Database& operator=(Database&& other) noexcept = delete;

        ~Database();

        //Getter and setters-----------------------------------------------------------------------------

        [[nodiscard]] sqlite3* Get() const noexcept;

        //Core functions---------------------------------------------------------------------------------

        void InitializeScheme();

    private:

        //Private members/data---------------------------------------------------------------------------

        sqlite3*                m_db                {nullptr};

        //Private functions------------------------------------------------------------------------------
        
        std::string LoadSQLFile(const std::string& path) const;
        void ExecSQL(const std::string& querry) const;
};

#endif
