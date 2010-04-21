#ifndef __CB_ITEM_DATA__
#define __CB_ITEM_DATA__

#include <wx/treectrl.h>

#define CB_SINGLE_FILE 1
#define CB_TEXT_ARCHIVE 2
#define CB_TEXT_SECTION 3

class CBItemData : public wxTreeItemData
{
public:

	CBItemData();
	virtual ~CBItemData();

	void SetType(int type);
	int GetType();

	void* GetData();
	void SetData(void* data);

	size_t GetSectionIndex();
	void SetSectionIndex(size_t sectionIdx);

	wxString GetString();
	void SetString(wxString str);

private:
	int type;
	void* data;
	size_t sectionIdx;
	wxString str;
};

#endif