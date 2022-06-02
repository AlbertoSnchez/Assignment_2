#ifndef Gallow_h
#define Gallow_h
#include <allegro.h> 

class Gallow {    
public:
	BITMAP *theGallow, *firMistake, *secMistake, *thiMistake, *fouMistake, *fifMistake, *sixMistake;
	
    Gallow();
    
    void printGallow();
    void firstMistake();
	void secondMistake();
	void thirdMistake();
	void fourthMistake();
	void fifthMistake();
	void sixthMistake();
};

#endif
