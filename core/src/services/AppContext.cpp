#include <core/services/AppContext.h>

AppContext* AppContext::instance = nullptr;

AppContext::AppContext(std::unique_ptr<ISubjectRepository> subjectRepo) 
    :   m_subjectRepo(std::move(subjectRepo)),
        m_subjectService(*m_subjectRepo)
{}

void AppContext::Initialize(std::unique_ptr<ISubjectRepository> repo) {
    if (!instance) {
        if (!repo) throw std::runtime_error("Must provide repository on initialization!");
        instance = new AppContext(std::move(repo));
    }
}

AppContext& AppContext::Instance() {
    if (!instance) throw std::runtime_error("AppContext not initialized yet!");
    return *instance;
}

SubjectService& AppContext::Subjects() {
    return m_subjectService;
}
