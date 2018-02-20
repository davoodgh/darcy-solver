
    Up = ( -M & fvc::grad(p) );
    phip = (fvc::interpolate(Up)) & mesh.Sf();
    phi = phip+phiG;

    U = fvc::reconstruct(phi);
    U.correctBoundaryConditions();

    phib == Fbf*phi+(((Lbf-Fbf*Lf)&g) & mesh.Sf());
    phia == phi - phib;
    

    Ub = fvc::reconstruct(phib);
    Ua = U-Ub;

    Ub.correctBoundaryConditions();  
    Ua.correctBoundaryConditions();
