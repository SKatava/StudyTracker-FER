#include <backend/sqlite/SQLiteSessionRepository.h>

#include <sqlite3.h>
#include <iostream>


SQLiteSessionRepository::SQLiteSessionRepository(Database& db) 
    : m_db(db)
{}

int SQLiteSessionRepository::Add(const Session& session) {
    sqlite3_stmt* stmt;
    int rc = SQLITE_OK;
    const char* insertSQL = R"sql(
        INSERT INTO study_sessions (
        subject_id,
        description,
        date,
        duration_minutes) 
        VALUES (?, ?, ?, ?);
    )sql";

    rc = sqlite3_prepare_v2(m_db.Get(), insertSQL, -1, &stmt, nullptr);
    if (rc != SQLITE_OK) {
        std::cerr << "Failed to prepare statement: " << sqlite3_errmsg(m_db.Get()) << std::endl;
        return -1;
    }

    sqlite3_bind_int(stmt, 1, session.subjectId);
    sqlite3_bind_text(stmt, 2, session.description.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 3, session.date.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_int(stmt, 4, session.minutes);

    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE) {
        std::cerr << "Execution failed: " << sqlite3_errmsg(m_db.Get()) << std::endl;
        return -1;
    } else {
        std::cout << "Inserted successfully!" << std::endl;
    }

    int newId = static_cast<int>(sqlite3_last_insert_rowid(m_db.Get()));

    sqlite3_finalize(stmt);

    return newId;
}

std::vector<Session> SQLiteSessionRepository::GetAll() {
    std::vector<Session> sessions;

    const char* selectSQL = R"sql(
        SELECT * FROM study_sessions;
    )sql";

    sqlite3_stmt* stmt;
    int rc = sqlite3_prepare_v2(m_db.Get(), selectSQL, -1, &stmt, nullptr);
    if (rc != SQLITE_OK) {
        std::cerr << "Failed to prepare SELECT statement: " << sqlite3_errmsg(m_db.Get()) << std::endl;
        return sessions; 
    }

    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
        Session s;

        s.id = sqlite3_column_int(stmt, 0);
        s.subjectId = sqlite3_column_int(stmt, 1);
        s.description = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
        s.date = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3));
        s.minutes = sqlite3_column_int(stmt, 4);

        sessions.push_back(std::move(s));
    }

    if (rc != SQLITE_DONE) {
        std::cerr << "Error iterating rows: " << sqlite3_errmsg(m_db.Get()) << std::endl;
    }

    sqlite3_finalize(stmt);

    return sessions;
}

void SQLiteSessionRepository::Remove(int id) {
    sqlite3_stmt* stmt;

    const char* deleteSQL = R"sql(
        DELETE FROM study_sessions WHERE id = ?;
    )sql";

    int rc = sqlite3_prepare_v2(m_db.Get(), deleteSQL, -1, &stmt, nullptr);
    if (rc != SQLITE_OK) {
        std::cerr << "Failed to prepare DELETE: "
                  << sqlite3_errmsg(m_db.Get()) << std::endl;
        return;
    }

    sqlite3_bind_int(stmt, 1, id);

    rc = sqlite3_step(stmt);

    if (rc != SQLITE_DONE) {
        std::cerr << "DELETE failed: "
                  << sqlite3_errmsg(m_db.Get()) << std::endl;
    }

    sqlite3_finalize(stmt);
}
