observer_demo: main.o Channel.o MobileSubscriber.o EmailSubscriber.o
	g++ -std=c++11 -Wall main.o Channel.o MobileSubscriber.o EmailSubscriber.o -o observer_demo

main.o: main.cpp Channel.h MobileSubscriber.h EmailSubscriber.h
	g++ -std=c++11 -Wall -c main.cpp

Channel.o: Channel.cpp Channel.h ISubject.h IObserver.h VideoEvent.h
	g++ -std=c++11 -Wall -c Channel.cpp

MobileSubscriber.o: MobileSubscriber.cpp MobileSubscriber.h IObserver.h VideoEvent.h
	g++ -std=c++11 -Wall -c MobileSubscriber.cpp

EmailSubscriber.o: EmailSubscriber.cpp EmailSubscriber.h IObserver.h VideoEvent.h
	g++ -std=c++11 -Wall -c EmailSubscriber.cpp

clean:
	rm -f *.o observer_demo