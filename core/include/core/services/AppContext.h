#ifndef APPCONTEXT_CLASS_H
#define APPCONTEXT_CLASS_H

#include <memory>

#include <core/services/SubjectService.h>

class AppContext {
    public:
        static void Initialize(std::unique_ptr<ISubjectRepository> repo);
        static AppContext& Instance();
        AppContext(std::unique_ptr<ISubjectRepository> subjectRepo);
        SubjectService& Subjects();

    private:
        std::unique_ptr<ISubjectRepository> m_subjectRepo;
        SubjectService m_subjectService;
        static AppContext* instance;
};

#endif

