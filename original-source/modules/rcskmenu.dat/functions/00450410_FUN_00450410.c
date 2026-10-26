/*
 * FUN_00450410 at 00450410
 * uint __register FUN_00450410(undefined4 param_1)
 * Address ranges: 00450410-00450438
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

uint FUN_00450410(undefined4 param_1)

{
  undefined1 uStack_7;
  undefined1 uStack_6;
  undefined4 local_4;
  
  uStack_7 = (undefined1)((uint)param_1 >> 8);
  uStack_6 = (undefined1)((uint)param_1 >> 0x10);
  local_4 = CONCAT31(CONCAT21((short)param_1,uStack_7),uStack_6) & 0xffffff;
  return local_4;
}

