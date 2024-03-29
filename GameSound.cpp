
#include "GameSound.h"

using namespace sf;
using namespace std;
void GameSound::create_sound( vector< string>& sound)
{
	for (int i = 0; i < sound.size(); i++){

		m_sound.emplace_back( Sound());
		m_sound[i].setBuffer(AssetManager::GetSoundBuffer(sound[i]));
	}
}

bool GameSound::play(int index, bool loop){

	if (!m_sound.empty()){

		if (m_sound[index].getStatus() ==  SoundSource::Status::Stopped) {

			m_sound[index].setLoop(loop);
			m_sound[index].play();
		}
		else return true;
	}

	return false;
}

void GameSound::stop(int index){

	if (!m_sound.empty()) {

		if (m_sound[index].getStatus() ==  SoundSource::Status::Playing) m_sound[index].stop();
	}
}

void GameSound::all_stop(){

	if (!m_sound.empty()) {

		for (int i = 0; i < m_sound.size(); i++) {

			if (m_sound[i].getStatus() ==  SoundSource::Status::Playing) m_sound[i].stop();
		}
	}
}








