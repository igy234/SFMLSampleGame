#pragma once
#include"stdafx.h"
#include "IStateOperator.h"

class MusicProvider
{
	Music music;
	vector<string> MenuMusic = { "Menu/M1.wav" };
	vector<string> GalleryMusic = { "Gallery/G1.wav", "Gallery/G2.wav", "Gallery/G3.wav", "Gallery/G4.wav", "Gallery/G5.wav" };
	vector<string> IngameMusic = { "Ingame/I1.wav", "Ingame/I2.wav", "Ingame/I3.wav", "Ingame/I4.wav", "Ingame/I5.wav", "Ingame/I6.wav", "Ingame/I7.wav", "Ingame/I8.wav", };
	shared_ptr<IStateOperator<GameState>> MusicOperator;
	MusicProvider();
	void ShuffleAndPlay();
public:
	void play(GameState state);
	void CheckMusicStatus();
	static MusicProvider& instance();
};

