male(prince_charles).
female(princess_ann).
male(prince_andrew).
male(prince_edward).

offspring(prince_charles, queen_elizabeth).
offspring(princess_ann, queen_elizabeth).
offspring(prince_andrew, queen_elizabeth).
offspring(prince_edward, queen_elizabeth).

older(prince_charles, princess_ann).
older(princess_ann, prince_andrew).
older(prince_andrew, prince_edward).

older(X,Y) :-
    \+ X = Y,
    older(X,Z),
    older(Z,Y).

:- dynamic printed_successors/1.
printed_successors([]).

%for old Royal succession

successor(X) :-
    ((male(X),
      male(Y),
      older(X, Y),
      offspring(X, queen_elizabeth),
      offspring(Y, queen_elizabeth))

    ;(male(X),
     offspring(X, queen_elizabeth))

    ;(female(X),
     female(Y),
      older(X, Y),
      offspring(X, queen_elizabeth),
      offspring(Y, queen_elizabeth))

    ;(female(X),
     offspring(X, queen_elizabeth))

    ),

    \+ printed_successors([X]),

    asserta(printed_successors([X])).

%print all successors as a single list in reverse order
print_all_successors :-
    findall(Successor, printed_successors([Successor]), AllSuccessors),
    reverse(AllSuccessors, ReversedSuccessors),
    writeln(ReversedSuccessors).
