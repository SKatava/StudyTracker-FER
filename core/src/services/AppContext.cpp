#include <core/services/AppContext.h>

AppContext* AppContext::instance = nullptr;

AppContext::AppContext(std::unique_ptr<ISubjectRepository> subjectRepo, std::unique_ptr<ISessionRepository> sessionRepo, std::unique_ptr<ITaskRepository> taskRepo) 
    :   m_subjectRepo(std::move(subjectRepo)),
        m_subjectService(*m_subjectRepo),
        m_sessionRepo(std::move(sessionRepo)),
        m_sessionService(*m_sessionRepo),
        m_taskRepo(std::move(taskRepo)),
        m_taskService(*m_taskRepo)
        
{}

void AppContext::Initialize(std::unique_ptr<ISubjectRepository> subjectRepo, std::unique_ptr<ISessionRepository> sessionRepo, std::unique_ptr<ITaskRepository> taskRepo) {
    if (!instance) {
        if (!subjectRepo) throw std::runtime_error("Must provide subject repository on initialization!");
        if (!sessionRepo) throw std::runtime_error("Must provide session repository on initialization!");
        if (!taskRepo) throw std::runtime_error("Must provide task repository on initialization!");

        instance = new AppContext(std::move(subjectRepo), std::move(sessionRepo), std::move(taskRepo));
    }
}

AppContext& AppContext::Instance() {
    if (!instance) throw std::runtime_error("AppContext not initialized yet!");
    return *instance;
}

SubjectService& AppContext::Subjects() {
    return m_subjectService;
}

SessionService& AppContext::Sessions() {
    return m_sessionService;
}

TaskService& AppContext::Tasks() {
    return m_taskService;
}
