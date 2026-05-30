# DatingPipidRadiation

Data accompanying the manuscript:

**Dating the early pipid evolutionary radiation in western Gondwana**  
Alfred Lemierre, Gilles Didier, and Michel Laurin

## Contents

### `data`

The directory `data` contains:

- the stratigraphic occurrence datasets:
  - with the oldest occurrences of *Pachycentrata*: `Pipoid_occurences_old_11_25.csv`;
  - without the oldest occurrences of *Pachycentrata*: `Pipoid_occurences_young.csv`;
- the two sets of most parsimonious trees:
  - constrained topology: `Topology_constrainnostromeri_fixed.tre`;
  - unconstrained topology: `Topology_unconstrainnostromeri_fixed.tre`;
- the two consensus trees used to display the results:
  - constrained consensus topology: `Topologyconsensus_constrainnostromeri_fixed.tre`;
  - unconstrained consensus topology: `Topologyconsensus_unconstrainnostromeri_fixed.tre`.

### `src`

The directory `src` contains the source files of the software.

The software requires the following libraries:

- [cairo](https://www.cairographics.org/)
- [GSL](https://www.gnu.org/software/gsl/)

To build the software, run:

```sh
make all
```

from the `src` directory.

### `clades`

The directory `clades` contains the files describing the clades considered in the study.

### `script.sh`

The file `script.sh` contains the commands used to produce the figures.

It must be edited to match your local file organization.
