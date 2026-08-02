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
function VectorTypeName<T{$if FPC_FULLVERSION<30205};GSlice:record;TT:record{$else},GSlice{$endif}>.SqrLengthTo(const AVector2:TSelf):Double;inline;
var
  i:integer;
begin
  result:=sqr(AVector2.v[0]-v[0]);
  for i:=1 to ArrH do begin
    result:=result+sqr(AVector2.v[i]-v[i]);
  end;
end;
function VectorTypeName<T{$if FPC_FULLVERSION<30205};GSlice:record;TT:record{$else},GSlice{$endif}>.LengthTo(const AVector2:TSelf):Double;inline;
begin
  result:=Sqrt(SqrLengthTo(AVector2));
end;

{$IfNDef IntParam}
function VectorTypeName<T{$if FPC_FULLVERSION<30205};GSlice:record;TT:record{$else},GSlice{$endif}>.Normalized:TSelf;
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
procedure VectorTypeName<T{$if FPC_FULLVERSION<30205};GSlice:record;TT:record{$else},GSlice{$endif}>.Normalize;inline;
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
function VectorTypeName<T{$if FPC_FULLVERSION<30205};GSlice:record;TT:record{$else},GSlice{$endif}>.DeHomogenized:TSlice;
begin
  if abs({$if FPC_FULLVERSION<30205}T(CutOff){$else}CutOff{$endif})>eps then begin
    result:=Slice/CutOff;
  end else
    result:=Slice;
end;

procedure VectorTypeName<T{$if FPC_FULLVERSION<30205};GSlice:record;TT:record{$else},GSlice{$endif}>.DeHomogenize;
var
  i:integer;
begin
  if abs(v[High(TCoordArray)])>eps then begin
    for i:=Low(TCoordArray) to High(TCoordArray)-1 do begin
      v[i]:=v[i]/v[High(TCoordArray)];
    end;
    v[High(TCoordArray)]:=1;
  end;
end;
function VectorTypeName<T{$if FPC_FULLVERSION<30205};GSlice:record;TT:record{$else},GSlice{$endif}>.MulOnSc(const ASc:double):TSelf;
var
  i:integer;
begin
  for i:=0 to ArrH do begin
    result.v[i]:=v[i]*ASc;
  end;
end;

function VectorTypeName<T{$if FPC_FULLVERSION<30205};GSlice:record;TT:record{$else},GSlice{$endif}>.LerpTo(const AVector2:TSelf;const a:double):TSelf;
begin
  result:=self.Add(AVector2.Sub(self).MulOnSC(a));
end;

function VectorTypeName<T{$if FPC_FULLVERSION<30205};GSlice:record;TT:record{$else},GSlice{$endif}>.WithLength(const ALength:Double):TSelf;
var
  l:double;
begin
  l:=Length;
  if l>eps then
    result:=self*(ALength/Length)
  else
    result:=self;
end;


{$EndIf}
function VectorTypeName<T{$if FPC_FULLVERSION<30205};GSlice:record;TT:record{$else},GSlice{$endif}>.IsEqual(const AVector2:TSelf;const AEps:Double=sqreps):boolean;
begin
  Result:=SqrLengthTo(AVector2)<AEps;
end;
function VectorTypeName<T{$if FPC_FULLVERSION<30205};GSlice:record;TT:record{$else},GSlice{$endif}>.IsNul(const AEps:Double=sqreps):boolean;
begin
  Result:=SqrLength<AEps;
end;
function VectorTypeName<T{$if FPC_FULLVERSION<30205};GSlice:record;TT:record{$else},GSlice{$endif}>.Add(const AVector2:TSelf):TSelf;
var
  i:integer;
begin
  for i:=0 to ArrH do begin
    result.v[i]:=v[i]+AVector2.v[i];
  end;
end;
function VectorTypeName<T{$if FPC_FULLVERSION<30205};GSlice:record;TT:record{$else},GSlice{$endif}>.Sub(const AVector2:TSelf):TSelf;
var
  i:integer;
begin
  for i:=0 to ArrH do begin
    result.v[i]:=v[i]-AVector2.v[i];
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

procedure VectorTypeName<T{$if FPC_FULLVERSION<30205};GSlice:record;TT:record{$else},GSlice{$endif}>.setup(const AData:TCoordArray);inline;
begin
  v:=AData;
end;

constructor VectorTypeName<T{$if FPC_FULLVERSION<30205};GSlice:record;TT:record{$else},GSlice{$endif}>.CreateRec(const AData:TCoordArray);
begin
  self.v:=AData;
end;

{$IfDef TwoDimension}
function VectorTypeName<T{$if FPC_FULLVERSION<30205};GSlice:record;TT:record{$else},GSlice{$endif}>.Turned90R:TSelf;
begin
 result.x:=y;
 result.y:=-x;
end;

function VectorTypeName<T{$if FPC_FULLVERSION<30205};GSlice:record;TT:record{$else},GSlice{$endif}>.Turned90L:TSelf;
begin
 result.x:=-y;
 result.y:=x;
end;

procedure VectorTypeName<T{$if FPC_FULLVERSION<30205};GSlice:record;TT:record{$else},GSlice{$endif}>.Turn90R;
var
  tmp:T;
begin
  tmp:=y;
  y:=-x;
  x:=tmp;
end;

procedure VectorTypeName<T{$if FPC_FULLVERSION<30205};GSlice:record;TT:record{$else},GSlice{$endif}>.Turn90L;
var
  tmp:T;
begin
  tmp:=y;
  y:=x;
  x:=-tmp;
end;

{$EndIf}


