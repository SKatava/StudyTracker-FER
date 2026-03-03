#ifndef SUBJECT_CLASS_H
#define SUBJECT_CLASS_H

#include <string>
#include <cstdint>
#include <chrono>
#include <vector>



class Subject {
    public:
        static constexpr uint8_t MIN_HOURS_PER_ECTS = 25;
        static constexpr uint8_t MAX_HOURS_PER_ECTS = 30;

        // -------------------- Construction --------------------
        
        Subject();
        Subject(const std::string& name, uint8_t ECTS, uint8_t daysOfSemester);

        Subject(const Subject&) = delete;
        Subject& operator=(const Subject&) = delete;

        Subject(Subject&&) noexcept = default;
        Subject& operator=(Subject&&) noexcept = default;

        ~Subject() = default;
        
        // -------------------- Getters --------------------

        [[nodiscard]] const std::string& GetName() const noexcept;
        [[nodiscard]] uint8_t GetECTS() const noexcept;
        [[nodiscard]] uint16_t GetDaysOfSemester() const noexcept;
        [[nodiscard]] uint32_t GetNeededMinutes() const noexcept;
        [[nodiscard]] uint32_t GetInvestedMinutes() const noexcept;

        // -------------------- Domain Behavior --------------------

        void SetName(const std::string& name);
        void SetETCS(const uint8_t& ECTS);
        void SetDaysOfSemester(uint8_t daysOfSemester);
 

    private:
        // -------------------- State --------------------

        int32_t             m_id                    {-1};
        std::string         m_name                  {"UNKNOWN"};
        std::string         m_daysTillEnd           {"UNKNOWN"};
        uint8_t             m_ECTS                  {0};
        uint16_t            m_daysOfSemester        {0};
        uint32_t            m_studyMinutesNeeded    {0};
        uint32_t            m_lectureMinutesNeeded  {0};
        uint32_t            m_lectureMinutesDone    {0};
        uint32_t            m_studyMinutesDone      {0};
        uint32_t            m_tasksMinutesDone      {0};
        uint8_t             m_points                {0};
        uint8_t             m_finalGrade            {0};
        bool                m_isFinished            {false};
        
        // -------------------- Internal Logic --------------------
        
        void CalculateNeededHours();

};

#endif
