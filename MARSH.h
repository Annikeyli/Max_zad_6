#include <iostream>
#include <fstream>
#include <cstring>

class MARSH {
private:
    char nazv_nach[20];
    char nazv_kon[20];
    int number_marsh;

public:
    MARSH();
    MARSH(const char* start, const char* end, int num);
    MARSH(const MARSH& other);

    int getNumber() const { return number_marsh; }
    const char* getStart() const { return nazv_nach; }
    const char* getEnd() const { return nazv_kon; }

    bool operator<(const MARSH& other) const;
    bool operator==(const MARSH& other) const;
    bool insert(const MARSH& a, const MARSH& b);
    static bool compMARSH(const MARSH& a, const MARSH& b);

    friend std::ostream& operator<<(std::ostream& os, const MARSH& m);
    friend std::istream& operator>>(std::istream& is, MARSH& m);
};
