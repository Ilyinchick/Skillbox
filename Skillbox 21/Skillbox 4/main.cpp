#include <iostream>
#include <ctime>

struct position {
    int x, y, min = 0, max = 40;
};

struct character {
    std::string name;
    int health;
    int armor;
    int damage;
    position pos;
};

char field[40][40];

character enemy[5];

character player;

void initialize();

void initializeEnemy(int i);

void initializePlayer();

std::string enterStr();

int enterInt();

void fillField();

void initializeEnemyPos(position* pos);

position enterPos();

void printField();

int main() {
    std::srand(std::time(nullptr));
    fillField();
    initialize();
    printField();

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
    newEnemy.name = "Enemy #" + std::to_string(i+1);
    newEnemy.health = rand() % 101 + 50;
    newEnemy.armor = rand() % 51;
    newEnemy.damage = rand() % 16 + 15;
    initializeEnemyPos(&pos);
    newEnemy.pos = pos;
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
    } else  return pos;
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

void initializeEnemyPos(position* pos) {
    int x = rand() % 40, y = rand() % 40;
    if (field[x][y] != '.') {
        initializeEnemyPos(pos);
    } else {
        field[x][y] = 'E';
        pos -> x = x;
        pos -> y = y;
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