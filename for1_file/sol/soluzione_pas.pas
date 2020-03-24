(*
 *  Soluzione di for1
 *
 *  Autore: Romeo Rizzi, last: 2020-03-24
 *)

var N, i : longint;
begin
{$ifdef EVAL}
    assign(input, 'input.txt'); reset(input);
    assign(output, 'output.txt'); rewrite(output);
{$endif}
    read(N);
    for i := 1 to N do
       write(i, ' ');
    writeln();
end.

