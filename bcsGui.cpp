#include "bcsGui.h"
#include <wx/wx.h>
#include <wx/dirdlg.h>
#include <wx/textdlg.h>
#include <wx/msgdlg.h>
#include <wx/string.h>
#include <wx/window.h>

using namespace std;

bcsGui::bcsGui()
{
    //ctor
}

bcsGui::~bcsGui()
{
    //dtor
}

std::string bcsGui::SelDir(string initDir)
{
    string selDir;
    wxDirDialog dlg(NULL, "Choose input directory", initDir, wxDD_DEFAULT_STYLE | wxDD_DIR_MUST_EXIST);
    if (dlg.ShowModal() == wxID_OK)
    {
        selDir = dlg.GetPath().ToStdString();
        return selDir;

    }
    dlg.Destroy();

}

string bcsGui::GetText(bool memo, string initVal, string prompt, string caption)
{
    wxString wxInit;
    wxInit = initVal;
    string rval;
    if (memo)
    {
        wxTextEntryDialog dlg(NULL, prompt, caption, wxInit, (wxCANCEL | wxOK | wxTE_MULTILINE), wxPoint(50, 50));
        if (dlg.ShowModal() == wxID_OK)
        {
            // We can be certain that this string contains letters only.
            wxString value = dlg.GetValue();
            rval = value;
            return rval;
        }
        else
        {
            rval = "";
            return rval;
        }
    }
    else
    {
        wxTextEntryDialog dlg(NULL, prompt, caption, wxInit, (wxCANCEL | wxOK), wxPoint(50, 50));
        if (dlg.ShowModal() == wxID_OK)
        {
            // We can be certain that this string contains letters only.
            wxString value = dlg.GetValue();
            rval = value;
            return rval;
        }
        else
        {
            rval = "";
            return rval;
        }

    }
}

int bcsGui::yornQues(string caption, string prompt)
{
    int answer;
    answer = wxMessageBox(caption, prompt, wxYES_NO | wxCANCEL, NULL );
    return answer;
}
string bcsGui::openFileDialog(wxWindow* parent, const wxString& message, const wxString& defaultDir, const wxString& defaultFile, const wxString& wildcard, int flags)
{
    string path;
    wxFileDialog openFileDialog(parent, message, defaultDir, defaultFile, wildcard, flags);
    if (openFileDialog.ShowModal() == wxID_OK)
    {
        path = openFileDialog.GetPath().ToStdString();
    }
    return path;
}






