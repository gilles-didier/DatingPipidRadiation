# DatingPipidRadiation

Data accompanying the manuscript:

**Dating the early pipid evolutionary radiation in western Gondwana**  
 by Alfred Lemierre, Gilles Didier, and Michel Laurin

Directory `data` contains
- the stratigraphic datasets with (`Pipoid_occurences_old_11_25.csv`) and without (` Pipoid_occurences_young.csv`) the oldest occurrences of *Pachycentrata*;
- the two sets of most parsimonious trees: constrained (`Topology_constrainnostromeri_fixed.tre`) and unconstrained (`Topology_unconstrainnostromeri_fixed.tre`);
- the two consensus trees used to displaying the results (`Topologyconsensus_constrainnostromeri_fixed.tre` and `Topologyconsensus_unconstrainnostromeri_fixed.tre`)


Directory `src` contains the source files of the software. It requires the [cairo](https://www.cairographics.org/) and [GSL](https://www.gnu.org/software/gsl/) libraries. In order to build the software, just type
```
make all
```
in the src directory.

Directory `clades` contains the files of the clades considered in the study.

File `script.sh` contains the commands used to produce the figures. It needs to be edited to fit your file organization.

