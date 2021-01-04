# VLSI-Testing-and-Testability
Detection of Multiple Stuck-at Faults Using Test Pattern of Single Stuck-at Faults

## Abstract
There are exponentially more multiple faults than
single faults in any given circuit design. Only a
few additional test patterns are needed to cover all the
multiple faults, if the test generation starts from the
complete test set for single faults. In this project, we first
show the case where test patterns for single faults are
sufficient to cover all multiple faults, and then explain
in which conditions some of the multiple faults may
be overlooked. The method we are using can efficiently
generate the complete test set for double faults without
traversing all the faults. Since most of the double faults
can be detected by the single faults’ test set, this method
only selects the uncovered double faults by analyzing the
propagation paths of single faults and then generating
new test patterns only for those uncovered faults.

## Steps to execute VLSI-TT project

1. Generate the fault list of any benchmark circuit with the help of ATPG tool “Atalanta”. Example: For c432 benchmark circuit, command which generate the fault list is given by:
‘atalanta-M –t c432.pat –W 1 –F c432.flt c432.bench’
- This will generate ‘c432.flt’ file.
2. Now generate test patterns along with fault masking format of given benchmark circuit by using “Atalanta” tool.
Example: For c432 benchmark circuit, command which generate test patterns is given by:
‘atalanta-M –D 1 –t c432.pat –W 4 c432.bench’
  - This will generate ‘c432.pat’ file.
3. ‘c432.pat’ file act as an input to a program file ‘main.cpp’ written in C++. This program will generate three fault lists which are: Potentially Undetected Fault List, Undetected Fault List & Detected Fault List.
  - Potentially Undetected Fault List contains the DSA faults which may or may not be detected by the test patterns of SSA faults.
  - Undetected Fault List contains the DSA faults which will never get detected by the test patterns of SSA faults.
  - Detected Fault List contains the DSA faults which will be detected by the test patterns of SSA faults.
4. These fault lists are our results for the implemented algorithm. Our results for different combinational & sequential benchmark circuits are shown in excel sheet named ‘Analysis.xls’.
