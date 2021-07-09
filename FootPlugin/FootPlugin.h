#pragma once
#include"../IPlugin/IPlugin.h"

class FootPlugin : public IPlugin
{
private:
	const char* m_Name;
public:
	FootPlugin(const char* name);
	const char * get_name();
};