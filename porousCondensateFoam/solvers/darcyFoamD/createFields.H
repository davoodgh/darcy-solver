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

volTensorField M ("M",K/mu);
surfaceTensorField Kf(fvc::interpolate(K,"K"));
surfaceTensorField Mf ("Mf",Kf/mu);
surfaceScalarField phig("phig",(rho * Mf & g) & mesh.Sf());
surfaceTensorField Lf ("Lf",rho * Mf);


/////////////////////////////


