#ifndef STUDYSESSION_STRUCT_H
#define STUDYSESSION_STRUCT_H

#include <string>
#include <cstdint>

struct Session {
    int32_t         id              {-1};
    int32_t         subjectId       {-1};
    uint32_t        minutes         {0}; 
    std::string     description     {"UNKNOWN"};
    std::string     date            {"UNKNOWN"}; // format is "dd-mm-yyyy"

    int GetDay() const {
        std::string day = date.substr(0,2);
        return std::stoi(day);
    }

    int GetMonth() const {
        std::string month = date.substr(3,5);
        return std::stoi(month);
    }

     int GetYear() const {
        std::string year = date.substr(6,10);
        return std::stoi(year);
    }
};

#endif
