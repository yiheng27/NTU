Offspring(prince_charles, queen_elizabeth).
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
    ((older(X, Y),
      offspring(X, queen_elizabeth),
      offspring(Y, queen_elizabeth))

    ;offspring(X, queen_elizabeth)),

    \+ printed_successors([X]),

    asserta(printed_successors([X])).

%print all successors as a single list in reverse order
print_all_successors :-
    findall(Successor, printed_successors([Successor]), AllSuccessors),
    reverse(AllSuccessors, ReversedSuccessors),
    writeln(ReversedSuccessors).
