//////////////////////////////////////////////////// Production well1 phaseb//////////////////////////////////////////////////////////////////
//                                                                                                                                          //                                                                       
///////////////////////////////////////////////  well plan is constant pressure///////////////////////////////////////////////////////////////

coefExplicitSourcePro1b =1;
coefImplicitSourcePro1b =1;
coefPConstantPro1b = wellIndexPro1b;

declineHeadPro1b = ( cellCoordinate - zCoordinatePro1b*WPro1 ) & g * rhob;

explicitSourceTermPro1b = ( coefPConstantPro1b*pbPro1b*WPro1/volumePro1b - coefPConstantPro1b*declineHeadPro1b*WPro1/volumePro1b );
qWellPro1b = sum( coefPConstantPro1b*p*WPro1 + coefPConstantPro1b*declineHeadPro1b*WPro1 - coefPConstantPro1b*pbPro1b*WPro1 );

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



