    label pRefCell = 0;
    scalar pRefValue = 0;
    setRefCell
    (
        p,
        mesh.solutionDict().subDict("positivePressureControl"),
        pRefCell,
        pRefValue
    );
 
