#ifndef UNIT_H
#define UNIT_H

#include "Resource.h"
#include "SoundEffect.h"

class Unit : public Resource
{
public:
	// constructors/destructors
	Unit();
	virtual ~Unit();

	// methods
	void Serialize(std::ostream& _stream) override;
	void Deserialize(std::istream& _stream) override;
	void ToString() override;
	void AssignNonDefaultValues() override;

	// members
	static ObjectPool<Unit>* Pool;

private:
	// members
	SoundEffect* m_soundEffect;
};

#endif
