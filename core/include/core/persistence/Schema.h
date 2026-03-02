#ifndef SCHEMA_STRUCT_H
#define SCHEMA_STRUCT_H

#include <string>
#include <vector>

struct Schema {
    static const std::vector<std::string>& GetTables() {
        static std::vector<std::string> tables = {
            R"(CREATE TABLE IF NOT EXISTS subjects (
                    id INTEGER PRIMARY KEY AUTOINCREMENT,
                    name TEXT NOT NULL,
                    ects INTEGER NOT NULL,
                    date_till_end TEXT NOT NULL,
                    lecture_hours_needed INTEGER NOT NULL,
                    study_hours_needed INTEGER NOT NULL,
                    lecture_hours_done INTEGER NOT NULL,
                    study_hours_done INTEGER NOT NULL,
                    tasks_hours_done INTEGER NOT NULL,
                    points INTEGER NOT NULL,
                    finished INTEGER NOT NULL CHECK (finished IN (0,1)) DEFAULT 0,
                    final_grade INTEGER NOT NULL
                );)",
            R"(CREATE TABLE IF NOT EXISTS study_sessions (
                    id INTEGER PRIMARY KEY AUTOINCREMENT,
                    subject_id INTEGER NOT NULL,
                    description TEXT NOT NULL,
                    date TEXT NOT NULL,
                    duration_hours INTEGER NOT NULL,
                    FOREIGN KEY(subject_id) REFERENCES subjects(id) ON DELETE CASCADE
                );)",
            R"(CREATE TABLE IF NOT EXISTS tasks (
                    id INTEGER PRIMARY KEY AUTOINCREMENT,
                    subject_id INTEGER NOT NULL,
                    description TEXT NOT NULL,
                    hours_taken INTEGER NOT NULL,
                    done INTEGER NOT NULL CHECK (done IN (0,1)) DEFAULT 0,
                    start_date TEXT NOT NULL,
                    end_date TEXT NOT NULL,
                    finish_date TEXT,
                    FOREIGN KEY(subject_id) REFERENCES subjects(id) ON DELETE CASCADE
                );)" 
        };
        return tables;
    }
};

#endif
