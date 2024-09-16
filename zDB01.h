#ifndef ZDB01_H
#define ZDB01_H
#include <mysql++.h>
#include <wx/arrstr.h>
#include <wx/textctrl.h>
#include <result.h>


class zDB01
{
public:
    zDB01();
    virtual ~zDB01();
    void listDatabases();
    wxArrayString dbn, lk1, lk2, lk3;
    void selDB();
    wxString db;
    std::string curDB;
    void de01();
    void initField(std::string inputValue, wxTextCtrl * field);
    std::string fieldToString(wxTextCtrl * field);
    void nb01();
    void listCategories(bool idPrim);
    void listLinks(int curCat, bool dRID);
    void getLink(int curCat);
    void listLk1Lk2();
    mysqlpp::StoreQueryResult zres;
//    mysqlpp::StoreQueryResult ares;
    void insertCat(std::string cat, std::string memo);
    void insertLink(std::string idlk1, std::string lkn, std::string lnk, std::string ddes);
    void DeleteLink(std::string delId);
    void editLink(std::string delId, std::string idkl2, std::string ilk, std::string lnk, std::string ddes, std::string idlk1);
    std::string strIdlk1 = "43";
    bool insertMode;
    void editCat(std::string idlk1, std::string cat, std::string memo);
    std::string database = "bcswebtools";
    std::string server = "localhost";
    std::string user = "bcs";
    std::string password = "Peace007!amb";
    void getCat();

protected:

private:
};

#endif // ZDB01_H
