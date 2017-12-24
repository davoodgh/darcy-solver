
/////////////////////////////////////////////////////////////////Injection 1///////////////////////////////////////////////////////////////////

if ( activeWellInj1.value()==1 )
{
       ///////////////////////////////////////////////
        if ( activeTimeConditionInj1.value()==1 )
        { 
           if ( runTime.value() <= timeConditionInj1.value() )
           {
               if      ( lessTimeConditionPlanInj1 == " pConst " ) 
               {
                       # include "pConstPlanInj1.H"
               }
               else if ( lessTimeConditionPlanInj1 == " qConst " ) 
               {
                       # include "qConstPlanInj1.H"
               }

           }  ////for runTime.value() <= timeConditionInj1

           else if ( runTime.value() > timeConditionInj1.value() )
           {

              if      ( moreTimeConditionPlanInj1 == " pConst " )
              {  
                      # include "pConstPlanInj1.H"
              }
              else if ( moreTimeConditionPlanInj1 == " qConst " )
              {  
                      # include "qConstPlanInj1.H"
              }

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
        if ( activeQConditionInj1.value()==1 )
        { 
           if ( qWellInj1.value() <= qConditionInj1.value() )
           {
               if      ( lessQConditionPlanInj1 == " pConst " ) 
               { 
                       # include "pConstPlanInj1.H"
               }
               else if ( lessQConditionPlanInj1 == " qConst " )  
               {
                       # include "qConstPlanInj1.H"
               }

           }  ////for qWellInj1 <= qConditionInj1

           else if ( qWellInj1.value() > qConditionInj1.value() )
           {

              if      ( moreQConditionPlanInj1 == " pConst " ) 
              { 
                      # include "pConstPlanInj1.H"
              }
              else if ( moreQConditionPlanInj1 == " qConst " )
              {  
                      # include "qConstPlanInj1.H"
              }

           }  ////for qWellInj1 > qConditionInj1
      
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
        //if ( activeGorConditionInj1.value()==1 )
        //{ 
           //if ( gorWellInj1.value() <= gorConditionInj1.value() )
           //{
               //if      ( lessGorConditionPlanInj1 == " pConst " )
               //{  
                       //# include "pConstPlanInj1.H"
               //}
               //else if ( lessGorConditionPlanInj1 == " qConst " ) 
                 //{ 
                       //# include "qConstPlanInj1.H"
                 //}

           //}  ////for gorWellInj1 <= gorConditionInj1

           //if ( gorWellInj1.value() > gorConditionInj1.value() )
           //{

              //if      ( moreGorConditionPlanInj1 == " pConst " ) 
              //{ 
                      //# include "pConstPlanInj1.H"
              //}
              //else if ( moreGorConditionPlanInj1 == " qConst " ) 
                //{ 
                      //# include "qConstPlanInj1.H"
                //}

           //}  ////for gorWellInj1 > gorConditionInj1
      
          //else
          //{

           //FatalErrorIn
          //(
            //"in chooseWellPlan.H"
          //)
          //<< "type of plan unrecongnized : pConst and qConst available" 
          //<< exit(FatalError);

          //}

        //}   /// for activeGorConditionInj1    
     

} ////for activeWellInj1

else if ( activeWellInj1.value()==0 )
{

coefImplicitSourceInj1 = 0;
coefExplicitSourceInj1 = 0 

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




/////////////////////////////////////////////////////////Production1///////////////////////////////////////////////////////////////////////////

if ( activeWellPro1.value()==1 )
{
       ///////////////////////////////////////////////
        if ( activeTimeConditionPro1.value()==1 )
        { 
           if ( runTime.value() <= timeConditionPro1.value() )
           {
               if      ( lessTimeConditionPlanPro1 == " pConst " )
               { 
                       # include "pConstPlanPro1.H"
               }
               else if ( lessTimeConditionPlanPro1 == " qConst " )
               {  
                       # include "qConstPlanPro1.H"
               }

           }  ////for runTime.value() <= timeConditionPro1

           else if ( runTime.value() > timeConditionPro1.value() )
           {

              if      ( moreTimeConditionPlanPro1 == " pConst " ) 
              { 
                      # include "pConstPlanPro1.H"
              }
              else if ( moreTimeConditionPlanPro1 == " qConst " ) 
              { 
                      # include "qConstPlanPro1.H"
              }

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
        if ( activeQConditionPro1.value()==1 )
        { 
           if ( qWellPro1.value() <= qConditionPro1.value() )
           {
               if      ( lessQConditionPlanPro1 == " pConst " )
               {  
                       # include "pConstPlanPro1.H"
               }
               else if ( lessQConditionPlanPro1 == " qConst " ) 
               { 
                       # include "qConstPlanPro1.H"
               }

           }  ////for qWellPro1 <= qConditionPro1

           else if ( qWellPro1.value() > qConditionPro1.value() )
           {

              if      ( moreQConditionPlanPro1 == " pConst " ) 
              { 
                      # include "pConstPlanPro1.H"
              }
              else if ( moreQConditionPlanPro1 == " qConst " ) 
              { 
                      # include "qConstPlanPro1.H"
              }

           }  ////for qWellPro1 > qConditionPro1
      
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
        //if ( activeGorConditionPro1.value()==1 )
        //{ 
           //if ( gorWellPro1.value() <= gorConditionPro1.value() )
           //{
               //if      ( lessGorConditionPlanPro1 == " pConst " ) 
               //{ 
                       //# include "pConstPlanPro1.H"
               //}
               //else if ( lessGorConditionPlanPro1 == " qConst " )
               //{  
                       //# include "qConstPlanPro1.H"
               //}

           //}  ////gorWellPro1 <= gorConditionPro1

           //if ( gorWellPro1.value() > gorConditionPro1.value() )
           //{

              //if      ( moreGorConditionPlanPro1 == " pConst " )
              //{  
                      //# include "pConstPlanPro1.H"
              //}
              //else if ( moreGorConditionPlanPro1 == " qConst " )
              //{  
                      //# include "qConstPlanPro1.H"
              //}

           //}  ////gorWellPro1 > gorConditionPro1
      
          //else
          //{

           //FatalErrorIn
          //(
            //"in chooseWellPlan.H"
          //)
          //<< "type of plan unrecongnized : pConst and qConst available" 
          //<< exit(FatalError);

          //}

        //}   /// for activeGorConditionPro1    
     

} ////for activeWellPro1

else if ( activeQConditionPro1.value()==0 )
{

coefImplicitSourcePro1 = 0;
coefExplicitSourcePro1 = 0; 

}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
