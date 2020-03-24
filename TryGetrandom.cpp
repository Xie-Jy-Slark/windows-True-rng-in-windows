#include <iostream>
#include "Getrandom.h"

using namespace::std;

signed main() {
  Getrandom rng;
  unsigned long long maxll{ 0xffffffffffffffff };
  cout << "Max of unsigned long long: \n" <<maxll << endl;
  cout << "\nmethod: rng.get():" << endl;
  for (auto i(0); i < 10; i++)
    cout << rng.get() << endl;
  cout << "\nMethod: rng.getint():" << endl;
  for (auto i(0); i < 10; i++)
    cout << rng.getint() << " ";
  cout << endl;
  for (auto i(0); i < 10; i++)
    cout << rng.getint(-5, 7) << " ";
  cout << endl << "\nMethod: rng.getdouble():" << endl;
  for (auto i(0); i < 10; i++)
    cout << rng.getdouble() << " ";
  cout << endl;
  for (auto i(0); i < 10; i++)
    cout << rng.getdouble(2.0, 4.0) << " ";
  cout << endl << "\navoid bugs:" << endl;
  cout << rng.getint(0, 0) << endl;
  cout << rng.getdouble(0, 0) << endl;
  cout << rng.getint(0, -1) << endl;
  cout << rng.getdouble(0, -1) << endl;
  return 0;
}
