#include <cstddef>

#define CONCAT(a,b) a ## b
#define CONCAT2(a,b) CONCAT(a,b)
#define PAD(bytes) char CONCAT2(padding, __LINE__ ) [bytes]

struct Player
{
    PAD(0x54);
    int x_integer;
    int y_integer;
    PAD(0x4);
    double x_decimal;
    double y_decimal;
    double x_velocity;
    double y_velocity;
    PAD(0x7c);
    int hp;
    int hp_max;
    PAD(0x24);
    int violet_skill;
    int red_skill;
    int green_skill;
    PAD(0x204);
    int cells;
};
static_assert(offsetof(Player, x_integer) == 0x54);
static_assert(offsetof(Player, y_integer) == 0x58);
static_assert(offsetof(Player, x_decimal) == 0x60);
static_assert(offsetof(Player, y_decimal) == 0x68);
static_assert(offsetof(Player, x_velocity) == 0x70);
static_assert(offsetof(Player, y_velocity) == 0x78);
static_assert(offsetof(Player, hp) == 0xfc);
static_assert(offsetof(Player, hp_max) == 0x100);
static_assert(offsetof(Player, violet_skill) == 0x128);
static_assert(offsetof(Player, red_skill) == 0x12c);
static_assert(offsetof(Player, green_skill) == 0x130);
static_assert(offsetof(Player, cells) == 0x338);

struct Record
{
    PAD(0x20);
    double timePassed;
    PAD(0x4);
    int coin;
    PAD(0x20);
    int killWithoutBeingHitNow;
    int killWithoutBeingHitMax;
};
static_assert(offsetof(Record, timePassed) == 0x20);
static_assert(offsetof(Record, coin) == 0x2c);
static_assert(offsetof(Record, killWithoutBeingHitNow) == 0x50);
static_assert(offsetof(Record, killWithoutBeingHitMax) == 0x54);

struct Game
{
    PAD(0x5c);
    Record* record;
    PAD(0x4);
    Player* player;
};
static_assert(offsetof(Game, record) == 0x5c);
static_assert(offsetof(Game, player) == 0x64);