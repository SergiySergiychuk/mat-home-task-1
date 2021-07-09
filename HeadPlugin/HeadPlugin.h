#pragma once
#include"../IPlugin/IPlugin.h"

class HeadPlugin : public IPlugin
{
private:
	const char* m_Name;
public:
	HeadPlugin(const char* name);
	const char* get_name();
};