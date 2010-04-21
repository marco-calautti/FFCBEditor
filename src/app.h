#include <wx/wx.h>
#include <wx/intl.h>
class App : public wxApp{

public:
	virtual bool OnInit();

private:
	wxLocale locale;
};
DECLARE_APP(App);