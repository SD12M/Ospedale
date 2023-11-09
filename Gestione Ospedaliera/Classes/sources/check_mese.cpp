#include "Classes/headers/check_mese.h"
bool CheckMese::check_mese(const QString &value)
{
    if (value != "gennaio" && value != "febbraio" && value != "marzo" &&
        value != "aprile" && value != "maggio" && value != "giugno" &&
        value != "luglio" && value != "agosto" && value != "settembre" &&
        value != "ottobre" && value != "novembre" && value != "dicembre") {
        return false;
    }
    return true;
}
