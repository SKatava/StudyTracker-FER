#ifndef SQLITETASKREPOSITORY_CLASS_H
#define SQLITETASKREPOSITORY_CLASS_H

#include <core/repositories/ITaskRepository.h>
#include <backend/sqlite/Database.h>

class SQLiteTaskRepository : public ITaskRepository {
    public:
        explicit SQLiteTaskRepository(Database& db);
        int Add(const Task& task) override;
        std::vector<Task> GetAll() override;
        void Update(const Task& task) override;
        void Remove(int id) override;

    private:
        Database& m_db;
};

#endif
