#include <string>
#include <wx/string.h>
#include <wx/window.h>

using namespace std;

class bcsGui
{
public:
    bcsGui();
    virtual ~bcsGui();
    std::string SelDir(string initDir);
    string GetText(bool memo, string initVal, string prompt, string caption);
    int yornQues(string caption, string prompt);
    string openFileDialog(wxWindow* parent, const wxString& message, const wxString& defaultDir, const wxString& defaultFile, const wxString& wildcard, int flags);

protected:

private:
};
