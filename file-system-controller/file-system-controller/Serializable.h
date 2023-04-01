#ifndef SERIALIZABLE_H
#define SERIALIZABLE_H

#include "StdIncludes.h"

class Serializable
{
public:
	// constructors/Destructors
	Serializable() {}
	virtual ~Serializable() {}

	// methods
	virtual void Serialize(std::ostream& _stream) = 0;
	virtual void Deserialize(std::istream& _stream) = 0;
};

#endif SERIALIZABLE_H

