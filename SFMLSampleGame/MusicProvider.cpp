#include "stdafx.h"
#include "MusicProvider.h"
#include "Utils.h"
#include "StateOperator.h"

MusicProvider::MusicProvider()
	:MusicOperator(make_shared<StateOperator<GameState>>())
{
	MusicOperator->SetNewState(GameState::Menu);
}

void MusicProvider::ShuffleAndPlay()
	
{
	vector<string> TracksToPlay;
	switch (MusicOperator->GetCurrentState())
	{
	case GameState::Menu:
		TracksToPlay = MenuMusic;
		break;
	case GameState::Deck:
		TracksToPlay = GalleryMusic;
		break;
	case GameState::Play:
		TracksToPlay = IngameMusic;
		break;
	}
	int track = getRand(TracksToPlay.size());

	if (!music.openFromFile("Resources/Audio/" + TracksToPlay[track]))
	{
		cerr << "Error while loading music" << endl; //error handling
		system("pause");
	}

	music.play();
}

void MusicProvider::play(GameState state)
{
	if (state == MusicOperator->GetCurrentState())
		return;
	MusicOperator->SetNewState(state);
	ShuffleAndPlay();
}

void MusicProvider::CheckMusicStatus()
{
	if (music.getStatus() == SoundSource::Status::Stopped)
	{
		ShuffleAndPlay();
	}
}

MusicProvider& MusicProvider::instance()
{
	static MusicProvider INSTANCE;
	return INSTANCE;
}