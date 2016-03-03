/* 
 * File:   Executable.cpp
 * Author: ilayda zeynep ozdemir
 * 
 * Created on December 17, 2015, 1:37 PM
 */

#include "Executable.h"
using namespace std;
namespace File__131044022 {

    
    Executable::Executable(const std::string name_, const std::string owner_, const std::string ext) : File(name_, owner_) {
        setExtension(ext);
    }

    Executable::Executable(const std::string name_, const std::string ext) : File(name_) {
        setExtension(ext);
    }

    Executable::Executable(const Executable& orig) {

    }

    Executable::~Executable() {
    }

    void Executable::setExtension(const std::string Ext) {
        extension = Ext;
    }

    std::string Executable::getExtension()const {
        return extension;
    }

    void Executable::ls()const {
        cout << "ls: cannot access exec.dh: No such file or directory" << endl;
    }

    void Executable::ls(const std::string parameter)const {
        cout << "ls: cannot access exec.dh: No such file or directory" << endl;
    }

    bool Executable::cp(const Executable &givenExe) {
        cout << "sadece directory ve file'da cp fonksiyonu calisir" << endl;
    }

}