 
fvMatrix<scalar> pInSb(fvm::laplacian(-Mbf,p) + fvm::Sp(coefImplicitSourcePro1b*coefPConstantPro1b*WPro1/volumePro1b,p)

                       + fvm::Sp(coefImplicitSourceInj1b*coefPConstantInj1b*WInj1/volumeInj1b,p));



    // Last argument in insertBlockCoupling says if the column direction
    // should be incremented. This is needed for arbitrary positioning
    // of U and p in the system. This could be better. VV, 30/April/2014
    //XpEqn.insertBlockCoupling(0, 1, pInSb, true);
    //XpEqn.insertBlockCoupling(1, 0, SbInp, false);
