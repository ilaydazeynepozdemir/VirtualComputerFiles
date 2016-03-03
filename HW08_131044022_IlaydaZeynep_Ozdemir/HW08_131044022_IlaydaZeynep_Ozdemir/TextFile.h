/* 
 * File:   TextFile.h
 * Author: ilayda zeynep ozdemir
 *
 * Created on December 17, 2015, 1:39 PM
 */

#ifndef TEXTFILE_H
#define	TEXTFILE_H
#include "File.h"
namespace File__131044022 {

    class TextFile : public File {
        // It has members for stroring the text type, Ascii, Unicode etc.
    public:
        TextFile(const std::string name_ = "text", const std::string owner_ = "ilayda", const int size_ = 0, const std::string text_type = "unicode");
        TextFile(const std::string name_ , const std::string owner_, const int size_ );
        //TextFile(int size=0);
        TextFile(const TextFile& orig);
        virtual ~TextFile();
        void setTextType(const std::string type);
        std::string getTextType()const;
        virtual bool cp(const TextFile &givenText);
        virtual void ls()const;
    private:
        std::string m_textType;

    };
}
#endif	/* TEXTFILE_H */

