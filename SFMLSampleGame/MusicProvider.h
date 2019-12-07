#pragma once
#include"stdafx.h"
#include "IStateOperator.h"

class MusicProvider
{
	Music music;
	vector<string> MenuMusic = { "Menu/M1.ogg" };
	vector<string> GalleryMusic = { "Gallery/G1.ogg", "Gallery/G2.ogg", "Gallery/G3.ogg", "Gallery/G4.ogg", "Gallery/G5.ogg" };
	vector<string> IngameMusic = { "Ingame/I1.ogg", "Ingame/I2.ogg", "Ingame/I3.ogg", "Ingame/I4.ogg", "Ingame/I5.ogg", "Ingame/I6.ogg", "Ingame/I7.ogg", "Ingame/I8.ogg", };
	shared_ptr<IStateOperator<GameState>> MusicOperator;
	MusicProvider();
	void ShuffleAndPlay();
public:
	void play(GameState state);
	void CheckMusicStatus();
	static MusicProvider& instance();
};

