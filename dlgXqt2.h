#ifndef DLGXQT2_H
#define DLGXQT2_H

//(*Headers(dlgXqt2)
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/radiobox.h>
#include <wx/sizer.h>
//*)

class dlgXqt2: public wxDialog
{
public:

    dlgXqt2(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
    virtual ~dlgXqt2();
    int isel;


    //(*Declarations(dlgXqt2)
    wxButton* butCancel;
    wxRadioBox* rbtRadBut;
    //*)

protected:

    //(*Identifiers(dlgXqt2)
    static const long ID_RADIOBOX1;
    static const long ID_BUTTON1;
    //*)

private:

    //(*Handlers(dlgXqt2)
    //*)

    DECLARE_EVENT_TABLE()
    void OnbutCancelClick(wxCommandEvent& event);
    void OnrbtRadButSelect(wxCommandEvent& event);
};

#endif
