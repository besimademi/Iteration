#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

class matrica {
    double m[10][11];
    double gnm = 0;
    double xn[10];
    int iterimet;
public:
    //Funksioni per te dhene vlerat ne matriks
    void matric(int n) {
        cout << "Jepeni sistemin:\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n + 1; j++) {
                if (j == n) {
                    cout << "Jepe rezultatin e rreshtit " << i + 1 << " :"; cin >> m[i][j];
                }
                else {
                    cout << "Jepeni x" << j + 1 << " tek reshti " << i + 1 << " :"; cin >> m[i][j];
                }
            }
        }
        cout << "\n\nJepeni X(0): ";
        for (int i = 0; i < n; i++)
        {
            cout << "Jepeni x" << i + 1 << " (0): "; cin >> xn[i];
        }
    }
    //Funksioni i cili e rregullon xn
    void rregullo_xn(int n)
    {
        for (int i = 0; i < n; i++)
        {
            double shuma = m[i][n];
            for (int j = 0; j < n; j++)
            {
                if (j != i)
                {
                    shuma = shuma - m[i][j] * xn[j];
                }
            }
            xn[i] = shuma / m[i][i];
        }

    }

    //Zgjidhja me gaus seidelin
    void gaus_seidel(int n, int iter_max, double gabimi)//parametrat e funksionit: sa elemente ka funksioni n, sa iterime te kryhen me shume, dhe gabimi i toleruar
    {
        for (int iter = 0; iter < iter_max; iter++)// cikel per xhdo iterim
        {
            double gab_max = 0;
            for (int i = 0; i < n; i++)//cikel per te llogaritur xhdo element te xn
            {
                double shuma = m[i][n];
                for (int j = 0; j < n; j++)//cikel per te kaluar tek xhdo element i reshtit mbledhja mes tyre dhe krahasimi se mos te jete i=j
                {
                    if (j != i)
                    {
                        shuma = shuma - m[i][j] * xn[j];//shuma e reshtit e cila behet
                    }
                }
                double xn_vjeter = xn[i];//ruajtja e xn se vjeter per te krahasuar gabimin
                xn[i] = shuma / m[i][i];// update i xn 
                gab_max = max(gab_max, fabs(xn[i] - xn_vjeter));//llogaritja i gabimit
            }
            if (gab_max < gabimi)// kushti i gabimit
            {
                cout << "Konvergjanca u arit pas " << iter + 1 << " iterimesh.\n\n";
                break;// ne qofte se arihet do te nderpritet funskioni
            }
            iterimet = iter;
        }
        cout << "Nuk mund te plotesohej gabimi i kerkuar!! Por perseri do te shfaqen vlerat e xn te reja pas " << iterimet + 1 << " iterimesh.\n";
    }


    void shfaq(int n) {
        //shfaqja e xn perfundimtare
        for (int i = 0; i < n; i++)
        {
            cout << "Vlerat e reja pas " << iterimet + 1 << " iterimeve:\n";
            cout << "x" << i + 1 << " = " << xn[i] << endl;
        }
    }
};

int main() {
    matrica mat;
    int n, zgjedhja;
    int iterimet;
    double gabimi;
    cout << "Mire se vini ne programin e 'Metoda iterative per zgjidhjen e sistemve te ekuacioneve lineare.' \n\n " << setw(50) << "METODA E GAUSS SEIDELIT :)\n";
    do {
        cout << "A deshironi te vazhdoni ne program?\n1.PO.\n2.JO.\n"; cin >> zgjedhja;//zgjedhja e perderuesit
        switch (zgjedhja) {
        case 1://rasti 1
            cout << "Jepeni madhesin e sistemit. (me shume 10)"; cin >> n;
            cout << "Jepeni numrin me te madh te iterimeve: "; cin >> iterimet;
            cout << "Jepeni tolerimin e gabimit: "; cin >> gabimi;
            mat.matric(n);
            mat.rregullo_xn(n);
            mat.gaus_seidel(n, iterimet, gabimi);
            mat.shfaq(n);
            break;
        case 2://rasti 2
            cout << "Diten e mire. :)\n";
            break;
        default://zgjedhje gabim
            cout << "Keni dhene zgjedhje gabim. Provo perseri.\n";
            break;
        }
    } while (zgjedhja != 2);// hapat e mesiperm tek funskioni kryesor de te perseriten ne qofte se zgjedhja eshte e ndryshme prej 2
    return 0;
}
