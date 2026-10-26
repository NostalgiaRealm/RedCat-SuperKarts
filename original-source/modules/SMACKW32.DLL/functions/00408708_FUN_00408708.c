/*
 * FUN_00408708 at 00408708
 * undefined8 __fastcall FUN_00408708(undefined4 param_1, undefined4 param_2)
 * Address ranges: 00408708-0040873e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined8 __fastcall FUN_00408708(undefined4 param_1,undefined4 param_2)

{
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  undefined8 uVar1;
  
  DAT_004104f4 = 0;
  DAT_004104f8 = 0;
  GetStdHandle(0xfffffff6);
  FUN_004085c7(extraout_ECX,extraout_EDX);
  GetStdHandle(0xfffffff5);
  FUN_004085c7(extraout_ECX_00,extraout_EDX_00);
  GetStdHandle(0xfffffff4);
  uVar1 = FUN_004085c7(extraout_ECX_01,extraout_EDX_01);
  return CONCAT44(param_2,(int)uVar1);
}

