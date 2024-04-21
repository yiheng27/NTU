company(sumsum).
company(appy).
competitor_of(sumsum, appy).
developed(sumsum, galactica_s3).
stole(stevey, galactica_s3).
boss(stevey, appy).

rival(X,Y):-
    company(X),
    company(Y),
    competitor_of(X,Y).

business(X):-
    smart_phone_technology(X).

smart_phone_technology(galactica-s3).

unethical(X) :-
    boss(X, Company),
    competitor_of(Competitor, Company),
    developed(Competitor, Technology),
    stole(X, Technology).
