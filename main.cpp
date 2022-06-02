#include <allegro.h> 
#include <winalleg.h>
#include "Gallow.h" 
#include <iostream>
#include <windows.h>
#include <MMSystem.h>
#include <string.h>    
#include <time.h>    


 
void init();
void deinit();

int main() {
	//PlaySound(TEXT("Minoru.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
	/*MIDI *music;
	music = load_midi("Minoru 187  Gaming Background Music HD.mid");
	play_midi(music,true);*/
	MessageBox(NULL, "Welcome to Hangman!\nBasically you have to guess the word\nby typing letters, but you have limited\nchances, five to be precise. Every time\nyou type a wrong letter, a part of the\nhangman is going to be drawn\nif it's complety drawn you lose\nbut if you can guess it before that, win!!\n\nBy the end, if you wanna keep playing\njust press any key\n\nKey instructions:\n   -Type a letter              (every letter)\n   -Turn off the music   (ctrl+m)\n   -Exit		       (esc)\n   -Help		       (ctrl+h)", "Hangman", MB_OK | MB_DEFBUTTON2);
	char letter, word[30], attempt[30], letters[32], aux[2];
	int mistakes, i;
	bool right, musicOn = true; 
	char words [10][30]={"dictionary","thunderstorm","meanwhile","satisfactory","waterfall","primary school","fortunately","yesterday","parking lot","good afternoon"};
	init();
	srand(time(NULL));
	Gallow *gallow = new Gallow();
	while (!key[KEY_ESC]) {
		/* put your code here */
		strcpy(word, words[rand()%10]);
		mistakes = 0;
		strcpy(letters,"");    
		for (i=1; i<=strlen(word); i++){
			if (word[i-1]==32)
		      attempt[i-1]=32;
		    else
		      attempt[i-1]=95;
		}
		attempt[i-1]='\0';        
		do {
			clear_bitmap(screen);
			gallow->printGallow();
			switch(mistakes){
		    	case 1: gallow->firstMistake();
		    	break;
		    	case 2: gallow->secondMistake();
		    	break;
		    	case 3: gallow->thirdMistake();
		    	break;
		    	case 4: gallow->fourthMistake();
		    	break;
		    	case 5: gallow->fifthMistake();
		    	break;
			}		     
		    textprintf(screen, font, 228,35, palette_color[14],"You have %d/6 mistakes", mistakes);
			textprintf(screen, font, 228,62, palette_color[15],attempt);                         
		    textprintf(screen, font, 100,115, palette_color[11],"You've tried this letters: %s", letters);
	    	textprintf(screen, font, 100,138, palette_color[12],"Type in one letter");
		    letter = readkey()&0xff;
		    if ((key[KEY_LCONTROL] || key[KEY_RCONTROL]) && key[KEY_H])
		    	MessageBox(NULL, "Welcome to Hangman!\nBasically you have to guess the word\nby typing letters, but you have limited\nchances, five to be precise. Every time\nyou type a wrong letter, a part of the\nhangman is going to be drawn\nif it's complety drawn you lose\nbut if you can guess it before that, win!!\n\nBy the end, if you wanna keep playing\njust press any key\n\nKey instructions:\n   -Type a letter              (every letter)\n   -Turn off the music   (ctrl+m)\n   -Exit		       (esc)\n   -Help		       (ctrl+h)", "Hangman", MB_OK | MB_DEFBUTTON2);
			if ((key[KEY_LCONTROL] || key[KEY_RCONTROL]) && key[KEY_M])
				if (musicOn){
					musicOn = false;
					PlaySound(NULL,0,0);
				} else{
					musicOn = true;
					PlaySound(TEXT("Minoru.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
				}
			else{
				strcpy (aux," "); 
			    aux[0]= letter;
			    strcat (letters, aux);
			    strcat (letters, "-");
			    right = 0;     
			    for (i=1; i<=strlen(word); i++)
			    	if(tolower(letter)== tolower(word[i-1])){
					  attempt[i-1]= word[i-1];
					  right = true;
					}
			    if (!right)  
			      mistakes ++;
			}
		    
		}while ( strcmp (attempt,word) && (mistakes<6) && !key[KEY_ESC]);   
		
		if ( strcmp (attempt,word)==0){
			textprintf(screen, font, 100,161, palette_color[9],"YOU WIN!!");
			textprintf(screen, font, 100,184, palette_color[9],"The word was: %s", word);
		}
		else{
			textprintf(screen, font, 100,161, palette_color[10],"Sorry, the word was: %s", word);
		    gallow->sixthMistake();
		}
		readkey();
	}
	deinit();
	allegro_exit();
	return 0;
}
END_OF_MAIN()

void init() {
	int depth, res;
	allegro_init();
	depth = desktop_color_depth();
	if (depth == 0) depth = 32;
	set_color_depth(depth);
	res = set_gfx_mode(GFX_AUTODETECT_WINDOWED, 640, 480, 0, 0);
	if (res != 0) {
		allegro_message(allegro_error);
		exit(-1);
	}

	install_timer();
	install_keyboard();
	install_sound(DIGI_AUTODETECT,MIDI_AUTODETECT,NULL);
	//install_mouse();
	/* add other initializations here */
}

void deinit() {
	clear_keybuf();
	/* add other deinitializations here */
}
