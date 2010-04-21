#include "DBManager.h"
#include<wx/file.h>

DBManager* DBManager::instance=NULL; //inizializzo l'istanza

DBManager::DBManager()
{
	if(!wxFile::Exists(DB_FILE_NAME)){
		doc.SetRoot(new wxXmlNode(wxXML_ELEMENT_NODE,wxT("filesdb")));
	}else
		doc.Load(DB_FILE_NAME);
}

DBManager* DBManager::GetInstance()
{
	if(!instance)
		instance=new DBManager();
	return instance;
}

bool DBManager::Contains(wxString& fileName)
{
	wxXmlNode* root=doc.GetRoot();
	wxXmlNode* node=root->GetChildren();

	while(node){
		wxString name;
		node->GetPropVal(wxT("name"),&name);
		if(name==fileName) return true;
		node=node->GetNext();
	}

	return false;
}

FileType DBManager::GetFileType(wxString& fileName)
{
	//if(!Contains(fileName)) return NO_FILE;

	wxXmlNode* root=doc.GetRoot();
	wxXmlNode* node=root->GetChildren();

	while(node){
		wxString name;
		wxString type;
		node->GetPropVal(wxT("name"),&name);
		node->GetPropVal(wxT("type"),&type);

		if(name==fileName){ //ho trovato il file
			if(type==STR_SINGLE_FILE){
				return SINGLE_FILE;
			}else if(type==STR_TEXT_ARCHIVE){
				return TEXT_ARCHIVE;
			}else return NO_FILE;
		}

		node=node->GetNext();
	}

	return NO_FILE;

}

wxString DBManager::GetFileDescription(wxString& fileName)
{
	wxXmlNode* root=doc.GetRoot();
	wxXmlNode* node=root->GetChildren();

	while(node){
		wxString name;
		wxString descr;
		node->GetPropVal(wxT("name"),&name);

		if(fileName==name){
			return node->GetNodeContent();
		}

		node=node->GetNext();
	}

	return wxEmptyString;

}

int DBManager::SetFileDescription(wxString& fileName,wxString& description)
{
	wxXmlNode* root=doc.GetRoot();
	wxXmlNode* node=root->GetChildren();

	while(node){
		wxString name;
		node->GetPropVal(wxT("name"),&name);

		if(fileName==name){
			node->GetChildren()->SetContent(description);
			if(!doc.Save(DB_FILE_NAME))
				return IO_ERROR;
			break;
		}

		node=node->GetNext();
	}
	
	return SUCCESS;
}

int DBManager::AddFile(wxString& fileName,FileType type,wxString description)
{
	if(Contains(fileName)) return ALREADY_EXISTS;

	wxXmlNode* root=doc.GetRoot();

	wxXmlNode* node=new wxXmlNode(root,wxXML_ELEMENT_NODE,wxT("cbfile"));

	wxString strType;

	switch(type){
		case SINGLE_FILE:
			strType=STR_SINGLE_FILE;
		break;

		case TEXT_ARCHIVE:
			strType=STR_TEXT_ARCHIVE;
		break;
	}
	wxXmlProperty* prop=new wxXmlProperty(wxT("name"),fileName);
	wxXmlProperty* prop2=new wxXmlProperty(wxT("type"),strType);
	prop->SetNext(prop2);
	node->SetProperties(prop);

	wxXmlNode* content=new wxXmlNode(node,wxXML_CDATA_SECTION_NODE,wxEmptyString);
	content->SetContent(description);

	if(!doc.Save(DB_FILE_NAME))
		return IO_ERROR;

	return SUCCESS;

}

int DBManager::GetFileNames(wxArrayString* arrStr)
{
	wxXmlNode* root=doc.GetRoot();
	wxXmlNode* node=root->GetChildren();

	while(node){
		wxString name;
		node->GetPropVal(wxT("name"),&name);
		arrStr->Add(name);
		node=node->GetNext();
	}

	return SUCCESS;
}