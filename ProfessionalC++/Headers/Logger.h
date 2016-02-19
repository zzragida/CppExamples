#ifndef __LOGGER__
#define __LOGGER__

class Preferences;

class Logger
{
public:
	static void setPreference(const Preference& inPrefs);
	static void logError(const char* inError);
};

#endif // __LOGGER__
