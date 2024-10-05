# json-to-cpp
Intended to create cpp header files from json

**Bin**
Where the headers get put;
Packet_* defines packets
Group_* defines group-specific packets
Device_* defines packets that go to the given device; it's intended to import packets from here

**Common**
Copied straight to bin on each build. I put a common.h file in here, idk what else to put here

**env**
has a python env to build

**src**
-common.py-contains imports, utility function
-compile.py-where the header creation is done
-fields.py-where fields are managed
-read_json.py-reads json

./main.sh-run and create headers
