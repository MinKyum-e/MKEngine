#include "mkResource.h"
namespace mk
{
	Resource::Resource(enums::eResourceType resourceType)
		:mResourceType(resourceType)
		,mPath(L"")
	{

	}
	Resource::~Resource()
	{

	}
}