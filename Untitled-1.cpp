#include <iostream>
using namespace std;
int bac_da_thuc(int x) {
  int b = -1;
  while (x > 0) {
    b++;
    x = x / 2;
  }
  return b;
}
int nhan_da_thuc(int a, int b) {
  int kq = 0;
  while (b > 0) {
    if (b % 2 == 1) {
      kq = kq ^ a;
    }
    a = a * 2;
    b = b / 2;
  }
  return kq;
}
void chia_da_thuc(int A, int B, int &Q, int &R) {
  Q = 0;
  R = A;
  int bacB = bac_da_thuc(B);
  while (bac_da_thuc(R) >= bacB) {
    int dich_trai = bac_da_thuc(R) - bacB;
    int d = 1;
    for (int i = 0; i < dich_trai; i++) {
      d = d * 2;
    }
    Q = Q ^ d;
    R = R ^ (B * d);
  }
}
int tim_nghich_dao(int a, int m) {
  int r1 = m;
  int r2 = a;
  int t1 = 0;
  int t2 = 1;
  cout << "--- Tim nghich dao cua " << a << " ---" << "\n";
  while (r2 > 0) {
    int q = 0;
    int r = 0;
    chia_da_thuc(r1, r2, q, r);
    cout << "Phep chia r: " << r1 << " / " << r2 << " duoc thuong q = " << q
         << ", so du r = " << r << "\n";
    int q_nhan_t2 = nhan_da_thuc(q, t2);
    cout << "Phep nhan: q * t2 = " << q << " * " << t2 << " = " << q_nhan_t2
         << "\n";
    int t = t1 ^ q_nhan_t2;
    cout << "Tinh t moi: t1 ^ (q * t2) = " << t1 << " ^ " << q_nhan_t2 << " = "
         << t << "\n\n";
    r1 = r2;
    r2 = r;
    t1 = t2;
    t2 = t;
  }
  cout << "Nghich dao cua " << a << " la: " << t1 << "\n\n";
  return t1;
}
int main() {
  int m = 1033;
  int a = 523;
  int b = 1015;
  tim_nghich_dao(a, m);
  tim_nghich_dao(b, m);
  return 0;
}