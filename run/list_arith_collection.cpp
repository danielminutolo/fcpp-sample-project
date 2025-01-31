// Copyright © 2021 Giorgio Audrito. All Rights Reserved.

/**
 * @file list_collection.cpp
 * @brief Runs a single execution of the spreading collection case study with a graphical user interface.
 */

#include "lib/list_arith_collection.hpp"

using namespace fcpp;

int main() {
    //! @brief The network object type (interactive simulator with given options).
    using net_t = component::interactive_simulator<option::list>::net;
    //! @brief The initialisation values (simulation name, texture of the reference plane, node movement speed).
    auto init_v = common::make_tagged_tuple<option::name, option::texture, option::speed>(
        "List-Arithmetic Collection",
        "fcpp.png",
        comm/4
    );
    //! @brief Construct the network object.
    net_t network{init_v};
    //! @brief Run the simulation until exit.
    network.run();
    return 0;
}
