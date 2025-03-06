#ifndef TEMPLATEFV_H
#define TEMPLATEFV_H
#include <math.h>

template <class T>
class FourVectorT {
    public:
        // constructor
        FourVectorT(T px, T py, T pz, T e):  // note: T replaces type
            m_px(px), m_py(py), m_pz(pz), m_e(e) {}
        
        // getters
        T px() const {return m_px;}
        T py() const {return m_py;}
        T pz() const {return m_pz;}
        T e() const {return m_e;}
        T mInv() const {return sqrt(m_e*m_e-(m_px*m_px+m_py*m_py+m_pz*m_pz));}
        T pt() const {return sqrt(m_px*m_px+m_py*m_py);}

        // sum between FourVectors<double> and FourVectors<float>
        template <class T2>
        FourVectorT<T> operator+(const T2 & other) const{
            return FourVectorT(m_px+other.px(), m_py+other.py(), m_pz+other.pz(), m_e+other.e());
        }

        // setters
        void setPx(T px) {m_px=px;}
        void setPy(T py) {m_py=py;}
        void setPz(T pz) {m_pz=pz;}
        void setE(T e) {m_e=e;}

    private:
        T m_px;
        T m_py;
        T m_pz;
        T m_e;

};

template <class T>
class PtEtaPhiMassVector {
    public:
        PtEtaPhiMassVector(T pt, T eta, T phi, T mInv):
            m_pt(pt), m_eta(eta), m_phi(phi), m_mInv(mInv) {}

        //getters
        T pt() const {return m_pt;}
        T eta() const {return m_eta;}
        T phi() const {return m_phi;}
        T mInv() const {return m_mInv;}

        // create member functions to convert from one class to the other
        T px() const {return m_pt*cos(m_phi);}
        T py() const {return m_pt*sin(m_phi);}
        T pz() const {return m_pt*cos(theta());}
        T theta() const {return T(2.)*atan(exp(-m_eta));}
        T e() const {return sqrt(m_mInv*m_mInv+m_pt*m_pt+pz()*pz());}

        // define sum
        template <class T2>
        FourVectorT<T> operator+(const T2 & other) const{
            return FourVectorT(px()+other.px(), py()+other.py(), pz()+other.pz(), e()+other.e());
        }

        // setters
        void setPt(T pt) {m_pt=pt;}
        void setEta(T eta) {m_eta=eta;}
        void setPhi(T phi) {m_phi=phi;}
        void setMInv(T mInv) {m_mInv=mInv;}

    private:
        T m_pt;
        T m_eta;
        T m_phi;
        T m_mInv;

};



#endif