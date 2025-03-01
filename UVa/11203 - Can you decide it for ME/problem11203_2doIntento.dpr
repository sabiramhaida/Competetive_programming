program problem11203_2doIntento (input, output);

{$APPTYPE CONSOLE}


Function StrToInt(Const S: String): Integer;
Var
  E: Integer;
Begin
  Val(S, Result, E);
End;


function ocurrencias(const s: string; const c:char) : integer;
var
  i : integer;
begin
result := 0;
for i:=0 to length(s) do
  if s[i] = c then
    inc(result);
end;


function isTheorem(s : string) : boolean;
var
  i, x, y, z : integer;
  posM, posE : integer;
begin
result := false;
if (ocurrencias(s, 'M') = 1) and (ocurrencias(s, 'E') = 1) and (ocurrencias(s, '?') >= 4) then
  begin
  x := 0; y := 0; z := 0;
  posM := pos('M', s);
  for i:=1 to posM-1 do
    if (s[i] = '?') then
      inc(x)
    else
      exit;
  s := copy(s, posM + 1, length(s));
  posE := pos('E', s);
  for i:=1 to posE-1 do
  if (s[i] = '?') then
    inc(y)
  else
    exit;
  s := copy(s, posE + 1, length(s));
  for i:=1 to length(s) do
  if (s[i] = '?') then
    inc(z)
  else
    exit;

  result := (x + y = z) and (x*y*z <> 0);
  end;
end;

var
  howMany : integer;
  i, principalLoop : integer;
  line : String;
  correctChars : Set of char;
  invalid : boolean;

//Main:
begin
//reset(input, 'input.txt');
//reset(output, 'out.txt');
correctChars := ['M', 'E', '?'];
readLn(line);
howMany := strToInt(line);

for principalLoop := 1 to howMany do
  begin
  invalid := false;
  readLn(line);
  for i := 1 to length(line) do
      if not (line[i] in correctChars) then
        invalid := true;
  if invalid then
    writeLn('no-theorem')
  else
    begin
    if isTheorem(line) then
      writeLn('theorem')
    else
      writeLn('no-theorem');
    end;
  end;
end.
