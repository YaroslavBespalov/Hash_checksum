This project realizes utility that can calculate hash checksum by two algorithms: crc32, sum32.

Build instructions:
```
# clone repo and download googletests
git clone https://gitlab.com/Bespalovhw1/csc_blank_task.git
cd csc_blank_task
git submodule update --init --recursive

# make build directory
mkdir build
cd build

# generate projects
cmake ..

# build
make

# run unittests
./hashlib_unittest

# run program
./hasher <algo> <path/to/file>


admissible <algo> : crc32 , sum32
```

