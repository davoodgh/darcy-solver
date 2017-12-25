///////////////////////////////////////// Pro1
coefExplicitSourcePro1 =1;
coefImplicitSourcePro1 =1;
coefPConstantPro1 = wellIndexPro1;
explicitSourceTermPro1= ( coefPConstantPro1*pbPro1*WPro1/volumePro1 );
qWellPro1 = sum( coefPConstantPro1*p*WPro1 - coefPConstantPro1*pbPro1*WPro1 );
