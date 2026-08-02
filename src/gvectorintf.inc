    type
      TCoordType={$if FPC_FULLVERSION<30205}TT{$else}T{$endif};
      TCoordArray=array [0..ArrS-1] of T;
      TSelf=VectorTypeName<T{$if FPC_FULLVERSION<30205},GSlice,TT{$else},GSlice{$endif}>;
      TSlice=GSlice;
    const
      ArrH=High(TCoordArray);
      ArrL=Low(TCoordArray);

    function SqrLength:Double;inline;
    function Length:Double;inline;
    function SqrLengthTo(const AVector2:TSelf):Double;inline;
    function LengthTo(const AVector2:TSelf):Double;inline;
    {$IfNDef IntParam}
    function Normalized:TSelf;inline;
    procedure Normalize;inline;
    function DeHomogenized:TSlice;inline;
    procedure DeHomogenize;inline;
    function MulOnSc(const ASc:double):TSelf;inline;
    function LerpTo(const AVector2:TSelf;const a:double):TSelf;inline;
    function WithLength(const ALength:Double):TSelf;inline;
    {$EndIf}
    function IsEqual(const AVector2:TSelf;const AEps:Double=sqreps):boolean;inline;
    function IsNul(const AEps:Double=sqreps):boolean;inline;
    function Add(const AVector2:TSelf):TSelf;inline;
    function Sub(const AVector2:TSelf):TSelf;inline;

    class operator +(const l,r:TSelf):TSelf;inline;
    class operator -(const l,r:TSelf):TSelf;inline;overload;
    class operator -(const r:TSelf):TSelf;inline;overload;
    class operator *(const l:TSelf;const r:T):TSelf;inline;
    class operator *(const l,r:TSelf):Real;inline;
    {$IfNDef IntParam}
    class operator /(const l:TSelf;const r:Real):TSelf;inline;
    {$EndIf}
    class function Make(const AData:TCoordArray):TSelf;static;inline;
    procedure setup(const AData:TCoordArray);inline;
    constructor CreateRec(const AData:TCoordArray);
    {$IfDef TwoDimension}
    function Turned90R:TSelf;inline;
    function Turned90L:TSelf;inline;
    procedure Turn90R;inline;
    procedure Turn90L;inline;
    {$EndIf}
