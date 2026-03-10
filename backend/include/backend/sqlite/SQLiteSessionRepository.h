#ifndef SQLITESESSIONREPOSITORY_CLASS_H
#define SQLITESESSIONREPOSITORY_CLASS_H

#include <core/repositories/ISessionRepository.h>
#include <backend/sqlite/Database.h>

class SQLiteSessionRepository : public ISessionRepository {
    public:
        explicit SQLiteSessionRepository(Database& db);
        int Add(const Session& session) override;
        std::vector<Session> GetAll() override;
        void Remove(int id) override;

    private:
        Database& m_db;
};

#endif
