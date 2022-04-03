#ifndef READ_H_INCLUDED
#define READ_H_INCLUDED

/*!
    \brief Function read the contents of the file to the buffer
    \param[in] structure containing buffer
    \returns 0 if there are no errors

*/
int ReadInBuF(struct TextInfo *Text);

/*!
    \brief Function splits the buffer into strings
    \param[in] structure containing buffer
    \param[out] structure containing strings and their size

*/

void CreateStrings(struct TextInfo Text, struct String *Str);

/*!
    \brief Function defines number of strings
*/

int StrCount(char *HumletText, long sizeFile);

/// All information about the text that is read from file
struct TextInfo {

    char *buf; ///< buffer with the contests of file
    struct String* strings; ///< pointers to strings in the buffer
    const char *nameOfText; ///< name of the text read from file
    int sizeOfText; ///< size of text read from file
    int numberOfStrings; ///< number of strings of text read from file

};

/// Strings from buffer and their size
struct String {

    char *data;
    int NumberOfChar;

};

#endif // READ_H_INCLUDED
