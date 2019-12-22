#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <iterator>
#include <vector>

using namespace std;

string CumleAra(string paragraf,string arananText,string arananText2)
{
	int baslangic = 0;
	int bitis = 0;
	//ilk text aranýr
	for (int index = 0; index < paragraf.length() - arananText.length(); index++) 
	{
		if (paragraf.substr(index,arananText.length()) == arananText)
		{
			baslangic = index + arananText.length();
			break;
		}
	}
	//ikinci text aranýr	
	for (int index = 0; index < paragraf.length() - arananText2.length(); index++) 
	{
		if (paragraf.substr(index,arananText2.length()) == arananText2)
		{
			bitis = index;
			break;
		}
	}
	
	return paragraf.substr(baslangic,bitis - baslangic);
}
int main()
{	
    //Dosya okuma
    string paragraf;
    ifstream fileparag ("the_truman_show_script.txt");
    if (fileparag.is_open())
    {
        getline (fileparag,paragraf);
        fileparag.close();
    }
    else cout << "Unable to open file";
    
    //Arana textler Dosya okuma
    string arananText,ilkcumle,soncumle,aranankelime,bulunan;
    //int baslangic = 0;
    int bitis = 0;
    ifstream myfile ("statements.txt");
    if (myfile.is_open())
    {
        while ( getline (myfile,arananText))
        {
        	for (int index = 0; index < arananText.length() - 3; index++) 
			{	
				if (arananText.substr(index,3) == "___")
				{
					ilkcumle = arananText.substr(0,index -1);
					soncumle = arananText.substr(index+3,arananText.length()-index-1);
					bulunan = CumleAra(paragraf,ilkcumle,soncumle);					
					cout << ilkcumle << bulunan << soncumle << "\n";
				}								
			}
        }
        myfile.close();
    }
    else cout << "Unable to open file";
	
	
    return 0;
}

