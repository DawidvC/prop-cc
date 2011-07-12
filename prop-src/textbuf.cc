///////////////////////////////////////////////////////////////////////////////
//
//  Text buffer class
//
///////////////////////////////////////////////////////////////////////////////

#include <cstdlib>
#include <cstring>
#include "textbuf.h"

///////////////////////////////////////////////////////////////////////////////
//
//  Constructor and destructor
//
///////////////////////////////////////////////////////////////////////////////

TextBuffer::TextBuffer() : buffer(0), limit(0), cursor(0)
{}

TextBuffer::~TextBuffer()
{
  if (buffer)
    free (buffer);
}

///////////////////////////////////////////////////////////////////////////////
//
//  Transfer text from one buffer to another.
//
///////////////////////////////////////////////////////////////////////////////

TextBuffer::TextBuffer( const TextBuffer& b)
{
  TextBuffer * B = (TextBuffer *)&b;
  buffer = B->buffer;
  limit  = B->limit;
  cursor = B->cursor;
  B->buffer = 0;
  B->limit  = 0;
  B->cursor = 0;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Transfer text from one buffer to another.
//
///////////////////////////////////////////////////////////////////////////////

void TextBuffer::operator = ( const TextBuffer& b)
{
  if (&b == this)
    return;
  if (buffer)
    free (buffer); // kill self
  TextBuffer * B = (TextBuffer *)&b;
  buffer = B->buffer;
  limit  = B->limit;
  cursor = B->cursor;
  B->buffer = 0;
  B->limit  = 0;
  B->cursor = 0;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Emit a string
//
///////////////////////////////////////////////////////////////////////////////

void TextBuffer::emit( const char * text, long len)
{
  if (len < 0)
    len = std::strlen(text);
  if (cursor + len >= limit)
    grow(len);
  std::memcpy(cursor, text, len);
  cursor += len;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Emit a character
//
///////////////////////////////////////////////////////////////////////////////

void TextBuffer::emit( char c)
{
  if (cursor + 1 >= limit)
    grow(256);
  *cursor++ = c;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to expand the buffer
//
///////////////////////////////////////////////////////////////////////////////

void TextBuffer::grow( std::size_t growth)
{
  std::size_t old_size = cursor - buffer;
  std::size_t new_size = (limit - buffer) * 2 + growth;
  if (buffer)
    buffer = (char *)std::realloc(buffer, new_size);
  else
    buffer = (char *)std::malloc(new_size);
  cursor = buffer + old_size;
  limit  = buffer + new_size;
}
