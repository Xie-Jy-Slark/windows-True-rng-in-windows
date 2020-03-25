#include "Getrandom.h"

Getrandom::Getrandom() {
  LPCSTR UserName("MyKeyContainer");
  if (CryptAcquireContext(&Rnd, UserName, NULL, PROV_RSA_FULL, 0)) available = true;
  else {
    if (GetLastError() == NTE_BAD_KEYSET) {
      if (CryptAcquireContext(
        &Rnd,
        UserName,
        NULL,
        PROV_RSA_FULL,
        CRYPT_NEWKEYSET)) available = true;
      else available = false;
    }
    else available = false;
  }
}

Getrandom::~Getrandom() {
  if (!CryptReleaseContext(Rnd, 0))
    throw "The handle could not be released";
}

unsigned long long Getrandom::get() {
  unsigned long long rev{};
  if (available && CryptGenRandom(Rnd, 8, (BYTE*)(&rev))) return rev;
  else return 0;
}

long long Getrandom::getint(long long left, long long right) {
  unsigned long long rev{};
  if (right > left && available && CryptGenRandom(Rnd, 8, (BYTE*)(&rev))) return rev % (right - left) + left;
  else return left;
}
double Getrandom::getdouble(double left, double right) {
  unsigned long long rev{};
  if (right > left && available && CryptGenRandom(Rnd, 8, (BYTE*)(&rev))) {
    long double revr{ static_cast<long double>(rev) / 0xffffffffffffffff };
    return static_cast<double>(revr * (right - left) + left);
  }
  else return left;
}
