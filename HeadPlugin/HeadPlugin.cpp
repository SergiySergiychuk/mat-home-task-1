#include<iostream>

#include"HeadPlugin.h"

HeadPlugin::HeadPlugin(const char* name) :m_Name(name) {}
const char* HeadPlugin::get_name()
{
	return m_Name;
}

extern "C" __declspec(dllexport) void init(std::unique_ptr<IPlugin>&plugin)
{
	plugin.reset(new HeadPlugin("Head Plugin"));
}

