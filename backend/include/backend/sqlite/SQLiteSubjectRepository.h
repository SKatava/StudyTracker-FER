#ifndef SQLITESUBJECTREPOSITORY_CLASS_H
#define SQLITESUBJECTREPOSITORY_CLASS_H

#include <core/repositories/ISubjectRepository.h>
#include <backend/sqlite/Database.h>

class SQLiteSubjectRepository : public ISubjectRepository {
    public:
        explicit SQLiteSubjectRepository(Database& db);
        int Add(const Subject& subject) override;
        std::vector<Subject> GetAll() override;
        void Update(const Subject& subject) override;
        void Remove(int id) override;

    private:
        Database& m_db;
};

#endif
