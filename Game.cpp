#include "Game.h"

#include<thread>
#include<chrono>
using namespace std;

Game::Game():
 mWindow(sf::VideoMode(600, 600), "Bouncing Ball!"),
 mCircle(10.f)
{
mCircle.setFillColor(sf::Color::Red);
mCircle.move(sf::Vector2f(200.f, 100.f));
//Initial vector value
mMovingVec.x = 2.f;
mMovingVec.y = 2.f;
}

void Game::run(){
	while(mWindow.isOpen()){
		processEvents();
		update();
		render();
	}
}

void Game::processEvents(){
	sf::Event event;
	while (mWindow.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			mWindow.close();
	}
}

void Game::update(){
	if(mMovingVec.x + mCircle.getPosition().x > (mWindow.getSize().x - mCircle.getRadius()) ||
	mMovingVec.x + mCircle.getPosition().x < 0.f) {
		mMovingVec.x = -1* mMovingVec.x;
	}
	if(mMovingVec.y + mCircle.getPosition().y > (mWindow.getSize().y - mCircle.getRadius()) ||
	mMovingVec.y + mCircle.getPosition().y < 0.f) {
		mMovingVec.y = -1* mMovingVec.y;
	}
	mCircle.move(mMovingVec);
}

void Game::render(){
	mWindow.clear();
	mWindow.draw(mCircle);
	mWindow.display();
	//this_thread::sleep_for(chrono::milliseconds(10));
}


