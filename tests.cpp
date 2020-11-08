#include <gmock/gmock.h>
#include "ExecDocs.hpp"

using namespace ::testing;

TEST(ExecDocsTests, reading_header1)
{
    const char content[] = "# This is it";
    auto result = execdocs::parse(content);
    ASSERT_THAT(result.h1, ElementsAre("This is it"));
}

TEST(ExecDocsTests, reading_two_headers)
{
    const char content[] = "# This is it\n\n# That was it";
    auto result = execdocs::parse(content);
    ASSERT_THAT(result.h1, ElementsAre("This is it", "That was it"));
}