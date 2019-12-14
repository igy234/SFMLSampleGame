#pragma once
#include"stdafx.h"
#include "IStateOperator.h"
//start of existing at the begining of the program and end of existing at the end of the program
///Singleton class managing soundtrack of application 
class MusicProvider
{
	///holding music
	Music music;

	///vector of strings holding paths and names of menu music files
	vector<string> MenuMusic = { "Menu/M1.ogg" };

	///vector of strings holding paths and names of gallery music files
	vector<string> GalleryMusic = { "Gallery/G1.ogg", "Gallery/G2.ogg", "Gallery/G3.ogg", "Gallery/G4.ogg", "Gallery/G5.ogg" };

	///vector of strings holding paths and names of Ingame music files
	vector<string> IngameMusic = { "Ingame/I1.ogg", "Ingame/I2.ogg", "Ingame/I3.ogg", "Ingame/I4.ogg", "Ingame/I5.ogg", "Ingame/I6.ogg", "Ingame/I7.ogg", "Ingame/I8.ogg", };

	///Attribute used for managing the states in which different musics should be played
	shared_ptr<IStateOperator<GameState>> MusicOperator;

	///@brief constrctuor setting first state as menu state and ascribing MusicOperator attribute
	MusicProvider();

	///@brief method checking in which state game currently is and choosing appropriate track list, choosing random music to play for given state and loading it
	void ShuffleAndPlay();
public:
	///@brief method checking if state changed, if yes then changing to new state and shuffling for new song, if not then continues playing current song 
	///@param "state" representing state of the program
	void play(GameState state);

	///@brief method checking if given track ended, if yes then shuffling for new track
	void CheckMusicStatus();

	///@brief creation of static instance of music provider
	///@return static instance of music provider
	static MusicProvider& instance();
};

