# playfair_cypher

1. Download the file
2. Extract it
3. Open the Terminal
4. cd to the directory
5. Run the following commands:
---
    mkdir build
    cd build
    cmake ..
    cmake --build .
---

If you want to encode the files, run:

---
    ./playfair encode <keyfile> <results_dir> <file1> ... <filen>
---

If you want to decode the files, run:

---
    ./playfair decode <keyfile> <results_dir> <file1> ... <filen>
---
