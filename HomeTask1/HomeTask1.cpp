
#include<iostream>
#include<Windows.h>
#include<filesystem>
#include<string>

#include"../IPlugin/IPlugin.h"


using dll_function = void(*)(std::unique_ptr<IPlugin>&);

void load_plugin(const char* path);

int main()
{
	constexpr auto dir = "../Plugins";
	for (const auto& entry : std::filesystem::directory_iterator(dir)) {
		load_plugin(entry.path().string().c_str());
	}

}
void load_plugin(const char* path) {
	std::unique_ptr<IPlugin>plugin = nullptr;
	auto hinstLib = LoadLibraryA(path);
	if (hinstLib != NULL)
	{
		std::cout << "Plugin was found\n";
		auto test_plugin_func = reinterpret_cast<dll_function>(GetProcAddress(hinstLib, "init"));
		if (NULL != test_plugin_func)
		{
			std::cout << "func was found\n";
			test_plugin_func(plugin);
			std::cout<<"---- Plugin name: " << plugin.get()->get_name() << std::endl;;
		}
		else
		{
			std::cout << "func wasn't found";
		}
		FreeLibrary(hinstLib);
	}
	else
	{
		std::cout << "Plugin wasn't found";
	}
}




