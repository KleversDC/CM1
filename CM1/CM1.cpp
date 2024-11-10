#include <iostream>
using namespace std;

class Reservoir {
private:
    char* name;
    char* type; // тип водойми (наприклад, "море", "ставок", "басейн")
    double width;
    double length;
    double maxDepth;

    int stringLength(const char* str) const {
        int length = 0;
        while (str[length] != '\0') {
            ++length;
        }
        return length;
    }

    void stringCopy(char* dest, const char* src) const {
        while (*src) {
            *dest++ = *src++;
        }
        *dest = '\0';
    }

public:
    Reservoir() : name(nullptr), type(nullptr), width(0), length(0), maxDepth(0) {}

    Reservoir(const char* name, const char* type, double width, double length, double maxDepth)
        : width(width), length(length), maxDepth(maxDepth) {
        this->name = new char[stringLength(name) + 1];
        stringCopy(this->name, name);

        this->type = new char[stringLength(type) + 1];
        stringCopy(this->type, type);
    }

    Reservoir(const Reservoir& other)
        : width(other.width), length(other.length), maxDepth(other.maxDepth) {
        name = new char[stringLength(other.name) + 1];
        stringCopy(name, other.name);

        type = new char[stringLength(other.type) + 1];
        stringCopy(type, other.type);
    }

    Reservoir& operator=(const Reservoir& other) {
        if (this != &other) {
            delete[] name;
            delete[] type;

            width = other.width;
            length = other.length;
            maxDepth = other.maxDepth;

            name = new char[stringLength(other.name) + 1];
            stringCopy(name, other.name);

            type = new char[stringLength(other.type) + 1];
            stringCopy(type, other.type);
        }
        return *this;
    }

    ~Reservoir() {
        delete[] name;
        delete[] type;
    }

    double calculateVolume() const {
        return width * length * maxDepth;
    }

    double calculateSurfaceArea() const {
        return width * length;
    }

    bool isSameType(const Reservoir& other) const {
        int i = 0;
        while (type[i] != '\0' && other.type[i] != '\0') {
            if (type[i] != other.type[i]) return false;
            i++;
        }
        return type[i] == '\0' && other.type[i] == '\0';
    }

    bool compareSurfaceArea(const Reservoir& other) const {
        return isSameType(other) && calculateSurfaceArea() > other.calculateSurfaceArea();
    }

    void setName(const char* newName) {
        delete[] name;
        name = new char[stringLength(newName) + 1];
        stringCopy(name, newName);
    }

    void setType(const char* newType) {
        delete[] type;
        type = new char[stringLength(newType) + 1];
        stringCopy(type, newType);
    }

    void setDimensions(double newWidth, double newLength, double newMaxDepth) {
        width = newWidth;
        length = newLength;
        maxDepth = newMaxDepth;
    }

    const char* getName() const {
        return name;
    }

    const char* getType() const {
        return type;
    }

    double getWidth() const {
        return width;
    }

    double getLength() const {
        return length;
    }

    double getMaxDepth() const {
        return maxDepth;
    }

    void display() const {
        cout << "Reservoir: " << name << endl;
        cout << "Dimensions: " << width << " x " << length << endl;
        cout << "Volume: " << calculateVolume() << endl;
        cout << "Surface Area: " << calculateSurfaceArea() << endl;
    }
};

int main() {
    Reservoir lake("Lake Baikal", "lake", 50, 100, 30);
    Reservoir ocean("Pacific Ocean", "ocean", 5000, 8000, 500);

    lake.display();
    ocean.display();


    Reservoir copyOfLake = lake;
    copyOfLake.display();

}


