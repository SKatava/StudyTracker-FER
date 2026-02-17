#ifndef SUBJECT_CLASS_H
#define SUBJECT_CLASS_H

#include <string>
#include <cstdint>
#include <chrono>
#include <vector>

#include "StudySession.h"

#define MIN_HOURS_PER_ECTS 25
#define MAX_HOURS_PER_ECTS 30

class Subject {
    public:

        //Object construction, destruction and movement--------------------------------------------------

        Subject();
        Subject(const std::string& name, uint8_t ECTS, uint8_t daysOfSemester);

        Subject(const Subject&) = delete;
        Subject& operator=(const Subject&) = delete;

        Subject(Subject&&) noexcept = default;
        Subject& operator=(Subject&&) noexcept = default;

        ~Subject() = default;
        
        //Getter and setters-----------------------------------------------------------------------------

        void SetName(const std::string& name);
        [[nodiscard]] const std::string& GetName() const noexcept;

        void SetETCS(const uint8_t& ECTS);
        [[nodiscard]] uint8_t GetECTS() const noexcept;

        void SetDaysOfSemester(uint8_t daysOfSemester);
        [[nodiscard]] uint8_t GetDaysOfSemester() const noexcept;

        [[nodiscard]] uint8_t GetNeededHours() const noexcept;
        
        [[nodiscard]] uint8_t GetInvestedHours() const noexcept;

        //Core functions---------------------------------------------------------------------------------
        
        void LogStudySession(uint8_t hours, const std::string& notes = "");

    private:

        //Private members/data---------------------------------------------------------------------------

        std::string                 m_name              {"UNKNOWN"};
        uint8_t                     m_ECTS              {0};
        uint8_t                     m_daysOfSemester    {0};
        uint8_t                     m_neededHours       {0};
        uint8_t                     m_investedHours     {0};
        std::vector<StudySession>   m_studySessions     {};

        //Private functions------------------------------------------------------------------------------
        
        void CalculateNeededHours();

};

#endif
