#pragma once

#include <string_view>
#include <vector>

namespace execdocs {

struct result {
    std::vector<std::string_view> h1{};
};

result parse(std::string_view content);

};