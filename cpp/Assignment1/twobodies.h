#ifndef TWOBODIES_H
#define TWOBODIES_H
#include "particle.h"
#include <iostream>

using namespace std;
class TwoBodiesDecayedParticle : public Particle {
    public:
        TwoBodiesDecayedParticle(const Particle &p1, const Particle &p2, int pid=0, float tau=0):
            Particle(p1+p2, pid, tau), m_p1(p1), m_p2(p2) {}

        void print() const {
            cout << "Combined pt and mass" << endl;
            cout << pt() << " " << mInv() << endl;
            cout << "Particle 1" << endl;
            cout << m_p1.pt() << " " << m_p1.mInv() << " " << m_p1.pid() << endl;
            cout << "Particle 2" << endl;
            cout << m_p2.pt() << " " << m_p2.mInv() << " " << m_p2.pid()<< endl;
        }
    private:
        Particle m_p1;
        Particle m_p2;
};
#endif