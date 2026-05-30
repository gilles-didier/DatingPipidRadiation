#Working directories - to be changed in order to fit your file organization
exec_dir="/home/gilles/Dropbox/AlfredDev/src"
data_dir="/home/gilles/Dropbox/AlfredDev/data"
clad_dir="/home/gilles/Dropbox/AlfredDev/clades"
resu_dir="/home/gilles/Dropbox/AlfredDev/results"

#Parameters used in the study
origin_time=-250
main_it=2000
main_it_ext=7500
burn_it=10000
gap_it=300
gap_it_ext=200
rand_seed=5555
proc_nb=40

#Calcul des distributions

#Distribution de temps de divergence arbre non contraints et ages récents
"$exec_dir/dspe" -o $origin_time -s $main_it -u 0.1 -b $burn_it -g $gap_it -r $rand_seed -t $proc_nb "$clad_dir/Topologies_unconstrain_nostromeri_fixed.tre_0.txt" "$data_dir/Topologies_unconstrain_nostromeri_fixed.tre" "$data_dir/Pipoid_occurences_young.csv" "$resu_dir/Pipid_unconstraint_young_0" &

"$exec_dir/dspe" -o $origin_time -s $main_it -u 0.1 -b $burn_it -g $gap_it -r $rand_seed -t $proc_nb "$clad_dir/Topologies_unconstrain_nostromeri_fixed.tre_1.txt" "$data_dir/Topologies_unconstrain_nostromeri_fixed.tre" "$data_dir/Pipoid_occurences_young.csv" "$resu_dir/Pipid_unconstraint_young_1" &

"$exec_dir/dspe" -o $origin_time -s $main_it -u 0.1 -b $burn_it -g $gap_it -r $rand_seed -t $proc_nb "$clad_dir/Topologies_unconstrain_nostromeri_fixed.tre_2.txt" "$data_dir/Topologies_unconstrain_nostromeri_fixed.tre" "$data_dir/Pipoid_occurences_young.csv" "$resu_dir/Pipid_unconstraint_young_2" &

"$exec_dir/dspe" -o $origin_time -s $main_it -u 0.1 -b $burn_it -g $gap_it -r $rand_seed -t $proc_nb "$clad_dir/Topologies_unconstrain_nostromeri_fixed.tre_4.txt" "$data_dir/Topologies_unconstrain_nostromeri_fixed.tre" "$data_dir/Pipoid_occurences_young.csv" "$resu_dir/Pipid_unconstraint_young_4" &

"$exec_dir/dspe" -o $origin_time -s $main_it -u 0.1 -b $burn_it -g $gap_it -r $rand_seed -t $proc_nb "$clad_dir/Topologies_unconstrain_nostromeri_fixed.tre_5.txt" "$data_dir/Topologies_unconstrain_nostromeri_fixed.tre" "$data_dir/Pipoid_occurences_young.csv" "$resu_dir/Pipid_unconstraint_young_5" &

"$exec_dir/dspe" -o $origin_time -s $main_it -u 0.1 -b $burn_it -g $gap_it -r $rand_seed -t $proc_nb "$clad_dir/Topologies_unconstrain_nostromeri_fixed.tre_6.txt" "$data_dir/Topologies_unconstrain_nostromeri_fixed.tre" "$data_dir/Pipoid_occurences_young.csv" "$resu_dir/Pipid_unconstraint_young_6" &

"$exec_dir/dspe" -o $origin_time -s $main_it -u 0.1 -b $burn_it -g $gap_it -r $rand_seed -t $proc_nb "$clad_dir/Topologies_unconstrain_nostromeri_fixed.tre_7.txt" "$data_dir/Topologies_unconstrain_nostromeri_fixed.tre" "$data_dir/Pipoid_occurences_young.csv" "$resu_dir/Pipid_unconstraint_young_7" &

"$exec_dir/dspe" -o $origin_time -s $main_it -u 0.1 -b $burn_it -g $gap_it -r $rand_seed -t $proc_nb "$clad_dir/Topologies_unconstrain_nostromeri_fixed.tre_8.txt" "$data_dir/Topologies_unconstrain_nostromeri_fixed.tre" "$data_dir/Pipoid_occurences_young.csv" "$resu_dir/Pipid_unconstraint_young_8" &

"$exec_dir/dspe" -o $origin_time -s $main_it -u 0.1 -b $burn_it -g $gap_it -r $rand_seed -t $proc_nb "$clad_dir/Topologies_unconstrain_nostromeri_fixed.tre_9.txt" "$data_dir/Topologies_unconstrain_nostromeri_fixed.tre" "$data_dir/Pipoid_occurences_young.csv" "$resu_dir/Pipid_unconstraint_young_9" &

"$exec_dir/dspe" -o $origin_time -s $main_it -u 0.1 -b $burn_it -g $gap_it -r $rand_seed -t $proc_nb "$clad_dir/Topologies_unconstrain_nostromeri_fixed.tre_10.txt" "$data_dir/Topologies_unconstrain_nostromeri_fixed.tre" "$data_dir/Pipoid_occurences_young.csv" "$resu_dir/Pipid_unconstraint_young_10" &

"$exec_dir/dspe" -o $origin_time -s $main_it -u 0.1 -b $burn_it -g $gap_it -r $rand_seed -t $proc_nb "$clad_dir/Topologies_unconstrain_nostromeri_fixed.tre_12.txt" "$data_dir/Topologies_unconstrain_nostromeri_fixed.tre" "$data_dir/Pipoid_occurences_young.csv" "$resu_dir/Pipid_unconstraint_young_12" &

"$exec_dir/dspe" -o $origin_time -s $main_it -u 0.1 -b $burn_it -g $gap_it -r $rand_seed -t $proc_nb "$clad_dir/Topologies_unconstrain_nostromeri_fixed.tre_13.txt" "$data_dir/Topologies_unconstrain_nostromeri_fixed.tre" "$data_dir/Pipoid_occurences_young.csv" "$resu_dir/Pipid_unconstraint_young_13" &

"$exec_dir/dspe" -o $origin_time -s $main_it -u 0.1 -b $burn_it -g $gap_it -r $rand_seed -t $proc_nb "$clad_dir/Topologies_unconstrain_nostromeri_fixed.tre_14.txt" "$data_dir/Topologies_unconstrain_nostromeri_fixed.tre" "$data_dir/Pipoid_occurences_young.csv" "$resu_dir/Pipid_unconstraint_young_14" &

"$exec_dir/dspe" -o $origin_time -s $main_it -u 0.1 -b $burn_it -g $gap_it -r $rand_seed -t $proc_nb "$clad_dir/Topologies_unconstrain_nostromeri_fixed.tre_18.txt" "$data_dir/Topologies_unconstrain_nostromeri_fixed.tre" "$data_dir/Pipoid_occurences_young.csv" "$resu_dir/Pipid_unconstraint_young_18" &

"$exec_dir/dspe" -o $origin_time -s $main_it -u 0.1 -b $burn_it -g $gap_it -r $rand_seed -t $proc_nb "$clad_dir/Topologies_unconstrain_nostromeri_fixed.tre_23.txt" "$data_dir/Topologies_unconstrain_nostromeri_fixed.tre" "$data_dir/Pipoid_occurences_young.csv" "$resu_dir/Pipid_unconstraint_young_23" &

"$exec_dir/dspe" -o $origin_time -s $main_it -u 0.1 -b $burn_it -g $gap_it -r $rand_seed -t $proc_nb "$clad_dir/Topologies_unconstrain_nostromeri_fixed.tre_25.txt" "$data_dir/Topologies_unconstrain_nostromeri_fixed.tre" "$data_dir/Pipoid_occurences_young.csv" "$resu_dir/Pipid_unconstraint_young_25" &

"$exec_dir/dspe" -o $origin_time -s $main_it -u 0.1 -b $burn_it -g $gap_it -r $rand_seed -t $proc_nb "$clad_dir/Topologies_unconstrain_nostromeri_fixed.tre_31.txt" "$data_dir/Topologies_unconstrain_nostromeri_fixed.tre" "$data_dir/Pipoid_occurences_young.csv" "$resu_dir/Pipid_unconstraint_young_31" &

"$exec_dir/dspe" -o $origin_time -s $main_it -u 0.1 -b $burn_it -g $gap_it -r $rand_seed -t $proc_nb "$clad_dir/Topologies_unconstrain_nostromeri_fixed.tre_32.txt" "$data_dir/Topologies_unconstrain_nostromeri_fixed.tre" "$data_dir/Pipoid_occurences_young.csv" "$resu_dir/Pipid_unconstraint_young_32" &

"$exec_dir/dspe" -o $origin_time -s $main_it -u 0.1 -b $burn_it -g $gap_it -r $rand_seed -t $proc_nb "$clad_dir/Topologies_unconstrain_nostromeri_fixed.tre_35.txt" "$data_dir/Topologies_unconstrain_nostromeri_fixed.tre" "$data_dir/Pipoid_occurences_young.csv" "$resu_dir/Pipid_unconstraint_young_35" &

"$exec_dir/dspe" -o $origin_time -s $main_it -u 0.1 -b $burn_it -g $gap_it -r $rand_seed -t $proc_nb "$clad_dir/Topologies_unconstrain_nostromeri_fixed.tre_39.txt" "$data_dir/Topologies_unconstrain_nostromeri_fixed.tre" "$data_dir/Pipoid_occurences_young.csv" "$resu_dir/Pipid_unconstraint_young_39" &

"$exec_dir/drsp" -a "$clad_dir/map_unconstraint.txt" -y 20 -x 6 -c "$resu_dir/Topologies_unconstrain_nostromeri_fixed.tre_" .txt -d "$resu_dir/Pipid_unconstraint_young_" .csv "$data_dir/Topologyconsensus_unconstrainnostromeri_fixed.tre" "$data_dir/Pipoid_occurences_young.csv"

#Distribution de temps de divergence arbres contraints et ages récents
"$exec_dir/dspe" -o $origin_time -s $main_it -u 0.1 -b $burn_it -g $gap_it -r $rand_seed -t $proc_nb "$clad_dir/Topologies_constrain_nostromeri_fixed.tre_0.txt" "$data_dir/Topologies_constrain_nostromeri_fixed.tre" "$data_dir/Pipoid_occurences_young.csv" "$resu_dir/Pipid_constraint_young_0" &

"$exec_dir/dspe" -o $origin_time -s $main_it -u 0.1 -b $burn_it -g $gap_it -r $rand_seed -t $proc_nb "$clad_dir/Topologies_constrain_nostromeri_fixed.tre_2.txt" "$data_dir/Topologies_constrain_nostromeri_fixed.tre" "$data_dir/Pipoid_occurences_young.csv" "$resu_dir/Pipid_constraint_young_2" &

"$exec_dir/dspe" -o $origin_time -s $main_it -u 0.1 -b $burn_it -g $gap_it -r $rand_seed -t $proc_nb "$clad_dir/Topologies_constrain_nostromeri_fixed.tre_5.txt" "$data_dir/Topologies_constrain_nostromeri_fixed.tre" "$data_dir/Pipoid_occurences_young.csv" "$resu_dir/Pipid_constraint_young_5" &

"$exec_dir/dspe" -o $origin_time -s $main_it -u 0.1 -b $burn_it -g $gap_it -r $rand_seed -t $proc_nb "$clad_dir/Topologies_constrain_nostromeri_fixed.tre_7.txt" "$data_dir/Topologies_constrain_nostromeri_fixed.tre" "$data_dir/Pipoid_occurences_young.csv" "$resu_dir/Pipid_constraint_young_7" &

"$exec_dir/dspe" -o $origin_time -s $main_it -u 0.1 -b $burn_it -g $gap_it -r $rand_seed -t $proc_nb "$clad_dir/Topologies_constrain_nostromeri_fixed.tre_9.txt" "$data_dir/Topologies_constrain_nostromeri_fixed.tre" "$data_dir/Pipoid_occurences_young.csv" "$resu_dir/Pipid_constraint_young_9" &

"$exec_dir/dspe" -o $origin_time -s $main_it -u 0.1 -b $burn_it -g $gap_it -r $rand_seed -t $proc_nb "$clad_dir/Topologies_constrain_nostromeri_fixed.tre_10.txt" "$data_dir/Topologies_constrain_nostromeri_fixed.tre" "$data_dir/Pipoid_occurences_young.csv" "$resu_dir/Pipid_constraint_young_10" &

"$exec_dir/dspe" -o $origin_time -s $main_it -u 0.1 -b $burn_it -g $gap_it -r $rand_seed -t $proc_nb "$clad_dir/Topologies_constrain_nostromeri_fixed.tre_11.txt" "$data_dir/Topologies_constrain_nostromeri_fixed.tre" "$data_dir/Pipoid_occurences_young.csv" "$resu_dir/Pipid_constraint_young_11" &

"$exec_dir/dspe" -o $origin_time -s $main_it -u 0.1 -b $burn_it -g $gap_it -r $rand_seed -t $proc_nb "$clad_dir/Topologies_constrain_nostromeri_fixed.tre_17.txt" "$data_dir/Topologies_constrain_nostromeri_fixed.tre" "$data_dir/Pipoid_occurences_young.csv" "$resu_dir/Pipid_constraint_young_17" &

"$exec_dir/dspe" -o $origin_time -s $main_it -u 0.1 -b $burn_it -g $gap_it -r $rand_seed -t $proc_nb "$clad_dir/Topologies_constrain_nostromeri_fixed.tre_19.txt" "$data_dir/Topologies_constrain_nostromeri_fixed.tre" "$data_dir/Pipoid_occurences_young.csv" "$resu_dir/Pipid_constraint_young_19" &

"$exec_dir/dspe" -o $origin_time -s $main_it -u 0.1 -b $burn_it -g $gap_it -r $rand_seed -t $proc_nb "$clad_dir/Topologies_constrain_nostromeri_fixed.tre_24.txt" "$data_dir/Topologies_constrain_nostromeri_fixed.tre" "$data_dir/Pipoid_occurences_young.csv" "$resu_dir/Pipid_constraint_young_24" &


"$exec_dir/dspe" -o $origin_time -s $main_it -u 0.1 -b $burn_it -g $gap_it -r $rand_seed -t $proc_nb "$clad_dir/Topologies_constrain_nostromeri_fixed.tre_25.txt" "$data_dir/Topologies_constrain_nostromeri_fixed.tre" "$data_dir/Pipoid_occurences_young.csv" "$resu_dir/Pipid_constraint_young_25" &

"$exec_dir/dspe" -o $origin_time -s $main_it -u 0.1 -b $burn_it -g $gap_it -r $rand_seed -t $proc_nb "$clad_dir/Topologies_constrain_nostromeri_fixed.tre_28.txt" "$data_dir/Topologies_constrain_nostromeri_fixed.tre" "$data_dir/Pipoid_occurences_young.csv" "$resu_dir/Pipid_constraint_young_28" &

"$exec_dir/dspe" -o $origin_time -s $main_it -u 0.1 -b $burn_it -g $gap_it -r $rand_seed -t $proc_nb "$clad_dir/Topologies_constrain_nostromeri_fixed.tre_35.txt" "$data_dir/Topologies_constrain_nostromeri_fixed.tre" "$data_dir/Pipoid_occurences_young.csv" "$resu_dir/Pipid_constraint_young_35" &

#additional nodes
dspe -o $origin_time -s $main_it -u 0.1 -b $burn_it -g $gap_it -r $rand_seed -t $proc_nb "$clad_dir/Topologies_constrain_nostromeri_fixed.tre_35.txt" "$data_dir/Topologies_constrain_nostromeri_fixed.tre" "$data_dir/Pipoid_occurences_young.csv" "$resu_dir/Pipid_constraint_young_35" &

"$exec_dir/dspb" -o $origin_time -s $main_it -u 0.1 -b $burn_it -g $gap_it -r $rand_seed -t $proc_nb "$clad_dir/Topologies_constrain_nostromeri_fixed.tre_T.txt" "$data_dir/Topologies_constrain_nostromeri_fixed.tre" "$data_dir/Pipoid_occurences_young.csv" "$resu_dir/Pipid_constraint_young_T" &

"$exec_dir/dspb" -o $origin_time -s $main_it -u 0.1 -b $burn_it -g $gap_it -r $rand_seed -t $proc_nb "$clad_dir/Topologies_constrain_nostromeri_fixed.tre_X.txt" "$data_dir/Topologies_constrain_nostromeri_fixed.tre" "$data_dir/Pipoid_occurences_young.csv" "$resu_dir/Pipid_constraint_young_X" &

"$exec_dir/dspb" -o $origin_time -s $main_it -u 0.1 -b $burn_it -g $gap_it -r $rand_seed -t $proc_nb "$clad_dir/Topologies_constrain_nostromeri_fixed.tre_Y.txt" "$data_dir/Topologies_constrain_nostromeri_fixed.tre" "$data_dir/Pipoid_occurences_young.csv" "$resu_dir/Pipid_constraint_young_Y" &

"$exec_dir/dspb" -o $origin_time -s $main_it -u 0.1 -b $burn_it -g $gap_it -r $rand_seed -t $proc_nb "$clad_dir/Topologies_constrain_nostromeri_fixed.tre_Z.txt" "$data_dir/Topologies_constrain_nostromeri_fixed.tre" "$data_dir/Pipoid_occurences_young.csv" "$resu_dir/Pipid_constraint_young_Z" &

"$exec_dir/drsp" -a "$clad_dir/map_constraint.txt" -y 20 -x 6 -c "$resu_dir/Topologies_constrain_nostromeri_fixed.tre_" .txt -d "$resu_dir/Pipid_constraint_young_" .csv "$data_dir/Topologyconsensus_constrainnostromeri_fixed.tre" "$data_dir/Pipoid_occurences_young.csv"

#Distribution de temps de divergence arbre non contraints et ages anciens
"$exec_dir/dspe" -o $origin_time -s $main_it -u 0.1 -b $burn_it -g $gap_it -r $rand_seed -t $proc_nb "$clad_dir/Topologies_unconstrain_nostromeri_fixed.tre_0.txt" "$data_dir/Topologies_unconstrain_nostromeri_fixed.tre" "$data_dir/Pipoid_occurences_old_11_25.csv" "$resu_dir/Pipid_unconstraint_old_0" &

"$exec_dir/dspe" -o $origin_time -s $main_it -u 0.1 -b $burn_it -g $gap_it -r $rand_seed -t $proc_nb "$clad_dir/Topologies_unconstrain_nostromeri_fixed.tre_1.txt" "$data_dir/Topologies_unconstrain_nostromeri_fixed.tre" "$data_dir/Pipoid_occurences_old_11_25.csv" "$resu_dir/Pipid_unconstraint_old_1" &

"$exec_dir/dspe" -o $origin_time -s $main_it -u 0.1 -b $burn_it -g $gap_it -r $rand_seed -t $proc_nb "$clad_dir/Topologies_unconstrain_nostromeri_fixed.tre_2.txt" "$data_dir/Topologies_unconstrain_nostromeri_fixed.tre" "$data_dir/Pipoid_occurences_old_11_25.csv" "$resu_dir/Pipid_unconstraint_old_2" &

"$exec_dir/dspe" -o $origin_time -s $main_it -u 0.1 -b $burn_it -g $gap_it -r $rand_seed -t $proc_nb "$clad_dir/Topologies_unconstrain_nostromeri_fixed.tre_4.txt" "$data_dir/Topologies_unconstrain_nostromeri_fixed.tre" "$data_dir/Pipoid_occurences_old_11_25.csv" "$resu_dir/Pipid_unconstraint_old_4" &

"$exec_dir/dspe" -o $origin_time -s $main_it -u 0.1 -b $burn_it -g $gap_it -r $rand_seed -t $proc_nb "$clad_dir/Topologies_unconstrain_nostromeri_fixed.tre_5.txt" "$data_dir/Topologies_unconstrain_nostromeri_fixed.tre" "$data_dir/Pipoid_occurences_old_11_25.csv" "$resu_dir/Pipid_unconstraint_old_5" &

"$exec_dir/dspe" -o $origin_time -s $main_it -u 0.1 -b $burn_it -g $gap_it -r $rand_seed -t $proc_nb "$clad_dir/Topologies_unconstrain_nostromeri_fixed.tre_6.txt" "$data_dir/Topologies_unconstrain_nostromeri_fixed.tre" "$data_dir/Pipoid_occurences_old_11_25.csv" "$resu_dir/Pipid_unconstraint_old_6" &

"$exec_dir/dspe" -o $origin_time -s $main_it -u 0.1 -b $burn_it -g $gap_it -r $rand_seed -t $proc_nb "$clad_dir/Topologies_unconstrain_nostromeri_fixed.tre_7.txt" "$data_dir/Topologies_unconstrain_nostromeri_fixed.tre" "$data_dir/Pipoid_occurences_old_11_25.csv" "$resu_dir/Pipid_unconstraint_old_7" &

"$exec_dir/dspe" -o $origin_time -s $main_it -u 0.1 -b $burn_it -g $gap_it -r $rand_seed -t $proc_nb "$clad_dir/Topologies_unconstrain_nostromeri_fixed.tre_8.txt" "$data_dir/Topologies_unconstrain_nostromeri_fixed.tre" "$data_dir/Pipoid_occurences_old_11_25.csv" "$resu_dir/Pipid_unconstraint_old_8" &

"$exec_dir/dspe" -o $origin_time -s $main_it -u 0.1 -b $burn_it -g $gap_it -r $rand_seed -t $proc_nb "$clad_dir/Topologies_unconstrain_nostromeri_fixed.tre_9.txt" "$data_dir/Topologies_unconstrain_nostromeri_fixed.tre" "$data_dir/Pipoid_occurences_old_11_25.csv" "$resu_dir/Pipid_unconstraint_old_9" &

"$exec_dir/dspe" -o $origin_time -s $main_it -u 0.1 -b $burn_it -g $gap_it -r $rand_seed -t $proc_nb "$clad_dir/Topologies_unconstrain_nostromeri_fixed.tre_10.txt" "$data_dir/Topologies_unconstrain_nostromeri_fixed.tre" "$data_dir/Pipoid_occurences_old_11_25.csv" "$resu_dir/Pipid_unconstraint_old_10" &

"$exec_dir/dspe" -o $origin_time -s $main_it -u 0.1 -b $burn_it -g $gap_it -r $rand_seed -t $proc_nb "$clad_dir/Topologies_unconstrain_nostromeri_fixed.tre_12.txt" "$data_dir/Topologies_unconstrain_nostromeri_fixed.tre" "$data_dir/Pipoid_occurences_old_11_25.csv" "$resu_dir/Pipid_unconstraint_old_12" &

"$exec_dir/dspe" -o $origin_time -s $main_it -u 0.1 -b $burn_it -g $gap_it -r $rand_seed -t $proc_nb "$clad_dir/Topologies_unconstrain_nostromeri_fixed.tre_13.txt" "$data_dir/Topologies_unconstrain_nostromeri_fixed.tre" "$data_dir/Pipoid_occurences_old_11_25.csv" "$resu_dir/Pipid_unconstraint_old_13" &

"$exec_dir/dspe" -o $origin_time -s $main_it -u 0.1 -b $burn_it -g $gap_it -r $rand_seed -t $proc_nb "$clad_dir/Topologies_unconstrain_nostromeri_fixed.tre_14.txt" "$data_dir/Topologies_unconstrain_nostromeri_fixed.tre" "$data_dir/Pipoid_occurences_old_11_25.csv" "$resu_dir/Pipid_unconstraint_old_14" &

"$exec_dir/dspe" -o $origin_time -s $main_it -u 0.1 -b $burn_it -g $gap_it -r $rand_seed -t $proc_nb "$clad_dir/Topologies_unconstrain_nostromeri_fixed.tre_18.txt" "$data_dir/Topologies_unconstrain_nostromeri_fixed.tre" "$data_dir/Pipoid_occurences_old_11_25.csv" "$resu_dir/Pipid_unconstraint_old_18" &

"$exec_dir/dspe" -o $origin_time -s $main_it -u 0.1 -b $burn_it -g $gap_it -r $rand_seed -t $proc_nb "$clad_dir/Topologies_unconstrain_nostromeri_fixed.tre_23.txt" "$data_dir/Topologies_unconstrain_nostromeri_fixed.tre" "$data_dir/Pipoid_occurences_old_11_25.csv" "$resu_dir/Pipid_unconstraint_old_23" &

"$exec_dir/dspe" -o $origin_time -s $main_it -u 0.1 -b $burn_it -g $gap_it -r $rand_seed -t $proc_nb "$clad_dir/Topologies_unconstrain_nostromeri_fixed.tre_25.txt" "$data_dir/Topologies_unconstrain_nostromeri_fixed.tre" "$data_dir/Pipoid_occurences_old_11_25.csv" "$resu_dir/Pipid_unconstraint_old_25" &

"$exec_dir/dspe" -o $origin_time -s $main_it -u 0.1 -b $burn_it -g $gap_it -r $rand_seed -t $proc_nb "$clad_dir/Topologies_unconstrain_nostromeri_fixed.tre_31.txt" "$data_dir/Topologies_unconstrain_nostromeri_fixed.tre" "$data_dir/Pipoid_occurences_old_11_25.csv" "$resu_dir/Pipid_unconstraint_old_31" &

"$exec_dir/dspe" -o $origin_time -s $main_it -u 0.1 -b $burn_it -g $gap_it -r $rand_seed -t $proc_nb "$clad_dir/Topologies_unconstrain_nostromeri_fixed.tre_32.txt" "$data_dir/Topologies_unconstrain_nostromeri_fixed.tre" "$data_dir/Pipoid_occurences_old_11_25.csv" "$resu_dir/Pipid_unconstraint_old_32" &

"$exec_dir/dspe" -o $origin_time -s $main_it -u 0.1 -b $burn_it -g $gap_it -r $rand_seed -t $proc_nb "$clad_dir/Topologies_unconstrain_nostromeri_fixed.tre_35.txt" "$data_dir/Topologies_unconstrain_nostromeri_fixed.tre" "$data_dir/Pipoid_occurences_old_11_25.csv" "$resu_dir/Pipid_unconstraint_old_35" &

"$exec_dir/dspe" -o $origin_time -s $main_it -u 0.1 -b $burn_it -g $gap_it -r $rand_seed -t $proc_nb "$clad_dir/Topologies_unconstrain_nostromeri_fixed.tre_39.txt" "$data_dir/Topologies_unconstrain_nostromeri_fixed.tre" "$data_dir/Pipoid_occurences_old_11_25.csv" "$resu_dir/Pipid_unconstraint_old_39" &

"$exec_dir/drsp" -a "$clad_dir/map_unconstraint.txt" -y 20 -x 6 -c "$resu_dir/Topologies_unconstrain_nostromeri_fixed.tre_" .txt -d "$resu_dir/Pipid_unconstraint_old_" .csv "$data_dir/Topologyconsensus_unconstrainnostromeri_fixed.tre" "$data_dir/Pipoid_occurences_old_11_25.csv"

"$exec_dir/drsp" -a "$clad_dir/map_unconstraint.txt" -y 20 -x 6 -c "$resu_dir/Topologies_unconstrain_nostromeri_fixed.tre_" .txt -d "$resu_dir/Pipid_unconstraint_young_" .csv "$data_dir/Topologyconsensus_unconstrainnostromeri_fixed.tre" "$data_dir/Pipoid_occurences_young.csv"

#additional nodes uncons old
"$exec_dir/dspb" -o $origin_time -s $main_it -u 0.1 -b $burn_it -g $gap_it -r $rand_seed -t $proc_nb "$clad_dir/Topologies_unconstrain_nostromeri_fixed.tre_U.txt" "$data_dir/Topologies_unconstrain_nostromeri_fixed.tre" "$data_dir/Pipoid_occurences_old_11_25.csv" "$resu_dir/Pipid_unconstraint_old_U" &

"$exec_dir/dspb" -o $origin_time -s $main_it -u 0.1 -b $burn_it -g $gap_it -r $rand_seed -t $proc_nb "$clad_dir/Topologies_unconstrain_nostromeri_fixed.tre_Z.txt" "$data_dir/Topologies_unconstrain_nostromeri_fixed.tre" "$data_dir/Pipoid_occurences_old_11_25.csv" "$resu_dir/Pipid_unconstraint_old_Z" &

"$exec_dir/dspb" -o $origin_time -s $main_it -u 0.1 -b $burn_it -g $gap_it -r $rand_seed -t $proc_nb "$clad_dir/Topologies_unconstrain_nostromeri_fixed.tre_T.txt" "$data_dir/Topologies_unconstrain_nostromeri_fixed.tre" "$data_dir/Pipoid_occurences_old_11_25.csv" "$resu_dir/Pipid_unconstraint_old_T" &

"$exec_dir/dspb" -o $origin_time -s $main_it -u 0.1 -b $burn_it -g $gap_it -r $rand_seed -t $proc_nb "$clad_dir/Topologies_unconstrain_nostromeri_fixed.tre_R.txt" "$data_dir/Topologies_unconstrain_nostromeri_fixed.tre" "$data_dir/Pipoid_occurences_old_11_25.csv" "$resu_dir/Pipid_unconstraint_old_R" &

"$exec_dir/dspb" -o $origin_time -s $main_it -u 0.1 -b $burn_it -g $gap_it -r $rand_seed -t $proc_nb "$clad_dir/Topologies_unconstrain_nostromeri_fixed.tre_G.txt" "$data_dir/Topologies_unconstrain_nostromeri_fixed.tre" "$data_dir/Pipoid_occurences_old_11_25.csv" "$resu_dir/Pipid_unconstraint_old_G" &


#additional nodes uncons young
"$exec_dir/dspb" -o $origin_time -s $main_it -u 0.1 -b $burn_it -g $gap_it -r $rand_seed -t $proc_nb "$clad_dir/Topologies_unconstrain_nostromeri_fixed.tre_T.txt" "$data_dir/Topologies_unconstrain_nostromeri_fixed.tre" "$data_dir/Pipoid_occurences_young.csv" "$resu_dir/Pipid_unconstraint_young_T" &

"$exec_dir/dspb" -o $origin_time -s $main_it -u 0.1 -b $burn_it -g $gap_it -r $rand_seed -t $proc_nb "$clad_dir/Topologies_unconstrain_nostromeri_fixed.tre_X.txt" "$data_dir/Topologies_unconstrain_nostromeri_fixed.tre" "$data_dir/Pipoid_occurences_young.csv" "$resu_dir/Pipid_unconstraint_young_X" &

"$exec_dir/dspb" -o $origin_time -s $main_it -u 0.1 -b $burn_it -g $gap_it -r $rand_seed -t $proc_nb "$clad_dir/Topologies_unconstrain_nostromeri_fixed.tre_Y.txt" "$data_dir/Topologies_unconstrain_nostromeri_fixed.tre" "$data_dir/Pipoid_occurences_young.csv" "$resu_dir/Pipid_unconstraint_young_Y" &

"$exec_dir/dspb" -o $origin_time -s $main_it -u 0.1 -b $burn_it -g $gap_it -r $rand_seed -t $proc_nb "$clad_dir/Topologies_unconstrain_nostromeri_fixed.tre_Z.txt" "$data_dir/Topologies_unconstrain_nostromeri_fixed.tre" "$data_dir/Pipoid_occurences_young.csv" "$resu_dir/Pipid_unconstraint_young_Z" &

"$exec_dir/dspb" -o $origin_time -s $main_it -u 0.1 -b $burn_it -g $gap_it -r $rand_seed -t $proc_nb "$clad_dir/Topologies_unconstrain_nostromeri_fixed.tre_P.txt" "$data_dir/Topologies_unconstrain_nostromeri_fixed.tre" "$data_dir/Pipoid_occurences_young.csv" "$resu_dir/Pipid_unconstraint_young_P" &

"$exec_dir/dspb" -o $origin_time -s $main_it -u 0.1 -b $burn_it -g $gap_it -r $rand_seed -t $proc_nb "$clad_dir/Topologies_unconstrain_nostromeri_fixed.tre_R.txt" "$data_dir/Topologies_unconstrain_nostromeri_fixed.tre" "$data_dir/Pipoid_occurences_young.csv" "$resu_dir/Pipid_unconstraint_young_R" &

"$exec_dir/dspb" -o $origin_time -s $main_it -u 0.1 -b $burn_it -g $gap_it -r $rand_seed -t $proc_nb "$clad_dir/Topologies_unconstrain_nostromeri_fixed.tre_U.txt" "$data_dir/Topologies_unconstrain_nostromeri_fixed.tre" "$data_dir/Pipoid_occurences_young.csv" "$resu_dir/Pipid_unconstraint_young_U" &

#Distribution de temps de divergence arbres contraints et ages anciens
"$exec_dir/dspe" -o $origin_time -s $main_it -u 0.1 -b $burn_it -g $gap_it -r $rand_seed -t $proc_nb "$clad_dir/Topologies_constrain_nostromeri_fixed.tre_0.txt" "$data_dir/Topologies_constrain_nostromeri_fixed.tre" "$data_dir/Pipoid_occurences_old_11_25.csv" "$resu_dir/Pipid_constraint_old_0" &

"$exec_dir/dspe" -o $origin_time -s $main_it -u 0.1 -b $burn_it -g $gap_it -r $rand_seed -t $proc_nb "$clad_dir/Topologies_constrain_nostromeri_fixed.tre_2.txt" "$data_dir/Topologies_constrain_nostromeri_fixed.tre" "$data_dir/Pipoid_occurences_old_11_25.csv" "$resu_dir/Pipid_constraint_old_2" &

"$exec_dir/dspe" -o $origin_time -s $main_it -u 0.1 -b $burn_it -g $gap_it -r $rand_seed -t $proc_nb "$clad_dir/Topologies_constrain_nostromeri_fixed.tre_5.txt" "$data_dir/Topologies_constrain_nostromeri_fixed.tre" "$data_dir/Pipoid_occurences_old_11_25.csv" "$resu_dir/Pipid_constraint_old_5" &

"$exec_dir/dspe" -o $origin_time -s $main_it -u 0.1 -b $burn_it -g $gap_it -r $rand_seed -t $proc_nb "$clad_dir/Topologies_constrain_nostromeri_fixed.tre_7.txt" "$data_dir/Topologies_constrain_nostromeri_fixed.tre" "$data_dir/Pipoid_occurences_old_11_25.csv" "$resu_dir/Pipid_constraint_old_7" &

"$exec_dir/dspe" -o $origin_time -s $main_it -u 0.1 -b $burn_it -g $gap_it -r $rand_seed -t $proc_nb "$clad_dir/Topologies_constrain_nostromeri_fixed.tre_9.txt" "$data_dir/Topologies_constrain_nostromeri_fixed.tre" "$data_dir/Pipoid_occurences_old_11_25.csv" "$resu_dir/Pipid_constraint_old_9" &

"$exec_dir/dspe" -o $origin_time -s $main_it -u 0.1 -b $burn_it -g $gap_it -r $rand_seed -t $proc_nb "$clad_dir/Topologies_constrain_nostromeri_fixed.tre_10.txt" "$data_dir/Topologies_constrain_nostromeri_fixed.tre" "$data_dir/Pipoid_occurences_old_11_25.csv" "$resu_dir/Pipid_constraint_old_10" &

"$exec_dir/dspe" -o $origin_time -s $main_it -u 0.1 -b $burn_it -g $gap_it -r $rand_seed -t $proc_nb "$clad_dir/Topologies_constrain_nostromeri_fixed.tre_11.txt" "$data_dir/Topologies_constrain_nostromeri_fixed.tre" "$data_dir/Pipoid_occurences_old_11_25.csv" "$resu_dir/Pipid_constraint_old_11" &

"$exec_dir/dspe" -o $origin_time -s $main_it -u 0.1 -b $burn_it -g $gap_it -r $rand_seed -t $proc_nb "$clad_dir/Topologies_constrain_nostromeri_fixed.tre_17.txt" "$data_dir/Topologies_constrain_nostromeri_fixed.tre" "$data_dir/Pipoid_occurences_old_11_25.csv" "$resu_dir/Pipid_constraint_old_17" &

"$exec_dir/dspe" -o $origin_time -s $main_it -u 0.1 -b $burn_it -g $gap_it -r $rand_seed -t $proc_nb "$clad_dir/Topologies_constrain_nostromeri_fixed.tre_19.txt" "$data_dir/Topologies_constrain_nostromeri_fixed.tre" "$data_dir/Pipoid_occurences_old_11_25.csv" "$resu_dir/Pipid_constraint_old_19" &

"$exec_dir/dspe" -o $origin_time -s $main_it -u 0.1 -b $burn_it -g $gap_it -r $rand_seed -t $proc_nb "$clad_dir/Topologies_constrain_nostromeri_fixed.tre_24.txt" "$data_dir/Topologies_constrain_nostromeri_fixed.tre" "$data_dir/Pipoid_occurences_old_11_25.csv" "$resu_dir/Pipid_constraint_old_24" &


"$exec_dir/dspe" -o $origin_time -s $main_it -u 0.1 -b $burn_it -g $gap_it -r $rand_seed -t $proc_nb "$clad_dir/Topologies_constrain_nostromeri_fixed.tre_25.txt" "$data_dir/Topologies_constrain_nostromeri_fixed.tre" "$data_dir/Pipoid_occurences_old_11_25.csv" "$resu_dir/Pipid_constraint_old_25" &

"$exec_dir/dspe" -o $origin_time -s $main_it -u 0.1 -b $burn_it -g $gap_it -r $rand_seed -t $proc_nb "$clad_dir/Topologies_constrain_nostromeri_fixed.tre_28.txt" "$data_dir/Topologies_constrain_nostromeri_fixed.tre" "$data_dir/Pipoid_occurences_old_11_25.csv" "$resu_dir/Pipid_constraint_old_28" &

"$exec_dir/dspe" -o $origin_time -s $main_it -u 0.1 -b $burn_it -g $gap_it -r $rand_seed -t $proc_nb "$clad_dir/Topologies_constrain_nostromeri_fixed.tre_35.txt" "$data_dir/Topologies_constrain_nostromeri_fixed.tre" "$data_dir/Pipoid_occurences_old_11_25.csv" "$resu_dir/Pipid_constraint_old_35" &

#additional nodes cons old
"$exec_dir/dspb" -o $origin_time -s $main_it -u 0.1 -b $burn_it -g $gap_it -r $rand_seed -t $proc_nb "$clad_dir/Topologies_constrain_nostromeri_fixed.tre_T.txt" "$data_dir/Topologies_constrain_nostromeri_fixed.tre" "$data_dir/Pipoid_occurences_old_11_25.csv" "$resu_dir/Pipid_constraint_old_T" &

"$exec_dir/dspb" -o $origin_time -s $main_it -u 0.1 -b $burn_it -g $gap_it -r $rand_seed -t $proc_nb "$clad_dir/Topologies_constrain_nostromeri_fixed.tre_X.txt" "$data_dir/Topologies_constrain_nostromeri_fixed.tre" "$data_dir/Pipoid_occurences_old_11_25.csv" "$resu_dir/Pipid_constraint_old_X" &

"$exec_dir/dspb" -o $origin_time -s $main_it -u 0.1 -b $burn_it -g $gap_it -r $rand_seed -t $proc_nb "$clad_dir/Topologies_constrain_nostromeri_fixed.tre_Y.txt" "$data_dir/Topologies_constrain_nostromeri_fixed.tre" "$data_dir/Pipoid_occurences_old_11_25.csv" "$resu_dir/Pipid_constraint_old_Y" &

"$exec_dir/dspb" -o $origin_time -s $main_it -u 0.1 -b $burn_it -g $gap_it -r $rand_seed -t $proc_nb "$clad_dir/Topologies_constrain_nostromeri_fixed.tre_Z.txt" "$data_dir/Topologies_constrain_nostromeri_fixed.tre" "$data_dir/Pipoid_occurences_old_11_25.csv" "$resu_dir/Pipid_constraint_old_Z" &

#additional nodes cons young
"$exec_dir/dspb" -o $origin_time -s $main_it -u 0.1 -b $burn_it -g $gap_it -r $rand_seed -t $proc_nb "$clad_dir/Topologies_constrain_nostromeri_fixed.tre_T.txt" "$data_dir/Topologies_constrain_nostromeri_fixed.tre" "$data_dir/Pipoid_occurences_young.csv" "$resu_dir/Pipid_constraint_young_T" &

"$exec_dir/dspb" -o $origin_time -s $main_it -u 0.1 -b $burn_it -g $gap_it -r $rand_seed -t $proc_nb "$clad_dir/Topologies_constrain_nostromeri_fixed.tre_X.txt" "$data_dir/Topologies_constrain_nostromeri_fixed.tre" "$data_dir/Pipoid_occurences_young.csv" "$resu_dir/Pipid_constraint_young_X" &

"$exec_dir/dspb" -o $origin_time -s $main_it -u 0.1 -b $burn_it -g $gap_it -r $rand_seed -t $proc_nb "$clad_dir/Topologies_constrain_nostromeri_fixed.tre_Y.txt" "$data_dir/Topologies_constrain_nostromeri_fixed.tre" "$data_dir/Pipoid_occurences_young.csv" "$resu_dir/Pipid_constraint_young_Y" &

"$exec_dir/dspb" -o $origin_time -s $main_it -u 0.1 -b $burn_it -g $gap_it -r $rand_seed -t $proc_nb "$clad_dir/Topologies_constrain_nostromeri_fixed.tre_Z.txt" "$data_dir/Topologies_constrain_nostromeri_fixed.tre" "$data_dir/Pipoid_occurences_young.csv" "$resu_dir/Pipid_constraint_young_Z" &


"$exec_dir/drsp" -a "$clad_dir/map_constraint.txt" -y 20 -x 6 -c "$clad_dir/Topologies_constrain_nostromeri_fixed.tre_" .txt -d "$resu_dir/Pipid_constraint_old_" .csv "$data_dir/Topologyconsensus_constrainnostromeri_fixed.tre" "$data_dir/Pipoid_occurences_old_11_25.csv"

"$exec_dir/drsp" -a "$clad_dir/map_constraint.txt" -y 20 -x 6 -c "$clad_dir/Topologies_constrain_nostromeri_fixed.tre_" .txt -d "$resu_dir/Pipid_constraint_young_" .csv "$data_dir/Topologyconsensus_constrainnostromeri_fixed.tre" "$data_dir/Pipoid_occurences_young.csv"

#Distribution de temps d'extinction arbre non contraints et ages récents
"$exec_dir/dext" -o $origin_time -s $main_it_ext -b $burn_it -g $gap_it_ext -f 0.2 -a 0.33 0.33 -w 0.5 0.5 0.5 -i 5. 5. 5. -t 1 -m 0 -u 0.05 -n Patagopipa_corsolinii -n Cratopipa_novaolindensis -n Vulcanobatrachus_mandelai -n Oumtkoutia_anae -n Avitabatrachus_uliana -n Thoraciliacus_rostriceps -n Nevobatrachus_gracilis -n Singidella_latecostata -n Shelania_pascuali -n Shelania_laurenti -n Saltenia_ibanezi  -n Llankibatrachus_truebae  -n Eoxenopoides_reuningi -n Xenopus_arabiensis -n Kuruleufenia_xenopoides -n Pachycentrata_taqueti -n Xenopus_romeri -n Inbecetenanura_ragei "$data_dir/Topologies_unconstrain_nostromeri_fixed.tre" "$data_dir/Pipoid_occurences_young.csv" "$resu_dir/Pipid_unconstraint_young_" &

#Distribution de temps d'extinction arbre contraints et ages récents
"$exec_dir/dext" -o $origin_time -s $main_it_ext -b $burn_it -g $gap_it_ext -f 0.2 -a 0.33 0.33 -w 0.5 0.5 0.5 -i 5. 5. 5. -t 1 -m 0 -u 0.05 -n Patagopipa_corsolinii -n Cratopipa_novaolindensis -n Vulcanobatrachus_mandelai -n Oumtkoutia_anae -n Avitabatrachus_uliana -n Thoraciliacus_rostriceps -n Nevobatrachus_gracilis -n Singidella_latecostata -n Shelania_pascuali -n Shelania_laurenti -n Saltenia_ibanezi  -n Llankibatrachus_truebae  -n Eoxenopoides_reuningi -n Xenopus_arabiensis -n Kuruleufenia_xenopoides -n Pachycentrata_taqueti -n Xenopus_romeri -n Inbecetenanura_ragei "$data_dir/Topologies_constrain_nostromeri_fixed.tre" "$data_dir/Pipoid_occurences_young.csv" "$resu_dir/Pipid_constraint_young_" &

#Distribution de temps d'extinction arbre non contraints et ages anciens
"$exec_dir/dext" -o $origin_time -s $main_it_ext -b $burn_it -g $gap_it_ext -f 0.2 -a 0.33 0.33 -w 0.5 0.5 0.5 -i 5. 5. 5. -t 1 -m 0 -u 0.05 -n Patagopipa_corsolinii -n Cratopipa_novaolindensis -n Vulcanobatrachus_mandelai -n Oumtkoutia_anae -n Avitabatrachus_uliana -n Thoraciliacus_rostriceps -n Nevobatrachus_gracilis -n Singidella_latecostata -n Shelania_pascuali -n Shelania_laurenti -n Saltenia_ibanezi  -n Llankibatrachus_truebae  -n Eoxenopoides_reuningi -n Xenopus_arabiensis -n Kuruleufenia_xenopoides -n Pachycentrata_taqueti -n Xenopus_romeri -n Inbecetenanura_ragei "$data_dir/Topologies_unconstrain_nostromeri_fixed.tre" "$data_dir/Pipoid_occurences_old_11_25.csv" "$resu_dir/Pipid_unconstraint_old_" &


#Distribution de temps d'extinction arbre contraints et ages anciens
"$exec_dir/dext" -o $origin_time -s $main_it_ext -b $burn_it -g $gap_it_ext -f 0.2 -a 0.33 0.33 -w 0.5 0.5 0.5 -i 5. 5. 5. -t 1 -m 0 -u 0.05 -n Patagopipa_corsolinii -n Cratopipa_novaolindensis -n Vulcanobatrachus_mandelai -n Oumtkoutia_anae -n Avitabatrachus_uliana -n Thoraciliacus_rostriceps -n Nevobatrachus_gracilis -n Singidella_latecostata -n Shelania_pascuali -n Shelania_laurenti -n Saltenia_ibanezi  -n Llankibatrachus_truebae  -n Eoxenopoides_reuningi -n Xenopus_arabiensis -n Kuruleufenia_xenopoides -n Pachycentrata_taqueti -n Xenopus_romeri -n Inbecetenanura_ragei "$data_dir/Topologies_constrain_nostromeri_fixed.tre" "$data_dir/Pipoid_occurences_old_11_25.csv" "$resu_dir/Pipid_constraint_old_" &




#Distribution de temps d'extinction arbre contraints et ages anciens Shelaniinae
"$exec_dir/dext" -o $origin_time -s $main_it_ext -b $burn_it -g $gap_it_ext -f 0.2 -a 0.33 0.33 -w 0.5 0.5 0.5 -i 5. 5. 5. -t 1 -m 0 -u 0.05 -c "$clad_dir/Shelaniinae.txt" "$data_dir/Topologies_constrain_nostromeri_fixed.tre" "$data_dir/Pipoid_occurences_old_11_25.csv" "$resu_dir/Pipid_constraint_old_" &

#Figure arbre non contraint et ages récents
"$exec_dir/drsp" -a "$clad_dir/map_unconstraint.txt" -b "$clad_dir/tip.txt" -m -150 -M -23.02 -y 20 -x 6 -c "$clad_dir/Topologies_unconstrain_nostromeri_fixed.tre_" .txt -d "$resu_dir/Pipid_unconstraint_young_" .csv "$data_dir/Topologyconsensus_unconstrainnostromeri_fixed.tre" "$data_dir/Pipoid_occurences_young.csv"

mv "$data_dir/Topologyconsensus_unconstrainnostromeri_fixed_tree_tikz.tex" "$resu_dir/Topologyconsensus_unconstrainnostromeri_fixed_tree_young_tikz.tex"

#Figure arbre contraint et ages récents
"$exec_dir/drsp" -a "$clad_dir/map_constraint.txt" -b "$clad_dir/tip.txt" -m -150 -M -23.02 -y 20 -x 6 -c "$clad_dir/Topologies_constrain_nostromeri_fixed.tre_" .txt -d "$resu_dir/Pipid_constraint_young_" .csv "$data_dir/Topologyconsensus_constrainnostromeri_fixed.tre" "$data_dir/Pipoid_occurences_young.csv"

mv "$data_dir/Topologyconsensus_constrainnostromeri_fixed_tree_tikz.tex" "$resu_dir/Topologyconsensus_constrainnostromeri_fixed_tree_young_tikz.tex"

#Figure arbre non contraint et ages anciens
"$exec_dir/drsp" -a "$clad_dir/map_unconstraint.txt" -b "$clad_dir/tip.txt" -m -150 -M -23.02 -y 20 -x 6 -c "$clad_dir/Topologies_unconstrain_nostromeri_fixed.tre_" .txt -d "$resu_dir/Pipid_unconstraint_old_" .csv "$data_dir/Topologyconsensus_unconstrainnostromeri_fixed.tre" "$data_dir/Pipoid_occurences_old_11_25.csv"

mv "$data_dir/Topologyconsensus_unconstrainnostromeri_fixed_tree_tikz.tex" "$resu_dir/Topologyconsensus_unconstrainnostromeri_fixed_tree_old_tikz.tex"

#Figure arbre contraint et ages anciens
"$exec_dir/drsp" -a "$clad_dir/map_constraint.txt" -b "$clad_dir/tip.txt" -m -150 -M -23.02 -y 20 -x 6 -c "$clad_dir/Topologies_constrain_nostromeri_fixed.tre_" .txt -d "$resu_dir/Pipid_constraint_old_" .csv "$data_dir/Topologyconsensus_constrainnostromeri_fixed.tre" "$data_dir/Pipoid_occurences_old_11_25.csv"

mv "$data_dir/Topologyconsensus_constrainnostromeri_fixed_tree_tikz.tex" "$resu_dir/Topologyconsensus_constrainnostromeri_fixed_tree_old_tikz.tex"
