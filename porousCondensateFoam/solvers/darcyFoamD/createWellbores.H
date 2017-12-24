/////////////////////////////////////////////////////////////////////////

Info<< "Reading wellboreProperties\n" << endl;

IOdictionary wellboreProperties
(
    IOobject
    (
        "wellboreProperties",
        runTime.constant(),
        mesh,
        IOobject::MUST_READ,
        IOobject::NO_WRITE
    )
);


// Injection1 
autoPtr<wellcase> wellInj1 = wellcase::New(mesh,wellboreProperties,"Inj1");
const dimensionedScalar& activeWellInj1 = wellInj1->activeWell();

const dimensionedScalar& activeTimeConditionInj1 = wellInj1->activeTimeCondition();
const dimensionedScalar& timeConditionInj1 = wellInj1->timeCondition();

const dimensionedScalar& activeQConditionInj1 = wellInj1->activeQCondition();
const dimensionedScalar& qConditionInj1 = wellInj1->qCondition();

const dimensionedScalar& activeGorConditionInj1 = wellInj1->activeGorCondition();
const dimensionedScalar& gorConditionInj1 = wellInj1->gorCondition();

const word& lessTimeConditionPlanInj1 = wellInj1->lessTimeConditionPlan();
const word& moreTimeConditionPlanInj1 = wellInj1->moreTimeConditionPlan();

const word& lessQConditionPlanInj1 = wellInj1->lessQConditionPlan();
const word& moreQConditionPlanInj1 = wellInj1->moreQConditionPlan();

const word& lessGorConditionPlanInj1 = wellInj1->lessGorConditionPlan();
const word& moreGorConditionPlanInj1 = wellInj1->moreGorConditionPlan();

const dimensionedScalar& qConstantInj1 = wellInj1->qConstant();

const dimensionedScalar& volumeInj1 = wellInj1->volume();
const dimensionedScalar& radiusInj1 = wellInj1->radius();
const dimensionedScalar& heightInj1 = wellInj1->height();
const dimensionedScalar& deltaxInj1 = wellInj1->deltax();
const dimensionedScalar& deltayInj1 = wellInj1->deltay();
const dimensionedScalar& pbInj1 = wellInj1->pb();

Info<< "Reading field WInj1 (injection wellbore)\n" << endl;
volScalarField WInj1
(
    IOobject
    (
        "WInj1",
        runTime.timeName(),
        mesh,
        IOobject::READ_IF_PRESENT,
        IOobject::NO_WRITE
    ),
    mesh,
    dimensionedScalar("",dimensionSet(0,0,0,0,0),0)
);

dimensionedScalar SrcInj1("SrcInj1",dimensionSet(0,0,-1,0,0),0.);
SrcInj1 = qConstantInj1/volumeInj1;

//Fields for constant q plan in wellInj1

volScalarField coefQConstantInj1
(
    IOobject
    (
        "coefQConstantInj1",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::NO_WRITE
    ),
    mesh,
dimensionedScalar  ("coefQConstantInj1",dimensionSet (0,0,0,0,0,0,0),0)    
);

//Fields for constant pressure plan in wellInj1

volScalarField coefPConstantInj1
(
    IOobject
    (
        "coefPConstantInj1",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::NO_WRITE
    ),
    mesh,
dimensionedScalar  ("coefPConstantInj1",dimensionSet (-1,4,1,0,0,0,0),0)
);

volScalarField r_eqInj1=0.28*  Foam::pow( deltaxInj1*deltaxInj1*Foam::pow(K2,0.5) + deltayInj1*deltayInj1*Foam::pow(K1,0.5),0.5 ) / (Foam::pow(K1,0.25) + Foam::pow(K2,0.25) );

volScalarField  wellIndexInj1 = (2*3.14*heightInj1*Foam::pow(Kx*Ky,0.5)) / (mu*log(r_eqInj1/radiusInj1));

dimensionedScalar coefImplicitSourceInj1("coefImplicitSourceInj1",dimensionSet (0,0,0,0,0,0,0),0);
dimensionedScalar coefExplicitSourceInj1("coefExplicitSourceInj1",dimensionSet (0,0,0,0,0,0,0),1);
///

volScalarField explicitSourceTermInj1
(
    IOobject
    (
       "explicitSourceTermInj1",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::NO_WRITE
    ),
    mesh,
dimensionedScalar  ("explicitSourceTermInj1",dimensionSet (0,0,-1,0,0,0,0),0)   
);

dimensionedScalar qWellInj1("qWellInj1",dimensionSet (0,3,-1,0,0,0,0),0);

// production1
autoPtr<wellcase> wellPro1 = wellcase::New(mesh,wellboreProperties,"Pro1");
const dimensionedScalar& activeWellPro1 = wellPro1->activeWell();

const dimensionedScalar& activeTimeConditionPro1 = wellPro1->activeTimeCondition();
const dimensionedScalar& timeConditionPro1 = wellPro1->timeCondition();

const dimensionedScalar& activeQConditionPro1 = wellPro1->activeQCondition();
const dimensionedScalar& qConditionPro1 = wellPro1->qCondition();

const dimensionedScalar& activeGorConditionPro1 = wellPro1->activeGorCondition();
const dimensionedScalar& gorConditionPro1 = wellPro1->gorCondition();

const word& lessTimeConditionPlanPro1 = wellPro1->lessTimeConditionPlan();
const word& moreTimeConditionPlanPro1 = wellPro1->moreTimeConditionPlan();

const word& lessQConditionPlanPro1 = wellPro1->lessQConditionPlan();
const word& moreQConditionPlanPro1 = wellPro1->moreQConditionPlan();

const word& lessGorConditionPlanPro1 = wellPro1->lessGorConditionPlan();
const word& moreGorConditionPlanPro1 = wellPro1->moreGorConditionPlan();

const dimensionedScalar& qConstantPro1 = wellPro1->qConstant();

const dimensionedScalar& volumePro1 = wellPro1->volume();
const dimensionedScalar& radiusPro1 = wellPro1->radius();
const dimensionedScalar& heightPro1 = wellPro1->height();
const dimensionedScalar& deltaxPro1 = wellPro1->deltax();
const dimensionedScalar& deltayPro1 = wellPro1->deltay();
const dimensionedScalar& pbPro1 = wellPro1->pb();

Info<< "Reading field WPro1 (production wellbore)\n" << endl;
volScalarField WPro1
(
    IOobject
    (
        "WPro1",
        runTime.timeName(),
        mesh,
        IOobject::READ_IF_PRESENT,
        IOobject::NO_WRITE
    ),
    mesh,
    dimensionedScalar("",dimensionSet(0,0,0,0,0),0)
);

dimensionedScalar SrcPro1("SrcPro1",dimensionSet(0,0,-1,0,0),0.);
SrcPro1 = qConstantPro1/volumePro1;

//Fields for constant q plan in wellPro1

volScalarField coefQConstantPro1
(
    IOobject
    (
        "coefQConstantPro1",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::NO_WRITE
    ),
    mesh,
dimensionedScalar  ("coefQConstantPro1",dimensionSet (0,0,0,0,0,0,0),0)
);


//Fields for constant pressure plan in wellPro1

volScalarField coefPConstantPro1
(
    IOobject
    (
        "coefPConstantPro1",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::NO_WRITE
    ),
    mesh,
dimensionedScalar  ("coefPConstantPro1",dimensionSet (-1,4,1,0,0,0,0),0)
);

volScalarField  r_eqPro1=0.28*  Foam::pow( deltaxPro1*deltaxPro1*Foam::pow(K2,0.5) + deltayPro1*deltayPro1*Foam::pow(K1,0.5),0.5 ) / (Foam::pow(K1,0.25) + Foam::pow(K2,0.25) );

volScalarField  wellIndexPro1 = (2*3.14*heightPro1*Foam::pow(Kx*Ky,0.5)) / (mu*log(r_eqPro1/radiusPro1));

dimensionedScalar coefImplicitSourcePro1("coefImplicitSourcePro1",dimensionSet (0,0,0,0,0,0,0),0);
dimensionedScalar coefExplicitSourcePro1("coefExplicitSourcePro1",dimensionSet (0,0,0,0,0,0,0),1);

volScalarField explicitSourceTermPro1
(
    IOobject
    (
       "explicitSourceTermPro1",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::NO_WRITE
    ),
    mesh,
dimensionedScalar  ("explicitSourceTermPro1",dimensionSet (0,0,-1,0,0,0,0),0)   
);
 
dimensionedScalar qWellPro1("qWellPro1",dimensionSet (0,3,-1,0,0,0,0),0);
////////////////////////////////////////////
