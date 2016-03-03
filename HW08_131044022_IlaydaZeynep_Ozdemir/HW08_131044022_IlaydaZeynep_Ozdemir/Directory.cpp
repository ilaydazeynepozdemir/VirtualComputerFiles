/* 
 * File:   Directory.cpp
 * Author: ilayda zeynep ozdemir
 * 
 * Created on December 17, 2015, 1:36 PM
 */

#include <string.h>

#include "Directory.h"

using namespace std;
namespace File__131044022 {

    Directory::Directory(const std::string name_, const std::string owner_, const int size_) : File(name_, owner_, size_), m_total(0) {
        // m_allFile.push_back(this);
        setPermission("drwxrwxr-x");
        increaseTotal();
    }

    Directory::Directory(const std::string name_, const int size_) : File(name_, size_), m_total(0) {
        setPermission("drwxrwxr-x");
        increaseTotal();
    }

    Directory::Directory(const Directory& orig) : File(orig) {
        setPermission("drwxrwxr-x");
        setTotal(orig.getTotal());
    }

    Directory& Directory::operator=(Directory& r_direct) {
        if ((this) != &r_direct) {
            m_keep.clear();
            m_keep.resize(0);
        }
        for (int i = 0; i < r_direct.m_keep.size(); ++i)
            m_keep.push_back(r_direct.m_keep.at(i));


        setLastModification(r_direct.getLastModificationDay(), r_direct.getLastModificationMounth(), r_direct.getLastModificationYear());
        setName(r_direct.getName());
        setOwner(r_direct.getOwner());
        setSize(r_direct.getSize());
        setPermission(r_direct.getPermission());
        setPath(r_direct.path());
        setPermission("drwxrwxr-x");
        setTotal(r_direct.getTotal());
        return (*this);
    }

    void Directory::setTotal(const int tot) {
        m_total = tot;
    }

    void Directory::increaseTotal() {
        ++m_total;
    }

    int Directory::getTotal()const {
        return m_total;
    }

    void Directory::ls()const {
        //1'den baslatma sebebim kendisini de tutuyor
        //burada kaldiiiiiiiiin
        for (int i = 1; i < m_keep.size(); ++i) {
            cout << /*m_keep.at(i)->getTotal()<<*/m_keep.at(i)->getName() << "    ";
        }
        //m_keepte kendisi ve kendisinden sonrakileri tutuyorum
    }

    void Directory::ls(const std::string parameter)const {
        if (parameter == "-l") {//total yazdir
            cout << "Total=" << getTotal() << endl;
            for (int i = 1; i < m_keep.size(); ++i) {
                // Directory* direct = dynamic_cast<Directory*> (m_keep.at(i));
                //NULL olmamalı ama oluyor
                //directoryden baska bir sey gelmiyor bu ls'e
                //BURAYI DUZELTMEDEN YOLLAMA

                //if (direct != NULL)
                //cout << (direct->getTotal());
                cout << m_keep.at(i)->getPermission() << " " << getOwner()
                        << " " << m_keep.at(i)->getSize() << " " << m_keep.at(i)->getLastModification()
                        << " " << m_keep.at(i)->getName() << endl;
            }
        } else if (parameter == "-R") {//yanlis
            for (int i = 1; i < m_keep.size(); ++i) {//birden baslama sebebi kendi icin cagirmasin diye
                cout << this->m_keep.at(i)->path() << ":" << endl;
                this->ls();
                cout << endl; //ilk elemani icin cagiriyor sonra o elemaninin 
                //pointer vectorundeki elemanlari icin cagiriyor
                //icindeki klasor icin yani
                for (int j = 0; j < m_keep.at(i)->m_keep.size(); ++j) {//icindeki pointer vektorunden kopyalanan seye ulasmali
                    m_keep.at(i)->m_keep.at(j)->ls("-R");
                }
            }

        } else if (parameter == "-a") {//gizli dosyalar
            this->ls();
        } /*else if (parameter == "-Rl") {//icindekilerin de icine giriyor
            ls("-R");
            ls("-l");
        }*/
        return;
    }

    Directory& Directory::cd(Directory& file) {
        for (int i = 0; i < m_keep.size(); ++i) {
            if (file.getName() == m_keep.at(i)->getName() &&
                    file.getOwner() == m_keep.at(i)->getOwner()
                    && file.getSize() == m_keep.at(i)->getSize()) {
                file.setPath(m_keep.at(i)->path());
            }
        }
        setPath(file.path() + "/" + file.getName());
        //cout << path() << endl;
        return (*this);
    }

    Directory& Directory::cd() {
        //  File::cd();
        if (!m_keep.empty())
            m_keep.clear();
        else cout << "Zaten en bastasin! Hic dosya yok!" << endl;
        return (*this);
    }

    bool Directory::cp(const Directory& givenDirect) {
        Directory* copyDirect = new Directory(givenDirect); //copy constructor
        copyDirect->setPath(givenDirect.path() + "/" + getName()); //kopyalayip pathi degistiriyorum
        copyDirect->setTotal(givenDirect.getTotal());
        m_keep.push_back(copyDirect);
        //son eklenenin size'i ile ana dosyanin sizelerini toplariz
        this->setSize(this->getSize() + copyDirect->getSize()); //cagiranin sizei
        return true;
    }

}
