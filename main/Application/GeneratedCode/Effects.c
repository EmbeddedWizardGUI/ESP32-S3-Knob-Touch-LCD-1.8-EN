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
#include "_CoreTimer.h"
#include "_EffectsEffect.h"
#include "_EffectsEffectTimerClass.h"
#include "_EffectsFloatEffect.h"
#include "_EffectsInt32Effect.h"
#include "_EffectsTimingList.h"
#include "Effects.h"

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

/* Initializer for the class 'Effects::Effect' */
void EffectsEffect__Init( EffectsEffect _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  XObject__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( EffectsEffect );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( EffectsEffect );

  /* ... and initialize objects, variables, properties, etc. */
  _this->invCycleDuration = 0.001f;
  _this->Timing = EffectsTimingLinear;
  _this->CycleDuration = 1000;
}

/* Re-Initializer for the class 'Effects::Effect' */
void EffectsEffect__ReInit( EffectsEffect _this )
{
  /* At first re-initialize the super class ... */
  XObject__ReInit( &_this->_.Super );
}

/* Finalizer method for the class 'Effects::Effect' */
void EffectsEffect__Done( EffectsEffect _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( XObject );

  /* Don't forget to deinitialize the super class ... */
  XObject__Done( &_this->_.Super );
}

/* 'C' function for method : 'Effects::Effect.timerSlot()' */
void EffectsEffect_timerSlot( EffectsEffect _this, XObject sender )
{
  XBool done;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  if ( _this->timer == 0 )
    return;

  if ( _this->startDirection == 0 )
  {
    _this->startDirection = 1;
    _this->direction = _this->startDirection;
    _this->startTime = _this->timer->Time;
    _this->cycleCounter = 0;
    _this->lastFrame = -1.0f;
  }

  if (( _this->startDirection > 0 ) && ( _this->direction > 0 ))
    done = EffectsEffect_runFwdFwd( _this );
  else
    if (( _this->startDirection < 0 ) && ( _this->direction < 0 ))
      done = EffectsEffect_runRevRev( _this );
    else
      if ( _this->startDirection > 0 )
        done = EffectsEffect_runFwdRev( _this );
      else
        done = EffectsEffect_runRevFwd( _this );

  if ( done )
  {
    EffectsEffect_OnSetEnabled( _this, 0 );
    EwSignal( _this->OnFinished, ((XObject)_this ));
  }
}

/* 'C' function for method : 'Effects::Effect.run()' */
void EffectsEffect_run( EffectsEffect _this, XFloat aFrame )
{
  if (( _this->timingList == 0 ) && ((( _this->Timing == EffectsTimingBounce_In ) 
      || ( _this->Timing == EffectsTimingBounce_Out )) || ( _this->Timing == EffectsTimingBounce_InOut )))
  {
    XFloat sum = 0.5f;
    XInt32 i;
    XFloat invSum;
    _this->timingList = EwNewObject( EffectsTimingList, 0 );
    _this->timingList->spans[ 0 ] = 1.0f;
    _this->timingList->amps[ 0 ] = 1.0f;

    for ( i = 1; i < 4; i = i + 1 )
    {
      _this->timingList->spans[ EwCheckIndex( i, 12 )] = _this->timingList->spans[ 
      EwCheckIndex( i - 1, 12 )] * 0.707107f;
      _this->timingList->amps[ EwCheckIndex( i, 12 )] = _this->timingList->amps[ 
      EwCheckIndex( i - 1, 12 )] * 0.5f;
      sum = sum + _this->timingList->spans[ EwCheckIndex( i, 12 )];
    }

    invSum = 1.0f / sum;
    _this->timingList->spans[ 0 ] = 0.5f;
    sum = 0.0f;

    for ( i = 0; i < 4; i = i + 1 )
    {
      _this->timingList->spans[ EwCheckIndex( i, 12 )] = _this->timingList->spans[ 
      EwCheckIndex( i, 12 )] * invSum;
      sum = sum + _this->timingList->spans[ EwCheckIndex( i, 12 )];
    }

    _this->timingList->spans[ 4 ] = _this->timingList->spans[ 4 ] + ( 1.0f - sum );
  }

  switch ( _this->Timing )
  {
    case EffectsTimingPower_In :
      aFrame = EwMathPow( aFrame, 3.0f );
    break;

    case EffectsTimingPower_Out :
    {
      aFrame = 1.0f - aFrame;
      aFrame = 1.0f - EwMathPow( aFrame, 3.0f );
    }
    break;

    case EffectsTimingPower_InOut :
    {
      aFrame = aFrame * 2.0f;

      if ( aFrame < 1.0f )
        aFrame = EwMathPow( aFrame, 3.0f ) / 2.0f;
      else
      {
        aFrame = 2.0f - aFrame;
        aFrame = ( 2.0f - EwMathPow( aFrame, 3.0f )) * 0.5f;
      }
    }
    break;

    case EffectsTimingExp_In :
      aFrame = ( EwMathPow( 2.718f, 3.0f * aFrame ) - 1.0f ) / 19.0793f;
    break;

    case EffectsTimingExp_Out :
    {
      aFrame = 1.0f - aFrame;
      aFrame = 1.0f - (( EwMathPow( 2.718f, 3.0f * aFrame ) - 1.0f ) / 19.0793f );
    }
    break;

    case EffectsTimingExp_InOut :
    {
      aFrame = aFrame * 2.0f;

      if ( aFrame < 1.0f )
        aFrame = (( EwMathPow( 2.718f, 3.0f * aFrame ) - 1.0f ) / 19.0793f ) / 2.0f;
      else
      {
        aFrame = 2.0f - aFrame;
        aFrame = ( 2.0f - (( EwMathPow( 2.718f, 3.0f * aFrame ) - 1.0f ) / 19.0793f )) 
        * 0.5f;
      }
    }
    break;

    case EffectsTimingSine_In :
      aFrame = 1.0f - EwMathCos( aFrame * 90.0f );
    break;

    case EffectsTimingSine_Out :
      aFrame = EwMathSin( aFrame * 90.0f );
    break;

    case EffectsTimingSine_InOut :
    {
      aFrame = aFrame * 2.0f;

      if ( aFrame < 1.0f )
      {
        aFrame = 1.0f - EwMathCos( aFrame * 90.0f );
        aFrame = aFrame * 0.5f;
      }
      else
      {
        aFrame = 2.0f - aFrame;
        aFrame = 1.0f - EwMathCos( aFrame * 90.0f );
        aFrame = ( 2.0f - aFrame ) * 0.5f;
      }
    }
    break;

    case EffectsTimingCircle_In :
      aFrame = 1.0f - EwMathSqrt( 1.0f - ( aFrame * aFrame ));
    break;

    case EffectsTimingCircle_Out :
    {
      aFrame = 1.0f - aFrame;
      aFrame = EwMathSqrt( 1.0f - ( aFrame * aFrame ));
    }
    break;

    case EffectsTimingCircle_InOut :
    {
      aFrame = aFrame * 2.0f;

      if ( aFrame < 1.0f )
      {
        aFrame = 1.0f - EwMathSqrt( 1.0f - ( aFrame * aFrame ));
        aFrame = aFrame * 0.5f;
      }
      else
      {
        aFrame = 2.0f - aFrame;
        aFrame = 1.0f - EwMathSqrt( 1.0f - ( aFrame * aFrame ));
        aFrame = ( 2.0f - aFrame ) * 0.5f;
      }
    }
    break;

    case EffectsTimingBack_In :
      aFrame = (( aFrame * aFrame ) * aFrame ) - (( aFrame * 0.5f ) * EwMathSin( 
      aFrame * 180.0f ));
    break;

    case EffectsTimingBack_Out :
    {
      aFrame = 1.0f - aFrame;
      aFrame = (( aFrame * aFrame ) * aFrame ) - (( aFrame * 0.5f ) * EwMathSin( 
      aFrame * 180.0f ));
      aFrame = 1.0f - aFrame;
    }
    break;

    case EffectsTimingBack_InOut :
    {
      aFrame = aFrame * 2.0f;

      if ( aFrame < 1.0f )
      {
        aFrame = (( aFrame * aFrame ) * aFrame ) - (( aFrame * 0.5f ) * EwMathSin( 
        aFrame * 180.0f ));
        aFrame = aFrame * 0.5f;
      }
      else
      {
        aFrame = 2.0f - aFrame;
        aFrame = (( aFrame * aFrame ) * aFrame ) - (( aFrame * 0.5f ) * EwMathSin( 
        aFrame * 180.0f ));
        aFrame = ( 2.0f - aFrame ) * 0.5f;
      }
    }
    break;

    case EffectsTimingElastic_In :
      aFrame = (( aFrame * aFrame ) * aFrame ) * EwMathSin(( aFrame * 90.0f ) * 
      13.0f );
    break;

    case EffectsTimingElastic_Out :
    {
      aFrame = 1.0f - aFrame;
      aFrame = 1.0f - ((( aFrame * aFrame ) * aFrame ) * EwMathSin(( aFrame * 90.0f ) 
      * 13.0f ));
    }
    break;

    case EffectsTimingElastic_InOut :
    {
      aFrame = aFrame * 2.0f;

      if ( aFrame < 1.0f )
      {
        aFrame = (( aFrame * aFrame ) * aFrame ) * EwMathSin(( aFrame * 90.0f ) 
        * 13.0f );
        aFrame = aFrame * 0.5f;
      }
      else
      {
        aFrame = 2.0f - aFrame;
        aFrame = (( aFrame * aFrame ) * aFrame ) * EwMathSin(( aFrame * 90.0f ) 
        * 13.0f );
        aFrame = ( 2.0f - aFrame ) * 0.5f;
      }
    }
    break;

    case EffectsTimingBounce_In :
    {
      EffectsTimingList list = _this->timingList;
      XInt32 i = 0;
      XFloat t1 = 0.0f;
      XFloat t2 = list->spans[ 0 ];
      XFloat t = 1.0f - aFrame;

      while ( t > t2 )
      {
        i = i + 1;
        t1 = t2;
        t2 = t2 + list->spans[ EwCheckIndex( i, 12 )];
      }

      aFrame = ( t - t1 ) / ( t2 - t1 );

      if ( i == 0 )
        aFrame = 1.0f - ( aFrame * aFrame );
      else
      {
        aFrame = ( 2.0f * aFrame ) - 1.0f;
        aFrame = list->amps[ EwCheckIndex( i, 12 )] * ( 1.0f - ( aFrame * aFrame ));
      }
    }
    break;

    case EffectsTimingBounce_Out :
    {
      EffectsTimingList list = _this->timingList;
      XInt32 i = 0;
      XFloat t1 = 0.0f;
      XFloat t2 = list->spans[ 0 ];

      while ( aFrame > t2 )
      {
        i = i + 1;
        t1 = t2;
        t2 = t2 + list->spans[ EwCheckIndex( i, 12 )];
      }

      aFrame = ( aFrame - t1 ) / ( t2 - t1 );

      if ( i == 0 )
        aFrame = aFrame * aFrame;
      else
      {
        aFrame = ( 2.0f * aFrame ) - 1.0f;
        aFrame = 1.0f - ( list->amps[ EwCheckIndex( i, 12 )] * ( 1.0f - ( aFrame 
        * aFrame )));
      }
    }
    break;

    case EffectsTimingBounce_InOut :
    {
      EffectsTimingList list = _this->timingList;
      XInt32 i = 0;
      XFloat t1 = 0.0f;
      XFloat t2 = list->spans[ 0 ];
      XFloat f = aFrame * 2.0f;
      XFloat t = f - 1.0f;

      if ( f < 1.0f )
        t = -t;

      while ( t > t2 )
      {
        i = i + 1;
        t1 = t2;
        t2 = t2 + list->spans[ EwCheckIndex( i, 12 )];
      }

      t = ( t - t1 ) / ( t2 - t1 );

      if ( i == 0 )
        t = t * t;
      else
      {
        t = ( 2.0f * t ) - 1.0f;
        t = 1.0f - ( list->amps[ EwCheckIndex( i, 12 )] * ( 1.0f - ( t * t )));
      }

      if ( f < 1.0f )
        aFrame = 0.5f * ( 1.0f - t );
      else
        aFrame = 0.5f * ( 1.0f + t );
    }
    break;

    default : 
      if ( _this->useBezier2 )
      {
        XFloat f = aFrame;
        XFloat nf = 1.0f - f;
        aFrame = (( nf * f ) * ( _this->curveFactor1 + 1.0f )) + ( f * f );
      }
      else
        if ( _this->useBezier3 )
        {
          XFloat f = aFrame;
          XFloat nf = 1.0f - f;
          XFloat f2 = f * f;
          XFloat nf2 = nf * nf;
          aFrame = ((( nf2 * f ) * ( _this->curveFactor1 + 1.0f )) + (( nf * f2 ) 
          * ( _this->curveFactor2 + 2.0f ))) + ( f2 * f );
        }
  }

  EffectsEffect__Animate( _this, aFrame );
  EwSignal( _this->OnAnimate, ((XObject)_this ));
}

/* 'C' function for method : 'Effects::Effect.runRevRev()' */
XBool EffectsEffect_runRevRev( EffectsEffect _this )
{
  XInt32 time = (XInt32)( _this->timer->Time - _this->startTime );
  XInt32 period0;
  XInt32 periodN;
  XBool done;
  XFloat frame;

  if ( time < 0 )
    time = -time;

  period0 = _this->CycleDuration;
  periodN = _this->CycleDuration;
  done = 0;
  frame = _this->lastFrame;

  if (( _this->cycleCounter == 0 ) && ( time >= period0 ))
  {
    _this->cycleCounter = 1;
    time = time - period0;
    _this->startTime = _this->startTime + period0;
  }

  if (( _this->cycleCounter > 0 ) && ( time >= periodN ))
  {
    XInt32 cycles = time / periodN;
    _this->cycleCounter = _this->cycleCounter + cycles;
    time = time - ( cycles * periodN );
    _this->startTime = _this->startTime + ( cycles * periodN );
  }

  if (( _this->cycleCounter > 2 ) && ( _this->NoOfCycles == 0 ))
    _this->cycleCounter = 1;

  if (( _this->cycleCounter >= _this->NoOfCycles ) && ( _this->NoOfCycles > 0 ))
  {
    done = 1;
    frame = 0.0f;
  }
  else
    if ( time >= 0 )
      frame = 1.0f - ((XFloat)time * _this->invCycleDuration );
    else
      if ( frame >= 0.0f )
        frame = 0.0f;

  if ( frame != _this->lastFrame )
  {
    if ( frame < 0.0f )
      frame = 0.0f;

    if ( frame > 1.0f )
      frame = 1.0f;
  }

  if ( frame != _this->lastFrame )
  {
    _this->lastFrame = frame;
    EffectsEffect_run( _this, frame );
  }

  return done;
}

/* 'C' function for method : 'Effects::Effect.runRevFwd()' */
XBool EffectsEffect_runRevFwd( EffectsEffect _this )
{
  XInt32 time = (XInt32)( _this->startTime - _this->timer->Time );
  XInt32 period0 = _this->CycleDuration;
  XInt32 periodN = _this->CycleDuration;
  XBool done = 0;
  XFloat frame = _this->lastFrame;

  if (( _this->cycleCounter > 1 ) && ( time < 0 ))
  {
    XInt32 cycles = (( -time + periodN ) - 1 ) / periodN;

    if (( _this->cycleCounter - cycles ) <= 0 )
      cycles = _this->cycleCounter - 1;

    _this->cycleCounter = _this->cycleCounter - cycles;
    time = time + ( cycles * periodN );
    _this->startTime = _this->startTime + ( cycles * periodN );
  }

  if ((( _this->cycleCounter == 1 ) && ( time < 0 )) && ( _this->NoOfCycles > 0 ))
  {
    _this->cycleCounter = 0;
    time = time + period0;
    _this->startTime = _this->startTime + period0;
  }

  if ((( _this->cycleCounter == 1 ) && ( time < 0 )) && ( _this->NoOfCycles == 0 ))
  {
    XInt32 cycles = (( -time + periodN ) - 1 ) / periodN;
    time = time + ( cycles * periodN );
    _this->startTime = _this->startTime + ( cycles * periodN );
  }

  if ( time < 0 )
  {
    done = 1;
    frame = 1.0f;
  }
  else
    if ( time >= 0 )
      frame = 1.0f - ((XFloat)time * _this->invCycleDuration );
    else
      if ( frame >= 0.0f )
        frame = 1.0f;

  if ( frame != _this->lastFrame )
  {
    if ( frame < 0.0f )
      frame = 0.0f;

    if ( frame > 1.0f )
      frame = 1.0f;
  }

  if ( frame != _this->lastFrame )
  {
    _this->lastFrame = frame;
    EffectsEffect_run( _this, frame );
  }

  return done;
}

/* 'C' function for method : 'Effects::Effect.runFwdRev()' */
XBool EffectsEffect_runFwdRev( EffectsEffect _this )
{
  XInt32 time = (XInt32)( _this->startTime - _this->timer->Time );
  XInt32 period0 = _this->CycleDuration;
  XInt32 periodN = _this->CycleDuration;
  XBool done = 0;
  XFloat frame = _this->lastFrame;

  if (( _this->cycleCounter > 1 ) && ( time < 0 ))
  {
    XInt32 cycles = (( -time + periodN ) - 1 ) / periodN;

    if (( _this->cycleCounter - cycles ) <= 0 )
      cycles = _this->cycleCounter - 1;

    _this->cycleCounter = _this->cycleCounter - cycles;
    time = time + ( cycles * periodN );
    _this->startTime = _this->startTime + ( cycles * periodN );
  }

  if ((( _this->cycleCounter == 1 ) && ( time < 0 )) && ( _this->NoOfCycles > 0 ))
  {
    _this->cycleCounter = 0;
    time = time + period0;
    _this->startTime = _this->startTime + period0;
  }

  if ((( _this->cycleCounter == 1 ) && ( time < 0 )) && ( _this->NoOfCycles == 0 ))
  {
    XInt32 cycles = (( -time + periodN ) - 1 ) / periodN;
    time = time + ( cycles * periodN );
    _this->startTime = _this->startTime + ( cycles * periodN );
  }

  if ( time < 0 )
  {
    done = 1;
    frame = 0.0f;
  }
  else
    if ( time >= 0 )
      frame = (XFloat)time * _this->invCycleDuration;
    else
      if ( frame >= 0.0f )
        frame = 0.0f;

  if ( frame != _this->lastFrame )
  {
    if ( frame < 0.0f )
      frame = 0.0f;

    if ( frame > 1.0f )
      frame = 1.0f;
  }

  if ( frame != _this->lastFrame )
  {
    _this->lastFrame = frame;
    EffectsEffect_run( _this, frame );
  }

  return done;
}

/* 'C' function for method : 'Effects::Effect.runFwdFwd()' */
XBool EffectsEffect_runFwdFwd( EffectsEffect _this )
{
  XInt32 time = (XInt32)( _this->timer->Time - _this->startTime );
  XInt32 period0;
  XInt32 periodN;
  XBool done;
  XFloat frame;

  if ( time < 0 )
    time = -time;

  period0 = _this->CycleDuration;
  periodN = _this->CycleDuration;
  done = 0;
  frame = _this->lastFrame;

  if (( _this->cycleCounter == 0 ) && ( time >= period0 ))
  {
    _this->cycleCounter = 1;
    time = time - period0;
    _this->startTime = _this->startTime + period0;
  }

  if (( _this->cycleCounter > 0 ) && ( time >= periodN ))
  {
    XInt32 cycles = time / periodN;
    _this->cycleCounter = _this->cycleCounter + cycles;
    time = time - ( cycles * periodN );
    _this->startTime = _this->startTime + ( cycles * periodN );
  }

  if (( _this->cycleCounter > 2 ) && ( _this->NoOfCycles == 0 ))
    _this->cycleCounter = 1;

  if (( _this->cycleCounter >= _this->NoOfCycles ) && ( _this->NoOfCycles > 0 ))
  {
    done = 1;
    frame = 1.0f;
  }
  else
    if ( time >= 0 )
      frame = (XFloat)time * _this->invCycleDuration;
    else
      if ( frame >= 0.0f )
        frame = 1.0f;

  if ( frame != _this->lastFrame )
  {
    if ( frame < 0.0f )
      frame = 0.0f;

    if ( frame > 1.0f )
      frame = 1.0f;
  }

  if ( frame != _this->lastFrame )
  {
    _this->lastFrame = frame;
    EffectsEffect_run( _this, frame );
  }

  return done;
}

/* 'C' function for method : 'Effects::Effect.OnSetTiming()' */
void EffectsEffect_OnSetTiming( EffectsEffect _this, XEnum value )
{
  if ( _this->Timing == value )
    return;

  _this->Timing = value;
  _this->timingList = 0;

  switch ( value )
  {
    case EffectsTimingEaseIn_EaseOut :
    {
      _this->curveFactor1 = -1.1f;
      _this->curveFactor2 = 1.1f;
    }
    break;

    case EffectsTimingEaseIn_FastOut :
    {
      _this->curveFactor1 = -1.0f;
      _this->curveFactor2 = -2.0f;
    }
    break;

    case EffectsTimingFastIn_EaseOut :
    {
      _this->curveFactor1 = 2.0f;
      _this->curveFactor2 = 1.0f;
    }
    break;

    case EffectsTimingFastIn_FastOut :
    {
      _this->curveFactor1 = 1.1f;
      _this->curveFactor2 = -1.1f;
    }
    break;

    case EffectsTimingLinear :
    {
      _this->curveFactor1 = 0.0f;
      _this->curveFactor2 = 0.0f;
    }
    break;

    default : 
    {
      _this->curveFactor1 = 0.0f;
      _this->curveFactor2 = 0.0f;
    }
  }

  _this->useBezier2 = (XBool)(( _this->curveFactor1 == _this->curveFactor2 ) && 
  ( _this->curveFactor1 != 0.0f ));
  _this->useBezier3 = (XBool)( !_this->useBezier2 && ( _this->curveFactor1 != _this->curveFactor2 ));
}

/* 'C' function for method : 'Effects::Effect.OnSetNoOfCycles()' */
void EffectsEffect_OnSetNoOfCycles( EffectsEffect _this, XInt32 value )
{
  if ( value < 0 )
    value = 0;

  _this->NoOfCycles = value;
}

/* 'C' function for method : 'Effects::Effect.OnSetCycleDuration()' */
void EffectsEffect_OnSetCycleDuration( EffectsEffect _this, XInt32 value )
{
  if ( value < 15 )
    value = 15;

  _this->CycleDuration = value;
  _this->invCycleDuration = 1.0f / (XFloat)value;
}

/* 'C' function for method : 'Effects::Effect.OnSetEnabled()' */
void EffectsEffect_OnSetEnabled( EffectsEffect _this, XBool value )
{
  if ( _this->Enabled == value )
    return;

  _this->Enabled = value;

  if ( !value && ( _this->timer != 0 ))
  {
    EwDetachObjObserver( EwNewSlot( _this, EffectsEffect_timerSlot ), (XObject)_this->timer, 
      0 );
    _this->timer = 0;
  }

  if ( value )
  {
    _this->timer = ((CoreTimer)EwGetAutoObject( &EffectsEffectTimer, EffectsEffectTimerClass ));
    EwAttachObjObserver( EwNewSlot( _this, EffectsEffect_timerSlot ), (XObject)_this->timer, 
      0 );
    _this->startDirection = 0;
    EwPostSignal( EwNewSlot( _this, EffectsEffect_timerSlot ), ((XObject)_this ));
  }
}

/* 'C' function for method : 'Effects::Effect.Animate()' */
void EffectsEffect_Animate( EffectsEffect _this, XFloat aProgress )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
  EW_UNUSED_ARG( aProgress );
}

/* Wrapper function for the virtual method : 'Effects::Effect.Animate()' */
void EffectsEffect__Animate( void* _this, XFloat aProgress )
{
  ((EffectsEffect)_this)->_.VMT->Animate((EffectsEffect)_this, aProgress );
}

/* Variants derived from the class : 'Effects::Effect' */
EW_DEFINE_CLASS_VARIANTS( EffectsEffect )
EW_END_OF_CLASS_VARIANTS( EffectsEffect )

/* Virtual Method Table (VMT) for the class : 'Effects::Effect' */
EW_DEFINE_CLASS( EffectsEffect, XObject, timingList, timingList, OnFinished, direction, 
                 direction, direction, "Effects::Effect" )
  EffectsEffect_Animate,
EW_END_OF_CLASS( EffectsEffect )

/* Initializer for the class 'Effects::Int32Effect' */
void EffectsInt32Effect__Init( EffectsInt32Effect _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  EffectsEffect__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( EffectsInt32Effect );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( EffectsInt32Effect );

  /* ... and initialize objects, variables, properties, etc. */
  _this->Value2 = 255;
}

/* Re-Initializer for the class 'Effects::Int32Effect' */
void EffectsInt32Effect__ReInit( EffectsInt32Effect _this )
{
  /* At first re-initialize the super class ... */
  EffectsEffect__ReInit( &_this->_.Super );
}

/* Finalizer method for the class 'Effects::Int32Effect' */
void EffectsInt32Effect__Done( EffectsInt32Effect _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( EffectsEffect );

  /* Don't forget to deinitialize the super class ... */
  EffectsEffect__Done( &_this->_.Super );
}

/* 'C' function for method : 'Effects::Int32Effect.Animate()' */
void EffectsInt32Effect_Animate( EffectsInt32Effect _this, XFloat aProgress )
{
  _this->Value = _this->Value1 + (XInt32)EwMathRound((XFloat)( _this->Value2 - _this->Value1 ) 
  * aProgress );

  if ( _this->Outlet.Object != 0 )
    EwOnSetInt32( _this->Outlet, _this->Value );
}

/* Variants derived from the class : 'Effects::Int32Effect' */
EW_DEFINE_CLASS_VARIANTS( EffectsInt32Effect )
EW_END_OF_CLASS_VARIANTS( EffectsInt32Effect )

/* Virtual Method Table (VMT) for the class : 'Effects::Int32Effect' */
EW_DEFINE_CLASS( EffectsInt32Effect, EffectsEffect, Outlet, Outlet, Outlet, Outlet, 
                 Value, Value, "Effects::Int32Effect" )
  EffectsInt32Effect_Animate,
EW_END_OF_CLASS( EffectsInt32Effect )

/* Initializer for the class 'Effects::FloatEffect' */
void EffectsFloatEffect__Init( EffectsFloatEffect _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  EffectsEffect__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( EffectsFloatEffect );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( EffectsFloatEffect );

  /* ... and initialize objects, variables, properties, etc. */
  _this->Value2 = 1.0f;
}

/* Re-Initializer for the class 'Effects::FloatEffect' */
void EffectsFloatEffect__ReInit( EffectsFloatEffect _this )
{
  /* At first re-initialize the super class ... */
  EffectsEffect__ReInit( &_this->_.Super );
}

/* Finalizer method for the class 'Effects::FloatEffect' */
void EffectsFloatEffect__Done( EffectsFloatEffect _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( EffectsEffect );

  /* Don't forget to deinitialize the super class ... */
  EffectsEffect__Done( &_this->_.Super );
}

/* 'C' function for method : 'Effects::FloatEffect.Animate()' */
void EffectsFloatEffect_Animate( EffectsFloatEffect _this, XFloat aProgress )
{
  _this->Value = _this->Value1 + (( _this->Value2 - _this->Value1 ) * aProgress );
}

/* Variants derived from the class : 'Effects::FloatEffect' */
EW_DEFINE_CLASS_VARIANTS( EffectsFloatEffect )
EW_END_OF_CLASS_VARIANTS( EffectsFloatEffect )

/* Virtual Method Table (VMT) for the class : 'Effects::FloatEffect' */
EW_DEFINE_CLASS( EffectsFloatEffect, EffectsEffect, _.VMT, _.VMT, _.VMT, _.VMT, 
                 _.VMT, _.VMT, "Effects::FloatEffect" )
  EffectsFloatEffect_Animate,
EW_END_OF_CLASS( EffectsFloatEffect )

/* Initializer for the class 'Effects::EffectTimerClass' */
void EffectsEffectTimerClass__Init( EffectsEffectTimerClass _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  CoreTimer__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( EffectsEffectTimerClass );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( EffectsEffectTimerClass );
}

/* Re-Initializer for the class 'Effects::EffectTimerClass' */
void EffectsEffectTimerClass__ReInit( EffectsEffectTimerClass _this )
{
  /* At first re-initialize the super class ... */
  CoreTimer__ReInit( &_this->_.Super );
}

/* Finalizer method for the class 'Effects::EffectTimerClass' */
void EffectsEffectTimerClass__Done( EffectsEffectTimerClass _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( CoreTimer );

  /* Don't forget to deinitialize the super class ... */
  CoreTimer__Done( &_this->_.Super );
}

/* The method Trigger() will be invoked when the timer is expired (when the interval 
   defined in @Begin or @Period is elapsed). The method can be overridden and implemented 
   in derived classes. The default implementation of this method sends a signal 
   to the slot method stored in the @OnTrigger property. */
void EffectsEffectTimerClass_Trigger( EffectsEffectTimerClass _this )
{
  CoreTimer_Trigger((CoreTimer)_this );
  EwNotifyObjObservers((XObject)_this, 0 );
}

/* Variants derived from the class : 'Effects::EffectTimerClass' */
EW_DEFINE_CLASS_VARIANTS( EffectsEffectTimerClass )
EW_END_OF_CLASS_VARIANTS( EffectsEffectTimerClass )

/* Virtual Method Table (VMT) for the class : 'Effects::EffectTimerClass' */
EW_DEFINE_CLASS( EffectsEffectTimerClass, CoreTimer, _.VMT, _.VMT, _.VMT, _.VMT, 
                 _.VMT, _.VMT, "Effects::EffectTimerClass" )
  EffectsEffectTimerClass_Trigger,
EW_END_OF_CLASS( EffectsEffectTimerClass )

/* The global autoobject Effects::EffectTimer triggers all actually active animation 
   effects. In this way all effects will run simultanously. Per default the timer 
   is configured with 15 ms period (~60 FPS). By overriding the Effects::EffectTimer 
   autoobject by a variant you can specify another resolution to drive the animations. */
EW_DEFINE_AUTOOBJECT( EffectsEffectTimer, EffectsEffectTimerClass )

/* Initializer for the auto object 'Effects::EffectTimer' */
void EffectsEffectTimer__Init( EffectsEffectTimerClass _this )
{
  CoreTimer_OnSetPeriod((CoreTimer)_this, 15 );
  CoreTimer_OnSetEnabled((CoreTimer)_this, 1 );
}

/* Re-Initializer for the auto object 'Effects::EffectTimer' */
void EffectsEffectTimer__ReInit( EffectsEffectTimerClass _this )
{
  EW_UNUSED_ARG( _this );
}

/* Table with links to derived variants of the auto object : 'Effects::EffectTimer' */
EW_DEFINE_AUTOOBJECT_VARIANTS( EffectsEffectTimer )
EW_END_OF_AUTOOBJECT_VARIANTS( EffectsEffectTimer )

/* Initializer for the class 'Effects::TimingList' */
void EffectsTimingList__Init( EffectsTimingList _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  XObject__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( EffectsTimingList );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( EffectsTimingList );
}

/* Re-Initializer for the class 'Effects::TimingList' */
void EffectsTimingList__ReInit( EffectsTimingList _this )
{
  /* At first re-initialize the super class ... */
  XObject__ReInit( &_this->_.Super );
}

/* Finalizer method for the class 'Effects::TimingList' */
void EffectsTimingList__Done( EffectsTimingList _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( XObject );

  /* Don't forget to deinitialize the super class ... */
  XObject__Done( &_this->_.Super );
}

/* Variants derived from the class : 'Effects::TimingList' */
EW_DEFINE_CLASS_VARIANTS( EffectsTimingList )
EW_END_OF_CLASS_VARIANTS( EffectsTimingList )

/* Virtual Method Table (VMT) for the class : 'Effects::TimingList' */
EW_DEFINE_CLASS( EffectsTimingList, XObject, _.VMT, _.VMT, _.VMT, _.VMT, _.VMT, 
                 _.VMT, "Effects::TimingList" )
EW_END_OF_CLASS( EffectsTimingList )

/* Embedded Wizard */
