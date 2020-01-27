include "globals.mzn";

% Jeu des buffles et des lions

int: NB;
int: NL;

int: max_transferts;

var 1..max_transferts - 1: nb_transferts;

array [1..max_transferts] of var 0..NL: LG;
array [1..max_transferts] of var 0..2: LC;
array [1..max_transferts] of var 0..NL: LD;
array [1..max_transferts] of var 0..NB: BG;
array [1..max_transferts] of var 0..2: BC;
array [1..max_transferts] of var 0..NB: BD;


constraint NL <= NB;

% États initial et final
constraint BD[1] = 0 /\ LD[1] = 0 /\ BG[1] = NB /\ LG[1] = NL;
constraint forall (t in nb_transferts .. max_transferts) (BD[t] = NB /\ LD[t] = NL /\ BG[t] = 0 /\ LG[t] = 0);
% Contraintes sur les états
constraint forall (t in 1 .. max_transferts) (
	   (BG[t] > 0 -> LG[t] <= BG[t]) /\ (BD[t] > 0 -> LD[t] <= BD[t])
);
constraint forall (t in 1 .. nb_transferts) (
	(
		   0 < BC[t] + LC[t] /\ BC[t] + LC[t] <= 2
		/\ 0 < BC[t+1] + LC[t+1] /\ BC[t+1] + LC[t+1] <= 2
	) /\ (
		   BG[t+1] = BG[t] - BC[t+1] /\ LG[t+1] = LG[t] - LC[t+1]
		/\ BD[t+1] = BD[t] + BC[t+1] /\ LD[t+1] = LD[t] + BC[t+1]
	\/
		   BD[t+1] = BD[t] - BC[t+1] /\ LD[t+1] = LD[t] - LC[t+1]
		/\ BG[t+1] = BG[t] + BC[t+1] /\ LG[t+1] = LG[t] + BC[t+1]
	)
);

solve minimize nb_transferts;
