#include "app.h"

#include "gui/FFCBMainFrame.h"
#include "cblib/CBFREBArchive.h"

IMPLEMENT_APP(App)
bool App::OnInit(){

	if(locale.Init(wxLANGUAGE_DEFAULT, wxLOCALE_CONV_ENCODING)){
		wxString path;
		path << wxT(".") << wxFILE_SEP_PATH << wxT("resources");
		locale.AddCatalogLookupPathPrefix(path);
		locale.AddCatalog(wxT("ffcbeditor"));
	}
	MainFrame* frame=new FFCBMainFrame(NULL);
	frame->Show();

	return true;

}
