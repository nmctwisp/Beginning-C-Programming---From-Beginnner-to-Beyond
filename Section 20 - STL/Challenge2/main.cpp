#include "Song.h"
#include <list>
#include <algorithm>
#include <iterator>
#include <string>
#include <cctype>
#include <iomanip>
#include <sstream>
#include <limits>


void display_menu() {
	std::cout << "\nF - Play First Song" << std::endl;
	std::cout << "N - Play Next song" << std::endl;
	std::cout << "P - Play Previous song" << std::endl;
	std::cout << "A - Add and play a new Song at current location" << std::endl;
	std::cout << "L - List the current playlist" << std::endl;
	std::cout << "===============================================" << std::endl;
	std::cout << "Enter a selection (Q to quit): ";
}

void play_current_song(const Song &song) {
	// This function should display 
	// Playing: followed by the song that is playing

	std::cout << "Now Playing: " << song << std::endl;
}

void display_playlist(const std::list<Song> &playlist, const Song &current_song) {
	// This function should display the current playlist 
	// and then the current song playing.

	std::cout << std::setw(30) << "Playlist" << std::endl;
	std::cout << std::setw(62) << std::setfill('-') << '\n';

	for (const Song& track : playlist)
		std::cout << std::setfill(' ')
			<< std::setw(30) << std::left << track.get_name()
			<< std::setw(30) << track.get_artist()
			<< std::setw(1) << track.get_rating() << std::endl;
	
	std::cout << '\n' << std::setw(30) << std::right << "Currently Playing" << std::endl;
	std::cout << std::setw(62) << std::setfill('-') << '\n';
	std::cout << std::setw(22) << std::setfill(' ') 
		<< current_song.get_name() << " by " << current_song.get_artist() << std::endl;
}


int main() {

	std::list<Song> playlist{
			{"God's Plan",        "Drake",                     5},
			{"Never Be The Same", "Camila Cabello",            5},
			{"Pray For Me",       "The Weekend and K. Lamar",  4},
			{"The Middle",        "Zedd, Maren Morris & Grey", 5},
			{"Wait",              "Maroone 5",                 4},
			{"Whatever It Takes", "Imagine Dragons",           3}
	};

	std::list<Song>::iterator current_song = playlist.begin();
	std::string action;
	

	display_menu();
	do {
		std::getline(std::cin, action);
		switch (std::tolower(action.front())) {
			case 'f':
			case 'F':
				current_song = playlist.begin();
				play_current_song(*current_song);
				break;
			case 'n':
			case 'N':
				if (current_song->get_name() == playlist.back().get_name())
					current_song = playlist.begin();

				std::advance(current_song, 1);
				play_current_song(*current_song);
				break;
			case 'p':
			case 'P':
				if (current_song->get_name() == playlist.front().get_name())
					current_song = playlist.end();

				std::advance(current_song, -1);

				play_current_song(*current_song);
				break;
			case 'a':
			case 'A':{
				std::string new_artist;
				std::string new_song;
				int new_rating;
				std::cout << "Enter the song name: ";
				std::getline(std::cin, new_song);
				std::cout << "Enter the song artist: ";
				std::getline(std::cin, new_artist);
				std::cout << "Enter the song rating: ";
				std::cin >> new_rating;
				
				playlist.emplace(current_song, new_song, new_artist, new_rating);
				
				break;
			}
			case 'l':
			case 'L':
				display_playlist(playlist, *current_song);
		}
		// Discarding the Input Buffer
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		display_menu();
	} while ((action != "Q") && (action != "Quit") && (action != "q") && (action != "quit"));

	std::cout << "Thanks for listening!" << std::endl;
	return 0;
}