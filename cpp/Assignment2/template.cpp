#include "templatefv.h"
#include <iostream>

/* 
Used only for FourVectorT class

int main() {
    FourVectorT<float> p4_a(0,50., 7., 100.);
    FourVectorT<double> p4_b(0,50., 7., 100.);
    std::cout << p4_a.mInv() << " " << p4_a.pt() << std::endl;
    std::cout << p4_b.mInv() << " " << p4_b.pt() << std::endl;
    std::cout << (p4_a+p4_b).mInv() << " " << (p4_a+p4_b).pt() << std::endl;
}
    *
*/

int main() {
    FourVectorT<float> p4_a(0,50.,7.,100.);
    PtEtaPhiMassVector<double> p4_b(50,0.5,1.7,10.);
    std::cout << p4_a.mInv() << " " << p4_a.pt() << std::endl;
    std::cout << p4_b.mInv() << " " << p4_b.pt() << std::endl;
    std::cout << (p4_a+p4_b).mInv() << " " << (p4_a+p4_b).pt() << std::endl;
}