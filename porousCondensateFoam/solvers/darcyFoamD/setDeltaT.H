scalar deltaT = readScalar(runTime.controlDict().lookup("deltaT"));
runTime.setDeltaT( deltaT);
Info<< "deltaT = " <<  runTime.deltaT().value() << endl;
