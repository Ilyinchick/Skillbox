#include <iostream>
#include <ctime>
#include <fstream>

struct position {
    int x, y;
};

struct character {
    std::string name;
    int health;
    int armor;
    int damage;
    position pos;

    std::string type;

    void printStats() {
        std::cout << name << " stats: \n" << "Health: " << health << "\nArmor: " << armor << "\nDamage: " << damage
                  << std::endl << "Position: " << pos.x << " - " << pos.y << std::endl;
    }
};

const std::string path = "C:\\Users\\ailyi\\CLionProjects\\Skillbox\\Skillbox 21\\Skillbox 4\\";

char field[40][40];

character enemy[5];

character player;

void initialize();

void initializeEnemy(int i);

void initializePlayer();

std::string enterStr();

int enterInt();

void fillField();

void initializeEnemyPos(position *pos);

position enterPos();

void printField();

void move();

void enemiesMove();

bool isValidCoordinate(position *pos);

std::string enterCommandMove();

void fight(character *player, character *enemy);

void takeDamage(character *object, int damage);

bool isAlive(character *object);

void moveTo(character *object, int direction);

character *findByPos(position pos);

bool enemiesAlive();

void loadGame();

void loadField();

void loadPlayer();

void loadEnemies();

void saveGame();

void savePlayer();

void saveEnemies();

void saveField();

int main() {
    std::srand(std::time(nullptr));

    fillField();
    initialize();
    while (isAlive(&player) && enemiesAlive()) {
        printField();
        player.printStats();
        move();
    }
    std::cout << "Game over." << std::endl;

    return 0;
}

void initialize() {
    initializePlayer();
    for (int i = 0; i < 5; i++) {
        initializeEnemy(i);
    }
}

void initializeEnemy(int i) {
    character newEnemy;
    position pos;
    newEnemy.name = "Enemy #" + std::to_string(i + 1);
    newEnemy.health = rand() % 101 + 50;
    newEnemy.armor = rand() % 51;
    newEnemy.damage = rand() % 16 + 15;
    initializeEnemyPos(&pos);
    newEnemy.pos = pos;
    newEnemy.type = "Enemy";
    enemy[i] = newEnemy;
}

void initializePlayer() {
    character newPlayer;
    std::cout << "Enter your name: " << std::endl;
    newPlayer.name = enterStr();
    std::cout << "Enter your health: " << std::endl;
    newPlayer.health = enterInt();
    std::cout << "Enter your armor : " << std::endl;
    newPlayer.armor = enterInt();
    std::cout << "Enter your damage: " << std::endl;
    newPlayer.damage = enterInt();
    newPlayer.pos = enterPos();
    field[newPlayer.pos.x][newPlayer.pos.y] = 'P';
    newPlayer.type = "Player";
    player = newPlayer;
}

position enterPos() {
    position pos;
    std::cout << "Enter your position: " << std::endl;
    pos.x = enterInt();
    pos.y = enterInt();
    if (pos.x > 40 || pos.y > 40) {
        std::cout << "Invalid values, try again." << std::endl;
        enterPos();
    } else return pos;
}

std::string enterStr() {
    std::string str;
    std::cin >> str;
    return str;
}

int enterInt() {
    int i;
    std::cin >> i;
    if (i <= 0) {
        std::cout << "Invalid values, try again." << std::endl;
        enterInt();
    } else {
        return i;
    }
}

void initializeEnemyPos(position *pos) {
    int x = rand() % 40, y = rand() % 40;
    if (field[x][y] != '.') {
        initializeEnemyPos(pos);
    } else {
        field[x][y] = 'E';
        pos->x = x;
        pos->y = y;
    }
}

void fillField() {
    for (int i = 0; i < 40; i++) {
        for (int j = 0; j < 40; j++) {
            field[i][j] = '.';
        }
    }
}

void printField() {
    std::cout << std::endl;
    for (int i = 0; i < 40; i++) {
        std::cout << std::endl;
        for (int j = 0; j < 40; j++) {
            std::cout << field[i][j] << " ";
        }
    }
    std::cout << std::endl;
}

void move() {

    std::string command = enterCommandMove();
    if (command == "save" || command == "load") {
        if (command == "save") saveGame();
        else loadGame();
    } else {
        field[player.pos.x][player.pos.y] = '.';
        if (command == "down") moveTo(&player, 3);
        else if (command == "up") moveTo(&player, 1);
        else if (command == "right") moveTo(&player, 2);
        else if (command == "left") moveTo(&player, 0);
        field[player.pos.x][player.pos.y] = 'P';
        enemiesMove();
    }

}

std::string enterCommandMove() {
    std::string command;
    std::cout << "Enter direction to move (right, left, up or down) or save/load game: " << std::endl;
    std::cin >> command;
    if (command == "right" || command == "left" || command == "up" || command == "down" || command == "save" ||
        command == "load") {
        return command;
    } else {
        std::cout << "Invalid command. Try again." << std::endl;
        enterCommandMove();
    }
}

void enemiesMove() {
    for (int i = 0; i < 5; i++) {
        if (isAlive(&enemy[i])) {
            field[enemy[i].pos.x][enemy[i].pos.y] = '.';
            int direction = rand() % 4;
            moveTo(&enemy[i], direction);
            field[enemy[i].pos.x][enemy[i].pos.y] = 'E';
        }
    }
}

bool isValidCoordinate(position *pos) {
    if (pos->x < 0 || pos->x > 40 || pos->y < 0 || pos->y > 40) return false;
    else return true;
}

void fight(character *fPlayer, character *fEnemy) {
    takeDamage(fPlayer, fEnemy->damage);
    takeDamage(fEnemy, fPlayer->damage);
    if (!isAlive(fEnemy)) field[fEnemy->pos.x][fEnemy->pos.y] = '.';
}

void takeDamage(character *object, int damage) {
    object->armor -= damage;
    if (object->armor < 0) {
        object->health += object->armor;
        object->armor = 0;
    }
    if (object->health < 0) object->health = 0;
}

bool isAlive(character *object) {
    if (object->health > 0) return true;
    else return false;
}

void moveTo(character *object, int direction) {
    position newPos = object->pos;
    switch (direction) {
        case 0: {
            newPos.y -= 1;
            break;
        }
        case 1: {
            newPos.x -= 1;
            break;
        }
        case 2: {
            newPos.y += 1;
            break;
        }
        case 3: {
            newPos.x += 1;
            break;
        }
    }
    if (isValidCoordinate(&newPos)) {
        if (field[newPos.x][newPos.y] == '.') object->pos = newPos;
        else if (field[newPos.x][newPos.y] == 'E' && object->type == "Player") {
            fight(&player, findByPos(newPos));
        } else if (field[newPos.x][newPos.y] == 'P' && object->type == "Enemy") {
            fight(object, &player);
        }
    }
}

character *findByPos(position pos) {
    for (int i = 0; i < 5; i++) {
        if (enemy[i].pos.x == pos.x && enemy[i].pos.y == pos.y) return &enemy[i];
    }
    std::cout << "No enemies in this position." << std::endl;
}

bool enemiesAlive() {
    int hp = 0;
    for (int i = 0; i < 5; i++) {
        hp += enemy[i].health;
    }
    if (hp > 0) return true;
    else return false;
}

void saveGame() {
    saveField();
    savePlayer();
    saveEnemies();
}

void loadGame() {
    loadPlayer();
    loadField();
    loadEnemies();
}

void saveEnemies() {
    for (int i = 0; i < 5; i++) {
        std::string newPath = path + enemy[i].name + ".txt";
        std::ofstream stream;
        stream.open(newPath);
        stream << enemy[i].name << std::endl << enemy[i].health << std::endl << enemy[i].armor << std::endl
               << enemy[i].damage << std::endl << enemy[i].pos.x << std::endl << enemy[i].pos.y << std::endl;
        stream.close();
    }
}

void loadEnemies() {
    for (int i = 0; i < 5; i++) {
        std::string newPath = path + enemy[i].name + ".txt";
        std::ifstream stream;
        stream.open(newPath);
        std::getline(stream, enemy[i].name);
        stream >> enemy[i].health  >> enemy[i].armor >> enemy[i].damage >> enemy[i].pos.x >> enemy[i].pos.y;
        stream.close();
    }
}

void saveField() {
    std::string fieldPath = path + "field.txt";
    std::ofstream stream;
    stream.open(fieldPath);
    for (int i = 0; i < 40; i++) {
        for (int j = 0; j < 40; j++) {
            stream << field[i][j];
        }
        stream << std::endl;
    }
    stream.close();
}

void loadField() {
    std::string fieldPath = path + "field.txt";
    char dummy;
    std::ifstream stream;
    stream.open(fieldPath);
    for (int i = 0; i < 40; i++) {
        for (int j = 0; j < 40; j++) {
            stream >> dummy;
            field[i][j] = dummy;
        }
    }
    stream.close();
}

void savePlayer() {
    std::string newPath = path + "player.txt";
    std::ofstream stream;
    stream.open(newPath);
    stream << player.name << std::endl << player.health << std::endl << player.armor << std::endl << player.damage
           << std::endl << player.pos.x << std::endl << player.pos.y;
    stream.close();
}

void loadPlayer() {
    std::string newPath = path + "player.txt";
    std::ifstream stream;
    stream.open(newPath);
    stream >> player.name >> player.health >> player.armor >> player.damage >> player.pos.x >> player.pos.y;
    stream.close();
}