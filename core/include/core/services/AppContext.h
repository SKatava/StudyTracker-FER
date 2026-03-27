#ifndef APPCONTEXT_CLASS_H
#define APPCONTEXT_CLASS_H

#include <memory>

#include <core/services/SubjectService.h>
#include <core/services/SessionService.h>
#include <core/services/TaskService.h>

class AppContext {
    public:
        static void Initialize(std::unique_ptr<ISubjectRepository> subjectRepo, std::unique_ptr<ISessionRepository> sessionRepo, std::unique_ptr<ITaskRepository> taskRepo);
        static AppContext& Instance();
        AppContext(std::unique_ptr<ISubjectRepository> subjectRepo, std::unique_ptr<ISessionRepository> sessionRepo, std::unique_ptr<ITaskRepository> taskRepo);
        SubjectService& Subjects();
        SessionService& Sessions();
        TaskService& Tasks();

    private:
        std::unique_ptr<ISubjectRepository> m_subjectRepo;
        std::unique_ptr<ISessionRepository> m_sessionRepo;
        std::unique_ptr<ITaskRepository> m_taskRepo;
        SubjectService m_subjectService;
        SessionService m_sessionService;
        TaskService m_taskService;
        static AppContext* instance;
};

#endif

