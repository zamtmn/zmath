function PointTypeName<T{$if FPC_FULLVERSION<30205};GSlice:record;TT:record;{$else},GSlice,{$endif}GVectorTypeName{$if FPC_FULLVERSION<30205}:record{$endif}>.SqrLength:Double;
var
  i:integer;
begin
  //Result:=SumOfSquares(v);
  result:=sqr(v[0]);
  for i:=1 to ArrH do begin
    result:=result+sqr(v[i]);
  end;
end;
function PointTypeName<T{$if FPC_FULLVERSION<30205};GSlice:record;TT:record;{$else},GSlice,{$endif}GVectorTypeName{$if FPC_FULLVERSION<30205}:record{$endif}>.Length:Double;
begin
  //result:=norm(v);
  result:=Sqrt(SqrLength);
end;
function PointTypeName<T{$if FPC_FULLVERSION<30205};GSlice:record;TT:record;{$else},GSlice,{$endif}GVectorTypeName{$if FPC_FULLVERSION<30205}:record{$endif}>.SqrLengthTo(const APt2:TSelf):Double;inline;
var
  i:integer;
begin
  result:=sqr(APt2.v[0]-v[0]);
  for i:=1 to ArrH do begin
    result:=result+sqr(APt2.v[i]-v[i]);
  end;
end;
function PointTypeName<T{$if FPC_FULLVERSION<30205};GSlice:record;TT:record;{$else},GSlice,{$endif}GVectorTypeName{$if FPC_FULLVERSION<30205}:record{$endif}>.LengthTo(const APt2:TSelf):Double;inline;
begin
  result:=Sqrt(SqrLengthTo(APt2));
end;

{$IfNDef IntParam}
function PointTypeName<T{$if FPC_FULLVERSION<30205};GSlice:record;TT:record;{$else},GSlice,{$endif}GVectorTypeName{$if FPC_FULLVERSION<30205}:record{$endif}>.Normalized:TSelf;
  procedure dbz;
  begin
    zDebugLn('{EH}'+rsDivByZero);
  end;
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
    dbz;
  end;
end;
procedure PointTypeName<T{$if FPC_FULLVERSION<30205};GSlice:record;TT:record;{$else},GSlice,{$endif}GVectorTypeName{$if FPC_FULLVERSION<30205}:record{$endif}>.Normalize;inline;
  procedure dbz;
  begin
    zDebugLn('{EH}'+rsDivByZero);
  end;
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
    dbz;
  end;
end;
function PointTypeName<T{$if FPC_FULLVERSION<30205};GSlice:record;TT:record;{$else},GSlice,{$endif}GVectorTypeName{$if FPC_FULLVERSION<30205}:record{$endif}>.MulOnSc(const ASc:double):TSelf;
var
  i:integer;
begin
  for i:=0 to ArrH do begin
    result.v[i]:=v[i]*ASc;
  end;
end;
function PointTypeName<T{$if FPC_FULLVERSION<30205};GSlice:record;TT:record;{$else},GSlice,{$endif}GVectorTypeName{$if FPC_FULLVERSION<30205}:record{$endif}>.LerpTo(const APt2:TSelf;const a:double):TSelf;
begin
  result:=self.Add(APt2.Sub(self).MulOnSC(a));
end;
{$EndIf}
function PointTypeName<T{$if FPC_FULLVERSION<30205};GSlice:record;TT:record;{$else},GSlice,{$endif}GVectorTypeName{$if FPC_FULLVERSION<30205}:record{$endif}>.IsEqual(const APt2:TSelf;const AEps:Double=sqreps):boolean;
begin
  Result:=SqrLengthTo(APt2)<AEps;
end;
function PointTypeName<T{$if FPC_FULLVERSION<30205};GSlice:record;TT:record;{$else},GSlice,{$endif}GVectorTypeName{$if FPC_FULLVERSION<30205}:record{$endif}>.IsNul(const AEps:Double=sqreps):boolean;
begin
  Result:=SqrLength<AEps;
end;

function PointTypeName<T{$if FPC_FULLVERSION<30205};GSlice:record;TT:record;{$else},GSlice,{$endif}GVectorTypeName{$if FPC_FULLVERSION<30205}:record{$endif}>.Add(const APt2:TSelf):TSelf;
var
  i:integer;
begin
  for i:=0 to ArrH do begin
    result.v[i]:=v[i]+APt2.v[i];
  end;
end;
function PointTypeName<T{$if FPC_FULLVERSION<30205};GSlice:record;TT:record;{$else},GSlice,{$endif}GVectorTypeName{$if FPC_FULLVERSION<30205}:record{$endif}>.Sub(const APt2:TSelf):TSelf;
var
  i:integer;
begin
  for i:=0 to ArrH do begin
    result.v[i]:=v[i]-APt2.v[i];
  end;
end;
(*class operator PointTypeName<T{$if FPC_FULLVERSION<30205};GSlice:record;TT:record;{$else},GSlice,{$endif}GVectorTypeName>.+(const l,r:TSelf):TSelf;
var
  i:integer;
begin
  for i:=0 to ArrH do begin
    result.v[i]:=l.v[i]+r.v[i];
  end;
end;*)
class operator PointTypeName<T{$if FPC_FULLVERSION<30205};GSlice:record;TT:record;{$else},GSlice,{$endif}GVectorTypeName{$if FPC_FULLVERSION<30205}:record{$endif}>.+(const l:TSelf;r:GVectorTypeName):TSelf;inline;overload;
 var
  i:integer;
begin
  for i:=0 to ArrH do begin
    result.v[i]:=l.v[i]+{$if FPC_FULLVERSION<30205}TSelf{$endif}(r).v[i];
  end;
end;
class operator PointTypeName<T{$if FPC_FULLVERSION<30205};GSlice:record;TT:record;{$else},GSlice,{$endif}GVectorTypeName{$if FPC_FULLVERSION<30205}:record{$endif}>.-(const l,r:TSelf):GVectorTypeName;
var
  i:integer;
begin
  for i:=0 to ArrH do begin
    {$if FPC_FULLVERSION<30205}TSelf{$endif}(result).v[i]:=l.v[i]-{$if FPC_FULLVERSION<30205}TSelf{$endif}(r).v[i];
  end;
end;
class operator PointTypeName<T{$if FPC_FULLVERSION<30205};GSlice:record;TT:record;{$else},GSlice,{$endif}GVectorTypeName{$if FPC_FULLVERSION<30205}:record{$endif}>.-(const l:TSelf;r:GVectorTypeName):TSelf;inline;overload;
var
  i:integer;
begin
  for i:=0 to ArrH do begin
    result.v[i]:=l.v[i]-{$if FPC_FULLVERSION<30205}TSelf{$endif}(r).v[i];
  end;
end;
class operator PointTypeName<T{$if FPC_FULLVERSION<30205};GSlice:record;TT:record;{$else},GSlice,{$endif}GVectorTypeName{$if FPC_FULLVERSION<30205}:record{$endif}>.-(const r:TSelf):TSelf;
var
  i:integer;
begin
  for i:=0 to ArrH do begin
    result.v[i]:=-r.v[i];
  end;
end;
class operator PointTypeName<T{$if FPC_FULLVERSION<30205};GSlice:record;TT:record;{$else},GSlice,{$endif}GVectorTypeName{$if FPC_FULLVERSION<30205}:record{$endif}>.*(const l:TSelf;const r:T):TSelf;
var
  i:integer;
begin
  for i:=0 to ArrH do begin
    result.v[i]:=l.v[i]*r;
  end;
end;
class operator PointTypeName<T{$if FPC_FULLVERSION<30205};GSlice:record;TT:record;{$else},GSlice,{$endif}GVectorTypeName{$if FPC_FULLVERSION<30205}:record{$endif}>.*(const l,r:TSelf):Real;
var
  i:integer;
begin
  result:=l.v[0]*r.v[0];
  for i:=1 to ArrH do begin
    result:=result+l.v[i]*r.v[i];
  end;
end;
{$IfNDef IntParam}
class operator PointTypeName<T{$if FPC_FULLVERSION<30205};GSlice:record;TT:record;{$else},GSlice,{$endif}GVectorTypeName{$if FPC_FULLVERSION<30205}:record{$endif}>./(const l:TSelf;const r:Real):TSelf;
var
  i:integer;
begin
  for i:=0 to ArrH do begin
    result.v[i]:=l.v[i]/r;
  end;
end;
{$EndIf}

class function PointTypeName<T{$if FPC_FULLVERSION<30205};GSlice:record;TT:record;{$else},GSlice,{$endif}GVectorTypeName{$if FPC_FULLVERSION<30205}:record{$endif}>.Make(const AData:TCoordArray):TSelf;
begin
  result.v:=AData;
end;

procedure PointTypeName<T{$if FPC_FULLVERSION<30205};GSlice:record;TT:record;{$else},GSlice,{$endif}GVectorTypeName{$if FPC_FULLVERSION<30205}:record{$endif}>.setup(const AData:TCoordArray);inline;
begin
  v:=AData;
end;

constructor PointTypeName<T{$if FPC_FULLVERSION<30205};GSlice:record;TT:record;{$else},GSlice,{$endif}GVectorTypeName{$if FPC_FULLVERSION<30205}:record{$endif}>.CreateRec(const AData:TCoordArray);
begin
  self.v:=AData;
end;

{$IfDef TwoDimension}
function PointTypeName<T{$if FPC_FULLVERSION<30205};GSlice:record;TT:record;{$else},GSlice,{$endif}GVectorTypeName{$if FPC_FULLVERSION<30205}:record{$endif}>.Turned90R:TSelf;
begin
 result.x:=y;
 result.y:=-x;
end;

function PointTypeName<T{$if FPC_FULLVERSION<30205};GSlice:record;TT:record;{$else},GSlice,{$endif}GVectorTypeName{$if FPC_FULLVERSION<30205}:record{$endif}>.Turned90L:TSelf;
begin
 result.x:=-y;
 result.y:=x;
end;

procedure PointTypeName<T{$if FPC_FULLVERSION<30205};GSlice:record;TT:record;{$else},GSlice,{$endif}GVectorTypeName{$if FPC_FULLVERSION<30205}:record{$endif}>.Turn90R;
var
  tmp:T;
begin
  tmp:=y;
  y:=-x;
  x:=tmp;
end;

procedure PointTypeName<T{$if FPC_FULLVERSION<30205};GSlice:record;TT:record;{$else},GSlice,{$endif}GVectorTypeName{$if FPC_FULLVERSION<30205}:record{$endif}>.Turn90L;
var
  tmp:T;
begin
  tmp:=y;
  y:=x;
  x:=-tmp;
end;

{$EndIf}

