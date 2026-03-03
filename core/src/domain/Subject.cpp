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

uint32_t Subject::GetInvestedMinutes() const noexcept {
    return m_lectureMinutesDone + m_studyMinutesDone + m_tasksMinutesDone;
}

// -------------------- Domain Behavior --------------------

void Subject::SetName(const std::string& name) {
    m_name = name;
}

void Subject::SetETCS(const uint8_t& ECTS) {
    m_ECTS = ECTS;
}

void Subject::SetDaysOfSemester(uint8_t daysOfSemester) {
    m_daysOfSemester = daysOfSemester;
}


// -------------------- Internal Logic --------------------

void Subject::CalculateNeededHours() {
    m_studyMinutesNeeded = MIN_HOURS_PER_ECTS * 60 * 25; 
}



