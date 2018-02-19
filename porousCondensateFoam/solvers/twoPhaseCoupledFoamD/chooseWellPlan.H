
///////////////////////////////////////////////////////////Injection 1 phasea/////////////////////////////////////////////////////////////////

if ( activeWellInj1a.value()==1 )
{
        //////////////////////////////////////////////
        if ( activeTimeConditionInj1a.value()==1 )
        { 

           if ( runTime.value() <= timeConditionInj1a.value() )
           {

               if      ( lessTimeConditionPlanInj1a == "pConst" ) 
               {
                       # include "pConstPlanInj1a.H"
               }

               else if ( lessTimeConditionPlanInj1a == "qConst" ) 
               {
                       # include "qConstPlanInj1a.H"
               }

               else
               {

                FatalErrorIn
                (
                 "in chooseWellPlan.H"
                )
                 << "type of plan unrecongnized : pConst and qConst available" 
                 << exit(FatalError);

              }
               

           }  ////for runTime.value() <= timeConditionInj1

           else if ( runTime.value() > timeConditionInj1a.value() )
           {

              if      ( moreTimeConditionPlanInj1a == "pConst" )
              {  
                      # include "pConstPlanInj1a.H"
              }

              else if ( moreTimeConditionPlanInj1a == "qConst" )
              {  
                      # include "qConstPlanInj1a.H"
              }
              
              else
              {

               FatalErrorIn
               (
                "in chooseWellPlan.H"
               )
                << "type of plan unrecongnized : pConst and qConst available" 
                << exit(FatalError);

              }

           }  ////for runTime.value() > timeConditionInj1
      
          

        }   /// for activeTimeConditionInj1a

        /////////////////////////////////////////////////
        if ( activeQConditionInj1a.value()==1 )
        { 
           if ( qWellInj1a.value() <= qConditionInj1a.value() )
           {
               if      ( lessQConditionPlanInj1a == "pConst" ) 
               { 
                       # include "pConstPlanInj1a.H"
               }
               else if ( lessQConditionPlanInj1a == "qConst" )  
               {
                       # include "qConstPlanInj1a.H"
               }
               
               else
               {

               FatalErrorIn
               (
                "in chooseWellPlan.H"
               )
               << "type of plan unrecongnized : pConst and qConst available" 
               << exit(FatalError);

              }

          }  ////for qWellInj1 <= qConditionInj1a

           else if ( qWellInj1a.value() > qConditionInj1a.value() )
           {

              if      ( moreQConditionPlanInj1a == "pConst" ) 
              { 
                      # include "pConstPlanInj1a.H"
              }
              else if ( moreQConditionPlanInj1a == "qConst" )
              {  
                      # include "qConstPlanInj1a.H"
              }
           
              else
              {

                FatalErrorIn
               (
                "in chooseWellPlan.H"
               )
               << "type of plan unrecongnized : pConst and qConst available" 
               << exit(FatalError);

              }

           }  ////for qWellInj1a > qConditionInj1a
      
          

        }   /// for activeQConditionInj1a

        /////////////////////////////////////////////////
        //if ( activeGorConditionInj1a.value()==1 )
        //{ 
           //if ( gorWellInj1a.value() <= gorConditionInj1a.value() )
           //{
               //if      ( lessGorConditionPlanInj1a == "pConst" )
               //{  
                       //# include "pConstPlanInj1a.H"
               //}
               //else if ( lessGorConditionPlanInj1a == "qConst" ) 
                 //{ 
                       //# include "qConstPlanInj1a.H"
                 //}
                 //else
                 //{

                 //FatalErrorIn
                 //(
                 //"in chooseWellPlan.H"
                 //)
                 //<< "type of plan unrecongnized : pConst and qConst available" 
                 //<< exit(FatalError);

                 // }

           //}  ////for gorWellInj1a <= gorConditionInj1a

           //if ( gorWellInj1a.value() > gorConditionInj1a.value() )
           //{

              //if      ( moreGorConditionPlanInj1a == "pConst" ) 
              //{ 
                      //# include "pConstPlanInj1a.H"
              //}
              //else if ( moreGorConditionPlanInj1a == "qConst" ) 
                //{ 
                      //# include "qConstPlanInj1a.H"
                //}
                //else
                //{

                 //FatalErrorIn
                //(
                 //"in chooseWellPlan.H"
                //)
               //<< "type of plan unrecongnized : pConst and qConst available" 
              // << exit(FatalError);

                //}

           //}  ////for gorWellInj1a > gorConditionInj1a
      
          

        //}   /// for activeGorConditionInj1a    
     

} ////for activeWellInj1

else if ( activeWellInj1a.value()==0 )
{

coefImplicitSourceInj1a = 0;
coefExplicitSourceInj1a = 0;

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




///////////////////////////////////////////////////////////Production1 phasea///////////////////////////////////////////////////////////////////

if ( activeWellPro1a.value()==1 )
{
       ///////////////////////////////////////////////
        if ( activeTimeConditionPro1a.value()==1 )
        { 

           if ( runTime.value() <= timeConditionPro1a.value() )
           {

               if      ( lessTimeConditionPlanPro1a == "pConst" )
               { 
                       # include "pConstPlanPro1a.H"
               }

               else if ( lessTimeConditionPlanPro1a == "qConst" )
               {  
                       # include "qConstPlanPro1a.H"
               }
               
               else
               {

                FatalErrorIn
               (
                "in chooseWellPlan.H"
               )
                << "type of plan unrecongnized : pConst and qConst available" 
                << exit(FatalError);

                }

           }  ////for runTime.value() <= timeConditionPro1a

           else if ( runTime.value() > timeConditionPro1a.value() )
           {

              if      ( moreTimeConditionPlanPro1a == "pConst" ) 
              { 
                      # include "pConstPlanPro1a.H"
              }

              else if ( moreTimeConditionPlanPro1a == "qConst" ) 
              { 
                      # include "qConstPlanPro1a.H"
              }
            
              else
              {

               FatalErrorIn
               (
                "in chooseWellPlan.H"
               )
                << "type of plan unrecongnized : pConst and qConst available" 
                << exit(FatalError);

              }

           }  ////for runTime.value() > timeConditionPro1a

        }   /// for activeTimeConditionPro1a

        /////////////////////////////////////////////////
        if ( activeQConditionPro1a.value()==1 )
        { 
           if ( qWellPro1a.value() <= qConditionPro1a.value() )
           {

               if      ( lessQConditionPlanPro1a == "pConst" )
               {  
                       # include "pConstPlanPro1a.H"
               }

               else if ( lessQConditionPlanPro1a == "qConst" ) 
               { 
                       # include "qConstPlanPro1a.H"
               }
 
               else
               {

                FatalErrorIn
               (
                "in chooseWellPlan.H"
               )
                << "type of plan unrecongnized : pConst and qConst available" 
                << exit(FatalError);

               }

           }  ////for qWellPro1a <= qConditionPro1a

           else if ( qWellPro1a.value() > qConditionPro1a.value() )
           {

              if      ( moreQConditionPlanPro1a == "pConst" ) 
              { 
                      # include "pConstPlanPro1a.H"
              }

              else if ( moreQConditionPlanPro1a == "qConst" ) 
              { 
                      # include "qConstPlanPro1a.H"
              }
              
              else
              {

               FatalErrorIn
              (
               "in chooseWellPlan.H"
              )
              << "type of plan unrecongnized : pConst and qConst available" 
              << exit(FatalError);

              }

           }  ////for qWellPro1a > qConditionPro1a
      
         
        }   /// for activeQConditionInj1a

        /////////////////////////////////////////////////
        //if ( activeGorConditionPro1a.value()==1 )
        //{ 
           //if ( gorWellPro1a.value() <= gorConditionPro1a.value() )
           //{
               //if      ( lessGorConditionPlanPro1a == "pConst" ) 
               //{ 
                       //# include "pConstPlanPro1a.H"
               //}
               //else if ( lessGorConditionPlanPro1a == "qConst" )
               //{  
                       //# include "qConstPlanPro1a.H"
               //}
               //else
              // {

               // FatalErrorIn
                //(
                 //"in chooseWellPlan.H"
                //)
                //<< "type of plan unrecongnized : pConst and qConst available" 
               //<< exit(FatalError);

               //}

           //}  ////gorWellPro1a <= gorConditionPro1a

           //if ( gorWellPro1a.value() > gorConditionPro1a.value() )
           //{

              //if      ( moreGorConditionPlanPro1a == "pConst" )
              //{  
                      //# include "pConstPlanPro1a.H"
              //}
              //else if ( moreGorConditionPlanPro1a == "qConst" )
              //{  
                      //# include "qConstPlanPro1a.H"
              //}
             
              //else
              //{

              //FatalErrorIn
              //(
               //"in chooseWellPlan.H"
               //)
               // << "type of plan unrecongnized : pConst and qConst available" 
                // << exit(FatalError);

               //}

           //}  ////gorWellPro1a > gorConditionPro1a
      
         

        //}   /// for activeGorConditionPro1a    
     

} ////for activeWellPro1a

else if ( activeQConditionPro1a.value()==0 )
{

coefImplicitSourcePro1a = 0;
coefExplicitSourcePro1a = 0; 

}
////////////////////////////////////////////////////final phase a in well1//////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////injection1 phaseb///////////////////////////////////////////////////////////////////

if ( activeWellInj1b.value()==1 )
{
        //////////////////////////////////////////////
        if ( activeTimeConditionInj1b.value()==1 )
        { 

           if ( runTime.value() <= timeConditionInj1b.value() )
           {

               if      ( lessTimeConditionPlanInj1b == "pConst" ) 
               {
                       # include "pConstPlanInj1b.H"
               }

               else if ( lessTimeConditionPlanInj1b == "qConst" ) 
               {
                       # include "qConstPlanInj1b.H"
               }

               else
               {

                FatalErrorIn
                (
                 "in chooseWellPlan.H"
                )
                 << "type of plan unrecongnized : pConst and qConst available" 
                 << exit(FatalError);

              }
               

           }  ////for runTime.value() <= timeConditionInj1b

           else if ( runTime.value() > timeConditionInj1b.value() )
           {

              if      ( moreTimeConditionPlanInj1b == "pConst" )
              {  
                      # include "pConstPlanInj1b.H"
              }

              else if ( moreTimeConditionPlanInj1b == "qConst" )
              {  
                      # include "qConstPlanInj1b.H"
              }
              
              else
              {

               FatalErrorIn
               (
                "in chooseWellPlan.H"
               )
                << "type of plan unrecongnized : pConst and qConst available" 
                << exit(FatalError);

              }

           }  ////for runTime.value() > timeConditionInj1b
      
          

        }   /// for activeTimeConditionInj1b

        /////////////////////////////////////////////////
        if ( activeQConditionInj1b.value()==1 )
        { 
           if ( qWellInj1b.value() <= qConditionInj1b.value() )
           {
               if      ( lessQConditionPlanInj1b == "pConst" ) 
               { 
                       # include "pConstPlanInj1b.H"
               }
               else if ( lessQConditionPlanInj1b == "qConst" )  
               {
                       # include "qConstPlanInj1b.H"
               }
               
               else
               {

               FatalErrorIn
               (
                "in chooseWellPlan.H"
               )
               << "type of plan unrecongnized : pConst and qConst available" 
               << exit(FatalError);

              }

          }  ////for qWellInj1 <= qConditionInj1b

           else if ( qWellInj1b.value() > qConditionInj1b.value() )
           {

              if      ( moreQConditionPlanInj1b == "pConst" ) 
              { 
                      # include "pConstPlanInj1b.H"
              }
              else if ( moreQConditionPlanInj1b == "qConst" )
              {  
                      # include "qConstPlanInj1b.H"
              }
           
              else
              {

                FatalErrorIn
               (
                "in chooseWellPlan.H"
               )
               << "type of plan unrecongnized : pConst and qConst available" 
               << exit(FatalError);

              }

           }  ////for qWellInj1b > qConditionInj1b
      
          

        }   /// for activeQConditionInj1b

        /////////////////////////////////////////////////
        //if ( activeGorConditionInj1b.value()==1 )
        //{ 
           //if ( gorWellInj1b.value() <= gorConditionInj1b.value() )
           //{
               //if      ( lessGorConditionPlanInj1b == "pConst" )
               //{  
                       //# include "pConstPlanInj1b.H"
               //}
               //else if ( lessGorConditionPlanInj1b == "qConst" ) 
                 //{ 
                       //# include "qConstPlanInj1b.H"
                 //}
                 //else
                 //{

                 //FatalErrorIn
                 //(
                 //"in chooseWellPlan.H"
                 //)
                 //<< "type of plan unrecongnized : pConst and qConst available" 
                 //<< exit(FatalError);

                 // }

           //}  ////for gorWellInj1b <= gorConditionInj1b

           //if ( gorWellInj1b.value() > gorConditionInj1b.value() )
           //{

              //if      ( moreGorConditionPlanInj1b == "pConst" ) 
              //{ 
                      //# include "pConstPlanInj1b.H"
              //}
              //else if ( moreGorConditionPlanInj1b == "qConst" ) 
                //{ 
                      //# include "qConstPlanInj1b.H"
                //}
                //else
                //{

                 //FatalErrorIn
                //(
                 //"in chooseWellPlan.H"
                //)
               //<< "type of plan unrecongnized : pConst and qConst available" 
              // << exit(FatalError);

                //}

           //}  ////for gorWellInj1b > gorConditionInj1b
      
          

        //}   /// for activeGorConditionInj1b    
     

} ////for activeWellInj1b

else if ( activeWellInj1b.value()==0 )
{

coefImplicitSourceInj1b = 0;
coefExplicitSourceInj1b = 0;

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




///////////////////////////////////////////////////////////Production1 phaseb///////////////////////////////////////////////////////////////////

if ( activeWellPro1b.value()==1 )
{
       ///////////////////////////////////////////////
        if ( activeTimeConditionPro1b.value()==1 )
        { 

           if ( runTime.value() <= timeConditionPro1b.value() )
           {

               if      ( lessTimeConditionPlanPro1b == "pConst" )
               { 
                       # include "pConstPlanPro1b.H"
               }

               else if ( lessTimeConditionPlanPro1b == "qConst" )
               {  
                       # include "qConstPlanPro1b.H"
               }
               
               else
               {

                FatalErrorIn
               (
                "in chooseWellPlan.H"
               )
                << "type of plan unrecongnized : pConst and qConst available" 
                << exit(FatalError);

                }

           }  ////for runTime.value() <= timeConditionPro1b

           else if ( runTime.value() > timeConditionPro1b.value() )
           {

              if      ( moreTimeConditionPlanPro1b == "pConst" ) 
              { 
                      # include "pConstPlanPro1b.H"
              }

              else if ( moreTimeConditionPlanPro1b == "qConst" ) 
              { 
                      # include "qConstPlanPro1b.H"
              }
            
              else
              {

               FatalErrorIn
               (
                "in chooseWellPlan.H"
               )
                << "type of plan unrecongnized : pConst and qConst available" 
                << exit(FatalError);

              }

           }  ////for runTime.value() > timeConditionPro1b

        }   /// for activeTimeConditionPro1b

        /////////////////////////////////////////////////
        if ( activeQConditionPro1b.value()==1 )
        { 
           if ( qWellPro1b.value() <= qConditionPro1b.value() )
           {

               if      ( lessQConditionPlanPro1b == "pConst" )
               {  
                       # include "pConstPlanPro1b.H"
               }

               else if ( lessQConditionPlanPro1b == "qConst" ) 
               { 
                       # include "qConstPlanPro1b.H"
               }
 
               else
               {

                FatalErrorIn
               (
                "in chooseWellPlan.H"
               )
                << "type of plan unrecongnized : pConst and qConst available" 
                << exit(FatalError);

               }

           }  ////for qWellPro1b <= qConditionPro1b

           else if ( qWellPro1b.value() > qConditionPro1b.value() )
           {

              if      ( moreQConditionPlanPro1b == "pConst" ) 
              { 
                      # include "pConstPlanPro1b.H"
              }

              else if ( moreQConditionPlanPro1b == "qConst" ) 
              { 
                      # include "qConstPlanPro1b.H"
              }
              
              else
              {

               FatalErrorIn
              (
               "in chooseWellPlan.H"
              )
              << "type of plan unrecongnized : pConst and qConst available" 
              << exit(FatalError);

              }

           }  ////for qWellPro1b > qConditionPro1b
      
         
        }   /// for activeQConditionInj1b

        /////////////////////////////////////////////////
        //if ( activeGorConditionPro1b.value()==1 )
        //{ 
           //if ( gorWellPro1b.value() <= gorConditionPro1b.value() )
           //{
               //if      ( lessGorConditionPlanPro1b == "pConst" ) 
               //{ 
                       //# include "pConstPlanPro1b.H"
               //}
               //else if ( lessGorConditionPlanPro1b == "qConst" )
               //{  
                       //# include "qConstPlanPro1b.H"
               //}
               //else
              // {

               // FatalErrorIn
                //(
                 //"in chooseWellPlan.H"
                //)
                //<< "type of plan unrecongnized : pConst and qConst available" 
               //<< exit(FatalError);

               //}

           //}  ////gorWellPro1b <= gorConditionPro1b

           //if ( gorWellPro1b.value() > gorConditionPro1b.value() )
           //{

              //if      ( moreGorConditionPlanPro1b == "pConst" )
              //{  
                      //# include "pConstPlanPro1b.H"
              //}
              //else if ( moreGorConditionPlanPro1b == "qConst" )
              //{  
                      //# include "qConstPlanPro1b.H"
              //}
             
              //else
              //{

              //FatalErrorIn
              //(
               //"in chooseWellPlan.H"
               //)
               // << "type of plan unrecongnized : pConst and qConst available" 
                // << exit(FatalError);

               //}

           //}  ////gorWellPro1b > gorConditionPro1b
      
         

        //}   /// for activeGorConditionPro1b    
     

} ////for activeWellPro1b

else if ( activeQConditionPro1b.value()==0 )
{

coefImplicitSourcePro1b = 0;
coefExplicitSourcePro1b = 0; 

}
////////////////////////////////////////////////////final phase b in well1//////////////////////////////////////////////////////////////////////


