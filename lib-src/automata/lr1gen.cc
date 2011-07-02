//////////////////////////////////////////////////////////////////////////////
// NOTICE:
//
// ADLib, Prop and their related set of tools and documentation are in the
// public domain.   The author(s) of this software reserve no copyrights on
// the source code and any code generated using the tools.  You are encouraged
// to use ADLib and Prop to develop software, in both academic and commercial
// settings, and are free to incorporate any part of ADLib and Prop into
// your programs.
//
// Although you are under no obligation to do so, we strongly recommend that
// you give away all software developed using our tools.
//
// We also ask that credit be given to us when ADLib and/or Prop are used in
// your programs, and that this notice be preserved intact in all the source
// code.
//
// This software is still under development and we welcome any suggestions
// and help from the users.
//
// Allen Leung
// 1994
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
//  This file contains the implementation of class |LR1Gen|, which
//  is a parser table generator for LR(1) grammars.
//////////////////////////////////////////////////////////////////////////////

#include <iostream.h>
#include <stdlib.h>
#include <string>
#include <new.h>
#include <AD/automata/lr1gen.h>     // LR(1) parser generator
#include <AD/automata/item.h>       // LR items
#include <AD/automata/lr0.h>        // LR(0) finite state machine
#include <AD/memory/mempool.h>      // Memory pool
#include <AD/contain/dchmap.h>      // Direct chaining hash map

//////////////////////////////////////////////////////////////////////////////
//  Constructor and destructor
//////////////////////////////////////////////////////////////////////////////

LR1Gen::LR1Gen()
{}

LR1Gen::~LR1Gen()
{}

//////////////////////////////////////////////////////////////////////////////
//  Parser compiler
//////////////////////////////////////////////////////////////////////////////

void LR1Gen::compile( const Grammar& /*G*/)
{
  ///////////////////////////////////////////////////////////////////////////
  // Some auxiliary data structures.
  //    a) A memory pool is used for memory management in this method.
  ///////////////////////////////////////////////////////////////////////////
  MemPool mem;   // Memory manager for shortlived objects.

  ///////////////////////////////////////////////////////////////////////////
  // Preprocess grammar and compute the CFSM.
  ///////////////////////////////////////////////////////////////////////////

  ///////////////////////////////////////////////////////////////////////////
  // Start generating the parser tables.
  ///////////////////////////////////////////////////////////////////////////
  start();

  ///////////////////////////////////////////////////////////////////////////
  // Generate the state transitions.
  ///////////////////////////////////////////////////////////////////////////

  ///////////////////////////////////////////////////////////////////////////
  // Finish the table compression process.
  ///////////////////////////////////////////////////////////////////////////
  finish();
}

//////////////////////////////////////////////////////////////////////////////
//  Code emission
//////////////////////////////////////////////////////////////////////////////

std::ostream& LR1Gen::gen_code( std::ostream& out, const char name []) const
{
  Super::gen_code( out, name);
  return out;
}
