#include <backend/sqlite/SQLiteSubjectRepository.h>

SQLiteSubjectRepository::SQLiteSubjectRepository(Database& db)
    :   m_db(db)
{}

int SQLiteSubjectRepository::Add(const Subject& subject) {
    return -1;
}

std::vector<Subject> SQLiteSubjectRepository::GetAll() {
    std::vector<Subject> sub;
    return sub;
}

void SQLiteSubjectRepository::Update(const Subject& subject) {}
    
void SQLiteSubjectRepository::Remove(int id) {}
