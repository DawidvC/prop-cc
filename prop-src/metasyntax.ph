///////////////////////////////////////////////////////////////////////////////
//
//  This file describes the interface to the meta-syntax compiler.
//
///////////////////////////////////////////////////////////////////////////////

#ifndef meta_syntax_h
#define meta_syntax_h

#include <new>
#include "parsegen.ph"


///////////////////////////////////////////////////////////////////////////////
//
//  Forward declarations
//
///////////////////////////////////////////////////////////////////////////////

class MetaSyntaxCompilerImpl;

///////////////////////////////////////////////////////////////////////////////
//
//  The meta-syntax compiler is responsible for translating patterns and
//  expressions written in meta-syntaxes into the equivalent in concrete
//  syntax.
//
///////////////////////////////////////////////////////////////////////////////

class MetaSyntaxCompiler : public virtual ParserCompiler
{
  MetaSyntaxCompiler (const MetaSyntaxCompiler&);
  void operator = (const MetaSyntaxCompiler&);
public:
  ////////////////////////////////////////////////////////////////////////////
  //
  //  Constructor and destructor
  //
  ////////////////////////////////////////////////////////////////////////////
           MetaSyntaxCompiler ();
  virtual ~MetaSyntaxCompiler ();

  ////////////////////////////////////////////////////////////////////////////
  //
  //  Methods to install a new grammar, parse expressions and patterns,
  //  and generate a new report.
  //
  ////////////////////////////////////////////////////////////////////////////
  void install_grammar( Id grammar_name, GramExp grammar);
  Exp parse_std::exp( Id grammar_name, const char *);
  Pat parse_pat( Id grammar_name, const char *);
  std::ostream& print_report( std::ostream&);

private:
   ////////////////////////////////////////////////////////////////////////////
   //
   //  Private implementation stuff.
   //
   ////////////////////////////////////////////////////////////////////////////
   MetaSyntaxCompilerImpl * impl;
   void compile_new_grammar( Id grammar_name, GramExp grammar);
   void flush_grammar( std::size_t memory_needed);
};

#endif
