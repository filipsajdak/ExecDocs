#pragma once

#include <tao/pegtl.hpp>
#include "ExecDocs.hpp"

namespace pegtl = tao::pegtl;

namespace
{
    using h1_prefix = pegtl::string<'#', ' '>;

    using name = pegtl::plus<pegtl::print>;

    using h1 = pegtl::seq<h1_prefix, name, pegtl::eolf>;

    using grammar = pegtl::plus<
                         pegtl::if_must<h1,
                                        pegtl::until<pegtl::sor<h1, pegtl::eolf>,
                                                     pegtl::any>>>;

    template <typename Rule>
    struct action{};

    template <>
    struct action<name>
    {
        template <typename ParseInput>
        static void apply(const ParseInput &in, execdocs::result &result)
        {
            result.h1.push_back(in.string_view());
        }
    };

} // namespace

namespace execdocs
{

    result parse(std::string_view content)
    {
        result r;

        pegtl::memory_input in(content, "");
        pegtl::parse<grammar, action>(in, r);

        return r;
    }

} // namespace execdocs