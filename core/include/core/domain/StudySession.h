#ifndef STUDYSESSION_STRUCT_H
#define STUDYSESSION_STRUCT_H

#include <cstdint>
#include <chrono>

struct StudySession {
    std::chrono::year_month_day     date;
    uint8_t                         hours;
    std::string                     note;
};

#endif
