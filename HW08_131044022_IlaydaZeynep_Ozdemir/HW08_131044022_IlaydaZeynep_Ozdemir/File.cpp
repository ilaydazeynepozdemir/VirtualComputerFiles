/* 
 * File:   File.cpp
 * Author: ilayda zeynep ozdemir
 * 
 * Created on December 17, 2015, 1:20 PM
 */

#include "File.h"
#include <time.h>
using namespace std;

namespace {
    std::string Itoa(int number);

    std::string Itoa(int number) {
        std::string stringNum;
        while (number > 0) {
            int last = number % 10;
            number /= 10;
            char i = '0';
            i = i + last;
            stringNum = i + stringNum;
        }
        return stringNum;
    }
}
namespace File__131044022 {

    File::File() : m_path(".") {
        m_keep.resize(0);
        setName("file");
        setOwner("ilayda");
        setModification();
        setSize(0);
        m_keep.push_back((this));
    }

    File::File(const string name_, const string owner_) : m_path(".") {
        m_keep.resize(0);
        setName(name_);
        setOwner(owner_);
        setModification();
        setPermission("rwxrwxr-x");
        setSize(0);
        m_keep.push_back((this));
    }

    File::File(const string name_, const string owner_, const int size_) : m_path(".") {
        m_keep.resize(0);
        setName(name_);
        setOwner(owner_);
        setModification();
        setPermission("rwxrwxr-x");
        setSize(size_);
        m_keep.push_back((this));
    }

    File::File(const string name_, const int size_) : m_path(".") {
        m_keep.resize(0);
        setName(name_);
        setOwner("ilayda");
        setPermission("rwxrwxr-x");
        setModification();
        setSize(size_);
        m_keep.push_back((this));
    }

    File::File(const string name_) : m_path(".") {
        m_keep.resize(0);
        //  m_allFile.resize(0);
        //  m_allFile.push_back(this);
        setName(name_);
        setOwner("ilayda");
        setModification();
        setPermission("rwxrwxr-x");
        setSize(0);
        m_keep.push_back((this));
    }

    File::File(const File& orig) : m_last_modification_mounth(orig.getLastModificationMounth()),
    m_last_modification_year(orig.getLastModificationYear()), m_last_modification_day(orig.getLastModificationDay()),
    m_name(orig.getName()), m_owner(orig.getOwner()), m_size(orig.getSize()), m_path(orig.path()) {
        setPermission(orig.getPermission());
        m_keep.resize(0);
        for (int i = 0; i < orig.m_keep.size(); ++i)
            m_keep.push_back(orig.m_keep.at(i));
    }

    File& File::operator=(File& r_file) {

        if ((this) != &r_file) {
            m_keep.clear();
            m_keep.resize(0);
        }
        for (int i = 0; i < r_file.m_keep.size(); ++i)
            m_keep.push_back(r_file.m_keep.at(i));


        setLastModification(r_file.getLastModificationDay(), r_file.getLastModificationMounth(), r_file.getLastModificationYear());
        setName(r_file.getName());
        setOwner(r_file.getOwner());
        setSize(r_file.getSize());
        setPermission(r_file.getPermission());
        setPath(r_file.path());
        return (*this);

    }

    void File::setModification() {
        time_t now = time(NULL);
        tm *local = localtime(&now);
        //ilk olusturuldugu tarih bilgileri
        setLastModification(local->tm_mday, 1 + local->tm_mon, 1900 + local->tm_year);
    }

    void File::setName(const string nameOfFile) {
        m_name = nameOfFile;
    }

    void File::setOwner(const string ownerOfFile) {
        m_owner = ownerOfFile;
    }

    void File::setSize(const int sizeOfFile) {
        m_size = sizeOfFile;
    }

    void File::setLastModification(const int day, const int mounth, const int year) {
        m_last_modification_day = day;
        m_last_modification_mounth = mounth;
        m_last_modification_year = year;
    }

    string File::getName()const {
        return m_name;
    }

    string File::getOwner()const {
        return m_owner;
    }

    int File::getSize()const {
        return m_size;
    }

    string File::getLastModification()const {
        return (Itoa(getLastModificationYear()) + "." + Itoa(getLastModificationMounth()) + "." + Itoa(getLastModificationDay()));
    }

    int File::getLastModificationDay()const {
        return (m_last_modification_day);
    }

    int File::getLastModificationMounth()const {
        return m_last_modification_mounth;
    }

    int File::getLastModificationYear()const {
        return m_last_modification_year;
    }

    string File::getPermission()const {
        return m_permission;
    }

    void File::setPermission(const std::string Perm) {
        m_permission = Perm;
    }

    void File::setPath(const std::string Path){
        m_path = Path;
    }
    

    string File::path()const {
        return m_path;
    }

    //alinan şey degistiğinde bu da degismesin diye yeni bir File* olusturulur

    bool File::cp(const File &givenFile) {
        File* copyFile = new File(givenFile); //copy constructor
        copyFile->setPath(givenFile.path() +"/"+ getName());//kopyalayip pathi degistiriyorum
        //cout<<"*******"<<copyFile->path()<<endl;
        m_keep.push_back(copyFile);
        //son eklenenin size'i ile ana dosyanin sizelerini toplariz
        this->setSize(this->getSize() + copyFile->getSize()); //cagiranin sizei
       
        
        return true;
    }

    File& File::cd( File file) {

        cout << "Not a directory" << endl;
        return (*this);
    }

    File& File::cd() {
        cout << "Not a directory" << endl;
        return (*this);
    }

    void File::ls(const string parameter)const {//terminalde bu sekilde isim basiyor
        cout << (*this).getName() << endl;
    }

    void File::ls()const {//terminalde bu sekilde ismini basiyor
        cout << (*this).getName() << endl;
    }

   
}
