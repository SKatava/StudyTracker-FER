#include <core/domain/Subject.h>


// -------------------- Construction --------------------



Subject::Subject(const std::string& name, uint8_t ECTS, uint8_t daysOfSemester) :
    m_name              (name), 
    m_ECTS              (ECTS), 
    m_daysOfSemester    (daysOfSemester) 
{
    CalculateNeededHours();
}



// -------------------- Getters --------------------

const std::string& Subject::GetName() const noexcept {
    return m_name;
}

uint8_t Subject::GetECTS() const noexcept {
    return m_ECTS;
}

uint16_t Subject::GetDaysOfSemester() const noexcept {
    return m_daysOfSemester;
}

uint32_t Subject::GetNeededMinutes() const noexcept {
    return m_lectureMinutesNeeded + m_studyMinutesNeeded;
}

uint32_t Subject::GetNeededLectureMinutes() const noexcept {
    return m_lectureMinutesNeeded;
}

uint32_t Subject::GetNeededStudyMinutes() const noexcept {
    return m_studyMinutesNeeded;
}

uint32_t Subject::GetInvestedMinutes() const noexcept {
    return m_lectureMinutesDone + m_studyMinutesDone + m_tasksMinutesDone;
}

uint32_t Subject::GetInvestedLectureMinutes() const noexcept {
    return m_lectureMinutesDone;
}

uint32_t Subject::GetInvestedStudyMinutes() const noexcept {
    return m_studyMinutesDone;
}

uint32_t Subject::GetInvestedTasksMinutes() const noexcept {
    return  m_tasksMinutesDone;
}

const std::string& Subject::GetEndDate() const noexcept {
    return m_endDate;
}

uint8_t Subject::GetFinalGrade() const noexcept {
    return m_finalGrade;
}

uint8_t Subject::GetPoints() const noexcept {
    return m_points;
}

bool Subject::GetIsFinished() const noexcept {
    return m_isFinished;
}


// -------------------- Getters --------------------

void Subject::SetId(const int32_t& id) { m_id = id; }
void Subject::SetName(const std::string& name) { m_name = name; }
void Subject::SetECTS(const uint8_t& ECTS) { m_ECTS = ECTS; }
void Subject::SetEndDate(const std::string& date) { m_endDate = date; }
void Subject::SetNeededLectureMinutes(uint32_t minutes) { m_lectureMinutesNeeded = minutes; }
void Subject::SetNeededStudyMinutes(uint32_t minutes) { m_studyMinutesNeeded = minutes; }
void Subject::SetInvestedLectureMinutes(uint32_t minutes) { m_lectureMinutesDone = minutes; }
void Subject::SetInvestedStudyMinutes(uint32_t minutes) { m_studyMinutesDone = minutes; }
void Subject::SetInvestedTasksMinutes(uint32_t minutes) { m_tasksMinutesDone = minutes; }
void Subject::SetPoints(uint8_t points) { m_points = points; }
void Subject::SetFinalGrade(uint8_t grade) { m_finalGrade = grade; }
void Subject::SetIsFinished(bool isFinished) { m_isFinished = isFinished; }

// -------------------- Domain Behavior --------------------

void Subject::SetDaysOfSemester(uint8_t daysOfSemester) {
    m_daysOfSemester = daysOfSemester;
}


// -------------------- Internal Logic --------------------

void Subject::CalculateNeededHours() {
    m_studyMinutesNeeded = MIN_HOURS_PER_ECTS * 60 * 25; 
}



