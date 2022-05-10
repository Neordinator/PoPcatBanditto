#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Window/Event.hpp>

#include "../Widgets/Grid/Grid.h"
#include "../StateMashine/StateMashine.h"

class Game : public sf::RenderWindow
{
public:
	Game(const float&, const float&);

    void run();
    const sf::SoundBuffer* thePop();
    const sf::SoundBuffer* theWhu();
    const sf::SoundBuffer* theIllum();

private:
    void handleEvents(sf::RenderWindow&, sf::Event&, StateMashine&);
    void loadResources();

    sf::Event events;

    sf::Font font_cyrilic_old;
    sf::Texture T_background;
    sf::Texture T_frame;

    sf::Texture T_oatmealShut;
    sf::Texture T_oatmealPop;

    sf::Texture T_illuminati;
    sf::Texture T_reptiloid;

    sf::Texture T_muskFace;
    sf::Texture T_muskSmoke;

    sf::SoundBuffer pop;
    sf::SoundBuffer whu;
    sf::SoundBuffer illum;

    std::list<Button*> buttons;
};