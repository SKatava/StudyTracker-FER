#include <backend/sqlite/SQLiteSubjectRepository.h>

#include <sqlite3.h>
#include <iostream>

SQLiteSubjectRepository::SQLiteSubjectRepository(Database& db)
    :   m_db(db)
{}

int SQLiteSubjectRepository::Add(const Subject& subject) {
    sqlite3_stmt* stmt;
    int rc = SQLITE_OK;
    const char* insertSQL = R"sql(
        INSERT INTO subjects (
        name, 
        ects, 
        date_till_end, 
        lecture_minutes_needed, 
        study_minutes_needed, 
        lecture_minutes_done, 
        study_minutes_done, 
        tasks_minutes_done, 
        points, 
        finished, 
        final_grade)
        VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?);
    )sql";

    rc = sqlite3_prepare_v2(m_db.Get(), insertSQL, -1, &stmt, nullptr);
    if (rc != SQLITE_OK) {
        std::cerr << "Failed to prepare statement: " << sqlite3_errmsg(m_db.Get()) << std::endl;
        return -1;
    }

    sqlite3_bind_text(stmt, 1, subject.GetName().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_int(stmt, 2, subject.GetECTS());
    sqlite3_bind_text(stmt, 3, subject.GetEndDate().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_int(stmt, 4, subject.GetNeededLectureMinutes());
    sqlite3_bind_int(stmt, 5, subject.GetNeededStudyMinutes());
    sqlite3_bind_int(stmt, 6, subject.GetInvestedLectureMinutes());
    sqlite3_bind_int(stmt, 7, subject.GetInvestedStudyMinutes());
    sqlite3_bind_int(stmt, 8, subject.GetInvestedTasksMinutes());
    sqlite3_bind_int(stmt, 9, subject.GetPoints());
    sqlite3_bind_int(stmt, 10, subject.GetIsFinished());
    sqlite3_bind_int(stmt, 11, subject.GetFinalGrade());

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

std::vector<Subject> SQLiteSubjectRepository::GetAll() {
    std::vector<Subject> subjects;

    const char* selectSQL = R"sql(
        SELECT * FROM subjects;
    )sql";

    sqlite3_stmt* stmt;
    int rc = sqlite3_prepare_v2(m_db.Get(), selectSQL, -1, &stmt, nullptr);
    if (rc != SQLITE_OK) {
        std::cerr << "Failed to prepare SELECT statement: " << sqlite3_errmsg(m_db.Get()) << std::endl;
        return subjects; 
    }

    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
        Subject s;

        s.SetId(sqlite3_column_int(stmt, 0));
        s.SetName(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));
        s.SetECTS(sqlite3_column_int(stmt, 2));
        s.SetEndDate(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3)));
        s.SetNeededLectureMinutes(sqlite3_column_int(stmt, 4));
        s.SetNeededStudyMinutes(sqlite3_column_int(stmt, 5));
        s.SetInvestedLectureMinutes(sqlite3_column_int(stmt, 6));
        s.SetInvestedStudyMinutes(sqlite3_column_int(stmt, 7));
        s.SetInvestedTasksMinutes(sqlite3_column_int(stmt, 8));
        s.SetPoints(sqlite3_column_int(stmt, 9));
        s.SetFinalGrade(sqlite3_column_int(stmt, 10));
        s.SetIsFinished(sqlite3_column_int(stmt, 11));

        subjects.push_back(std::move(s));
    }

    if (rc != SQLITE_DONE) {
        std::cerr << "Error iterating rows: " << sqlite3_errmsg(m_db.Get()) << std::endl;
    }

    sqlite3_finalize(stmt);

    return subjects;
} 

void SQLiteSubjectRepository::Update(const Subject& subject) {
    sqlite3_stmt* stmt;
    int rc = SQLITE_OK;

    const char* updateSQL = R"sql(
        UPDATE subjects SET
            name = ?,
            ects = ?,
            date_till_end = ?,
            lecture_minutes_needed = ?,
            study_minutes_needed = ?,
            lecture_minutes_done = ?,
            study_minutes_done = ?,
            tasks_minutes_done = ?,
            points = ?,
            final_grade = ?,
            finished = ?
        WHERE id = ?;
    )sql";

    rc = sqlite3_prepare_v2(m_db.Get(), updateSQL, -1, &stmt, nullptr);
    if (rc != SQLITE_OK) {
        std::cerr << "Failed to prepare UPDATE: "
                  << sqlite3_errmsg(m_db.Get()) << std::endl;
        return;
    }

    sqlite3_bind_text(stmt, 1, subject.GetName().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_int(stmt, 2, subject.GetECTS());
    sqlite3_bind_text(stmt, 3, subject.GetEndDate().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_int(stmt, 4, subject.GetNeededLectureMinutes());
    sqlite3_bind_int(stmt, 5, subject.GetNeededStudyMinutes());
    sqlite3_bind_int(stmt, 6, subject.GetInvestedLectureMinutes());
    sqlite3_bind_int(stmt, 7, subject.GetInvestedStudyMinutes());
    sqlite3_bind_int(stmt, 8, subject.GetInvestedTasksMinutes());
    sqlite3_bind_int(stmt, 9, subject.GetPoints());
    sqlite3_bind_int(stmt, 10, subject.GetFinalGrade());
    sqlite3_bind_int(stmt, 11, subject.GetIsFinished());

    sqlite3_bind_int(stmt, 12, subject.GetId());

    rc = sqlite3_step(stmt);

    if (rc != SQLITE_DONE) {
        std::cerr << "UPDATE failed: "
                  << sqlite3_errmsg(m_db.Get()) << std::endl;
    }

    sqlite3_finalize(stmt);
}
    
void SQLiteSubjectRepository::Remove(int id) {
    sqlite3_stmt* stmt;

    const char* deleteSQL = "DELETE FROM subjects WHERE id = ?;";

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
