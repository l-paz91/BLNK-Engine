// -----------------------------------------------------------------------------
#ifndef DebugFunctions_H
#define DebugFunctions_H
// -----------------------------------------------------------------------------

//--INCLUDES--//
#include <string>
#include <iostream>
#include <sstream>
#include <stdexcept>

// -----------------------------------------------------------------------------

namespace Blink
{
	// error() simply disguises throws:
	inline void error(const std::string& pErrorString)
	{
		throw std::runtime_error(pErrorString);
	}

	// -----------------------------------------------------------------------------

	inline void error(const std::string& pErrorString1, const std::string& pErrorString2)
	{
		error(pErrorString1 + pErrorString2);
	}

	// -----------------------------------------------------------------------------

	inline void error(const std::string& pErrorString, int i)
	{
		std::ostringstream os;
		os << pErrorString << ": " << i;
		error(os.str());
	}
}

// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
#endif // !DebugFunctions_H