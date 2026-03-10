#ifndef APPCONTEXT_CLASS_H
#define APPCONTEXT_CLASS_H

#include <memory>

#include <core/services/SubjectService.h>
#include <core/services/SessionService.h>

class AppContext {
    public:
        static void Initialize(std::unique_ptr<ISubjectRepository> subjectRepo, std::unique_ptr<ISessionRepository> sessionRepo);
        static AppContext& Instance();
        AppContext(std::unique_ptr<ISubjectRepository> subjectRepo, std::unique_ptr<ISessionRepository> sessionRepo);
        SubjectService& Subjects();
        SessionService& Sessions();

    private:
        std::unique_ptr<ISubjectRepository> m_subjectRepo;
        std::unique_ptr<ISessionRepository> m_sessionRepo;
        SubjectService m_subjectService;
        SessionService m_sessionService;
        static AppContext* instance;
};

#endif

