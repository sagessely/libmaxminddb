#include <netdb.h>
#include "MMDB_test_helper.h"

void run_tests()
{
    const char *file = "MaxMind-DB-test-ipv4-24.mmdb";
    const char *path = test_database_path(file);
    MMDB_s *mmdb = open_ok(path, MMDB_MODE_STANDARD, "standard mode");

    // All of the remaining tests require an open mmdb
    if (NULL == mmdb) {
        diag("could not open %s - skipping remaining tests", path);
        return;
    }

    ok(37 == mmdb->metadata.node_count, "node_count is 37");
    ok(24 == mmdb->metadata.record_size, "record_size is 24");
    ok(4 == mmdb->metadata.ip_version, "ip_version is 4");
    ok(2 == mmdb->metadata.binary_format_major_version, "binary_format_major_version is 2");
    ok(0 == mmdb->metadata.binary_format_minor_version, "binary_format_minor_version is 0");
    ok(6 == mmdb->full_record_byte_size, "full_record_byte_size is 6");

    MMDB_close(mmdb);
}

int main(void)
{
    plan(NO_PLAN);
    run_tests();
    done_testing();
}
