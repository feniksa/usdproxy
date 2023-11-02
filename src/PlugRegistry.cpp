#include "PlugRegistry.h"
#include "PlugPluginPtrVector.h"

namespace usdproxy
{

PlugPluginPtrVector PlugRegistry::RegisterPlugins(const std::string& pathToPlugInfo)
{
	pxr::PlugRegistry& plugRegistry = pxr::PlugRegistry::GetInstance();
	return PlugPluginPtrVector(plugRegistry.RegisterPlugins(pathToPlugInfo));
}


PlugPluginPtrVector PlugRegistry::GetAllPlugins()
{
	pxr::PlugRegistry& plugRegistry = pxr::PlugRegistry::GetInstance();
	return PlugPluginPtrVector(plugRegistry.GetAllPlugins());
}

}
