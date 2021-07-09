#include<iostream>

#include"HandPlugin.h"

HandPlugin::HandPlugin(const char * name):m_Name(name) {}
const char * HandPlugin::get_name()
{
	return m_Name;
}

extern "C" __declspec(dllexport) void init(std::unique_ptr<IPlugin>&plugin)
{
	plugin.reset(new HandPlugin("Hand Plugin"));
}
