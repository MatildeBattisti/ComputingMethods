#ifndef FOURVECTOR_H
#define FOURVECTOR_H
#include <math.h>

class FourVector {
    public:
        // constructor
        FourVector() {}
        FourVector(float px, float py, float pz, float e):
            m_px(px), m_py(py), m_pz(pz), m_e(e) {}  // initialize attributes of the class

        // getters
        float px() const {return m_px;}
        float py() const {return m_py;}
        float pz() const {return m_pz;}
        float e() const {return m_e;}

        // Functions returning invariant mass and transverse momentum
        float mInv() const {return sqrt(m_e*m_e-(m_px*m_px+m_py*m_py+m_pz*m_pz));}
        float pt() const {return sqrt(m_px*m_px+m_py*m_py);}

        // Operators that sum FourVectors or multiply them by scalars
        FourVector operator+(const FourVector & other) const{
            return FourVector(m_px+other.m_px, m_py+other.m_py, m_pz+other.m_pz, m_e+other.m_e);
        }

        FourVector operator*(float scalar) const{
            return FourVector(m_px*scalar, m_py*scalar, m_pz*scalar, m_e*scalar);
        }

        // setters
        void setPx(float px) {m_px=px;}
        void setPy(float py) {m_py=py;}
        void setPz(float pz) {m_pz=pz;}
        void setE(float e) {m_e=e;}

    private:
        float m_px;
        float m_py;
        float m_pz;
        float m_e;
};
#endif