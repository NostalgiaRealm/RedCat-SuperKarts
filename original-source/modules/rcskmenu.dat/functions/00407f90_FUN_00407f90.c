/*
 * FUN_00407f90 at 00407f90
 * undefined4 __register FUN_00407f90(byte * param_1)
 * Address ranges: 00407f90-00407fc8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00407f90(byte *param_1)

{
  undefined4 uVar1;
  int local_14;
  byte *local_10;
  undefined1 local_c;
  
  uVar1 = FUN_00402b8c(param_1,&local_14);
  if (local_14 != 0) {
    local_c = 0xb;
    local_10 = param_1;
    FUN_00407bc4((undefined4 *)PTR_PTR_0047c74c,&local_10,0);
  }
  return uVar1;
}

