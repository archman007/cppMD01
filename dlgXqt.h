#ifndef DLGXQT_H
#define DLGXQT_H
#include <wx/listbox.h>

//(*Headers(dlgXqt)
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/radiobox.h>
#include <wx/sizer.h>
//*)

//using namespace std;

class dlgXqt: public wxDialog
{
	public:

		dlgXqt(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~dlgXqt();
		int isel;

		//(*Declarations(dlgXqt)
		wxButton* butCancel;
		wxRadioBox* rbtRadBut;
		//*)

	protected:

		//(*Identifiers(dlgXqt)
		static const long ID_RADIOBOX1;
		static const long ID_BUTTON1;
		//*)

	private:

		//(*Handlers(dlgXqt)
		void OnbutCancelClick(wxCommandEvent& event);
		void OnrbtRadButSelect(wxCommandEvent& event);
		void OnbtnSelectClick(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
