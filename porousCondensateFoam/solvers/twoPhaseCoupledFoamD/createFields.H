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

Info << "Reading field Sb\n" << endl;
volScalarField Sb
(
    IOobject
    (
        "Sb",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);

volScalarField Sa
(
    IOobject
    (
        "Sa",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::AUTO_WRITE
    ),
    mesh,
    dimensionedScalar("",dimensionSet(0,0,0,0,0),0)
);


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

surfaceTensorField Kf = fvc::interpolate(K,"K");

///////////////////////////////////////////////////

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

dimensionedScalar eps
(
transportProperties.lookup("eps")
);

/////////////////////////////////////////

/////////////////////////////////////////

// phasea
autoPtr<incompressiblePhase> phasea = incompressiblePhase::New(mesh,transportProperties,"a");
volVectorField& Ua = phasea->U();
surfaceScalarField& phia = phasea->phi();
const dimensionedScalar& rhoa = phasea->rho();
const dimensionedScalar& mua = phasea->mu();

// phaseb
autoPtr<incompressiblePhase> phaseb = incompressiblePhase::New(mesh,transportProperties,"b");
volVectorField& Ub = phasea->U();
surfaceScalarField& phib = phaseb->phi();
const dimensionedScalar& rhob = phaseb->rho();
const dimensionedScalar& mub = phaseb->mu();

//////////////////////////////////////////

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
    Ua + Ub
);

volVectorField Up
(
    IOobject
    (
        "Up",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::NO_WRITE
    ),
 mesh,
dimensionedVector  ("Up",dimensionSet (0,1,-1,0,0,0,0),Foam::vector(0,0,0))
);

#include "createPhi.H"
surfaceScalarField phip = phi;
///////////////////////////////////////////////

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

//////////////////// Block vector field for pressure and saturation//////////////////////////////// 

   Info << "Creating field X\n" << endl;
    volVector2Field X
    (
        IOobject
        (
            "X",
            runTime.timeName(),
            mesh,
            IOobject::NO_READ,
            IOobject::NO_WRITE
        ),
        mesh,
        dimensionedVector2("zero", dimless, vector2::zero)
    );

////////////////////////////////////////////////////////////////////////////////////////////////////////



