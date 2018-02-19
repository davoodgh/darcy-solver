////////////////////////////////////////////////////////// Production well1 phasea/////////////////////////////////////////////////////////////
//                                                                                                                                           //
/////////////////////////////////////////////////////  well plan is constant pressure/////////////////////////////////////////////////////////

coefExplicitSourcePro1a =1;
coefImplicitSourcePro1a =1;
coefPConstantPro1a = wellIndexPro1a;

declineHeadPro1a = ( cellCoordinate - zCoordinatePro1a*WPro1 ) & g * rhoa;

explicitSourceTermPro1a = ( coefPConstantPro1a*pbPro1a*WPro1/volumePro1a - coefPConstantPro1a*declineHeadPro1a*WPro1/volumePro1a );
qWellPro1a = sum( coefPConstantPro1a*p*WPro1 + coefPConstantPro1a*declineHeadPro1a*WPro1 - coefPConstantPro1a*pbPro1a*WPro1 );

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



