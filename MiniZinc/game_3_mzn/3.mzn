% Jeu du saut-de-mouton

int: N;
int: max_etapes;

enum etat = {blanc,noir,vide};

var 1 .. max_etapes - 1: nb_etapes;
array [1 .. max_etapes, 1 .. 2*N +1] of var etat: tableau;

% État initial et final
constraint
	   forall (c in 1 .. N) (tableau[1,c] = blanc)
	/\ tableau[1,N+1] = vide
	/\ forall (c in N + 2 .. 2*N + 1) (tableau[1,c] = noir)
	/\ forall (t in nb_etapes .. max_etapes) (
		   forall (c in 1 .. N) (tableau[t,c] = noir)
		/\ tableau[t,N+1] = vide
		/\ forall (c in N + 2 .. 2*N + 1) (tableau[t,c] = blanc)
	);

% États intermédiaires
constraint forall (t in 1 .. nb_etapes) (
	   forall (c in 1 .. 2*N)     (tableau[t,c] = blanc /\ tableau[t,c+1] = vide -> tableau[t+1,c] = vide /\ tableau[t+1,c+1] = blanc)
	\/ forall (c in 2 .. 2*N + 1) (tableau[t,c] = noir  /\ tableau[t,c-1] = vide -> tableau[t+1,c] = vide /\ tableau[t+1,c-1] = noir)
	\/ forall (c in 1 .. 2*N - 1) (tableau[t,c] = blanc /\ tableau[t,c+1] != vide /\ tableau[t,c+2] = vide -> tableau[t+1,c] = vide /\ tableau[t+1,c+1] = tableau[t,c+1] /\ tableau[t+1,c+2] = blanc)
	\/ forall (c in 3 .. 2*N + 1) (tableau[t,c] = noir  /\ tableau[t,c-1] != vide /\ tableau[t,c-2] = vide -> tableau[t+1,c] = vide /\ tableau[t+1,c-1] = tableau[t,c-1] /\ tableau[t+1,c-2] = noir)
);

solve  minimize nb_etapes;
