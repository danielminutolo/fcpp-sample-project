// Copyright © 2021 Giorgio Audrito. All Rights Reserved.

#include "lib/fcpp.hpp"
#include "lib/spreading_collection.hpp"

using namespace fcpp;
using namespace component::tags;
using namespace coordination::tags;

using round_s = sequence::periodic<
    distribution::interval_n<times_t, 0, 1>,
    distribution::weibull_n<times_t, 10, 1, 10>
>;

using rectangle_d = distribution::rect_n<1, 0, 0, 0, side, side, height>;

constexpr size_t dim = 3;

DECLARE_OPTIONS(opt,
    parallel<true>,
    synchronised<false>,
    program<coordination::main>,
    round_schedule<round_s>,
    dimension<dim>,
    exports<vec<dim>, double>,
    log_schedule<sequence::periodic_n<1, 0, 1>>,
    tuple_store<
        my_distance,        double,
        source_diameter,    double,
        diameter,           double,
        distance_c,         color,
        source_diameter_c,  color,
        diameter_c,         color,
        node_shape,         shape,
        size,               double
    >,
    spawn_schedule<sequence::multiple_n<devices, 0>>,
    init<x, rectangle_d>,
    connector<connect::fixed<comm, 1, dim>>,
    shape_tag<node_shape>,
    size_tag<size>,
    color_tag<distance_c,source_diameter_c,diameter_c>
);

int main() {
    component::interactive_simulator<opt>::net network{common::make_tagged_tuple<name,epsilon,texture>("Spreading-Collection Composition", 0.1, "fcpp.png")};
    network.run();
    return 0;
}
