#ifndef ISUBJECT_H
#define ISUBJECT_H

#include "IObserver.h"
#include "VideoEvent.h"

class ISubject {
public:
    virtual ~ISubject() = default;
    virtual void attach(IObserver* obs) = 0;
    virtual void detach(IObserver* obs) = 0;
    virtual void notify(const VideoEvent& event) = 0;
};

#endif