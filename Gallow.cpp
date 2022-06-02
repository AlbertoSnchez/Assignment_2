#include <allegro.h> 
#include "Gallow.h"


Gallow::Gallow(){
    this->theGallow = load_bitmap("Gallow.bmp",NULL);
    this->firMistake = load_bitmap("First.bmp",NULL);
    this->secMistake = load_bitmap("Second.bmp",NULL);
    this->thiMistake = load_bitmap("Third.bmp",NULL);
    this->fouMistake = load_bitmap("Fourth.bmp",NULL);
    this->fifMistake = load_bitmap("Fifth.bmp",NULL);
    this->sixMistake = load_bitmap("Sixth.bmp",NULL);
}

void Gallow::printGallow(){
	draw_sprite(screen,theGallow,200,200);
}

void Gallow::firstMistake(){     
	draw_sprite(screen,firMistake,200,200);
}

void Gallow::secondMistake(){     
	draw_sprite(screen,secMistake,200,200);
}

void Gallow::thirdMistake(){     
	draw_sprite(screen,thiMistake,200,200);
}

void Gallow::fourthMistake(){     
	draw_sprite(screen,fouMistake,200,200);
}

void Gallow::fifthMistake(){
	draw_sprite(screen,fifMistake,200,200);
}

void Gallow::sixthMistake(){
	draw_sprite(screen,sixMistake,200,200);
}
