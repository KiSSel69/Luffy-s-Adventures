#ifndef BULLET_H
#define BULLET_H

#include "map.h"

#include <SFML/Graphics.hpp>

class Bullet : public sf::Drawable {
public:
    Bullet() : isLive(false), xInTexture(0), yInTexture(0), width(0), height(0), maxFlightLength(0),
        damage(0), posX(0), posY(0), speedX(0), dTime(0), scaleX(0), scaleY(0), maxPosX(0), minPosX(0) { };

    Bullet(std::string FilePath, int XInTexture, int YInTexture, int Width, int Height, int Damage, float PosX,
           float PosY, std::vector<Object>& ObjectsOnMap, float SpeedX, int MaxFlightLength = 200, float ScaleX = 0.3, float ScaleY = 0.3);

    ~Bullet() { };

    Bullet &operator=(const Bullet& other);

    bool getIsLive();
    void setIsLive();

    void update();

    void dTimeSet(float dTime);

    int getDamage();

    sf::FloatRect getRect();

private:
    bool isLive;

    sf::Texture texture;
    sf::Sprite sprite;

    int xInTexture;
    int yInTexture;
    int width;
    int height;
    int maxFlightLength;
    int damage;

    float posX;
    float posY;
    float speedX;
    float dTime;

    float scaleX;
    float scaleY;

    int maxPosX;
    int minPosX;

    std::vector<Object> objectsOnMap;

    void collision();
    void draw(sf::RenderTarget& target, sf::RenderStates state) const override final;
};

#endif //BULLET_H

