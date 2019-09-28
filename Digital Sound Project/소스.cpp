#include <iostream>
#include <SFML/Audio.hpp>
#include <cmath>
const float PI = 3.141592653589793238463;

using namespace sf;
using namespace std;

//��� ����: �Ҹ� ��ġ �ð�������/�ּ� �Ÿ� �� Attenuation ����
//����: �Ҹ��� �������, �߰����� library Ȯ���ؼ� �� ���� ��

int main()
{
	Listener::setPosition(0.0f, 0.0f, 0.0f);
	Listener::setDirection(0.f, 0.0f, -1.0f);

	sf::SoundBuffer buffer;
	buffer.loadFromFile("mono.wav");

	sf::Sound sound;
	sound.setBuffer(buffer);
	//sound.setLoop(true);
	sound.setMinDistance(8.0f);		//�ּҰŸ� ����
	sound.setAttenuation(1.0f);		//Attenuation ����
	sound.play();

	sf::Vector3f pos;
	float radius = 10.0f;
	float t = 0;
	float angular_velocity = 2 * PI / 4.0f;	//���ӵ� ������ ��

	sf::Clock clock;

	while (true)
	{
		sf::Time dt = clock.restart();

		t += dt.asSeconds() * angular_velocity;

		pos.x = radius * std::cos(t);
		pos.y = 0.f;
		pos.z = radius * std::sin(t);
		
		sound.setPosition(pos);
	}

	sound.stop();
}