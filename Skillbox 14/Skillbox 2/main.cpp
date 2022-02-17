#include <iostream>

void enter(char arr[3][3], bool flag);

bool isValid(bool flag, char symbol);

bool isAvailable(int x, int y, char arr[3][3]);

int isWin (char arr[3][3]);

void print(char arr[3][3]);

int main() {
    int counter = 0;
    bool win = false, flag = true;
    char arr [3][3] = { {' ', ' ', ' '},
                        {' ', ' ', ' '},
                        {' ', ' ', ' '} };

    while (!win && counter < 9) {
        enter(arr, flag);
        flag = !flag;
        print(arr);
        if (isWin(arr) != 0) win = true;
        counter++;
    }
    if (isWin(arr) == 1) std::cout << "X is win";
    else if (isWin(arr) == 2) std::cout << "O is win";
    else std::cout << "Game is over" << std::endl;

    return 0;
}


void enter(char arr[3][3], bool flag) {
    char symbol;
    int x , y;

    do {
        std::cout << "Enter your symbol: ";
        std::cin >> symbol;
        if (symbol != 'X' && symbol != 'O') std::cout << "Incorrect symbol. Try again" << std::endl;
        if (!isValid(flag, symbol)) std::cout << "Not your turn to play" << std::endl;
    } while ((symbol != 'X' && symbol != 'O') || !isValid(flag, symbol));

    do {
        char a, b;

        std::cout << "Enter position:" << std::endl;
        std::cin >> a >> b;
        x = a - 49;
        y = b - 49;

        if (x < 0 || x > 3 || y < 0 || y > 3) {
            std::cout << "Incorrect position. Try again" << std::endl;
            continue;
        }
        if (!isAvailable(x, y, arr)) {
            std::cout << "Position is already filled. Try again" << std::endl;
            continue;
        }
    } while (x < 0 || x > 3 || y < 0 || y > 3 || !isAvailable(x, y, arr));

    arr[x][y] = symbol;
}

bool isAvailable(int x, int y, char arr[3][3]) {
    if (arr[x][y] == ' ') return true;
    else return false;
}

int isWin (char arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        int Xx = 0, Oy = 0, Xy = 0, Ox = 0;
        for (int j = 0; j < 3; j++) {
            if (arr[i][j] == 'X') Xx++;
            if (arr[i][j] == 'O') Oy++;
            if (arr[j][i] == 'X') Xy++;
            if (arr[j][i] == 'O') Ox++;
            if (Xx > 2 || Xy > 2) return 1;
            if (Oy > 2 || Ox > 2) return 2;
        }
    }
    return 0;
}

bool isValid(bool flag, char symbol) {
    if (symbol == 'X' && flag) return true;
    if (symbol == 'O' && !flag) return true;
    return false;
}

void print(char arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << arr[i][j];
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}




