#include<iostream>

#include"FootPlugin.h"

FootPlugin::FootPlugin(const char* name):m_Name(name) {}
const char * FootPlugin::get_name()
{
	return m_Name;
}

extern "C" __declspec(dllexport) void init(std::unique_ptr<IPlugin>&plugin)
{
	plugin.reset(new FootPlugin("Foot Plugin"));
}

