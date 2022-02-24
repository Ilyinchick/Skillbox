#include <iostream>
#include <fstream>
#include <vector>

const std::string path = "C:\\Users\\ailyi\\CLionProjects\\Skillbox\\Skillbox 19\\Skillbox 5\\";

std::ifstream stream;

int players = 0, spectators = 0, position = 1;

bool questions[13];


bool isFileOpened(std::string path);

std::vector<std::string> getData(std::string path);

void printData(std::vector<std::string> data);

std::string enterStr();

bool answerCompare(std::string answer, std::string rightAnswer);

std::string getRightAnswer(std::string path);

std::string getQuestionPath(int pos);

std::string getAnswerPath(int pos);

void printScore();

bool isGameOver();

void fillquestions();

void enterPos();

void calculatePos(int offset = 1);

int main() {
    fillquestions();

    for (int i = 0; i < 13; i ++) {

        if (isGameOver()) break;
        enterPos();
        if (isFileOpened(getQuestionPath(position))) {
            std::cout << "Question " << position << "." << std::endl;
            printData(getData(getQuestionPath(position)));
            questions[position - 1] = false;
            if (answerCompare(enterStr(), getRightAnswer(getAnswerPath(position))) ) {

                std::cout << "Right answer! Well done!" << std::endl;
                players++;
            } else {
                std::cout << "Wrong answer! Better luck next time." << std::endl;
                spectators++;
            }
            printScore();

        } else {
            std::cout << "File is not opened, incorrect path." << std::endl;
        }

    }
    std::cout << "Game is over!" << std::endl;
    if (players == 6) {
        std::cout << "Congratulations to players!" << std::endl;
    } else {
        std::cout << "Congratulations to spectators!" << std::endl;
    }

    return 0;
}

bool isFileOpened(std::string path) {
    stream.open(path);
    bool flag;
    if (stream.is_open()) flag = true;
    else flag = false;
    stream.close();
    return flag;
}

std::vector<std::string> getData(std::string path) {
    std::vector <std::string> data;
    std::string strDummy;
    stream.open(path);
    while (!stream.eof()) {
        std::getline(stream, strDummy);
        data.push_back(strDummy);
    }
    stream.close();
    return data;
}

void printData(std::vector<std::string> data) {
    for (std::string s: data) {
        std::cout << s << std::endl;
    }
}

std::string enterStr() {
    std::string str;
    std::cout << "Enter your answer: " << std::endl;
    std::getline(std::cin, str);
    return str;
}

bool answerCompare(std::string answer, std::string rightAnswer) {
    for (int i = 0; i < answer.length(); i++) {
        if (answer[i] != rightAnswer[i]) return false;
    }
    return true;
}

std::string getRightAnswer(std::string path) {
    std::string rightAnswer;
    stream.open(path);
    if (stream.is_open()) {
         std::getline(stream, rightAnswer);
    } else {
        std::cout << "File with right answer not opened. Incorrect path." << std::endl;
    }
    stream.close();
    return rightAnswer;
}

std::string getQuestionPath(int pos) {
    std::string questionPath = path;
    questionPath += std::to_string(pos) + "q.txt";
    return questionPath;
}

std::string getAnswerPath(int pos) {
    std::string answerPath = path;
    answerPath += std::to_string(pos) + "a.txt";
    return answerPath;
}

void printScore() {
    std::cout << "Score is: " << players << " - " << spectators << std::endl;
}

bool isGameOver() {
    if (players == 6 || spectators == 6) return true;
    else return false;
}

void fillquestions() {
    for (int i = 0; i < 13; i ++) {
        questions[i] = true;
    }
}

void enterPos() {
    std::string str;
    int offset;
    std::cout << "Enter offset: " << std::endl;
    std::getline(std::cin, str);
    offset = std::stoi(str);
    calculatePos(offset);

    while (!questions[position - 1]) {
        std::cout << "Question " << position << " is already answered. Recalculate..." << std::endl;
        calculatePos();
    }
}

void calculatePos(int offset) {
    if (position + offset > 13) {
        offset -= 13;
        calculatePos(offset);
    } else {
        position += offset;
    }
}
