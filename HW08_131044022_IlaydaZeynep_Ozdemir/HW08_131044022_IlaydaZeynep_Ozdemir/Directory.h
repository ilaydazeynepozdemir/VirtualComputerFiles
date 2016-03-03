/* 
 * File:   Directory.h
 * Author: ilayda zeynep ozdemir
 *
 * Created on December 17, 2015, 1:36 PM
 */

#ifndef DIRECTORY_H
#define	DIRECTORY_H
#include "File.h"
#include <vector>
#include <string>
namespace File__131044022 {
    //ls komutu calisir
    //cp klasor kopyalamaz sadece dosya kopyalar

    class Directory : public File {
    public:
        Directory(const std::string name_ = "mydir", std::string owner_ = "ilayda", int size_ = 0);
        Directory(const std::string name_ , int size_ );
        Directory(const Directory& orig);
        Directory& operator=(Directory& r_direct);
        void setTotal(const int tot);
        virtual int getTotal()const ;
        virtual void increaseTotal();
        
        //ls listeler 
        //R parametresi directory icindeki directorylere de girer
        //l parametresi cagirilan directory icindekilerin adlarini listerler
        virtual void ls()const;
        virtual void ls(const std::string parameter)const;
        
        //cd o directory icinde girer
        virtual Directory& cd( Directory& file);
        virtual Directory& cd();
        
        //verilen directorynin kopyasi alinip m_keep file* vektorune eklenir
        virtual bool cp(const Directory &givenDirect);
        


        // std::string path()const;



    private:
        int m_total;
        //std::vector<Directory*> direct;


    };
}
#endif	/* DIRECTORY_H */

