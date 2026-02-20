#ifndef IOBSERVER_H
#define IOBSERVER_H

#include "VideoEvent.h"

class IObserver {
public:
    virtual ~IObserver() = default;
    virtual void update(const VideoEvent& event) = 0;

    // Identifiant lisible pour affichage (username, email, etc.)
    virtual std::string getId() const = 0;
};

#endif