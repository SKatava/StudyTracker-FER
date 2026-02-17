CREATE TABLE IF NOT EXISTS subjects (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    name TEXT NOT NULL,
    ects INTEGER NOT NULL,
    days_of_semester INTEGER NOT NULL
);

CREATE TABLE IF NOT EXISTS study_sessions (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    subject_id INTEGER NOT NULL,
    date TEXT NOT NULL,
    hours INTEGER NOT NULL,
    note TEXT,
    FOREIGN KEY(subject_id) REFERENCES subjects(id)
);
