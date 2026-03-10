#include <core/services/AppContext.h>

AppContext* AppContext::instance = nullptr;

AppContext::AppContext(std::unique_ptr<ISubjectRepository> subjectRepo, std::unique_ptr<ISessionRepository> sessionRepo) 
    :   m_subjectRepo(std::move(subjectRepo)),
        m_subjectService(*m_subjectRepo),
        m_sessionRepo(std::move(sessionRepo)),
        m_sessionService(*m_sessionRepo)
{}

void AppContext::Initialize(std::unique_ptr<ISubjectRepository> subjectRepo, std::unique_ptr<ISessionRepository> sessionRepo) {
    if (!instance) {
        if (!subjectRepo) throw std::runtime_error("Must provide subject repository on initialization!");
        if (!sessionRepo) throw std::runtime_error("Must provide session repository on initialization!");
        instance = new AppContext(std::move(subjectRepo), std::move(sessionRepo));
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
