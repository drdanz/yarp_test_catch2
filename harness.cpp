/*
 * Copyright (C) 2006 RobotCub Consortium
 * Copyright (C) 2018 Istituto Italiano di Tecnologia (IIT)
 * Authors: Paul Fitzpatrick, Daniele E. Domenichelli
 * CopyPolicy: Released under the terms of the LGPLv2.1 or later, see LGPL.TXT
 */


#define CATCH_CONFIG_RUNNER
#include <catch.hpp>

#ifdef YARP2_LINUX
# define CHECK_FOR_LEAKS
#endif

#ifdef CHECK_FOR_LEAKS
# include <mcheck.h>
#endif


#include <yarp/os/Network.h>
#include <yarp/os/Property.h>
#include <yarp/os/NameStore.h>

#include <yarp/serversql/yarpserversql.h>

using namespace yarp::os;

int main(int argc, char *argv[])
{
#ifdef CHECK_FOR_LEAKS
    mtrace();
#endif

    Catch::Session session;

    bool verbose = 0;

    using namespace Catch::clara;
    auto cli = session.cli() | Opt(verbose )["-y"]["--yarp-verbose"]("Enable verbose mode");
    session.cli( cli );

    int returnCode = session.applyCommandLine( argc, argv );
    if( returnCode != 0 ) {
        return returnCode;
    }

    yarp::os::Network yarp;

    yarp::os::Property opts;
    opts.put("portdb",":memory:");
    opts.put("subdb",":memory:");
    opts.put("local",1);
    yarp::os::NameStore *store = yarpserver_create(opts);
    yarp.queryBypass(store);

    if (verbose) {
        Network::setVerbosity(1);
    }

    returnCode = session.run();

    yarp.queryBypass(nullptr);
    delete store;

    return returnCode;
}
