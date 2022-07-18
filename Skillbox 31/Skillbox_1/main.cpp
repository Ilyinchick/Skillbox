#include <iostream>

class Toy {
private:
    std::string name;

public:
    Toy(std::string _name) : name(_name) {};

    Toy() : name("Emty_Name") {};

    std::string getName() {
        return name;
    }

    Toy& operator=(const Toy& oth) {
        if (this == &oth) return *this;
        name = oth.name;
        return *this;
    }
};

class Count {
private:
    int count;
public:
    Count(int i) : count(i) {};

    Count() : count(0) {};

    void inc() {
        count += 1;
    }

    void dec() {
        count -= 1;
    }

    int get() {
        return count;
    }

    Count &operator=(const Count &oth) {
        if (this == &oth) return *this;
        count = oth.count;
        return *this;
    }

};

class Shared_ptr_toy {

private:
    Toy *ptr_toy;
    Count *refs;

public:

    Shared_ptr_toy(std::string name) {
        ptr_toy = new Toy(name);
        refs = new Count(1);
    }

    Shared_ptr_toy(Toy* toy) {
        ptr_toy = toy;
        refs = new Count(1);
    }

    Shared_ptr_toy(const Shared_ptr_toy &oth) {
        ptr_toy = oth.ptr_toy;
        oth.refs->inc();
        refs = oth.refs;
    }

    static Shared_ptr_toy *makeShared(std::string name) {
        return new Shared_ptr_toy(name);
    }

    static Shared_ptr_toy *makeShared(const Shared_ptr_toy &oth) {
        oth.refs->inc();
        return new Shared_ptr_toy(oth);
    }

//    void deletePtr() {
//        delete ptr_toy;
//    }

    Shared_ptr_toy &operator=(const Shared_ptr_toy &oth) {
        if (this == &oth) return *this;
        if (ptr_toy != nullptr) {
            refs->dec();
            delete ptr_toy;
        }
        oth.refs->inc();
        ptr_toy = oth.ptr_toy;
        refs = oth.refs;
        return *this;
    }

    ~Shared_ptr_toy() {
        refs->dec();
        if (refs->get() <= 0) {
            std::cout << "Delete " << ptr_toy->getName() << std::endl;
            ptr_toy = nullptr;
            delete ptr_toy;
        }
        refs = nullptr;
        delete refs;
    }
};


class Dog {
private:
    std::string name;
    int age;
    Shared_ptr_toy lovely_toy;

public:

    Dog(std::string _name, int _age, Shared_ptr_toy* lovely) : name(_name), age(_age), lovely_toy(*lovely) {}

    void setLovely(Shared_ptr_toy* lovely) {
        lovely_toy = *lovely;
    }


};


int main() {

    Toy* tBall = new Toy("Ball");
    Toy* tBone = new Toy("Bone");


    Shared_ptr_toy* ball = new Shared_ptr_toy(tBall);
    Shared_ptr_toy* bone = new Shared_ptr_toy(tBone);

    Dog* d1 = new Dog("D1", 14, ball);
    Dog* d2 = new Dog("D2", 12, ball);
    Dog* d3 = new Dog("D3", 14, bone);
    Dog* d4 = new Dog("D4", 12, ball);
    Dog* d5 = new Dog("D5", 14, bone);
    Dog* d6 = new Dog("D6", 12, ball);

    d3->setLovely(ball);
    d5->setLovely(ball);


    delete bone;

    std::cout << "Hello" << std::endl;

    return 0;
}
