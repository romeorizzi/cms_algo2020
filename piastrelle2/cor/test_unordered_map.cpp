#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;
 
int main()
{
    unordered_map<string, int> months;
    months["january"] = 31;
    months["february"] = 28;
    months["march"] = 31;
    months["april"] = 30;
    months["may"] = 31;
    months["june"] = 30;
    months["july"] = 31;
    months["august"] = 31;
    months["september"] = 30;
    months["october"] = 31;
    months["november"] = 30;
    months["december"] = 31;
    cout << "september -> " << months["september"] << endl;
    cout << "april     -> " << months["april"] << endl;
    cout << "december  -> " << months["december"] << endl;
    cout << "february  -> " << months["february"] << endl;
    cout << "pippo  -> " << months["pippo"] << endl;
    string mio("pippo");
    string tuo = ""; tuo += "jan"; tuo += "uary";
    cout << mio << "  -> " << months[mio] << endl;
    cout << tuo << "  -> " << months[tuo] << endl;
    return 0;
}
