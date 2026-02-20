#ifndef CHANNEL_H
#define CHANNEL_H

#include <string>
#include <vector>
#include "ISubject.h"
#include "VideoEvent.h"
#include "IObserver.h"

class Channel : public ISubject {
public:
    Channel(const std::string& name);

    void attach(IObserver* obs);
    void detach(IObserver* obs);
    void notify(const VideoEvent& event);

    void publish(const std::string& title, const std::string& type);
    std::string getName() const;

private:
    std::string name_;
    std::vector<IObserver*> observers_; // pointeurs non possédés (gérés dans main)
};

#endif