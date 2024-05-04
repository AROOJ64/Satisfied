#include "Menu.h"
#include<SFML/Graphics.hpp>
#include<iostream>

using namespace std;
using namespace sf;

Menu::Menu(float width, float height, const Font& font)
{
	
	MainMenu[0].setFont(font);
	MainMenu[0].setFillColor(Color::Red);
	MainMenu[0].setString("Start Game");
	MainMenu[0].setCharacterSize(90);
	MainMenu[0].setPosition(Vector2f(170, height / (4) + 130));

	MainMenu[1].setFont(font);
	MainMenu[1].setFillColor(Color::White);
	MainMenu[1].setString("Exit Game");
	MainMenu[1].setCharacterSize(90);
	MainMenu[1].setPosition(Vector2f(170, height / (4) + 350));

	Selected = 0;

}

Menu::~Menu(){}

void Menu::setSelected(int n)
{
	Selected = n;
}

void Menu::draw(RenderWindow& window) {

	for (int i = 0; i < 2; i++) {
		window.draw(MainMenu[i]);
	}
}

void Menu::moveDown() {

	if (Selected + 1 <= 2) {
		MainMenu[Selected].setFillColor(Color::White);
		Selected++;
		if (Selected == 2) {
			Selected = 0;
		}
		MainMenu[Selected].setFillColor(Color::Red);
	}
}

void Menu::moveUp() {

	if (Selected - 1 >= -1) {

		MainMenu[Selected].setFillColor(Color::White);
		Selected--;
		if (Selected == -1) {
			Selected = 1;
		}
		MainMenu[Selected].setFillColor(Color::Red);
	}
}
