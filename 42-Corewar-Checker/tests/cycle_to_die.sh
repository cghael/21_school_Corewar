./test.sh -c 1535,1536 "02 90 00 00 00 31 02 04 54 03 02 03 06 64 03 00 00 08 00 04 09 FF F3 04 54 03 03 03 10 40 03 10 40 03 03 70 01" "02 D0 00 64 10 01 00 00 00 00 09 FF FB"
./test.sh -c 1531,1532,1537 "02 90 00 00 00 31 02 04 54 03 02 03 06 64 03 00 00 08 00 04 09 FF F3 04 54 03 03 03 03 70 01 00 00 03 70 01 00 00" "02 D0 00 64 10 01 00 00 00 00 09 FF FB"
./test.sh -c 1521,1522,1541 "02 90 00 00 00 31 02 04 54 03 02 03 06 64 03 00 00 08 00 04 09 FF F3 03 70 02 00 00 10 40 02 10 40 02 01 FF FF FF FF 03 70 01" "02 D0 00 64 10 01 00 00 00 00 09 FF FB"
./test.sh -c 1526,1527,1542 "02 90 00 00 00 31 02 04 54 03 02 03 06 64 03 00 00 08 00 04 09 FF F3 03 70 02 00 00 03 70 02 00 00 01 FF FF FF FF 03 70 01" "02 D0 00 64 10 01 00 00 00 00 09 FF FB"
./test.sh -c 3023,3024 "02 90 00 00 00 01 02 01 FF FF FF FF 0E 54 0F 0F 10 0E 54 0F 0F 10 04 54 03 02 03 06 64 03 00 00 00 08 10 09 FF E4 02 90 00 00 00 0D 03 04 54 03 02 03 06 64 03 00 00 00 40 04 09 FF F3 03 70 01 00 00 03 70 01" "01 FF FF FF FE 0E 54 0F 0F 10 0E 64 0F 00 64 10 09 FF F0"
./test.sh -c 3018,3019,3024 "02 90 00 00 00 01 02 01 FF FF FF FF 0E 54 0F 0F 10 0E 54 0F 0F 10 04 54 03 02 03 06 64 03 00 00 00 08 10 09 FF E4 02 90 00 00 00 0D 03 04 54 03 02 03 06 64 03 00 00 00 40 04 09 FF F3 03 70 01 00 00 03 70 01" "01 FF FF FF FE 01 FF FF FF FE 0E 54 0F 0F 10 0E 64 0F 00 64 10 09 FF F0"
./test.sh -c 16844,16845,16850 "02 90 00 00 00 01 02 02 90 00 00 00 33 03 01 FF FF FF FF 0E 54 01 01 10 0E 54 01 01 10 0E 54 01 01 10 04 54 03 02 03 06 64 03 00 00 00 80 10 09 FF DF 02 90 00 00 00 10 03 04 54 03 02 03 06 64 03 00 00 00 40 10 09 FF F3 03 70 01 00 00 03 70 01 00 00 03 70 01" "01 FF FF FF FE 01 FF FF FF FE 0E 54 0F 0F 10 0E 64 0F 00 64 10 09 FF F0"
./test.sh "00 00 02 D0 00 40 10 01 FF FF FF FF 09 FF FB" "00 00 00 02 D0 00 40 10 01 FF FF FF FE 09 FF FB" "00 00 00 00 02 D0 00 40 10 01 FF FF FF FD 09 FF FB" "00 00 00 00 00 02 D0 00 40 10 01 FF FF FF FC 09 FF FB"