#ifndef DLGNEWLINK_H
#define DLGNEWLINK_H

//(*Headers(dlgNewLink)
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

class dlgNewLink: public wxDialog
{
	public:

		dlgNewLink(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~dlgNewLink();

		//(*Declarations(dlgNewLink)
		wxButton* btnCancel;
		wxButton* btnInset;
		wxStaticText* lblDet;
		wxStaticText* lblLink;
		wxStaticText* lblidlk1;
		wxStaticText* lnlLinkName;
		wxTextCtrl* edtDetDes;
		wxTextCtrl* edtLink;
		wxTextCtrl* edtLinkName;
		wxTextCtrl* edtPrim;
		//*)

	protected:

		//(*Identifiers(dlgNewLink)
		static const long ID_STATICTEXT1;
		static const long ID_TEXTCTRL1;
		static const long ID_STATICTEXT2;
		static const long ID_TEXTCTRL2;
		static const long ID_STATICTEXT3;
		static const long ID_TEXTCTRL3;
		static const long ID_STATICTEXT4;
		static const long ID_TEXTCTRL4;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		//*)

	private:

		//(*Handlers(dlgNewLink)
		void OnbtnInsetClick(wxCommandEvent& event);
		void OnbtnCancelClick(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
