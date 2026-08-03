    const
      ArrS={$if defined(HAS_W)}4{$elseif defined(HAS_Z)}3{$elseif defined(HAS_Y)}2{$else}1{$endif};
    type
      TCoordType={$if FPC_FULLVERSION<30205}TT{$else}T{$endif};
      TCoordRec=record {$IfDef HAS_X}x{$EndIf}{$IfDef HAS_Y},y{$EndIf}{$IfDef HAS_Z},z{$EndIf}{$IfDef HAS_W},w{$EndIf}:TCoordType end;
      TCoordArray=array [0..ArrS-1] of T;
      TSelf=PointTypeName<T{$if FPC_FULLVERSION<30205},GSlice,TT{$else},GSlice{$endif},GVectorTypeName>;
      TSlice=GSlice;
    const
      ArrH=High(TCoordArray);
      ArrL=Low(TCoordArray);

    function SqrLength:Double;inline;
    function Length:Double;inline;
    function SqrLengthTo(const APt2:TSelf):Double;inline;
    function LengthTo(const APt2:TSelf):Double;inline;
    {$IfNDef IntParam}
    function Normalized:TSelf;inline;
    procedure Normalize;inline;
    function MulOnSc(const ASc:double):TSelf;inline;
    function LerpTo(const APt2:TSelf;const a:double):TSelf;inline;
    {$EndIf}
    function IsEqual(const APt2:TSelf;const AEps:Double=sqreps):boolean;inline;
    function IsNul(const AEps:Double=sqreps):boolean;inline;
    function Add(const APt2:TSelf):TSelf;inline;
    function Sub(const APt2:TSelf):TSelf;inline;

    //class operator +(const l,r:TSelf):TSelf;inline;
    class operator +(const l:TSelf;r:GVectorTypeName):TSelf;inline;overload;
    class operator -(const l,r:TSelf):GVectorTypeName;inline;overload;
    class operator -(const l:TSelf;r:GVectorTypeName):TSelf;inline;overload;
    class operator -(const r:TSelf):TSelf;inline;overload;
    class operator *(const l:TSelf;const r:T):TSelf;inline;
    class operator *(const l,r:TSelf):Real;inline;
    {$IfNDef IntParam}
    class operator /(const l:TSelf;const r:Real):TSelf;inline;
    {$EndIf}
    class function Make(const AData:TCoordArray):TSelf;static;inline;
    procedure setup(const AData:TCoordArray);inline;
    constructor CreateRec(const AData:TCoordArray);
    {$If defined(HAS_Y) and (not defined(HAS_Z))}
    function Turned90R:TSelf;inline;
    function Turned90L:TSelf;inline;
    procedure Turn90R;inline;
    procedure Turn90L;inline;
    {$EndIf}
    var
    case integer of
      0:({$IfDef HAS_X}x{$EndIf}{$IfDef HAS_Y},y{$EndIf}{$IfDef HAS_Z},z{$EndIf}{$IfDef HAS_W},w{$EndIf}:TCoordType);
      1:(v:TCoordArray);
      //2:(r:TCoordRec);
      3:(Slice:GSlice;CutOff:{$if FPC_FULLVERSION<30205}TT{$else}T{$endif});
      4:(asVector:GVectorTypeName);
