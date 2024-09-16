#ifndef DLGDE01_H
#define DLGDE01_H

//(*Headers(dlgDe01)
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

class dlgDe01: public wxDialog
{
	public:

		dlgDe01(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~dlgDe01();

		//(*Declarations(dlgDe01)
		wxStaticText* StaticText1;
		wxStaticText* StaticText2;
		wxTextCtrl* TextCtrl1;
		wxTextCtrl* TextCtrl2;
		//*)

	protected:

		//(*Identifiers(dlgDe01)
		static const long ID_STATICTEXT1;
		static const long ID_TEXTCTRL1;
		static const long ID_STATICTEXT2;
		static const long ID_TEXTCTRL2;
		//*)

	private:

		//(*Handlers(dlgDe01)
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
