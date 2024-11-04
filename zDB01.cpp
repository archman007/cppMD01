#include "zDB01.h"
#include <mysql++.h>
#include <wx/msgdlg.h>
#include "dlgSelDB.h"
#include "dlgDe01.h"
#include "dlgNb01.h"

using namespace mysqlpp;
using namespace std;

zDB01::zDB01()
{
    //ctor
}

zDB01::~zDB01()
{
    //dtor
}

void zDB01::listDatabases()
{
//    dlgSelDB dlb;
    dbn.Clear();
    try
    {
        Connection conn(true);
        conn.connect(database.c_str(), server.c_str(), user.c_str(), password.c_str());
        Query query = conn.query();
//       query << "SELECT * FROM lk1 LIMIT 10";
        query << "show DATABASES";
        StoreQueryResult ares = query.store();
        for (size_t i = 0; i < ares.num_rows(); i++)
        {
            string buf = std::string(ares[i]["Database"]);


//            wxMessageBox(buf);
            wxString tbuf = buf;
            dbn.Insert(tbuf,0,1);
//            lbxDbName.InsertItems(ares[i]["Database"]);
//            cout << "Name: " << ares[i]["idlk1"] << " - Address: " << ares[i]["cat"] << endl;

        }

        if (ares.num_rows() == 0)
        {
            wxMessageBox("No Data Detected!!", "Zero Query Results", wxICON_HAND);
        }
    }
    catch (BadQuery er)     // handle any connection or
    {
        // query errors that may come up
        cerr << "Error: " << er.what() << endl;
        wxMessageBox("Connection Error!", "Connection Error Detected", wxICON_ERROR | wxICON_HAND);
    }
    catch (const BadConversion& er)
    {
        // Handle bad conversions
        cerr << "Conversion error: " << er.what() << endl <<
             "\tretrieved data size: " << er.retrieved <<
             ", actual size: " << er.actual_size << endl;
        wxMessageBox("Conversino Error!", "Conversin Error Detected", wxICON_HAND);
    }
    catch (const Exception& er)
    {
        // Catch-all for any other MySQL++ exceptions
        string buf = er.what();
        cerr << "Error: " << er.what() << endl;
        wxMessageBox("Miscalleanous Error!", "Other Error Detected", wxICON_HAND);
    }
}

void zDB01::listCategories(bool idPrime)
{
//    dlgSelDB dlb;
    lk1.Clear();
    try
    {
        Connection conn(true);
        conn.connect(database.c_str(), server.c_str(), user.c_str(), password.c_str());
        Query query = conn.query();
        if (idPrime)
        {
            query << "select idlk1, cat from lk1 order by idlk1";
        }
        else
        {
            query << "select idlk1, cat from lk1 order by cat";
        }
        StoreQueryResult ares = query.store();
        zres = ares;

        for (size_t i = 0; i < ares.num_rows(); i++)
        {
//            string sbuf = std::string(ares[i]["idlk1"]) + " " + std::string(ares[i]["cat"]);
            lk1.Add(std::string(ares[i]["idlk1"]) + " " + std::string(ares[i]["cat"]));
//            wxMessageBox(std::string(ares[i]["idlk1"]) + " " + std::string(ares[i]["cat"]));
//           wxString tbuf = buf;
//           dbn.Insert(tbuf,0,1);
//            lbxDbName.InsertItems(ares[i]["Database"]);
//            cout << "Name: " << ares[i]["idlk1"] << " - Address: " << ares[i]["cat"] << endl;

        }

        if (ares.num_rows() == 0)
        {
            wxMessageBox("No Data Detected!!", "Zero Query Results", wxICON_HAND);
        }
    }
    catch (BadQuery er)     // handle any connection or
    {
        // query errors that may come up
        cerr << "Error: " << er.what() << endl;
        wxMessageBox("Connection Error!", "Connection Error Detected", wxICON_ERROR | wxICON_HAND);
    }
    catch (const BadConversion& er)
    {
        // Handle bad conversions
        cerr << "Conversion error: " << er.what() << endl <<
             "\tretrieved data size: " << er.retrieved <<
             ", actual size: " << er.actual_size << endl;
        wxMessageBox("Conversino Error!", "Conversin Error Detected", wxICON_HAND);
    }
    catch (const Exception& er)
    {
        // Catch-all for any other MySQL++ exceptions
        string buf = er.what();
        cerr << "Error: " << er.what() << endl;
        wxMessageBox("Miscalleanous Error!", "Other Error Detected", wxICON_HAND);
    }
}

void zDB01::listLinks(int curCat, bool dRID)
{
//    dlgSelDB dlb;
    lk2.Clear();
    try
    {
        Connection conn(true);
        conn.connect(database.c_str(), server.c_str(), user.c_str(), password.c_str());
        Query query = conn.query();
        //SELECT * FROM `lk2` WHERE idlk1 = 20 order by lkn
//        query << "select * from lk2 where idlk1 = 140 order by lkn";
        if (dRID)
        {
            query << "select * from lk2 where idlk1 = " << to_string(curCat) << " order by idlk2";
        }
        else
        {
            query << "select * from lk2 where idlk1 = " << to_string(curCat) << " order by lkn";
        }
        StoreQueryResult ares = query.store();
        zres = ares;
        for (size_t i = 0; i < ares.num_rows(); i++)
        {
            string sbuf = std::string(ares[i]["idlk2"]) + " " + std::string(ares[i]["lkn"]);
            lk2.Add(std::string(ares[i]["idlk2"]) + " " + std::string(ares[i]["lkn"]));

//            wxMessageBox(std::string(ares[i]["idlk1"]) + " " + std::string(ares[i]["cat"]));
//            wxMessageBox(std::string(ares[i]["idlk2"]) + " " + std::string(ares[i]["lkn"]));
//           wxString tbuf = buf;
//           dbn.Insert(tbuf,0,1);
//            lbxDbName.InsertItems(ares[i]["Database"]);
//            cout << "Name: " << ares[i]["idlk1"] << " - Address: " << ares[i]["cat"] << endl;

        }

        if (ares.num_rows() == 0)
        {
            wxMessageBox("No Data Detected!!", "Zero Query Results", wxICON_HAND);
        }
    }
    catch (BadQuery er)     // handle any connection or
    {
        // query errors that may come up
        cerr << "Error: " << er.what() << endl;
        wxMessageBox("Connection Error!", "Connection Error Detected", wxICON_ERROR | wxICON_HAND);
    }
    catch (const BadConversion& er)
    {
        // Handle bad conversions
        cerr << "Conversion error: " << er.what() << endl <<
             "\tretrieved data size: " << er.retrieved <<
             ", actual size: " << er.actual_size << endl;
        wxMessageBox("Conversino Error!", "Conversin Error Detected", wxICON_HAND);
    }
    catch (const Exception& er)
    {
        // Catch-all for any other MySQL++ exceptions
        string buf = er.what();
        cerr << "Error: " << er.what() << endl;
        wxMessageBox("Miscalleanous Error!", "Other Error Detected", wxICON_HAND);
    }
}

void zDB01::getLink(int curCat)
{
//    dlgSelDB dlb;
    lk3.Clear();
    try
    {
        Connection conn(true);
        conn.connect(database.c_str(), server.c_str(), user.c_str(), password.c_str());
        Query query = conn.query();
        //SELECT * FROM `lk2` WHERE idlk1 = 20 order by lkn
//        query << "select * from lk2 where idlk1 = 140 order by lkn";
        query << "select * from lk2 where idlk2 = " << to_string(curCat) << " order by lkn";
        StoreQueryResult ares = query.store();
        zres = ares;
        for (size_t i = 0; i < ares.num_rows(); i++)
        {
            string sbuf = std::string(ares[i]["idlk2"]) + " " + std::string(ares[i]["lkn"]);
            lk3.Add(std::string(ares[i]["lnk"]));

//            wxMessageBox(std::string(ares[i]["idlk1"]) + " " + std::string(ares[i]["cat"]));
//            wxMessageBox(std::string(ares[i]["idlk2"]) + " " + std::string(ares[i]["lkn"]));
//           wxString tbuf = buf;
//           dbn.Insert(tbuf,0,1);
//            lbxDbName.InsertItems(ares[i]["Database"]);
//            cout << "Name: " << ares[i]["idlk1"] << " - Address: " << ares[i]["cat"] << endl;

        }
        size_t rcount = ares.num_rows();

        if ((rcount == 1)  and (insertMode == true))
        {
            wxMessageBox("No Data Detected!!", "Zero Query Results", wxICON_HAND);
        }
    }
    catch (BadQuery er)     // handle any connection or
    {
        // query errors that may come up
        cerr << "Error: " << er.what() << endl;
        wxMessageBox("Connection Error!", "Connection Error Detected", wxICON_ERROR | wxICON_HAND);
    }
    catch (const BadConversion& er)
    {
        // Handle bad conversions
        cerr << "Conversion error: " << er.what() << endl <<
             "\tretrieved data size: " << er.retrieved <<
             ", actual size: " << er.actual_size << endl;
        wxMessageBox("Conversino Error!", "Conversin Error Detected", wxICON_HAND);
    }
    catch (const Exception& er)
    {
        // Catch-all for any other MySQL++ exceptions
        string buf = er.what();
        cerr << "Error: " << er.what() << endl;
        wxMessageBox("Miscalleanous Error!", "Other Error Detected", wxICON_HAND);
    }
}

void zDB01::selDB()
{
    dlgSelDB dlg(NULL,wxID_ANY);
    dbn.Sort();
    dlg.lbxDbNames->InsertItems(dbn, 0);
    if (dlg.ShowModal() == wxID_OK)
    {
        curDB = dlg.lbxDbNames->GetString(dlg.lbxDbNames->GetSelection());
    }

}

void zDB01::initField(string inputValue, wxTextCtrl * field)
{
    wxString dv = inputValue;
    field->Clear();
    field->SetEditable(true);
    field->ChangeValue(dv);
}

string zDB01::fieldToString(wxTextCtrl * field)
{
    string rstr;
    wxString s1 = field->GetValue();
    rstr = s1.ToStdString();
    return rstr;
}

void zDB01::de01()
{
    dlgDe01 dlg(NULL, wxID_ANY);
    if (dlg.ShowModal() == wxID_OK)
    {

    }

}

void zDB01::nb01()
{
    dlgNb01 dlg(NULL, wxID_ANY);
    dlg.lbxCats->InsertItems(lk1, 0);
    if (dlg.ShowModal() == wxID_OK)
    {

    }

}
void zDB01::listLk1Lk2()
{
//    dlgSelDB dlb;
    lk1.Clear();
    try
    {
        Connection conn(true);
        conn.connect(database.c_str(), server.c_str(), user.c_str(), password.c_str());
        Query query = conn.query();
        query << "select * from lk1, lk2 where lk2.idlk1 = lk1.idlk1 order by lk1.cat, lk2.lkn";
        zres = query.store();
        for (size_t i = 0; i < zres.num_rows(); i++)
        {
//            string sbuf = std::string(ares[i]["idlk1"]) + " " + std::string(ares[i]["cat"]);
//            lk1.Add(std::string(zres[i]["idlk1"]) + " " + std::string(zres[i]["cat"]));

//            wxMessageBox(std::string(ares[i]["idlk1"]) + " " + std::string(ares[i]["cat"]));
//           wxString tbuf = buf;
//           dbn.Insert(tbuf,0,1);
//            lbxDbName.InsertItems(ares[i]["Database"]);
//            cout << "Name: " << ares[i]["idlk1"] << " - Address: " << ares[i]["cat"] << endl;

        }

        if (zres.num_rows() == 0)
        {
            wxMessageBox("No Data Detected!!", "Zero Query Results", wxICON_HAND);
        }
    }
    catch (BadQuery er)     // handle any connection or
    {
        // query errors that may come up
        cerr << "Error: " << er.what() << endl;
        wxMessageBox("Connection Error!", "Connection Error Detected", wxICON_ERROR | wxICON_HAND);
    }
    catch (const BadConversion& er)
    {
        // Handle bad conversions
        cerr << "Conversion error: " << er.what() << endl <<
             "\tretrieved data size: " << er.retrieved <<
             ", actual size: " << er.actual_size << endl;
        wxMessageBox("Conversino Error!", "Conversin Error Detected", wxICON_HAND);
    }
    catch (const Exception& er)
    {
        // Catch-all for any other MySQL++ exceptions
        string buf = er.what();
        cerr << "Error: " << er.what() << endl;
        wxMessageBox("Miscalleanous Error!", "Other Error Detected", wxICON_HAND);
    }
}

void zDB01::insertCat(std::string cat, std::string memo)
{
    Connection conn(false);
    conn.connect(database.c_str(), server.c_str(), user.c_str(), password.c_str());
    Query query1 = conn.query();
    //INSERT INTO `lk1`(`idlk1`, `cat`, `ddes`) VALUES ('[value-1]','[value-2]','[value-3]')
    std::string qstr = "INSERT INTO `lk1`(`idlk1`, `cat`, `ddes`) VALUES ( ";
    qstr = qstr  +  "0" + ","+ "\"" + cat + "\",\"" + memo + "\")";
//       query1 << "INSERT INTO `lk1`(`idlk1`, `cat`, `ddes`) VALUES ( " <<  "0" << "," << cat << "," << memo << ")";
    query1.exec(qstr);

}
void zDB01::editCat(std::string idlk1, std::string cat, std::string memo)
{
    Connection conn(false);
    conn.connect(database.c_str(), server.c_str(), user.c_str(), password.c_str());
    Query query1 = conn.query();
    //INSERT INTO `lk1`(`idlk1`, `cat`, `ddes`) VALUES ('[value-1]','[value-2]','[value-3]')
    //UPDATE `lk1` SET `idlk1`='[value-1]',`cat`='[value-2]',`ddes`='[value-3]' WHERE 1
    std::string qstr = "UPDATE  `lk1` set `cat`= \"" + cat +"\", `ddes` =  \"" + memo + "\"" + " where `idlk1` = " +  strIdlk1;
//    qstr = qstr  +  "0" + ","+ "\"" + cat + "\",\"" + memo + "\")";
//       query1 << "INSERT INTO `lk1`(`idlk1`, `cat`, `ddes`) VALUES ( " <<  "0" << "," << cat << "," << memo << ")";
    query1.exec(qstr);

}

void zDB01::insertLink(std::string idlk1, std::string lkn, std::string lnk, std::string ddes)
{
    Connection conn(false);
    conn.connect(database.c_str(), server.c_str(), user.c_str(), password.c_str());
    Query query1 = conn.query();
    //INSERT INTO `lk2`(`idlk2`, `idlk1`, `lkn`, `lnk`, `ddes`) VALUES ('[value-1]','[value-2]','[value-3]','[value-4]','[value-5]')
    std::string qstr = "INSERT INTO `lk2`(`idlk2`, `idlk1`, `lkn`, `lnk`, `ddes`) VALUES (";
    qstr = qstr  +  "0" + "," + "\"" + idlk1 + "\",\"" + lkn + "\",\"" + lnk + "\",\"" + ddes +"\")";
    query1.exec(qstr);

}
void zDB01::DeleteLink(std::string delId)
{
    Connection conn(false);
    conn.connect(database.c_str(), server.c_str(), user.c_str(), password.c_str());
    Query query1 = conn.query();
//DELETE FROM `lk2` WHERE idlk2 = 712
    //INSERT INTO `lk2`(`idlk2`, `idlk1`, `lkn`, `lnk`, `ddes`) VALUES ('[value-1]','[value-2]','[value-3]','[value-4]','[value-5]')
    std::string qstr = "DELETE FROM `lk2` WHERE idlk2 = " + delId;
    query1.exec(qstr);

}

#include <wx/textfile.h>

void zDB01::editLink(std::string delId, std::string idkl2, std::string ilk, std::string lnk, std::string ddes, std::string idlk1)

{
    Connection conn(false);
    conn.connect(database.c_str(), server.c_str(), user.c_str(), password.c_str());
    Query query1 = conn.query();
//DELETE FROM `lk2` WHERE idlk2 = 712
    //INSERT INTO `lk2`(`idlk2`, `idlk1`, `lkn`, `lnk`, `ddes`) VALUES ('[value-1]','[value-2]','[value-3]','[value-4]','[value-5]')
    //UPDATE `lk2` SET `idlk2`='[value-1]',`idlk1`='[value-2]',`lkn`='[value-3]',`lnk`='[value-4]',`ddes`='[value-5]' WHERE 1


//    std::string qstr = "DELETE FROM `lk2` WHERE idlk2 = " + delId;
//    std::string qstr = "UPDATE `lk2` SET `lkn` = \" " + lnk + "\"" + ", `ddes`= \"" +  ddes + "\"" + " WHERE idlk2 = " + delId ;
//    std::string qstr = "UPDATE `lk2` SET `idlk1` =  \"" + delId + "\", " +  "`lkn` = \" " + lnk + "\"" + ", `ddes`= \"" +  ddes + "\"" + " WHERE idlk2 = " + delId ;
//    std::string qstr = "UPDATE `lk2` SET `idlk1` =  \"" + idlk1 + "\", " +  "`lkn` = \" " + lnk + "\"" + ", `ddes`= \"" +  ddes + "\"" + " WHERE idlk2 = " + delId ;
//    std::String qtr = "UPDATE `lk2` SET `idlk1`='"+ idlk1 + "',`lkn`='" + lkn + lnk + "[value-3]',`lnk`='[value-4]',`ddes`='[value-5]' WHERE idlk2 = 10
//    std::atring qstr = "UPDATE `lk2` SET `idlk1`=' " [value-2]" + "',`lkn`='[value-3]',`lnk`='[value-4]',`ddes`='[value-5]' WHERE idlk2 = 10
//    std::string qstr = "UPDATE `lk2` SET `idlk1`='" + idlk1 + "',`lkn`='" + ilk + "',`lnk`='" + lnk + "',`ddes`='" + ddes + "' WHERE idlk2 = " + idkl2;
//                       UPDATE `lk2` SET `idlk1`=162,`lkn`="https://archman.us:10000/\",`lnk`=\" Webmin",`ddes`="Note.\" WHERE `idlk2` = 1548";
    std::string qstr = "UPDATE `lk2` SET `idlk1`=" + idlk1 + ",`lkn`=\"" + ilk + "\",`lnk`=\"" + lnk + "\"" + ",`ddes`=\"" + ddes + "\" WHERE `idlk2` = " + delId + ";";

    if (query1.exec(qstr))
    {
        wxMessageBox("Update was OK!", "Update  OK");
    }
    else
    {
        wxTextFile file;
        string path = "/home/archman/workspace/cb/cpp/cppMD01/ddd01.txt";
        if (!wxFileExists(path))
        {
            file.Create(path);  // Create the file if it doesn't exist
        }
        else
        {
            file.Open(path);    // Open the file if it exists
        }

        // Add some lines to the file
        file.AddLine(qstr);

        // Write and save the file
        file.Write();
        file.Close();

        wxMessageBox("Update was NOT OK!", "Update  NOT OK");

    };

}

void zDB01::getCat()
{
    Connection conn(true);
    conn.connect(database.c_str(), server.c_str(), user.c_str(), password.c_str());
    Query query1 = conn.query();
//    std::string qstr = "UPDATE `lk2` SET `lkn` = \" " + lnk + "\"" + ", `ddes`= \"" +  ddes + "\"" + " WHERE idlk2 = " + delId ;
    query1 << "select * from lk1 where idlk1 =  \"" + strIdlk1 + "\"";
    StoreQueryResult ares = query1.store();
    zres = ares;
    //  query1.exec(qstr);
}
