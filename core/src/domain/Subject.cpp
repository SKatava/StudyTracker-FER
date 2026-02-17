#include <core/domain/Subject.h>


//Object construction, destruction and movement--------------------------------------------------

Subject::Subject(const std::string& name, uint8_t ECTS, uint8_t daysOfSemester) :
    m_name              (name), 
    m_ECTS              (ECTS), 
    m_daysOfSemester    (daysOfSemester) 
{
    CalculateNeededHours();
    m_studySessions.reserve(daysOfSemester); //In case it is done daily
}

//Getter and setters-----------------------------------------------------------------------------

void Subject::SetName(const std::string& name) {
    m_name = name;
}

const std::string& Subject::GetName() const noexcept {
    return m_name;
}

void Subject::SetETCS(const uint8_t& ECTS) {
    m_ECTS = ECTS;
}

uint8_t Subject::GetECTS() const noexcept {
    return m_ECTS;
}

void Subject::SetDaysOfSemester(uint8_t daysOfSemester) {
    m_daysOfSemester = daysOfSemester;
}

uint8_t Subject::GetDaysOfSemester() const noexcept {
    return m_daysOfSemester;
}

uint8_t Subject::GetNeededHours() const noexcept {
    return m_neededHours;
}

uint8_t Subject::GetInvestedHours() const noexcept {
    return m_investedHours;
}


//Core functions---------------------------------------------------------------------------------

void Subject::LogStudySession(uint8_t hours, const std::string& note) {
    auto now = std::chrono::system_clock::now();
    auto date = std::chrono::floor<std::chrono::days>(now);
    m_studySessions.push_back(StudySession(date, hours, note));
}

//Private functions------------------------------------------------------------------------------

void Subject::CalculateNeededHours() {
    m_neededHours = m_ECTS * MIN_HOURS_PER_ECTS; 
}



