#ifndef LEVEL_H
#define LEVEL_H

#include "Unit.h"

class Level : public Resource
{
public:
	// constructors/destructors
	Level();
	~Level();

	// methods
	void Serialize(std::ostream& _stream) override;
	void Deserialize(std::istream& _stream) override;
	void ToString() override;
	void AssignNonDefaultValues() override;
private:
	// members
	int m_mapSizeX;
	int m_mapSizeY;
	float m_gameTime;
	//Unit* m_unit;
	vector<Unit*> m_units;
	// and other interesting level members
};

#endif// LEVEL_H

