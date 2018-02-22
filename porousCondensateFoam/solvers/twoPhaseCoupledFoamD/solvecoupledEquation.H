 while (maxResidual > convergenceCriterion)
 {
              
        # include "readBlockSolverControls.H"
        # include "readFieldBounds.H" 

        p.storePrevIter();
        Sb.storePrevIter();

        // Initialize the X block system (matrix, source and reference to X)
        fvBlockMatrix<vector2> XEqn(X);
                  
        #include "updateEquationFields.H"
        // Assemble and insert pressure equation
        # include "pEqn.H"

        // Assemble and insert satiration equation
        # include "SbEqn.H"

        // Assemble and insert coupling terms
        # include "couplingTerms.H"

        // Solve the block matrix
        maxResidual = cmptMax(XEqn.solve().initialResidual());

        // Retrieve solution
        XEqn.retrieveSolution(0, p.internalField());
        XEqn.retrieveSolution(1, Sb.internalField());

        #include "updateEquationFields.H"
        #include "calculateFlux.H"
        #include "boundPSb.H"

        p.relax();
        Sb.relax();

 }
