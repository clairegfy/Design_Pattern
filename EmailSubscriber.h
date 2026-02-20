#ifndef EMAIL_SUBSCRIBER_H
#define EMAIL_SUBSCRIBER_H

#include <string>
#include "IObserver.h"

class EmailSubscriber : public IObserver {
public:
    EmailSubscriber(const std::string& email);
    void update(const VideoEvent& event);
    std::string getId() const;

private:
    std::string email_;
};

#endif