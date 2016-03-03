/* 
 * File:   Executable.h
 * Author: ilayda zeynep ozdemir
 *
 * Created on December 17, 2015, 1:37 PM
 */

#ifndef EXECUTABLE_H
#define	EXECUTABLE_H
#include "File.h"
namespace File__131044022 {
    //ls komutu calisir

    class Executable : public File {
        //It has members for storing the compiler that created the executable.
    public:
        Executable(const std::string name_="exec", const std::string owner_="ilayda",const std::string ext="g++");
        Executable(const std::string name_,const std::string ext);
        Executable(const Executable& orig);
        virtual ~Executable();
        void setExtension(const std::string Ext);
        std::string getExtension()const;
        virtual void ls()const;
        virtual void ls(const std::string parameter)const;
        virtual bool cp(const Executable &givenExe);
    private:
        std::string extension;

    };
}
#endif	/* EXECUTABLE_H */

