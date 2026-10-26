/*
 * FUN_00450468 at 00450468
 * uint __register FUN_00450468(undefined4 param_1)
 * Address ranges: 00450468-00450490
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

uint FUN_00450468(undefined4 param_1)

{
  undefined1 local_8;
  undefined1 uStack_7;
  undefined1 uStack_6;
  undefined4 local_4;
  
  uStack_6 = (undefined1)((uint)param_1 >> 0x10);
  uStack_7 = (undefined1)((uint)param_1 >> 8);
  local_8 = (undefined1)param_1;
  local_4 = (uint)CONCAT12(local_8,CONCAT11(uStack_7,uStack_6));
  return local_4;
}

