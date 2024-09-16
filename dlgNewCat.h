#ifndef DLGNEWCAT_H
#define DLGNEWCAT_H

//(*Headers(dlgNewCat)
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

class dlgNewCat: public wxDialog
{
	public:

		dlgNewCat(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~dlgNewCat();

		//(*Declarations(dlgNewCat)
		wxButton* btnCancel;
		wxButton* btnInsert;
		wxStaticText* lblCat;
		wxStaticText* lblMemo;
		wxTextCtrl* edtCat;
		wxTextCtrl* edtMemo;
		//*)

	protected:

		//(*Identifiers(dlgNewCat)
		static const long ID_STATICTEXT1;
		static const long ID_TEXTCTRL1;
		static const long ID_STATICTEXT2;
		static const long ID_TEXTCTRL2;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		//*)

	private:

		//(*Handlers(dlgNewCat)
		void OnbtnInsertClick(wxCommandEvent& event);
		void OnbtnCancelClick(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
