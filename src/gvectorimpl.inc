function VectorTypeName<T{$if FPC_FULLVERSION<30205};GSlice:record;TT:record;{$else},GSlice,{$endif}GDummy>.SqrLength:Double;
var
  i:integer;
begin
  //Result:=SumOfSquares(v);
  result:=sqr(v[0]);
  for i:=1 to ArrH do begin
    result:=result+sqr(v[i]);
  end;
end;
function VectorTypeName<T{$if FPC_FULLVERSION<30205};GSlice:record;TT:record;{$else},GSlice,{$endif}GDummy>.Length:Double;
begin
  //result:=norm(v);
  result:=Sqrt(SqrLength);
end;
{$IfNDef IntParam}
function VectorTypeName<T{$if FPC_FULLVERSION<30205};GSlice:record;TT:record;{$else},GSlice,{$endif}GDummy>.Normalized:TSelf;
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
procedure VectorTypeName<T{$if FPC_FULLVERSION<30205};GSlice:record;TT:record;{$else},GSlice,{$endif}GDummy>.Normalize;inline;
var
  len:Double;
  i:integer;
begin
  len:=Length;
  if abs(len)>eps then begin
    for i:=0 to ArrH do begin
      v[i]:=v[i]/len;
    end;
  end else begin
    //DebugLn('{EH}'+rsDivByZero);
    //len:=len+2;
  end;
end;
{$EndIf}
function VectorTypeName<T{$if FPC_FULLVERSION<30205};GSlice:record;TT:record;{$else},GSlice,{$endif}GDummy>.Add(const Vector2:TSelf):TSelf;
var
  i:integer;
begin
  for i:=0 to ArrH do begin
    result.v[i]:=v[i]+Vector2.v[i];
  end;
end;
function VectorTypeName<T{$if FPC_FULLVERSION<30205};GSlice:record;TT:record;{$else},GSlice,{$endif}GDummy>.Sub(const Vector2:TSelf):TSelf;
var
  i:integer;
begin
  for i:=0 to ArrH do begin
    result.v[i]:=v[i]-Vector2.v[i];
  end;
end;
class operator VectorTypeName<T{$if FPC_FULLVERSION<30205};GSlice:record;TT:record;{$else},GSlice,{$endif}GDummy>.+(const l,r:TSelf):TSelf;
var
  i:integer;
begin
  for i:=0 to ArrH do begin
    result.v[i]:=l.v[i]+r.v[i];
  end;
end;
class operator VectorTypeName<T{$if FPC_FULLVERSION<30205};GSlice:record;TT:record;{$else},GSlice,{$endif}GDummy>.-(const l,r:TSelf):TSelf;
var
  i:integer;
begin
  for i:=0 to ArrH do begin
    result.v[i]:=l.v[i]-r.v[i];
  end;
end;
class operator VectorTypeName<T{$if FPC_FULLVERSION<30205};GSlice:record;TT:record;{$else},GSlice,{$endif}GDummy>.-(const r:TSelf):TSelf;
var
  i:integer;
begin
  for i:=0 to ArrH do begin
    result.v[i]:=-r.v[i];
  end;
end;
class operator VectorTypeName<T{$if FPC_FULLVERSION<30205};GSlice:record;TT:record;{$else},GSlice,{$endif}GDummy>.*(const l:TSelf;const r:T):TSelf;
var
  i:integer;
begin
  for i:=0 to ArrH do begin
    result.v[i]:=l.v[i]*r;
  end;
end;
class operator VectorTypeName<T{$if FPC_FULLVERSION<30205};GSlice:record;TT:record;{$else},GSlice,{$endif}GDummy>.*(const l,r:TSelf):Real;
var
  i:integer;
begin
  result:=l.v[0]*r.v[0];
  for i:=1 to ArrH do begin
    result:=result+l.v[i]*r.v[i];
  end;
end;
{$IfNDef IntParam}
class operator VectorTypeName<T{$if FPC_FULLVERSION<30205};GSlice:record;TT:record;{$else},GSlice,{$endif}GDummy>./(const l:TSelf;const r:Real):TSelf;
var
  i:integer;
begin
  for i:=0 to ArrH do begin
    result.v[i]:=l.v[i]/r;
  end;
end;
{$EndIf}

class function VectorTypeName<T{$if FPC_FULLVERSION<30205};GSlice:record;TT:record;{$else},GSlice,{$endif}GDummy>.Make(const AData:TCoordArray):TSelf;
begin
  result.v:=AData;
end;

procedure VectorTypeName<T{$if FPC_FULLVERSION<30205};GSlice:record;TT:record;{$else},GSlice,{$endif}GDummy>.setup(const AData:TCoordArray);inline;
begin
  v:=AData;
end;

constructor VectorTypeName<T{$if FPC_FULLVERSION<30205};GSlice:record;TT:record;{$else},GSlice,{$endif}GDummy>.CreateRec(const AData:TCoordArray);
begin
  self.v:=AData;
end;

{$IfDef TwoDimension}
function VectorTypeName<T{$if FPC_FULLVERSION<30205};GSlice:record;TT:record;{$else},GSlice,{$endif}GDummy>.Turned90R:TSelf;
begin
 result.x:=y;
 result.y:=-x;
end;

function VectorTypeName<T{$if FPC_FULLVERSION<30205};GSlice:record;TT:record;{$else},GSlice,{$endif}GDummy>.Turned90L:TSelf;
begin
 result.x:=-y;
 result.y:=x;
end;

procedure VectorTypeName<T{$if FPC_FULLVERSION<30205};GSlice:record;TT:record;{$else},GSlice,{$endif}GDummy>.Turn90R;
var
  tmp:T;
begin
  tmp:=y;
  y:=-x;
  x:=tmp;
end;

procedure VectorTypeName<T{$if FPC_FULLVERSION<30205};GSlice:record;TT:record;{$else},GSlice,{$endif}GDummy>.Turn90L;
var
  tmp:T;
begin
  tmp:=y;
  y:=x;
  x:=-tmp;
end;

{$EndIf}

function VectorTypeName<T{$if FPC_FULLVERSION<30205};GSlice:record;TT:record;{$else},GSlice,{$endif}GDummy>.IsNul:boolean;
begin
  Result:=Sqrlength<=sqreps;
  {if SqrOneVertexlength>sqreps then
    Result:=false
  else
    Result:=true;}
end;

