#include <iostream>

void fillArr(char arr[10][10]);

void printArr(char arr[10][10]);

void placeOne(char arr[10][10]);

void placeLong(char arr[10][10], int length);

bool ifAvailable(char arr[10][10], int x1, int y1, int x2, int y2);

bool ifAvailable(char arr[10][10], int x, int y);

bool ifCorrectPlace(int x1, int y1, int x2, int y2);

void placeShips(char arr[10][10]);

bool shoot(char arr[10][10]);

bool isPlayerWin(char arr[10][10]);

void blindPrint(char arr[10][10]);

int inputCoordinate();

int main() {
    char arr1[10][10], arr2[10][10];

    fillArr(arr1);
    fillArr(arr2);

    std::cout << "Player 1 lands ships..." << std::endl;
    placeShips(arr1);
    std::cout << "Complete. Next turn." << std::endl;

    std::cout << "Player 2 lands ships..." << std::endl;
    placeShips(arr2);
    std::cout << "Complete." << std::endl;

    bool flag = true;
    while (!isPlayerWin(arr1) && !isPlayerWin(arr2)) {
        if (flag) {
            std::cout << "Player 1 shoots...";
            do {
                if (!shoot(arr2)) flag = !flag;
                else if (isPlayerWin(arr2)) break;
                blindPrint(arr2);
            } while (flag);
        } else {
            std::cout << "Player 2 shoots...";
            do {
                if (!shoot(arr1)) flag = !flag;
                else if (isPlayerWin(arr1)) break;
                blindPrint(arr1);
            } while (!flag);
        }
    }
    if (isPlayerWin(arr2)) std::cout << "Player 1 win!";
    else std::cout << "Player 2 win!";

    return 0;
}


void fillArr(char arr[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            arr[i][j] = ' ';
        }
    }
}

void printArr(char arr[10][10]){
    std::cout << std::endl;
    for (int i = 0; i < 10; i++) {
        std::cout << "|";
        for (int j = 0; j < 10; j++) {
            if (arr[i][j] != ' ') std::cout << arr[i][j] << "|";
            else std::cout << " |";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void placeOne(char arr[10][10]) {
    int x, y;
    std::cout << "Input coordinates for 1-mast ship: ";

    x = inputCoordinate();
    y = inputCoordinate();

    if (ifAvailable(arr, x, y)) {
        arr[x][y] = 'o';
        printArr(arr);
    }
    else {
        std::cout << "Incorrect coordinates, try again." << std::endl;
        placeOne(arr);
    }
}

void placeLong(char arr[10][10], int length) {
    int x1, y1, x2, y2;
    std::cout << "Input coordinates for " << length << "-mast ship: ";

    x1 = inputCoordinate();
    y1 = inputCoordinate();
    x2 = inputCoordinate();
    y2 = inputCoordinate();

    if (ifAvailable(arr, x1, y1, x2, y2) && ifCorrectPlace(x1, y1, x1, y2) && (y2 - y1 == length-1 || x2 - x1 == length-1)) {
        if (x1 == x2) {
            for (int i = y1; i <= y2; i++) {
                arr[x1][i] = 'o';
            }
        } else {
            for (int i = x1; i <= x2; i++) {
                arr[i][y1] = 'o';
            }
        }
        printArr(arr);
    } else {
        std::cout << "Incorrect coordinates, try again." << std::endl;
        placeLong(arr, length);
    }
}

void placeShips(char arr[10][10]) {
    for (int i = 0; i < 4; i++) {
        placeOne(arr);
    }
    for(int i = 0; i < 3; i++) {
        placeLong(arr, 2);
    }
    for (int i = 0; i < 2; i ++) {
        placeLong(arr, 3);
    }
    placeLong(arr, 4);
}

bool shoot(char arr[10][10]) {
    int x, y;
    std::cout << "Enter coordinates to shoot: ";

    x = inputCoordinate();
    y = inputCoordinate();

    if (arr[x][y] == 'o') {
        std::cout << "Hit!" << std::endl;
        arr[x][y] = 'H';
        return true;
    } else if (arr[x][y] == 'X' || arr[x][y] == 'H' ) {
        std::cout << "Incorrect coordinates. Try again." << std::endl;
        shoot(arr);
    } else {
        std::cout << "Miss." << std::endl;
        arr[x][y] = 'X';
        std::cout << "Next player turn." << std::endl;
        return false;
    }
}

bool ifCorrectPlace(int x1, int y1, int x2, int y2) {
    if (x1 == x2 || y1 == y2) return true;
    else return false;
}

bool ifAvailable(char arr[10][10], int x, int y) {
    if (arr[x][y] == ' ') return true;
    else return false;
}

bool ifAvailable(char arr[10][10], int x1, int y1, int x2, int y2) {
    if (x1 == x2) {
        for (int i = y1; i < y2; i++) {
            if (arr[x1][i] != ' ') return false;
        }
    } else {
        for (int i = y1; i < y2; i++) {
            if (arr[i][y1] != ' ') return false;
        }
    }
    return true;
}

bool isPlayerWin(char arr[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (arr[i][j] == 'o') return false;
        }
    }
    return true;
}

void blindPrint(char arr[10][10]) {
    std::cout << std::endl;
    for (int i = 0; i < 10; i++) {
        std::cout << "|";
        for (int j = 0; j < 10; j++) {
            if (arr[i][j] == ' ' || arr[i][j] == 'o') std::cout << " |";
            else std::cout << arr[i][j] << "|";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int inputCoordinate() {
    char a;
    int coordinate;
    std::cin >> a;
    if (a < 48 || a > 57) {
        std::cout << "Incorrect symbol, try again." << std::endl;
        inputCoordinate();
    } else {
        coordinate = a - 48;
        return coordinate;
    }
}