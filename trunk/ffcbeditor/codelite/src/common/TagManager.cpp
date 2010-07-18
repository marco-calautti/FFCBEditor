#include "TagManager.h"
#include <wx/file.h>

TagManager* TagManager::instance=NULL;

TagManager::TagManager()
{
	if(!wxFile::Exists(TAGS_FILE_NAME)){
		doc.SetRoot(new wxXmlNode(wxXML_ELEMENT_NODE,wxT("ffcbtags")));
	}else
		doc.Load(TAGS_FILE_NAME);
}

TagManager* TagManager::GetInstance()
{
	if(!instance)
		instance=new TagManager();
	return instance;
}

bool TagManager::GetTagValues(const wxString& tag,wxString* value,wxString* translation)
{
	wxXmlNode* root=doc.GetRoot();
	wxXmlNode* node=root->GetChildren();

	while(node){
		wxString id;
		node->GetPropVal(wxT("id"),&id);
		if(id==tag){ //tag found
			node->GetPropVal(wxT("value"),value);
			if(!node->GetPropVal(wxT("translation"),translation))
				*translation=wxEmptyString;
			return true;
		}
		node=node->GetNext();
	}
	
	return false;
		
}
