#ifndef MOBILE_SUBSCRIBER_H
#define MOBILE_SUBSCRIBER_H

#include <string>
#include "IObserver.h"

class MobileSubscriber : public IObserver {
public:
    MobileSubscriber(const std::string& username);
    void update(const VideoEvent& event);
    std::string getId() const;

private:
    std::string username_;
};

#endif