#include "PlugPluginPtrVector.h"
#include "PlugPlugin.h"

namespace usdproxy
{

const pxr::PlugPluginPtrVector& PlugPluginPtrVector::Get() const
{
	return m_plugPluginPtrVector;
}

PlugPluginPtrVector::PlugPluginPtrVector(const pxr::PlugPluginPtrVector& plugPluginPtrVector)
: m_plugPluginPtrVector(plugPluginPtrVector)
{
}

int PlugPluginPtrVector::Size() const
{
	return m_plugPluginPtrVector.size();
}

PlugPlugin PlugPluginPtrVector::Get(int index)
{
	return PlugPlugin(m_plugPluginPtrVector[index]);
}

}


