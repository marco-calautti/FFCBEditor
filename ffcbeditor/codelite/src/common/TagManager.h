#ifndef __TAG_MANAGER__
#define __TAG_MANAGER__

#include <wx/xml/xml.h>
#include <wx/wx.h>

#define TAGS_FILE_NAME wxT("tags.xml")

class TagManager : public wxObject
{
	static TagManager* instance;
	wxXmlDocument doc;
	
	TagManager();
	TagManager(const TagManager&){}
	TagManager& operator=(const TagManager&)
	{
		return *instance;
	}
	
public:
	static TagManager* GetInstance();
	bool GetTagValues(const wxString& tag,wxString* value,wxString* translation);

};

#endif
