
scalar  windexInj1 = (2*3.14*heightInj1*Foam::pow(Kx*Kz,0.5)) / (mu*log(r_eqInj1/radiusInj1));
scalar qwellInj1 = gMin( windexInj1*p*WInj1 - windexInj1*pbInj1*WInj1 );    

if (activetimeconditionInj1)

  {
    if ( runTime.value() <= timechangeplan)

     { 
       scalar coefunconstqInj1 = windexInj1;
       scalar coefconstqInj1 = 0;
     }

   else
       { 
         scalar coefunconstqInj1 = 0;
         scalar coefconstqInj1 = 1;
      }
    } 

else

   {
  
    if ( qwellInj1 >= qchangeplanInj1)

      { 
        scalar coefunconstqInj1 = windexInj1;
        scalar coefconstqInj1 = 0;
      }

   else
       { 
         scalar coefunconstqInj1 = 0;
         scalar coefconstqInj1 = 1;
       }
  }
/////////////////////////////////////////////////////////////

scalar  windexPro1 = (2*3.14*heightPro1*Foam::pow(Kx*Kz,0.5)) / (mu*log(r_eqPro1/radiusPro1));
scalar qwellPro1 = gMax( windexPro1*p*WPro1 - windexPro1*pbPro1*WPro1 );   

if (activetimeconditionPro1)

 {
  if ( runTime.value() >= timechangeplanPro1)

    { 
     scalar coefunconstqPro1 = windexPro1;
     scalar coefconstqPro1 = 0;
    }

  else
      { 
       scalar coefunconstqPro1 = 0;
       scalar coefconstqPro1 = 1;
      }
 }

else

   {
  
    if ( qwellPro1 <= qchangeplan)

     { 
       scalar coefunconstqPro1 = windexPro1;
       scalar coefconstqPro1 = 0;
     }

    else
        { 
         scalar coefunconstqPro1 = windexPro1;
         scalar coefconstqPro1 = 0;
        }
 }
////////////////////////////////////////////////////////////////////////
 
volScalarField  explicitsourceterm = (coefconstqPro1*SrcPro1*WPro1)*activatePro1 - (coefconstqInj1*SrcInj1*WInj1)*activateInj1

            + (coefunconstqPro1*WPro1*pbPro1/volumePro1)*activatePro1 - (coefunconstqInj1*WInj1*pbInj1/volumeInj1)*activateInj1;
 





