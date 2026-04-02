#ifndef DOMAINEVENTS_CLASS_H
#define DOMAINEVENTS_CLASS_H

#include <QObject>
#include <QString>
#include <QDateTime>

#include <core/domain/Subject.h>
#include <core/domain/Session.h>
#include <core/domain/Task.h>



class DomainEvents final : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY_MOVE(DomainEvents)

public:
    static DomainEvents& instance();

    // ── Subject related ──────────────────────────────────────────────
    void emitSubjectCreated(const Subject& subject);
    void emitSubjectUpdated(const Subject& subject);
    void emitSubjectDeleted(int subjectId, const QString& subjectName = {});

    // ── Session related ──────────────────────────────────────────────
    void emitSessionCreated(const Session& session);
    void emitSessionUpdated(const Session& session);
    void emitSessionDeleted(int sessionId, int subjectId);

    // ── Task related ──────────────────────────────────────────────
    void emitTaskCreated(const Task& task);
    void emitTaskUpdated(const Task& task);
    void emitTaskDeleted(int taskId, int subjectId);

signals:
    // Subject events
    void subjectCreated(const Subject& subject);
    void subjectUpdated(const Subject& subject);
    void subjectDeleted(int subjectId, QString subjectName);

    // Session events
    void sessionCreated(const Session& session);
    void sessionUpdated(const Session& session);
    void sessionDeleted(int sessionId, int subjectId);

    // Session events
    void taskCreated(const Task& task);
    void taskUpdated(const Task& task);
    void taskDeleted(int taskId, int subjectId);


private:
    DomainEvents() = default;
    ~DomainEvents() = default;
};


inline DomainEvents& DomainEvents::instance()
{
    static DomainEvents inst;
    return inst;
}

inline void DomainEvents::emitSubjectCreated(const Subject& subject)
{
    emit subjectCreated(subject);
}

inline void DomainEvents::emitSubjectUpdated(const Subject& subject)
{
    emit subjectUpdated(subject);
}

inline void DomainEvents::emitSubjectDeleted(int subjectId, const QString& subjectName)
{
    emit subjectDeleted(subjectId, subjectName);
}

inline void DomainEvents::emitSessionCreated(const Session& session)
{
    emit sessionCreated(session);
}

inline void DomainEvents::emitSessionUpdated(const Session& session)
{
    emit sessionUpdated(session);
}

inline void DomainEvents::emitSessionDeleted(int sessionId, int subjectId)
{
    emit sessionDeleted(sessionId, subjectId);
}

inline void DomainEvents::emitTaskCreated(const Task& task)
{
    emit taskCreated(task);
}

inline void DomainEvents::emitTaskUpdated(const Task& task)
{
    emit taskUpdated(task);
}

inline void DomainEvents::emitTaskDeleted(int sessionId, int subjectId)
{
    emit taskDeleted(sessionId, subjectId);
}

#endif
