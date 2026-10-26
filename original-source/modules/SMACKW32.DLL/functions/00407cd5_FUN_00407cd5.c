/*
 * FUN_00407cd5 at 00407cd5
 * undefined8 __fastcall FUN_00407cd5(undefined4 param_1, undefined4 param_2)
 * Address ranges: 00407cd5-00407ce5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined8 __fastcall FUN_00407cd5(undefined4 param_1,undefined4 param_2)

{
  uint in_EAX;
  undefined4 extraout_ECX;
  longlong lVar1;
  undefined8 uVar2;
  
  lVar1 = FUN_00408c60(param_1,in_EAX);
  uVar2 = FUN_00407c45(extraout_ECX,(uint)((ulonglong)lVar1 >> 0x20));
  return CONCAT44(param_2,(int)uVar2);
}

