#include <backend/sqlite/SQLiteTaskRepository.h>

#include <sqlite3.h>
#include <iostream>

SQLiteTaskRepository::SQLiteTaskRepository(Database& db)
    : m_db(db)
{}

int SQLiteTaskRepository::Add(const Task& task) {
    sqlite3_stmt* stmt;
    int rc = SQLITE_OK;
    const char* insertSQL = R"sql(
        INSERT INTO tasks (
        subject_id,
        description,
        minutes_taken,
        done,
        start_date,
        end_date,
        finish_date) 
        VALUES (?, ?, ?, ?, ?, ?, ?);
    )sql";

    rc = sqlite3_prepare_v2(m_db.Get(), insertSQL, -1, &stmt, nullptr);
    if (rc != SQLITE_OK) {
        std::cerr << "Failed to prepare statement: " << sqlite3_errmsg(m_db.Get()) << std::endl;
        return -1;
    }

    sqlite3_bind_int(stmt, 1, task.subjectId);
    sqlite3_bind_text(stmt, 2, task.description.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_int(stmt, 3, task.minutes);
    sqlite3_bind_int(stmt, 4, task.done);
    sqlite3_bind_text(stmt, 5, task.date_start.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 6, task.date_end.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 7, task.date_done.c_str(), -1, SQLITE_TRANSIENT);

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

std::vector<Task> SQLiteTaskRepository::GetAll() {
    std::vector<Task> tasks;

    const char* selectSQL = R"sql(
        SELECT * FROM tasks;
    )sql";

    sqlite3_stmt* stmt;
    int rc = sqlite3_prepare_v2(m_db.Get(), selectSQL, -1, &stmt, nullptr);
    if (rc != SQLITE_OK) {
        std::cerr << "Failed to prepare SELECT statement: " << sqlite3_errmsg(m_db.Get()) << std::endl;
        return tasks; 
    }

    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
        Task t;

        t.id = sqlite3_column_int(stmt, 0);
        t.subjectId = sqlite3_column_int(stmt, 1);
        t.description = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
        t.minutes = sqlite3_column_int(stmt, 3);
        t.done = sqlite3_column_int(stmt, 4);
        t.date_start = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 5));
        t.date_end = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 6));
        t.date_done = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 7));

        tasks.push_back(std::move(t));
    }

    if (rc != SQLITE_DONE) {
        std::cerr << "Error iterating rows: " << sqlite3_errmsg(m_db.Get()) << std::endl;
    }

    sqlite3_finalize(stmt);

    return tasks;
}

void SQLiteTaskRepository::Update(const Task& task) {
    sqlite3_stmt* stmt;
    int rc = SQLITE_OK;

    const char* updateSQL = R"sql(
        UPDATE tasks SET
            subject_id = ?,
            description = ?,
            minutes_taken = ?,
            done = ?,
            start_date = ?,
            end_date = ?,
            finish_date = ?
        WHERE id = ?;
    )sql";

    rc = sqlite3_prepare_v2(m_db.Get(), updateSQL, -1, &stmt, nullptr);
    if (rc != SQLITE_OK) {
        std::cerr << "Failed to prepare UPDATE: "
                  << sqlite3_errmsg(m_db.Get()) << std::endl;
        return;
    }

    sqlite3_bind_int(stmt, 1, task.subjectId);
    sqlite3_bind_text(stmt, 2, task.description.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_int(stmt, 3, task.minutes);
    sqlite3_bind_int(stmt, 4, task.done);
    sqlite3_bind_text(stmt, 5, task.date_start.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 6, task.date_end.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 7, task.date_done.c_str(), -1, SQLITE_TRANSIENT);

    sqlite3_bind_int(stmt, 8, task.id);

    rc = sqlite3_step(stmt);

    if (rc != SQLITE_DONE) {
        std::cerr << "UPDATE failed: "
                  << sqlite3_errmsg(m_db.Get()) << std::endl;
    }

    sqlite3_finalize(stmt);
}
 

void SQLiteTaskRepository::Remove(int id) {
    sqlite3_stmt* stmt;

    const char* deleteSQL = R"sql(
        DELETE FROM tasks WHERE id = ?;
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
