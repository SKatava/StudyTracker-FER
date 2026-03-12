#ifndef SUBJECTEVENT_CLASS_H
#define SUBJECTEVENT_CLASS_H

#include <QObject>
#include <core/domain/Subject.h>


class SubjectEvents : public QObject {
    Q_OBJECT

public:
    static SubjectEvents& instance() {
        static SubjectEvents inst;
        return inst;
    }

signals:
    void subjectCreated(const Subject& subject);
};

#endif
