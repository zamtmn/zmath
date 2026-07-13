function VectorTypeName<T{$if FPC_FULLVERSION<30205};GSlice:record;TT:record{$else},GSlice{$endif}>.SqrLength:Double;
var
  i:integer;
begin
  //Result:=SumOfSquares(v);
  result:=sqr(v[0]);
  for i:=1 to ArrH do begin
    result:=result+sqr(v[i]);
  end;
end;
function VectorTypeName<T{$if FPC_FULLVERSION<30205};GSlice:record;TT:record{$else},GSlice{$endif}>.Length:Double;
begin
  //result:=norm(v);
  result:=Sqrt(SqrLength);
end;
{$IfNDef IntParam}
function VectorTypeName<T{$if FPC_FULLVERSION<30205};GSlice:record;TT:record{$else},GSlice{$endif}>.NormalizeVertex:TSelf;
var
  len:Double;
  i:integer;
begin
  len:=Length;
  if abs(len)>eps then begin
    for i:=0 to ArrH do begin
      result.v[i]:=v[i]/len;
    end;
  end else begin
    //DebugLn('{EH}'+rsDivByZero);
    //len:=len+2;
  end;
end;
{$EndIf}
function VectorTypeName<T{$if FPC_FULLVERSION<30205};GSlice:record;TT:record{$else},GSlice{$endif}>.Add(const Vector2:TSelf):TSelf;
var
  i:integer;
begin
  for i:=0 to ArrH do begin
    result.v[i]:=v[i]+Vector2.v[i];
  end;
end;
function VectorTypeName<T{$if FPC_FULLVERSION<30205};GSlice:record;TT:record{$else},GSlice{$endif}>.Sub(const Vector2:TSelf):TSelf;
var
  i:integer;
begin
  for i:=0 to ArrH do begin
    result.v[i]:=v[i]-Vector2.v[i];
  end;
end;
class operator VectorTypeName<T{$if FPC_FULLVERSION<30205};GSlice:record;TT:record{$else},GSlice{$endif}>.+(const l,r:TSelf):TSelf;
var
  i:integer;
begin
  for i:=0 to ArrH do begin
    result.v[i]:=l.v[i]+r.v[i];
  end;
end;
class operator VectorTypeName<T{$if FPC_FULLVERSION<30205};GSlice:record;TT:record{$else},GSlice{$endif}>.-(const l,r:TSelf):TSelf;
var
  i:integer;
begin
  for i:=0 to ArrH do begin
    result.v[i]:=l.v[i]-r.v[i];
  end;
end;
class operator VectorTypeName<T{$if FPC_FULLVERSION<30205};GSlice:record;TT:record{$else},GSlice{$endif}>.-(const r:TSelf):TSelf;
var
  i:integer;
begin
  for i:=0 to ArrH do begin
    result.v[i]:=-r.v[i];
  end;
end;
class operator VectorTypeName<T{$if FPC_FULLVERSION<30205};GSlice:record;TT:record{$else},GSlice{$endif}>.*(const l:TSelf;const r:T):TSelf;
var
  i:integer;
begin
  for i:=0 to ArrH do begin
    result.v[i]:=l.v[i]*r;
  end;
end;
class operator VectorTypeName<T{$if FPC_FULLVERSION<30205};GSlice:record;TT:record{$else},GSlice{$endif}>.*(const l,r:TSelf):Real;
var
  i:integer;
begin
  result:=l.v[0]*r.v[0];
  for i:=1 to ArrH do begin
    result:=result+l.v[i]*r.v[i];
  end;
end;
{$IfNDef IntParam}
class operator VectorTypeName<T{$if FPC_FULLVERSION<30205};GSlice:record;TT:record{$else},GSlice{$endif}>./(const l:TSelf;const r:Real):TSelf;
var
  i:integer;
begin
  for i:=0 to ArrH do begin
    result.v[i]:=l.v[i]/r;
  end;
end;
{$EndIf}

class function VectorTypeName<T{$if FPC_FULLVERSION<30205};GSlice:record;TT:record{$else},GSlice{$endif}>.Make(const AData:TCoordArray):TSelf;
begin
  result.v:=AData;
end;

constructor VectorTypeName<T{$if FPC_FULLVERSION<30205};GSlice:record;TT:record{$else},GSlice{$endif}>.CreateRec(const AData:TCoordArray);
begin
  self.v:=AData;
end;

{$IfDef TwoDimension}
function VectorTypeName<T{$if FPC_FULLVERSION<30205};GSlice:record;TT:record{$else},GSlice{$endif}>.Turn90R:TSelf;
begin
 result.x:=y;
 result.y:=-x;
end;
function VectorTypeName<T{$if FPC_FULLVERSION<30205};GSlice:record;TT:record{$else},GSlice{$endif}>.Turn90L:TSelf;inline;
begin
 result.x:=-y;
 result.y:=x;
end;
{$EndIf}
