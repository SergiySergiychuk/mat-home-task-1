#pragma once
#include"../IPlugin/IPlugin.h"

class HandPlugin : public IPlugin
{
private:
	const char* m_Name;
public:
	HandPlugin(const char * name);
	const char * get_name();
};