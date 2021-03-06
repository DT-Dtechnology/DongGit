/*
 *    Feb. 2005
 *    Benjamin Gr�delbach
 */

/*
 * MD5 string/file hasher written in C++.
 * Copyright (C) 2009  David Vas, Anubisss
 * <http://code.google.com/p/md5-hasher/>

 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "stdafx.h"
#include <fstream>
#include <iostream>

#include "md5_wrapper.h"
#include "md5.h"

/*
 * internal hash function, calling
 * the basic methods from md5.h
 */
std::string md5wrapper::hashit(std::string text)
{
    MD5_CTX ctx;

    //init md5
    md5->MD5Init(&ctx);
    //update with our string
    md5->MD5Update(&ctx,
         (unsigned char*)text.c_str(),
         text.length());

    //create the hash
    unsigned char buff[16] = "";
    md5->MD5Final((unsigned char*)buff, &ctx);

    //converte the hash to a string and return it
    return convToString(buff);
}

/*
 * converts the numeric hash to
 * a valid std::string.
 * (based on Jim Howard's code;
 * http://www.codeproject.com/cpp/cmd5.asp)
 */
std::string md5wrapper::convToString(unsigned char *bytes)
{
    char asciihash[33];

    for(int i = 0; i < 16; i++)
    {
        ::sprintf(&asciihash[i*2], "%02x", bytes[i]);
    }
    asciihash[32] = '\0';
    return std::string(asciihash);
}

md5wrapper::md5wrapper()
{
    md5 = new MD5();
}

md5wrapper::~md5wrapper()
{
    delete md5;
}

/*
 * creates a MD5 hash from
 * "text" and returns it as
 * string
 */
std::string md5wrapper::getHashFromString(std::string text)
{
    return this->hashit(text);
}

/*
 * creates a MD5 hash from
 * a file specified in "filename" and
 * returns it as string
 * (based on Ronald L. Rivest's code
 * from RFC1321 "The MD5 Message-Digest Algorithm")
 */
std::string md5wrapper::getHashFromFile(std::string filename)
{
    FILE *file;
      MD5_CTX context;

    int len;
      unsigned char buffer[1024], digest[16];

    //open file
      if ((file = fopen(filename.c_str(), "rb")) == NULL)
    {
        return NONE_FILE_HASH;
    }

    //init md5
     md5->MD5Init(&context);

    //read the filecontent
    while((len = fread(buffer, 1, 1024, file)))
       {
        md5->MD5Update(&context, buffer, len);
    }

    /*
    generate hash, close the file and return the
    hash as std::string
    */
    md5->MD5Final(digest, &context);
     fclose(file);
    return convToString(digest);
 }

/*
 * EOF
 */
