/*******************************************************************************
*
* Embedded Wizard - GUI Solutions by TARA Systems
*
*                                                Copyright (c) TARA Systems GmbH
*                                    written by Paul Banach and Manfred Schweyer
*
********************************************************************************
*
* This file was generated automatically by Embedded Wizard tools based on the
* GUI project configuration and resources provided by you.
*
* Please do not modify this file! Any changes will be lost when it is generated
* again by the Embedded Wizard code generation process.
*
* The template of this heading text can be found in the file 'head.ewt' in the
* directory 'Platforms' of your Embedded Wizard installation directory. If you
* wish to adapt this text, please copy 'head.ewt' into your project directory
* and edit only that copy. Please avoid any modifications of the original
* template file.
*
* License, ownership and responsibility:
*
*   - The generated code is based on your project configuration and forms part
*     of your application. The application-specific content of this file
*     (including project-specific classes, resources and UI logic) is owned by
*     you or your licensors. You remain responsible for the overall design,
*     implementation, testing and validation of your application, including any
*     project-specific code and any changes or additions you make to the
*     generated code. TARA Systems GmbH is not responsible for defects or
*     malfunctions caused by such project-specific content or modifications.
*
*   - The use of Embedded Wizard Studio, the Embedded Wizard command line code
*     generator (ChoraC), the Embedded Wizard technology used to generate this
*     file and any Embedded Wizard Platform Packages and Runtime Components
*     required to build and run the generated code is subject to the Embedded
*     Wizard license terms (as published at https://www.embedded-wizard.de/legal),
*     including in particular:
*
*       - Embedded Wizard Terms and Conditions (EWTC)
*       - Embedded Wizard License Agreement (EWLA)
*       - Embedded Wizard Community License (EWCL)
*
*     The specific agreement(s) applicable to you and the applicable warranties
*     and limitations of liability are exclusively governed by these license
*     terms.
*
* Version  : 15.03
* Profile  : ESP32
* Platform : Espressif.ESP32.RGB565
*
*******************************************************************************/

#include "ewlocale.h"
#include "_ResourcesBitmap.h"
#include "_ResourcesFont.h"
#include "_ResourcesFontSet.h"
#include "Resources.h"

/* Strings for the language 'Default'. */
EW_CONST_STRING_PRAGMA static const unsigned short _StringsDefault0[] =
{
  0xFFFF, 0xFFFF, 0xC557, 0x0054, 0x0068, 0x0065, 0x0020, 0x0070, 0x0072, 0x006F,
  0x0070, 0x0065, 0x0072, 0x0074, 0x0079, 0x0020, 0x0027, 0x0046, 0x0072, 0x0061,
  0x006D, 0x0065, 0x0053, 0x0069, 0x007A, 0x0065, 0x0027, 0x0020, 0x0069, 0x0073,
  0x0020, 0x0052, 0x0045, 0x0041, 0x0044, 0x0020, 0x004F, 0x004E, 0x004C, 0x0059,
  0x002E, 0x0000, 0xC557, 0x0054, 0x0068, 0x0065, 0x0020, 0x0062, 0x0069, 0x0074,
  0x006D, 0x0061, 0x0070, 0x0020, 0x0069, 0x0073, 0x0020, 0x0061, 0x006C, 0x0072,
  0x0065, 0x0061, 0x0064, 0x0079, 0x0020, 0x0069, 0x006E, 0x0069, 0x0074, 0x0069,
  0x0061, 0x006C, 0x0069, 0x007A, 0x0065, 0x0064, 0x0020, 0x0077, 0x0069, 0x0074,
  0x0068, 0x0020, 0x0061, 0x0020, 0x0067, 0x0072, 0x0061, 0x0070, 0x0068, 0x0069,
  0x0063, 0x0073, 0x0020, 0x0065, 0x006E, 0x0067, 0x0069, 0x006E, 0x0065, 0x0020,
  0x0062, 0x0069, 0x0074, 0x006D, 0x0061, 0x0070, 0x0000
};

/* Constant values used in this 'C' module only. */
static const XPoint _Const0000 = { 0, 0 };
static const XStringRes _Const0001 = { _StringsDefault0, 0x0003 };
static const XStringRes _Const0002 = { _StringsDefault0, 0x002B };

#ifndef EW_DONT_CHECK_INDEX
  /* This function is used to check the indices when accessing an array.
     If you don't want this verification add the define EW_DONT_CHECK_INDEX
     to your Makefile or project settings. */
  static int EwCheckIndex( int aIndex, int aRange, const char* aFile, int aLine )
  {
    if (( aIndex < 0 ) || ( aIndex >= aRange ))
    {
      EwPrint( "[FATAL ERROR in %s:%d] Array index %d out of bounds %d",
                aFile, aLine, aIndex, aRange );
      EwPanic();
      return 0;
    }
    return aIndex;
  }

  #define EwCheckIndex( aIndex, aRange ) \
    EwCheckIndex( aIndex, aRange, __FILE__, __LINE__ )
#else
  #define EwCheckIndex( aIndex, aRange ) aIndex
#endif

/* Initializer for the class 'Resources::Bitmap' */
void ResourcesBitmap__Init( ResourcesBitmap _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  CoreResource__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( ResourcesBitmap );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( ResourcesBitmap );

  /* ... and initialize objects, variables, properties, etc. */
  _this->NoOfFrames = 1;

  /* Call the user defined constructor */
  ResourcesBitmap_Init( _this, aArg );
}

/* Re-Initializer for the class 'Resources::Bitmap' */
void ResourcesBitmap__ReInit( ResourcesBitmap _this )
{
  /* At first re-initialize the super class ... */
  CoreResource__ReInit( &_this->_.Super );
}

/* Finalizer method for the class 'Resources::Bitmap' */
void ResourcesBitmap__Done( ResourcesBitmap _this )
{
  /* Call the user defined destructor of the class */
  ResourcesBitmap_Done( _this );

  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( CoreResource );

  /* Don't forget to deinitialize the super class ... */
  CoreResource__Done( &_this->_.Super );
}

/* 'C' function for method : 'Resources::Bitmap.Done()' */
void ResourcesBitmap_Done( ResourcesBitmap _this )
{
  XHandle handle;

  if ( _this->bitmap == 0 )
    return;

  handle = _this->bitmap;
  EwFreeBitmap((XBitmap*)handle );
  _this->bitmap = 0;
  _this->FrameSize = _Const0000;
  _this->FrameDelay = 0;
  _this->NoOfFrames = 1;
  _this->Animated = 0;
}

/* 'C' function for method : 'Resources::Bitmap.Init()' */
void ResourcesBitmap_Init( ResourcesBitmap _this, XHandle aArg )
{
  XHandle handle;
  XInt32 noOfFrames;
  XPoint frameSize;
  XInt32 frameDelay;

  if ( aArg == 0 )
    return;

  handle = 0;
  noOfFrames = 1;
  frameSize = _Const0000;
  frameDelay = 0;
  {
    /* aArg is a pointer to the memory where the bitmap resource is stored. */
    XBitmap* bmp = EwLoadBitmap((const XBmpRes*)aArg );

    /* After the bitmap has been loaded get the size of the bitmap and store it
       in the following variables. */
    if ( bmp )
    {
      noOfFrames = bmp->NoOfVirtFrames;
      frameSize  = bmp->FrameSize;
      frameDelay = bmp->FrameDelay;
    }

    handle = (XHandle)(void*)bmp;
  }
  _this->bitmap = handle;
  _this->NoOfFrames = noOfFrames;
  _this->FrameSize = frameSize;
  _this->FrameDelay = frameDelay;
  _this->Animated = (XBool)((( _this->bitmap != 0 ) && ( _this->FrameDelay > 0 )) 
  && ( _this->NoOfFrames > 1 ));
}

/* 'C' function for method : 'Resources::Bitmap.OnSetFrameSize()' */
void ResourcesBitmap_OnSetFrameSize( ResourcesBitmap _this, XPoint value )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
  EW_UNUSED_ARG( value );

  {
    EwThrow( EwLoadString( &_Const0001 ));
    return;
  }
}

/* Wrapper function for the virtual method : 'Resources::Bitmap.OnSetFrameSize()' */
void ResourcesBitmap__OnSetFrameSize( void* _this, XPoint value )
{
  ((ResourcesBitmap)_this)->_.VMT->OnSetFrameSize((ResourcesBitmap)_this, value );
}

/* 'C' function for method : 'Resources::Bitmap.SetBitmap()' */
ResourcesBitmap ResourcesBitmap_SetBitmap( ResourcesBitmap _this, XHandle aBitmap )
{
  XInt32 noOfFrames;
  XPoint frameSize;
  XInt32 frameDelay;

  if ( _this->bitmap != 0 )
  {
    EwThrow( EwLoadString( &_Const0002 ));
    return 0;
  }

  if ( aBitmap == 0 )
    return _this;

  _this->bitmap = aBitmap;
  noOfFrames = 1;
  frameSize = _Const0000;
  frameDelay = 0;
  {
    XBitmap* bmp = (XBitmap*)aBitmap;

    noOfFrames = bmp->NoOfVirtFrames;
    frameSize  = bmp->FrameSize;
    frameDelay = bmp->FrameDelay;
  }
  _this->NoOfFrames = noOfFrames;
  _this->FrameSize = frameSize;
  _this->FrameDelay = frameDelay;
  _this->Animated = (XBool)(( _this->FrameDelay > 0 ) && ( _this->NoOfFrames > 1 ));
  return _this;
}

/* Wrapper function for the non virtual method : 'Resources::Bitmap.SetBitmap()' */
ResourcesBitmap ResourcesBitmap__SetBitmap( void* _this, XHandle aBitmap )
{
  return ResourcesBitmap_SetBitmap((ResourcesBitmap)_this, aBitmap );
}

/* 'C' function for method : 'Resources::Bitmap.Update()' */
void ResourcesBitmap_Update( ResourcesBitmap _this )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
}

/* Wrapper function for the virtual method : 'Resources::Bitmap.Update()' */
void ResourcesBitmap__Update( void* _this )
{
  ((ResourcesBitmap)_this)->_.VMT->Update((ResourcesBitmap)_this );
}

/* Variants derived from the class : 'Resources::Bitmap' */
EW_DEFINE_CLASS_VARIANTS( ResourcesBitmap )
EW_END_OF_CLASS_VARIANTS( ResourcesBitmap )

/* Virtual Method Table (VMT) for the class : 'Resources::Bitmap' */
EW_DEFINE_CLASS( ResourcesBitmap, CoreResource, _.VMT, _.VMT, _.VMT, _.VMT, _.VMT, 
                 _.VMT, "Resources::Bitmap" )
  ResourcesBitmap_OnSetFrameSize,
  ResourcesBitmap_Update,
EW_END_OF_CLASS( ResourcesBitmap )

/* Initializer for the class 'Resources::Font' */
void ResourcesFont__Init( ResourcesFont _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  CoreResource__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( ResourcesFont );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( ResourcesFont );

  /* Call the user defined constructor */
  ResourcesFont_Init( _this, aArg );
}

/* Re-Initializer for the class 'Resources::Font' */
void ResourcesFont__ReInit( ResourcesFont _this )
{
  /* At first re-initialize the super class ... */
  CoreResource__ReInit( &_this->_.Super );
}

/* Finalizer method for the class 'Resources::Font' */
void ResourcesFont__Done( ResourcesFont _this )
{
  /* Call the user defined destructor of the class */
  ResourcesFont_Done( _this );

  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( CoreResource );

  /* Don't forget to deinitialize the super class ... */
  CoreResource__Done( &_this->_.Super );
}

/* 'C' function for method : 'Resources::Font.Done()' */
void ResourcesFont_Done( ResourcesFont _this )
{
  ResourcesFont_freeFont( _this );
}

/* 'C' function for method : 'Resources::Font.Init()' */
void ResourcesFont_Init( ResourcesFont _this, XHandle aArg )
{
  ResourcesFont_loadFont( _this, aArg );
}

/* 'C' function for method : 'Resources::Font.freeFont()' */
void ResourcesFont_freeFont( ResourcesFont _this )
{
  XHandle handle;

  if ( _this->font == 0 )
    return;

  handle = _this->font;
  EwFreeFont((XFont*)handle );
  _this->font = 0;
  _this->Ascent = 0;
  _this->Descent = 0;
  _this->Leading = 0;
}

/* 'C' function for method : 'Resources::Font.loadFont()' */
void ResourcesFont_loadFont( ResourcesFont _this, XHandle aFontResource )
{
  XHandle handle;
  XInt32 ascent;
  XInt32 descent;
  XInt32 leading;

  if ( aFontResource == 0 )
    return;

  handle = 0;
  ascent = 0;
  descent = 0;
  leading = 0;
  {
    /* aFontResource is a pointer to a memory where the font resource is stored. */
    XFont* font = EwLoadFont((const XFntRes*)aFontResource );

    /* After the font has been loaded query its ascent and descent. */
    if ( font )
    {
      ascent  = font->Ascent;
      descent = font->Descent;
      leading = font->Leading;
    }

    handle = (XHandle)(void*)font;
  }
  _this->font = handle;
  _this->Ascent = ascent;
  _this->Descent = descent;
  _this->Leading = leading;
}

/* 'C' function for method : 'Resources::Font.GetFlowTextAdvance()' */
XInt32 ResourcesFont_GetFlowTextAdvance( ResourcesFont _this, XString aFlowString )
{
  XHandle handle;
  XInt32 advance;

  if ( _this->font == 0 )
    return 0;

  handle = _this->font;
  advance = 0;
  advance = EwGetFlowTextAdvance((XFont*)handle, aFlowString );
  return advance;
}

/* 'C' function for method : 'Resources::Font.ParseFlowString()' */
XString ResourcesFont_ParseFlowString( ResourcesFont _this, XString aString, XInt32 
  aOffset, XInt32 aWidth, XInt32 aMaxNoOfRows, XHandle aBidi )
{
  XHandle handle;
  XString result;

  if ( aOffset < 0 )
    aOffset = 0;

  if (( _this->font == 0 ) || (( aOffset > 0 ) && ( aOffset >= EwGetStringLength( 
      aString ))))
    return 0;

  handle = _this->font;
  result = 0;
  result = EwParseFlowString((XFont*)handle, aString + aOffset, aWidth, aMaxNoOfRows, aBidi );
  return result;
}

/* The method GetTextAdvance() calculates the horizontal advance in pixel of a text 
   row to print with this font. This value is calculated by the sum of advance values 
   of all affected glyphs. The text is passed in the parameter aString. The parameter 
   aOffset determines within aString the sign to start the calculation. If aOffset 
   is zero, the calculation starts with the first sign. The parameter aCount determines 
   the max. number of following sigs to calculate the advance value. If aCount is 
   -1, all signs until the end of the string will be evaluated. */
XInt32 ResourcesFont_GetTextAdvance( ResourcesFont _this, XString aString, XInt32 
  aOffset, XInt32 aCount )
{
  XHandle handle;
  XInt32 advance;

  if ( aOffset < 0 )
    aOffset = 0;

  if (( _this->font == 0 ) || (( aOffset > 0 ) && ( aOffset >= EwGetStringLength( 
      aString ))))
    return 0;

  handle = _this->font;
  advance = 0;
  advance = EwGetTextAdvance((XFont*)handle, aString + aOffset, aCount );
  return advance;
}

/* Variants derived from the class : 'Resources::Font' */
EW_DEFINE_CLASS_VARIANTS( ResourcesFont )
EW_END_OF_CLASS_VARIANTS( ResourcesFont )

/* Virtual Method Table (VMT) for the class : 'Resources::Font' */
EW_DEFINE_CLASS( ResourcesFont, CoreResource, _.VMT, _.VMT, _.VMT, _.VMT, _.VMT, 
                 _.VMT, "Resources::Font" )
EW_END_OF_CLASS( ResourcesFont )

/* Include a file containing the font resource : 'Resources::FontSmall' */
#include "_ResourcesFontSmall.h"

/* Table with links to derived variants of the font resource : 'Resources::FontSmall' */
EW_RES_WITHOUT_VARIANTS( ResourcesFontSmall )

/* Initializer for the class 'Resources::FontSet' */
void ResourcesFontSet__Init( ResourcesFontSet _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  ResourcesFont__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( ResourcesFontSet );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( ResourcesFontSet );

  /* Call the user defined constructor */
  ResourcesFontSet_Init( _this, aArg );
}

/* Re-Initializer for the class 'Resources::FontSet' */
void ResourcesFontSet__ReInit( ResourcesFontSet _this )
{
  /* At first re-initialize the super class ... */
  ResourcesFont__ReInit( &_this->_.Super );
}

/* Finalizer method for the class 'Resources::FontSet' */
void ResourcesFontSet__Done( ResourcesFontSet _this )
{
  /* Call the user defined destructor of the class */
  ResourcesFontSet_Done( _this );

  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( ResourcesFont );

  /* Don't forget to deinitialize the super class ... */
  ResourcesFont__Done( &_this->_.Super );
}

/* 'C' function for method : 'Resources::FontSet.Done()' */
void ResourcesFontSet_Done( ResourcesFontSet _this )
{
  _this->Super1.font = 0;
}

/* 'C' function for method : 'Resources::FontSet.Init()' */
void ResourcesFontSet_Init( ResourcesFontSet _this, XHandle aArg )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( aArg );

  _this->Super1.Mutable = 1;
}

/* The method GetLargerFont() searches the FontSet for a font with height larger 
   than the of the font provided in the parameter aFont. If such font is not found, 
   returns the largest font existing in this FontSet. */
ResourcesFont ResourcesFontSet_GetLargerFont( ResourcesFontSet _this, ResourcesFont 
  aFont )
{
  XInt32 height = aFont->Ascent + aFont->Descent;
  XInt32 foundNo = -1;
  XInt32 foundHeight = 2147483647;
  XInt32 i;

  for ( i = 0; i < 4; i++ )
    if ((( _this->fonts[ EwCheckIndex( i, 4 )] != 0 ) && (( _this->fonts[ EwCheckIndex( 
        i, 4 )]->Ascent + _this->fonts[ EwCheckIndex( i, 4 )]->Descent ) > height )) 
        && (( _this->fonts[ EwCheckIndex( i, 4 )]->Ascent + _this->fonts[ EwCheckIndex( 
        i, 4 )]->Descent ) < foundHeight ))
    {
      foundNo = i;
      foundHeight = _this->fonts[ EwCheckIndex( i, 4 )]->Ascent + _this->fonts[ 
      EwCheckIndex( i, 4 )]->Descent;
    }

  return (( foundNo >= 0 )? _this->fonts[ EwCheckIndex( foundNo, 4 )] : aFont );
}

/* The method GetSmallerFont() searches the FontSet for a font with height smaller 
   than the of the font provided in the parameter aFont. If such font is not found, 
   returns the smallest font existing in this FontSet. */
ResourcesFont ResourcesFontSet_GetSmallerFont( ResourcesFontSet _this, ResourcesFont 
  aFont )
{
  XInt32 height = aFont->Ascent + aFont->Descent;
  XInt32 foundNo = -1;
  XInt32 foundHeight = 0;
  XInt32 i;

  for ( i = 0; i < 4; i++ )
    if ((( _this->fonts[ EwCheckIndex( i, 4 )] != 0 ) && (( _this->fonts[ EwCheckIndex( 
        i, 4 )]->Ascent + _this->fonts[ EwCheckIndex( i, 4 )]->Descent ) < height )) 
        && (( _this->fonts[ EwCheckIndex( i, 4 )]->Ascent + _this->fonts[ EwCheckIndex( 
        i, 4 )]->Descent ) > foundHeight ))
    {
      foundNo = i;
      foundHeight = _this->fonts[ EwCheckIndex( i, 4 )]->Ascent + _this->fonts[ 
      EwCheckIndex( i, 4 )]->Descent;
    }

  return (( foundNo >= 0 )? _this->fonts[ EwCheckIndex( foundNo, 4 )] : aFont );
}

/* The method GetAnyFont() returns the first available font fond in the FontSet. */
ResourcesFont ResourcesFontSet_GetAnyFont( ResourcesFontSet _this )
{
  XInt32 i;

  for ( i = 0; i < 4; i++ )
    if ( _this->fonts[ EwCheckIndex( i, 4 )] != 0 )
      return _this->fonts[ EwCheckIndex( i, 4 )];

  return 0;
}

/* Variants derived from the class : 'Resources::FontSet' */
EW_DEFINE_CLASS_VARIANTS( ResourcesFontSet )
EW_END_OF_CLASS_VARIANTS( ResourcesFontSet )

/* Virtual Method Table (VMT) for the class : 'Resources::FontSet' */
EW_DEFINE_CLASS( ResourcesFontSet, ResourcesFont, fonts, fonts, _.VMT, _.VMT, _.VMT, 
                 _.VMT, "Resources::FontSet" )
EW_END_OF_CLASS( ResourcesFontSet )

/* Embedded Wizard */
