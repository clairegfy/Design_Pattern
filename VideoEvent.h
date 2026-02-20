#ifndef VIDEO_EVENT_H
#define VIDEO_EVENT_H

#include <string>


class VideoEvent {
public :
    std::string channelName;
    std::string title;
    std::string type; //Vidéo ou Live
};

#endif