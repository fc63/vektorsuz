#include <iostream>

#include <string>

class Ogrenci {
  private: std::string isim,
  soyisim;
  int numarasi;
  public: Ogrenci(std::string isim, std::string soyisim, int numarasi) {
    this -> isim = isim;
    this -> soyisim = soyisim;
    this -> numarasi = numarasi;
    std::cout << this -> numarasi << " Numarali " << this -> isim << " , " << this -> soyisim << " eklenmistir";
  }
  Ogrenci() {
    std::cout << "\nConstroctor\n";
  }
  ~Ogrenci() {
    std::cout << "\nDest\n";
  }
  std::string getisim() const {
    return isim;
  }
  std::string getsoyisim() const {
    return soyisim;
  }
  int getno() const {
    return numarasi;
  }
};
int main() {
  int choice = 0, numara, ogrencisayaci = 0, kapasite = 2, i = 0, tempi = 0, j = 0;
  Ogrenci * ogrenci = new Ogrenci[kapasite];
  std::string ad, soyad;
  do {
    std::cout << "\nOgrenci Not Sistemi\n1.Ogrenci Ekle\n2.Ogrenci Sil\n3.Ogrenci Bilgileri\n4.Kapat\nSeciminiz: ";
    std::cin >> choice;
    switch (choice) {

    case 1: {
      std::cout << "\nOgrenci Adi :";
      std::cin >> ad;
      std::cout << "\nOgrenci Soyadi :";
      std::cin >> soyad;
      std::cout << "\nOgrenci Numarasi :";
      std::cin >> numara;
      if (kapasite > ogrencisayaci) {
        ogrenci[ogrencisayaci++] = {
          ad,
          soyad,
          numara
        };
      } else {
        Ogrenci * temp = new Ogrenci[++kapasite];
        for (i = 0; i < ogrencisayaci; i++) {
          temp[i] = ogrenci[i];
        }
        delete[] ogrenci;
        ogrenci = temp;
        std::cout << "\nkapasite artirildi\n";
        ogrenci[ogrencisayaci++] = {
          ad,
          soyad,
          numara
        };
      }
    }
    break;

    case 2: {

      for (i = 0; i < ogrencisayaci; i++) {
        std::cout << i << ". " << ogrenci[i].getisim() << " " << ogrenci[i].getsoyisim() << " " << ogrenci[i].getno() << "\n";
      }
      std::cout << "\nSeciminiz :";
      std::cin >> tempi;
      Ogrenci * temp = new Ogrenci[--kapasite];
      for (i = 0; i < tempi; i++) {
        temp[i] = ogrenci[i];
      }
      for (i = tempi; i < --ogrencisayaci; i++) {
        temp[i] = ogrenci[i + 1];
      }
      delete[] ogrenci;
      ogrenci = temp;
      delete[] temp;
      temp = nullptr;
      std::cout << "\nOgrenci Silindi ve kapasite dusuruldu\n";
      break;
    }
    case 3: {
      for (i = 0; i < ogrencisayaci; i++) {
        std::cout << i << " . " << ogrenci[i].getisim() << " " << ogrenci[i].getsoyisim() << " " << ogrenci[i].getno() << "\n";
      }
      break;
    }
    default:
      std::cout << "Cikis";
      break;

    }
  } while (choice != 4);
  delete[] ogrenci;
  ogrenci = nullptr;
  return 0;
}
