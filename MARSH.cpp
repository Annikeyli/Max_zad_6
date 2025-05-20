#include "MARSH.h"
#include <clocale>
//#include "SORT.h"
//#include "SORTCOMP.h"

MARSH::MARSH() : number_marsh(0) {
	nazv_nach[0] = '\0';
	nazv_kon[0] = '\0';
}

MARSH::MARSH(const char* start, const char* end, int num) : number_marsh(num) {
	strncpy_s(nazv_nach, start, 19);
	strncpy_s(nazv_kon, end, 19);
	nazv_nach[19] = '\0';
	nazv_kon[19] = '\0';
}

MARSH::MARSH(const MARSH& other) : number_marsh(other.number_marsh) {
	strncpy_s(nazv_nach, other.nazv_nach, 19);
	strncpy_s(nazv_kon, other.nazv_kon, 19);
	nazv_nach[19] = '\0';
	nazv_kon[19] = '\0';
}

bool MARSH::operator<(const MARSH& other) const {
	return number_marsh < other.number_marsh;
}
bool MARSH::insert(const MARSH& a, const MARSH& b) {
	return a.number_marsh < b.number_marsh;
}

bool MARSH::compMARSH(const MARSH& a, const MARSH& b)
{
	return false;
}

//bool MARSH::compMARSH(const MARSH& a, const MARSH& b) {
//	return a.number_marsh < b.number_marsh;
//}

std::ostream& operator<<(std::ostream& os, const MARSH& m) {
	setlocale(LC_ALL, "Russian");
	os << "Маршрут №" << m.number_marsh << ": "
		<< m.nazv_nach << " - " << m.nazv_kon;
	return os;
}

std::istream& operator>>(std::istream& is, MARSH& m) {
	is >> m.nazv_nach >> m.nazv_kon >> m.number_marsh;
	return is;
}

