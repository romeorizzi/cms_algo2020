(*
 *  Soluzione di io
 *
 *  Autore: Romeo Rizzi
 *
 *  Descrizione: Banale
 *)

var a : longint;
begin
{$ifdef EVAL}
    assign(input, 'input.txt'); reset(input);
    assign(output, 'output.txt'); rewrite(output);
{$endif}
    read(a);
    writeln(a);
end.

