#ifndef CELL_H
#define CELL_H
#include "SFML\Graphics.hpp"
#include "CellType.h"

class Cell
{
public:
	Cell(CellType *celltype, sf::Vector3i startLocation);
	~Cell();

	sf::Color GetColor() const;
	bool setLocation(sf::Vector3i newLocation);
	sf::Vector3i GetLocation() const;
	int ComparePriority(const Cell& cell) const;
	int GetPriority();
	int GetTypeID();
private:
	CellType *m_type;
	sf::Vector3i m_location;
	int m_priority;
};

#endif