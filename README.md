# Overview
Quickly rename all the headers of a FASTA/FASTQ files with sequential numbers i.e. >1, >2, >3... Useful for simplification of file headers for input into programs.

## Manual
```
Input requires both arguments:
  -i    input file
  -ft   file type (fasta|fastq)
  ```
The output is a file named "renamed_output.fast(a|q)" in the same directory as the binary.
## Notes
- For FASTQ files, the software won't work if the sequences are shorter than 59bp or if the sequence names are longer than 59 characters. This is because the symbol "@" may be encountered both as the first FASTQ quality symbol or as a starting symbol of the FASTQ header. So the program distinguishes these two types of lines by their length only. You can manually edit this quantity and rebuild the binary with g++ if required. It could be useful to linearise your FASTQ file such that each sequence line is longer than 59 before using the rename binary.
