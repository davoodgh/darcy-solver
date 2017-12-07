Info << "Reading field p\n" << endl;
volScalarField p
(
    IOobject
    (
        "p",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);

Info << "Reading transportProperties\n" << endl;
IOdictionary transportProperties
(
    IOobject
    (
        "transportProperties",
        runTime.constant(),
        mesh,
        IOobject::MUST_READ_IF_MODIFIED,
        IOobject::NO_WRITE
    )
);

Info<< "Reading field U\n" << endl;
volVectorField U
(
    IOobject
    (
        "U",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::NO_WRITE
    ),
   mesh 
);


//#include "createPhi.H"

Info << "Reading field K\n" << endl;
volTensorField K
(
    IOobject
    (
        "K",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);

dimensionedScalar mu
(
transportProperties.lookup("mu")
);

dimensionedScalar rho
(
transportProperties.lookup("rho")
);

volTensorField M ("M",K/mu);
surfaceTensorField Kf(fvc::interpolate(K,"K"));
surfaceTensorField Mf ("Mf",Kf/mu);
surfaceScalarField phiG("phiG",(rho * Mf & g) & mesh.Sf());
surfaceScalarField phiPc("phiPc", 0 * phiG);


/////////////////////////////


