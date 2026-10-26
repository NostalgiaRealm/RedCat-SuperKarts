/*
 * FUN_00407ce6 at 00407ce6
 * longlong __fastcall FUN_00407ce6(undefined4 param_1, uint param_2)
 * Address ranges: 00407ce6-00407d2f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

longlong __fastcall FUN_00407ce6(undefined4 param_1,uint param_2)

{
  uint *in_EAX;
  uint uVar1;
  uint uVar2;
  
  uVar1 = *in_EAX + 0xb & 0xfffffff8;
  uVar2 = 0;
  if (uVar1 == 0) {
LAB_00407d2d:
    return CONCAT44(param_2,uVar2);
  }
  *in_EAX = uVar1;
  uVar1 = uVar1 + 0x3c;
  if (*in_EAX <= uVar1) {
    if (uVar1 < DAT_0040f054) {
      uVar1 = DAT_0040f054 & 0xfffffffe;
    }
    *in_EAX = uVar1;
    if (*in_EAX <= uVar1 + 0xfff) {
      uVar2 = uVar1 + 0xfff >> 8 & 0xfffff0;
      *in_EAX = uVar2 << 8;
      uVar2 = (uint)(uVar2 != 0);
      goto LAB_00407d2d;
    }
  }
  return (ulonglong)param_2 << 0x20;
}

