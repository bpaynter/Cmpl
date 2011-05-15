/***********************************************************************
 *  This code is part of cmplFrame
 *
 *  Copyright (C) 2010 Mike Steglich - Technical University
 *  of Applied Sciences  Wildau, Germany
 *  and Thomas Schleiff - Halle(Saale), Germany
 *
 *  cmplFrame and CMPL are projects of the Technical University of
 *  Applied Sciences Wildau and the Institute for Operations Research
 *  and Business Management at the Martin Luther University
 *  Halle-Wittenberg.
 *  Please visit the project homepage <www.coliop.org>
 *
 *  cmplFrame is free software; you can redistribute it and/or modify it
 *  under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  cmplFrame is distributed in the hope that it will be useful, but WITHOUT
 *  ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 *  or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public
 *  License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, see <http://www.gnu.org/licenses/>.
 *
 ***********************************************************************/

#include <QCoreApplication>


#include "cflocal.hh"
#include "cfremotesynchronously.hh"
#include "cfremoteasynchronously.hh"


int main(int argc, char *argv[]) {

    QCoreApplication app(argc, argv);

    string myModel = "diet.cmpl";
    string service ="http://gsbkip.chicagogsb.edu/os/OSSolverService.jws";


    cout << "test local started" << endl;
    cfLocal cfL;
    cfL.solve(myModel);
    cout << "test local finished" << endl;

    cout << "test remote synchronously started" << endl;
    cFRemoteSynchronously cfRs;
    cfRs.solve(myModel, service);
    cout << "test remote synchronously finished" << endl;

    cout << "test remote asynchronously started" << endl;
    cFRemoteAsynchronously cfRa;
    cfRa.runService(myModel, service);
    cout << "test remote asynchronously finished" << endl;


    return 0;
}
