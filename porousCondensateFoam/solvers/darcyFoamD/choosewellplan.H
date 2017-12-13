

/////////////////////////////////////////////////////////////////Injection 1///////////////////////////////////////////////////////////////////

if ( activeWellInj1 )
{
       ///////////////////////////////////////////////
        if ( activeTimeConditionInj1 )
        { 
           if ( runTime.value() <= timeConditionInj1 )
           {
               if      ( lessTimeConditionPlanInj1 == " pConst " )  # include "pConstPlan.H"
               else if ( lessTimeConditionPlanInj1 == " qConst " )  # include "qConstPlan.H"

           }  ////for runTime.value() <= timeConditionInj1

           if ( runTime.value() > timeConditionInj1 )
           {

              if      ( moreTimeConditionPlanInj1 == " pConst " )  # include "pConstPlan.H"
              else if ( moreTimeConditionPlanInj1 == " qConst " )  # include "qConstPlan.H"

           }  ////for runTime.value() > timeConditionInj1
      
          else
          {

           FatalErrorIn
          (
            "in chooseWellPlan.H"
          )
          << "type of plan unrecongnized : pConst and qConst available" 
          << exit(FatalError);

          }

        }   /// for activeTimeConditionInj1

        /////////////////////////////////////////////////
        if ( activeQConditionInj1 )
        { 
           if ( qWellInj1 <= qConditionInj1 )
           {
               if      ( lessQConditionPlanInj1 == " pConst " )  # include "pConstPlan.H"
               else if ( lessQConditionPlanInj1 == " qConst " )  # include "qConstPlan.H"

           }  ////for runTime.value() <= timeConditionInj1

           if ( qWellInj1 > qConditionInj1 )
           {

              if      ( moreQConditionPlanInj1 == " pConst " )  # include "pConstPlan.H"
              else if ( moreQConditionPlanInj1 == " qConst " )  # include "qConstPlan.H"

           }  ////for runTime.value() > timeConditionInj1
      
          else
          {

           FatalErrorIn
          (
            "in chooseWellPlan.H"
          )
          << "type of plan unrecongnized : pConst and qConst available" 
          << exit(FatalError);

          }

        }   /// for activeQConditionInj1

        /////////////////////////////////////////////////
        if ( activeGorConditionInj1 )
        { 
           if ( gorWellInj1 <= gorConditionInj1 )
           {
               if      ( lessGorConditionPlanInj1 == " pConst " )  # include "pConstPlan.H"
               else if ( lessGorConditionPlanInj1 == " qConst " )  # include "qConstPlan.H"

           }  ////for runTime.value() <= gorConditionInj1

           if ( gorWellInj1 > gorConditionInj1 )
           {

              if      ( moreGorConditionPlanInj1 == " pConst " )  # include "pConstPlan.H"
              else if ( moreGorConditionPlanInj1 == " qConst " )  # include "qConstPlan.H"

           }  ////for runTime.value() > timeConditionInj1
      
          else
          {

           FatalErrorIn
          (
            "in chooseWellPlan.H"
          )
          << "type of plan unrecongnized : pConst and qConst available" 
          << exit(FatalError);

          }

        }   /// for activeGorConditionInj1    
     

} ////for activeWellInj1

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




/////////////////////////////////////////////////////////Production1///////////////////////////////////////////////////////////////////////////

if ( activeWellPro1 )
{
       ///////////////////////////////////////////////
        if ( activeTimeConditionPro1 )
        { 
           if ( runTime.value() <= timeConditionPro1 )
           {
               if      ( lessTimeConditionPlanPro1 == " pConst " )  # include "pConstPlan.H"
               else if ( lessTimeConditionPlanPro1 == " qConst " )  # include "qConstPlan.H"

           }  ////for runTime.value() <= timeConditionPro1

           if ( runTime.value() > timeConditionPro1 )
           {

              if      ( moreTimeConditionPlanPro1 == " pConst " )  # include "pConstPlan.H"
              else if ( moreTimeConditionPlanPro1 == " qConst " )  # include "qConstPlan.H"

           }  ////for runTime.value() > timeConditionPro1
      
          else
          {

           FatalErrorIn
          (
            "in chooseWellPlan.H"
          )
          << "type of plan unrecongnized : pConst and qConst available" 
          << exit(FatalError);

          }

        }   /// for activeTimeConditionPro1

        /////////////////////////////////////////////////
        if ( activeQConditionPro1 )
        { 
           if ( qWellPro1 <= qConditionPro1 )
           {
               if      ( lessQConditionPlanPro1 == " pConst " )  # include "pConstPlan.H"
               else if ( lessQConditionPlanPro1 == " qConst " )  # include "qConstPlan.H"

           }  ////for runTime.value() <= timeConditionInj1

           if ( qWellPro1 > qConditionPro1 )
           {

              if      ( moreQConditionPlanPro1 == " pConst " )  # include "pConstPlan.H"
              else if ( moreQConditionPlanPro1 == " qConst " )  # include "qConstPlan.H"

           }  ////for runTime.value() > timeConditionPro1
      
          else
          {

           FatalErrorIn
          (
            "in chooseWellPlan.H"
          )
          << "type of plan unrecongnized : pConst and qConst available" 
          << exit(FatalError);

          }

        }   /// for activeQConditionInj1

        /////////////////////////////////////////////////
        if ( activeGorConditionPro1 )
        { 
           if ( gorWellPro1 <= gorConditionPro1 )
           {
               if      ( lessGorConditionPlanPro1 == " pConst " )  # include "pConstPlan.H"
               else if ( lessGorConditionPlanPro1 == " qConst " )  # include "qConstPlan.H"

           }  ////for runTime.value() <= gorConditionInj1

           if ( gorWellPro1 > gorConditionPro1 )
           {

              if      ( moreGorConditionPlanPro1 == " pConst " )  # include "pConstPlan.H"
              else if ( moreGorConditionPlanPro1 == " qConst " )  # include "qConstPlan.H"

           }  ////for runTime.value() > timeConditionPro1
      
          else
          {

           FatalErrorIn
          (
            "in chooseWellPlan.H"
          )
          << "type of plan unrecongnized : pConst and qConst available" 
          << exit(FatalError);

          }

        }   /// for activeGorConditionPro1    
     

} ////for activeWellPro1
