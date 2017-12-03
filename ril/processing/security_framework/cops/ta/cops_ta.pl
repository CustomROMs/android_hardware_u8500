#!/usr/bin/perl
use File::Copy;

printf("/******************************************************************\n");
printf(" * Copyright ST-Ericsson 2011\n");
printf(" *\n");
printf(" * Autogenerated file\n");
printf(" *\n");
printf(" * DO NOT EDIT THIS FILE!\n");
printf(" *****************************************************************/\n");
printf("#include \"cops_ta.h\"\n");

$file_count=0;
$count=0;

mkdir($ARGV[2]);

@oldfiles = <$ARGV[2]\\*.ssw>;

foreach $file (@oldfiles) {
    unlink($file);
}

@files = <$ARGV[0]ta\\*cops_ta_$ARGV[1]*.ssw>;

foreach $file (@files) {
    copy($file, $ARGV[2]) or die "File cannot be copied.";
    $file_count++;
}

printf("const uint8_t number_of_tas = %u;\n", $file_count);

foreach $file (@files) {
    printf("const uint8_t data%u[] = {\n", $count);
    $count++;
    $hex_dump="sde_perl " . $ARGV[0] . "tools\\hexdump.pl " . $file;
    open(HEX_DUMP, "$hex_dump |") or die "Can't run '$hex_dump'\n$!\n";
    while(<HEX_DUMP>) {
        print $_;
    }
    close HEX_DUMP;
    printf("};\n");
}

$count=0;
printf("const uint8_t *cops_ta_list[] = {\n");
foreach $file (@files) {
    printf("    data%u,\n", $count);
    $count++;
}
printf("};\n");

$count=0;
printf("const uint32_t cops_ta_size_list[] = {\n");
foreach $file (@files) {
    $file_size = -s $file;
    printf("    %u,\n", $file_size);
    $count++;
}
printf("};\n");
