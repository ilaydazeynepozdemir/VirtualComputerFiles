/* 
 * File:   TextFile.cpp
 *Author: ilayda zeynep ozdemir
 * 
 * Created on December 17, 2015, 1:39 PM
 */

#include "TextFile.h"
using namespace std;
namespace File__131044022 {

    TextFile::TextFile(const std::string name_, const std::string owner_,
            const int size_, const std::string text_type) : File(name_, owner_, size_) {
        setTextType(text_type);

    }

    TextFile::TextFile(const TextFile& orig) {
    }

    TextFile::~TextFile() {
    }

    void TextFile::setTextType(const std::string type) {
        m_textType = type;
    }
    string TextFile::getTextType()const{
        return m_textType;
    }
    bool TextFile::cp(const TextFile &givenText){
        cout<<"sadece directory ve file'da cp fonksiyonu calisir"<<endl;
        
    }
    void TextFile::ls()const{
        cout<<getName()<<endl;
    }
}
