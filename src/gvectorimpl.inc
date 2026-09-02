function VectorTypeName<T{$if FPC_FULLVERSION<30205};GSlice:record;TT:record{$else},GSlice{$endif}>.SqrLength:Double;
begin
  {$IfDef HAS_X}result:=sqr(x);{$Else}result:=0;{$EndIf}
  {$IfDef HAS_Y}result:=result+sqr(y);{$EndIf}
  {$IfDef HAS_Z}result:=result+sqr(z);{$EndIf}
  {$IfDef HAS_W}result:=result+sqr(w);{$EndIf}
end;
function VectorTypeName<T{$if FPC_FULLVERSION<30205};GSlice:record;TT:record{$else},GSlice{$endif}>.Length:Double;
begin
  //result:=norm(v);
  result:=Sqrt(SqrLength);
end;
function VectorTypeName<T{$if FPC_FULLVERSION<30205};GSlice:record;TT:record{$else},GSlice{$endif}>.SqrLengthTo(const AVector2:TSelf):Double;inline;
begin
  {$IfDef HAS_X}result:=sqr(AVector2.x-x);{$Else}result:=0;{$EndIf}
  {$IfDef HAS_Y}result:=result+sqr(AVector2.y-y);{$EndIf}
  {$IfDef HAS_Z}result:=result+sqr(AVector2.z-z);{$EndIf}
  {$IfDef HAS_W}result:=result+sqr(AVector2.w-w);{$EndIf}
end;
function VectorTypeName<T{$if FPC_FULLVERSION<30205};GSlice:record;TT:record{$else},GSlice{$endif}>.LengthTo(const AVector2:TSelf):Double;inline;
begin
  result:=Sqrt(SqrLengthTo(AVector2));
end;

{$IfNDef IntParam}
function VectorTypeName<T{$if FPC_FULLVERSION<30205};GSlice:record;TT:record{$else},GSlice{$endif}>.Normalized:TSelf;
  procedure dbz;
  begin
    zDebugLn('{EH}'+rsDivByZero);
  end;
var
  len:Double;
begin
  len:=Length;
  if abs(len)>eps then begin
    {$IfDef HAS_X}result.x:=x/len;{$EndIf}
    {$IfDef HAS_Y}result.y:=y/len;{$EndIf}
    {$IfDef HAS_Z}result.z:=z/len;{$EndIf}
    {$IfDef HAS_W}result.w:=w/len;{$EndIf}
  end else
    dbz;
end;
procedure VectorTypeName<T{$if FPC_FULLVERSION<30205};GSlice:record;TT:record{$else},GSlice{$endif}>.Normalize;inline;
var
  len:Double;
begin
  len:=Length;
  if abs(len)>eps then begin
    {$IfDef HAS_X}x:=x/len;{$EndIf}
    {$IfDef HAS_Y}y:=y/len;{$EndIf}
    {$IfDef HAS_Z}z:=z/len;{$EndIf}
    {$IfDef HAS_W}w:=w/len;{$EndIf}
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
begin
  {$IfDef HAS_X}result.x:=x*ASc;{$EndIf}
  {$IfDef HAS_Y}result.y:=y*ASc;{$EndIf}
  {$IfDef HAS_Z}result.z:=z*ASc;{$EndIf}
  {$IfDef HAS_W}result.w:=w*ASc;{$EndIf}
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
begin
  {$IfDef HAS_X}result.x:=x+AVector2.x;{$EndIf}
  {$IfDef HAS_Y}result.y:=y+AVector2.y;{$EndIf}
  {$IfDef HAS_Z}result.z:=z+AVector2.z;{$EndIf}
  {$IfDef HAS_W}result.w:=w+AVector2.w;{$EndIf}
end;
function VectorTypeName<T{$if FPC_FULLVERSION<30205};GSlice:record;TT:record{$else},GSlice{$endif}>.Sub(const AVector2:TSelf):TSelf;
begin
  {$IfDef HAS_X}result.x:=x-AVector2.x;{$EndIf}
  {$IfDef HAS_Y}result.y:=y-AVector2.y;{$EndIf}
  {$IfDef HAS_Z}result.z:=z-AVector2.z;{$EndIf}
  {$IfDef HAS_W}result.w:=w-AVector2.w;{$EndIf}
end;
class operator VectorTypeName<T{$if FPC_FULLVERSION<30205};GSlice:record;TT:record{$else},GSlice{$endif}>.+(const l,r:TSelf):TSelf;
begin
  {$IfDef HAS_X}result.x:=l.x+r.x;{$EndIf}
  {$IfDef HAS_Y}result.y:=l.y+r.y;{$EndIf}
  {$IfDef HAS_Z}result.z:=l.z+r.z;{$EndIf}
  {$IfDef HAS_W}result.w:=l.w+r.w;{$EndIf}
end;
class operator VectorTypeName<T{$if FPC_FULLVERSION<30205};GSlice:record;TT:record{$else},GSlice{$endif}>.-(const l,r:TSelf):TSelf;
begin
  {$IfDef HAS_X}result.x:=l.x-r.x;{$EndIf}
  {$IfDef HAS_Y}result.y:=l.y-r.y;{$EndIf}
  {$IfDef HAS_Z}result.z:=l.z-r.z;{$EndIf}
  {$IfDef HAS_W}result.w:=l.w-r.w;{$EndIf}
end;
class operator VectorTypeName<T{$if FPC_FULLVERSION<30205};GSlice:record;TT:record{$else},GSlice{$endif}>.-(const r:TSelf):TSelf;
begin
  {$IfDef HAS_X}result.x:=-r.x;{$EndIf}
  {$IfDef HAS_Y}result.y:=-r.y;{$EndIf}
  {$IfDef HAS_Z}result.z:=-r.z;{$EndIf}
  {$IfDef HAS_W}result.w:=-r.w;{$EndIf}
end;
class operator VectorTypeName<T{$if FPC_FULLVERSION<30205};GSlice:record;TT:record{$else},GSlice{$endif}>.*(const l:TSelf;const r:T):TSelf;
begin
  {$IfDef HAS_X}result.x:=l.x*r;{$EndIf}
  {$IfDef HAS_Y}result.y:=l.y*r;{$EndIf}
  {$IfDef HAS_Z}result.z:=l.z*r;{$EndIf}
  {$IfDef HAS_W}result.w:=l.w*r;{$EndIf}
end;
class operator VectorTypeName<T{$if FPC_FULLVERSION<30205};GSlice:record;TT:record{$else},GSlice{$endif}>.*(const l,r:TSelf):Real;
begin
  {$IfDef HAS_X}result:=l.x*r.x;{$else}result:=0{$EndIf}
  {$IfDef HAS_Y}result:=result+l.y*r.y;{$EndIf}
  {$IfDef HAS_Z}result:=result+l.z*r.z;{$EndIf}
  {$IfDef HAS_W}result:=result+l.w*r.w;{$EndIf}
end;
{$IfNDef IntParam}
class operator VectorTypeName<T{$if FPC_FULLVERSION<30205};GSlice:record;TT:record{$else},GSlice{$endif}>./(const l:TSelf;const r:Real):TSelf;
begin
  {$IfDef HAS_X}result.x:=l.x/r;{$EndIf}
  {$IfDef HAS_Y}result.y:=l.y/r;{$EndIf}
  {$IfDef HAS_Z}result.z:=l.z/r;{$EndIf}
  {$IfDef HAS_W}result.w:=l.w/r;{$EndIf}
end;
{$EndIf}

constructor VectorTypeName<T{$if FPC_FULLVERSION<30205};GSlice:record;TT:record{$else},GSlice{$endif}>.Make(const AData:TCoordArray);
begin
  v:=AData;
end;

procedure VectorTypeName<T{$if FPC_FULLVERSION<30205};GSlice:record;TT:record{$else},GSlice{$endif}>.setup(const AData:TCoordArray);inline;
begin
  v:=AData;
end;

constructor VectorTypeName<T{$if FPC_FULLVERSION<30205};GSlice:record;TT:record{$else},GSlice{$endif}>.Make(const {$IfDef HAS_X}AX{$EndIf}{$IfDef HAS_Y},AY{$EndIf}{$IfDef HAS_Z},AZ{$EndIf}{$IfDef HAS_W},AW{$EndIf}:TCoordType);overload;
begin
  {$IfDef HAS_X}x:=AX;{$EndIf}
  {$IfDef HAS_Y}y:=AY;{$EndIf}
  {$IfDef HAS_Z}z:=AZ;{$EndIf}
  {$IfDef HAS_W}w:=AW;{$EndIf}
end;

procedure VectorTypeName<T{$if FPC_FULLVERSION<30205};GSlice:record;TT:record{$else},GSlice{$endif}>.setup(const {$IfDef HAS_X}AX{$EndIf}{$IfDef HAS_Y},AY{$EndIf}{$IfDef HAS_Z},AZ{$EndIf}{$IfDef HAS_W},AW{$EndIf}:TCoordType);overload;
begin
  {$IfDef HAS_X}x:=AX;{$EndIf}
  {$IfDef HAS_Y}y:=AY;{$EndIf}
  {$IfDef HAS_Z}z:=AZ;{$EndIf}
  {$IfDef HAS_W}w:=AW;{$EndIf}
end;

{$If defined(HAS_Y) and (not defined(HAS_Z))}
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


