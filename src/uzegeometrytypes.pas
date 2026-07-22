{
*****************************************************************************
*                                                                           *
*  This file is part of the ZCAD                                            *
*                                                                           *
*  See the file COPYING.txt, included in this distribution,                 *
*  for details about the copyright.                                         *
*                                                                           *
*  This program is distributed in the hope that it will be useful,          *
*  but WITHOUT ANY WARRANTY; without even the implied warranty of           *
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.                     *
*                                                                           *
*****************************************************************************
}
{
@author(Andrey Zubarev <zamtmn@yandex.ru>) 
}

unit uzegeometrytypes;
{$Mode delphi}{$ModeSwitch advancedrecords}{$ModeSwitch typehelpers}{$H+}
{$Macro on}

interface

uses
  uzbLogIntf;

resourcestring
  rsDivByZero='Divide by zero';

const
  EPSILON:single=1e-40;
  EPSILON2:single=1e-30;
  eps=1e-14;
  floateps=1e-6;
  sqreps=1e-7;
  bigeps=1e-10;
  dbl_dig=15;
  tenEdbl_dig=1000000000000000;
type
  TzeMatrixType=(MTIdentity,MTScale,MTTranslate,MTRotate,MTShear);
  TzeMatrixTypes=set of TzeMatrixType;

  GMatrix4<TMtr>=record
    mtr:TMtr;
    t:TzeMatrixTypes;
    constructor CreateRec(AMtr:TMtr;At:TzeMatrixTypes);
    function IsIdentity:boolean;inline;
  end;
  GVector4<T{$if FPC_FULLVERSION<30205};GSlice:record;TT:record{$else},GSlice{$endif}>=record
    const
      ArrS=4;
    type
      TCoordRec=record x,y,z,w:T end;
    {$Define VectorTypeName := GVector4}
    {$Include gvectorintf.inc}
    {$UnDef VectorTypeName}
    var
      case Integer of
        0:(x,y,z,w:{$if FPC_FULLVERSION<30205}TT{$else}T{$endif});
        1:(v:TCoordArray);
        2:(r:TCoordRec);
        3:(Slice:GSlice;CutOff:{$if FPC_FULLVERSION<30205}TT{$else}T{$endif});
  end;
  GVector3<T{$if FPC_FULLVERSION<30205};GSlice:record;TT:record{$else},GSlice{$endif}>=record
    const
      ArrS=3;
    type
      TCoordRec=record x,y,z:T end;
    {$Define VectorTypeName := GVector3}
    {$Include gvectorintf.inc}
    {$UnDef VectorTypeName}
    var
      case Integer of
        0:(x,y,z:{$if FPC_FULLVERSION<30205}TT{$else}T{$endif});
        1:(v:TCoordArray);
        2:(r:TCoordRec);
        3:(Slice:GSlice;CutOff:{$if FPC_FULLVERSION<30205}TT{$else}T{$endif});
  end;
  GVector2<T{$if FPC_FULLVERSION<30205};GSlice:record;TT:record{$else},GSlice{$endif}>=record
    const
      ArrS=2;
    type
      TCoordRec=record x,y:T end;
    {$Define VectorTypeName := GVector2}
    {$Define TwoDimension}
    {$Include gvectorintf.inc}
    {$UnDef TwoDimension}
    {$UnDef VectorTypeName}
    var
      case Integer of
        0:(x,y:{$if FPC_FULLVERSION<30205}TT{$else}T{$endif});
        1:(v:TCoordArray);
        2:(r:TCoordRec);
        3:(Slice:GSlice;CutOff:{$if FPC_FULLVERSION<30205}TT{$else}T{$endif});
  end;
  GVector4i<T{$if FPC_FULLVERSION<30205};GSlice:record;TT:record{$else},GSlice{$endif}>=record
    const
      ArrS=4;
    type
      TCoordRec=record x,y,z,w:T end;
    {$Define VectorTypeName := GVector4i}
    {$Define IntParam}
    {$Include gvectorintf.inc}
    {$UnDef IntParam}
    {$UnDef VectorTypeName}
    var
      case Integer of
        0:(x,y,z,w:{$if FPC_FULLVERSION<30205}TT{$else}T{$endif});
        1:(v:TCoordArray);
        2:(r:TCoordRec);
        3:(Slice:GSlice;CutOff:{$if FPC_FULLVERSION<30205}TT{$else}T{$endif});
  end;
  GVector3i<T{$if FPC_FULLVERSION<30205};GSlice:record;TT:record{$else},GSlice{$endif}>=record
    const
      ArrS=3;
    type
      TCoordRec=record x,y,z:T end;
    {$Define VectorTypeName := GVector3i}
    {$Define IntParam}
    {$Include gvectorintf.inc}
    {$UnDef IntParam}
    {$UnDef VectorTypeName}
    var
      case Integer of
        0:(x,y,z:{$if FPC_FULLVERSION<30205}TT{$else}T{$endif});
        1:(v:TCoordArray);
        2:(r:TCoordRec);
        3:(Slice:GSlice;CutOff:{$if FPC_FULLVERSION<30205}TT{$else}T{$endif});
  end;


  GVector2i<T{$if FPC_FULLVERSION<30205};GSlice:record;TT:record{$else},GSlice{$endif}>=record
    const
      ArrS=2;
    type
      TCoordRec=record x,y:T end;
    {$Define VectorTypeName := GVector2i}
    {$Define IntParam}
    {$Define TwoDimension}
    {$Include gvectorintf.inc}
    {$UnDef TwoDimension}
    {$UnDef IntParam}
    {$UnDef VectorTypeName}
    var
      case Integer of
        0:(x,y:{$if FPC_FULLVERSION<30205}TT{$else}T{$endif});
        1:(v:TCoordArray);
        2:(r:TCoordRec);
        3:(Slice:GSlice;CutOff:{$if FPC_FULLVERSION<30205}TT{$else}T{$endif});
  end;


  GPoint3<T{$if FPC_FULLVERSION<30205};GSlice:record;TT:record;{$else},GSlice,{$endif}GVectorTypeName>=record
    const
      ArrS=3;
  type
    TCoordRec=record
      x,y,z:T
    end;
    {$Define PointTypeName := GPoint3}
    {$Include gpointintf.inc}
    {$UnDef PointTypeName}
    var
    case integer of
      0:(x,y,z:{$if FPC_FULLVERSION<30205}TT{$else}T{$endif});
      1:(v:TCoordArray);
      2:(r:TCoordRec);
      3:(Slice:GSlice;CutOff:{$if FPC_FULLVERSION<30205}TT{$else}T{$endif});
      4:(asVector:GVectorTypeName);
  end;
  GPoint2<T{$if FPC_FULLVERSION<30205};GSlice:record;TT:record;{$else},GSlice,{$endif}GVectorTypeName>=record
    const
      ArrS=2;
  type
    TCoordRec=record
      x,y:T
    end;
    {$Define PointTypeName := GPoint2}
    {$Define TwoDimension}
    {$Include gpointintf.inc}
    {$UnDef TwoDimension}
    {$UnDef PointTypeName}
    var
    case integer of
      0:(x,y:{$if FPC_FULLVERSION<30205}TT{$else}T{$endif});
      1:(v:TCoordArray);
      2:(r:TCoordRec);
      3:(Slice:GSlice;CutOff:{$if FPC_FULLVERSION<30205}TT{$else}T{$endif});
      4:(asVector:GVectorTypeName);
  end;
  GPoint2i<T{$if FPC_FULLVERSION<30205};GSlice:record;TT:record;{$else},GSlice,{$endif}GVectorTypeName>=record
    const
      ArrS=2;
  type
    TCoordRec=record
      x,y:T
    end;
    {$Define PointTypeName := GPoint2i}
    {$Define IntParam}
    {$Define TwoDimension}
    {$Include gpointintf.inc}
    {$UnDef TwoDimension}
    {$UnDef IntParam}
    {$UnDef PointTypeName}
    var
    case integer of
      0:(x,y:{$if FPC_FULLVERSION<30205}TT{$else}T{$endif});
      1:(v:TCoordArray);
      2:(r:TCoordRec);
      3:(Slice:GSlice;CutOff:{$if FPC_FULLVERSION<30205}TT{$else}T{$endif});
      4:(asVector:GVectorTypeName);
  end;

  PTZeDimLess=^TZeDimLess;
  TZeDimLess=type Double;

  PTZeAngle=^TZeAngle;
  TZeAngle=type Double;


  TzeXUnits=Double;
  TzeYUnits=Double;
  TzeZUnits=Double;

  //TDummyVector=record end;
  TDummyPoint=record end;

  TzeVector2d=GVector2<double,double{$if FPC_FULLVERSION<30205},double{$endif}>;
  PzeVector2d=^TzeVector2d;

  TzeVector3d=GVector3<double,TzeVector2d{$if FPC_FULLVERSION<30205},double{$endif}>;
  PzeVector3d=^TzeVector3d;

  TzeVector4d=GVector4<double,TzeVector3d{$if FPC_FULLVERSION<30205},double{$endif}>;
  PzeVector4d=^TzeVector4d;

  TzeVector2s=GVector2<single,single{$if FPC_FULLVERSION<30205},single{$endif}>;
  PzeVector2s=^TzeVector2s;

  TzeVector3s=GVector3<single,TzeVector2s{$if FPC_FULLVERSION<30205},single{$endif}>;
  PzeVector3s=^TzeVector3s;

  TzeVector4s=GVector4<single,TzeVector3s{$if FPC_FULLVERSION<30205},single{$endif}>;
  PzeVector4s=^TzeVector4s;

  TzeVector2i=GVector2i<integer,integer{$if FPC_FULLVERSION<30205},integer{$endif}>;
  PzeVector2i=^TzeVector2i;

  TzeVector3i=GVector3i<integer,TzeVector2i{$if FPC_FULLVERSION<30205},integer{$endif}>;
  PzeVector3i=^TzeVector3i;

  TzeVector4i=GVector4i<integer,TzeVector3i{$if FPC_FULLVERSION<30205},integer{$endif}>;
  PzeVector4i=^TzeVector4i;


  TzePoint2d=GPoint2<double,double{$if FPC_FULLVERSION<30205},double{$endif},TzeVector2d>;
  PzePoint2d=^TzePoint2d;

  TzePoint3d=GPoint3<double,TzePoint2d{$if FPC_FULLVERSION<30205},double{$endif},TzeVector3d>;
  PzePoint3d=^TzePoint3d;

  TzePoint2s=GPoint2<single,single{$if FPC_FULLVERSION<30205},single{$endif},TzeVector2s>;
  PzePoint2s=^TzePoint2s;

  TzePoint3s=GPoint3<single,TzePoint2s{$if FPC_FULLVERSION<30205},single{$endif},TzeVector3s>;
  PzePoint3s=^TzePoint3s;

  TzePoint2i=GPoint2i<integer,integer{$if FPC_FULLVERSION<30205},integer{$endif},TzeVector2i>;
  PzePoint2i=^TzePoint2i;


  {$if FPC_FULLVERSION >=30205}
  GRawMatrix4<GRow>=record
    case Integer of
      0:(l0,l1,l2,l3:GRow);
      1:(v:array [0..3] of GRow);
  end;
  GRawMatrix6<GRow>=record
    case Integer of
      0:(right,left,down,up,near,far:GRow);
      1:(v:array [0..5] of GRow);
  end;
  TzeFrustum=GRawMatrix6<TzeVector4d>;
  TzeMatrix4s=GRawMatrix4<TzeVector4s>;
  TzeMatrix4d=GRawMatrix4<TzeVector4d>;
  {$else}
  TzeFrustum=record
    case Integer of
      0:(right,left,down,up,near,far:TzeVector4d);
      1:(v:array [0..5] of TzeVector4d);
  end;
  TzeMatrix4s=record
    case Integer of
      0:(l0,l1,l2,l3:TzeVector4s);
      1:(v:array [0..3] of TzeVector4s);
  end;
  TzeMatrix4d=record
    case Integer of
      0:(l0,l1,l2,l3:TzeVector4d);
      1:(v:array [0..3] of TzeVector4d);
  end;
  {$endif}

  TzeTypedMatrix4d=GMatrix4<TzeMatrix4d>;
  TzeTypedMatrix4s=GMatrix4<TzeMatrix4s>;

  PzeTypedMatrix4d=^TzeTypedMatrix4d;
  PzeTypedMatrix4s=^TzeTypedMatrix4s;

  TzeQuaternion=record
    ImagPart:TzeVector3d;
    RealPart:double;
  end;
  PzeQuaternion=^TzeQuaternion;


  GDBBasis=record
    ox:TzeVector3d;
    oy:TzeVector3d;
    oz:TzeVector3d;
  end;

  GDBObj2dprop=record
    Basis:GDBBasis;
    P_insert:TzePoint3d;
  end;
  PGDBObj2dprop=^GDBObj2dprop;

  PGDBLineProp=^GDBLineProp;
  GDBLineProp=record
    lBegin:TzePoint3d;
    lEnd:TzePoint3d;
  end;

  FontFloat=Double;
  PFontFloat=^FontFloat;
  GDBFontVertex2D=GVector2<FontFloat,FontFloat{$if FPC_FULLVERSION<30205},FontFloat{$endif}>;
  PGDBFontVertex2D=^GDBFontVertex2D;

  GDBPolyVertex2D=record
    coord:TzePoint2d;
    count:Integer;
  end;
  PGDBPolyVertex2D=^GDBPolyVertex2D;

  tmatrixs=record
    pmodelMatrix:PzeTypedMatrix4d;
    pprojMatrix:PzeTypedMatrix4d;
    pviewport:PzeVector4i;
  end;
{Bounding volume}
  TBoundingBox=record
    LBN:TzePoint3d;(*'Near'*)
    RTF:TzePoint3d;(*'Far'*)
  end;
  TBoundingRect=record
    LB:TzePoint2d;(*'Near'*)
    RT:TzePoint2d;(*'Far'*)
  end;
  TInBoundingVolume=(IRFully,IRPartially,IREmpty,IRNotAplicable);
  OutBound4V=packed array [0..3]of TzePoint3d;
  PGDBQuad3d=^GDBQuad3d;
  GDBQuad2d=packed array[0..3] of TzePoint2d;
  GDBQuad3d=OutBound4V;
  tarcrtmodify=record
    p1,p2,p3:TzePoint2d;
  end;
  ptarcrtmodify=^tarcrtmodify;

  TArcData=record
    r,startangle,endangle:Double;
    p:TzePoint2d;
  end;

  TzeVector4dHlpr=type helper for TzeVector4d
    function asVector4s:TzeVector4s;inline;
  end;
  TzeVector3dHlpr=type helper for TzeVector3d
    function asPoint3d:TzePoint3d;inline;
  end;
  TzeVector3sHlpr=type helper for TzeVector3s
    function asPoint3s:TzePoint3s;inline;
  end;
  TzePoint3dHlpr=type helper for TzePoint3d
    //function asVector3d:TzeVector3d;inline;
    function asPoint3s:TzePoint3s;inline;
  end;
  TzeVector2dHlpr=type helper for TzeVector2d
    function asPoint2d:TzePoint2d;inline;
  end;
  TzePoint2DHlpr=type helper for TzePoint2d
    //function asVector2d:TzeVector2d;inline;
    function asPoint3d:TzePoint3d;inline;
    function asPoint2i:TzePoint2i;inline;
  end;

  InterceptProp<T>=record
    private
      FisIntercept:Boolean;//**< Есть это пересение или нет
      FInterceptCoord:T;   //**< Точка пересечения X,Y,Z
      Ft1,Ft2:Double;      //**< позиция на линии 1 и 2 в виде относительных цифр от 0 до 1
    Public
      Property isIntercept:Boolean read FisIntercept write FisIntercept;
      Property InterceptCoord:T read FInterceptCoord write FInterceptCoord;
      Property t1:Double read Ft1 write Ft1;
      Property t2:Double read Ft2 write Ft2;
  end;

  Intercept3DProp=InterceptProp<TzePoint3d>;

  Intercept2DProp=InterceptProp<TzePoint2d>;

const
 CMTScale=[MTIdentity,MTScale];
 CMTTranslate=[MTIdentity,MTTranslate];
 CMTRotate=[MTIdentity,MTRotate];
 CMTTransform=[MTIdentity,MTScale,MTTranslate,MTRotate];
 CMTIdentity=[MTIdentity];
 CMTShear=[MTShear];

implementation

{$Define VectorTypeName := GVector4}
{$Include gvectorimpl.inc}
{$UnDef VectorTypeName}

{$Define VectorTypeName := GVector3}
{$Include gvectorimpl.inc}
{$UnDef VectorTypeName}

{$DEFINE VectorTypeName := GVector2}
{$Define TwoDimension}
{$Include gvectorimpl.inc}
{$UnDef TwoDimension}
{$UnDef VectorTypeName}

{$Define VectorTypeName := GVector4i}
{$Define IntParam}
{$Include gvectorimpl.inc}
{$UnDef IntParam}
{$UnDef VectorTypeName}

{$Define VectorTypeName := GVector3i}
{$Define IntParam}
{$Include gvectorimpl.inc}
{$UnDef IntParam}
{$UnDef VectorTypeName}

{$DEFINE VectorTypeName := GVector2i}
{$Define IntParam}
{$Define TwoDimension}
{$Include gvectorimpl.inc}
{$UnDef TwoDimension}
{$UnDef IntParam}
{$UnDef VectorTypeName}


{$Define PointTypeName := GPoint3}
{$Include gpointimpl.inc}
{$UnDef PointTypeName}

{$DEFINE PointTypeName := GPoint2}
{$Define TwoDimension}
{$Include gpointimpl.inc}
{$UnDef TwoDimension}
{$UnDef PointTypeName}

{$DEFINE PointTypeName := GPoint2i}
{$Define IntParam}
{$Define TwoDimension}
{$Include gpointimpl.inc}
{$UnDef TwoDimension}
{$UnDef IntParam}
{$UnDef PointTypeName}

function TzeVector4dHlpr.asVector4s:TzeVector4s;
begin
  with TzeVector4s((@result)^) do// Этот хак убирает по одной лишней инструкции с каждого присвоения
  begin                          // возможно в будущем, это можно будет убрать, когда компилятор
                                 // сможет сам это оптимизировать
    v[0]:=self.v[0];
    v[1]:=self.v[1];
    v[2]:=self.v[2];
    v[3]:=self.v[3];
  end;

  //result.v[0]:=v[0];
  //result.v[1]:=v[1];
  //result.v[2]:=v[2];
  //result.v[3]:=v[3];

  //Result.x:=x;
  //Result.y:=y;
  //Result.z:=z;
  //Result.w:=w;
end;

function TzeVector3dHlpr.asPoint3d:TzePoint3d;
begin
  result:=TzePoint3d(self);
end;

function TzeVector3sHlpr.asPoint3s:TzePoint3s;
begin
  result:=TzePoint3s(self);
end;

{function TzePoint3dHlpr.asVector3d:TzeVector3d;
begin
  result:=TzeVector3d(self);
end;}

function TzePoint3dHlpr.asPoint3s:TzePoint3s;
begin
  Result.x:=x;
  Result.y:=y;
  Result.z:=z;
end;

function TzeVector2dHlpr.asPoint2d:TzePoint2d;
begin
  result:=TzePoint2d(self);
end;

{function TzePoint2DHlpr.asVector2d:TzeVector2d;
begin
  result:=TzeVector2d(self);
end;}

function TzePoint2DHlpr.asPoint3d:TzePoint3d;
begin
  result.x:=x;
  result.y:=y;
  result.z:=0;
end;

function TzePoint2DHlpr.asPoint2i:TzePoint2i;
begin
  result.x:=round(x);
  result.y:=round(y);
end;

constructor GMatrix4<TMtr>.CreateRec(AMtr:TMtr;At:TzeMatrixTypes);
begin
  mtr:=AMtr;
  t:=At;
end;
function GMatrix4<TMtr>.IsIdentity:Boolean;
begin
  result:=(t=CMTIdentity);
end;

end.
