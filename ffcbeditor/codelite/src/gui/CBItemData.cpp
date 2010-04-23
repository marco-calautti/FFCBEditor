#include "CBItemData.h"


CBItemData::CBItemData()
{
	type=0;
	data=NULL;
	sectionIdx=0;
}
CBItemData::~CBItemData()
{

}

int CBItemData::GetType()
{
	return type;
}

void CBItemData::SetType(int t)
{
	type=t;
}

void* CBItemData::GetData()
{
	return data;
}

void CBItemData::SetData(void* d)
{
	data=d;
}

size_t CBItemData::GetSectionIndex()
{
	return sectionIdx;
}

void CBItemData::SetSectionIndex(size_t i)
{
	sectionIdx=i;
}

wxString CBItemData::GetString()
{
	return str;
}
void CBItemData::SetString(wxString s)
{
	str=s;
}
