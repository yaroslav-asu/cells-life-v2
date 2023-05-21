#ifndef CELLS_LIVE_GAME_SCREEN_H
#define CELLS_LIVE_GAME_SCREEN_H


class GameScreen {
public:
    virtual void render(sf::RenderTarget &);
    virtual void update();
};


#endif //CELLS_LIVE_GAME_SCREEN_H
