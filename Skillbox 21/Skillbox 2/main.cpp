#include <iostream>
#include <vector>

struct room {
    std::string type = "default";
    int area = 0;
};

struct floor {
    std::vector<room> rooms;
    int height = 0;
};

struct house {
    int area = 0;
    std::vector<floor> floors;
    bool furnace = false;
};

struct building {
    std::string name = "default";
    int area = 0;
    bool furnace = false;
};

struct plot {
    int number = 0;
    house house;
    std::vector<building> otherBuildings;
};

std::vector<plot> village;

int enterInt(int min = 1, int max = 3, bool is_max = false);

void detailPlot(plot& plot);

void detailHouse(house& house);

void detailFloor(floor& floor);

void detailRoom(room& room);

void detailBuilding(building& building);

bool enterFurnace();

int calculateArea();


int main() {
    int area, count;

    std::cout << "Input count of plots in village: " << std::endl;
    count = enterInt(1);

    std::cout << "Let's detail village." << std::endl;

    for (int i = 0; i < count; i++) {
        plot plot;
        detailPlot(plot);
        village.push_back(plot);
    }
    area = calculateArea();
    std::cout << "Total area of buildings in village is " << area << std::endl;

    return 0;
}

int enterInt(int min, int max, bool is_max) {
    int count;
    std::cin >> count;
    if (count >= min) {
        if (is_max && count <= max) return count;
        else if (!is_max) return count;
        else {
            std::cout << "Invalid data. Try again: " << std::endl;
            enterInt(min, max);
        }
    }
    else {
        std::cout << "Invalid data. Try again: " << std::endl;
        enterInt(min, max);
    }
}

void detailPlot(plot& plot) {
    int count;
    detailHouse(plot.house);
    std::cout << "Enter count of other buildings: " << std::endl;
    count = enterInt(0);
    for (int i = 0; i < count; i++) {
        building building;
        detailBuilding(building);
        plot.otherBuildings.push_back(building);
    }
}

bool enterFurnace() {
    std::string furnace;
    std::cin >> furnace;
    if (furnace == "yes") return true;
    else if (furnace == "no") return false;
    else {
        std::cout << "Ivalid answer. Try again: " << std::endl;
        enterFurnace();
    }
}

int calculateArea() {
    int area = 0;
    for (plot p: village) {
        area += p.house.area;
        for (building b: p.otherBuildings) {
            area += b.area;
        }
    }
    return area;
}

void detailHouse(house& house) {
    int count;

    std::cout << "Enter house area: " << std::endl;
    house.area = enterInt(1);

    std::cout << "Enter count of floors (1-3): " << std::endl;
    count = enterInt(1, 3, true);
    for (int i = 0; i < count; i++) {
        floor floor;
        detailFloor(floor);
        house.floors.push_back(floor);
    }
    std::cout << "Is furnace in house? (yes/no)" << std::endl;
    house.furnace = enterFurnace();
}

void detailFloor(floor& floor) {
    int count;
    std::cout << "Enter height of floor: " << std::endl;
    floor.height = enterInt(1);
    std::cout << "Enter count of rooms: " << std::endl;
    count = enterInt(1);
    for (int i = 0; i < count; i++) {
        room room;
        detailRoom(room);
        floor.rooms.push_back(room);
    }
}

void detailRoom(room& room) {
    std::string type;
    std::cout << "Enter type of room: " << std::endl;
    std::cin >> type;
    room.type = type;
    std::cout << "Enter room area: " << std::endl;
    room.area = enterInt(1);
}

void detailBuilding(building& building) {
    std::string type;
    std::cout << "Enter type of building: " << std::endl;
    std::cin >> type;
    building.name = type;
    std::cout << "Enter area of building: " << std::endl;
    building.area = enterInt(1);
    std::cout << "Is furnace here?" << std::endl;
    building.furnace = enterFurnace();
}