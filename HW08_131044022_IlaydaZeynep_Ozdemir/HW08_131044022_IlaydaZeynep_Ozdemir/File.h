/* 
 * File:   File.h
 * Author: ilayda zeynep ozdemir
 *
 * Created on December 17, 2015, 1:20 PM
 */

#ifndef FILE_H
#define	FILE_H
#include <string>
#include <iostream>
#include <vector>

namespace File__131044022 {
    //turetilmis classlar hakkindahicbir bilgi kullanmadan yazilir
    //ls komutu calisir

    class File {
    public:
        File();
        File(const std::string name_);
        File(const std::string name_, const std::string owner_);
        File(const std::string name_, const int size_);
        File(const std::string name_, const std::string owner_, const int size_);

        File(const File& orig);
        // virtual ~File();
        File& operator=(File& r_file);
        void setName(const std::string nameOfFile);
        void setOwner(const std::string ownerOfFile);
        void setSize(const int sizeOfFile);
        
        void setLastModification(const int day, const int mounth, const int year);

        std::string getName()const;
        std::string getOwner()const;
        int getSize()const;


        std::string getLastModification()const;
        int getLastModificationDay()const;
        int getLastModificationMounth()const;
        int getLastModificationYear()const;
        std::string path()const; //getPath();)

        std::string getPermission()const;
        void setPermission(const std::string Perm);


        virtual void ls(const std::string parameter)const;
        virtual void ls()const;
        virtual File& cd( File file);
        virtual File& cd(); //bunun virtual olmasina gerek yok???
        void Fill(File *fill_);

        virtual bool cp(const File& givenFile); //verilen dosyayi gecerli dosyaya kopyalayacak // kopyalanabilirse true donecek
        std::vector<File*> m_keep; //cd icin bulundugu yerleri tutar



    protected:

        void setModification();
        void setPath(const std::string Path);
        //std::vector<File*> m_allFile;

    private:
        std::string m_name;
        std::string m_owner;
        std::string m_permission;

        int m_size;
        int m_last_modification_day;
        int m_last_modification_mounth;
        int m_last_modification_year;
        std::string m_path;


    };
}
#endif	/* FILE_H */

