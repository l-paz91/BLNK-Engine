// -----------------------------------------------------------------------------
#ifndef ConsoleManager_H
#define ConsoleManager_H
// -----------------------------------------------------------------------------

//--INCLUDES--//
#include <string>

// -----------------------------------------------------------------------------

struct ConsoleVariable
{
	ConsoleVariable(const std::string& pCommandName, 
		const std::string& pDescription, int32_t pDefaultValue)
		: mCommandName(pCommandName)
		, mDescription(pDescription)
		, mDefaultValue(pDefaultValue)
	{}
	
	std::string mCommandName;
	std::string mDescription;
	int32_t mDefaultValue;
};

// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
#endif // !ConsoleManager_H