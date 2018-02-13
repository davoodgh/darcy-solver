//////////////////////////////////////////////////////////////
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
        IOobject::MUST_READ,
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
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
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

volVectorField cellCoordinate
(
    IOobject
    (
        "cellCoordinate",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::NO_WRITE
    ),
   mesh,
   dimensionedVector  ("cellCoordinate",dimensionSet (0,1,0,0,0,0,0),Foam::vector(0,0,0)) 
);
cellCoordinate = mesh.C();

volTensorField M ("M",K/mu);
surfaceTensorField Kf(fvc::interpolate(K,"K"));
surfaceTensorField Mf ("Mf",Kf/mu);
surfaceScalarField phig("phig",(rho * Mf & g) & mesh.Sf());
surfaceTensorField Lf ("Lf",rho * Mf);


//////////////////////////////////////////////////////////////////////////////


