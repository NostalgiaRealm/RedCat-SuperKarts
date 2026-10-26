/*
 * FUN_0040adb0 at 0040adb0
 * undefined FUN_0040adb0(void)
 * Address ranges: 0040adb0-0040adbe
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __fastcall FUN_0040adb0(undefined4 param_1,undefined4 param_2)

{
  undefined1 uVar1;
  ushort uVar2;
  
  uVar2 = (ushort)((uint)param_2 >> 0x10);
  uVar1 = (undefined1)param_2;
  return CONCAT22(uVar2 >> 8 |
                  (ushort)((uint)(CONCAT22(uVar2,CONCAT11(uVar1,uVar1)) << 0x18) >> 0x10),
                  CONCAT11((char)((uint)param_2 >> 0x18),uVar1));
}

