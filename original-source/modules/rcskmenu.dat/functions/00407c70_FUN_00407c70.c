/*
 * FUN_00407c70 at 00407c70
 * undefined __register FUN_00407c70(undefined4 param_1)
 * Address ranges: 00407c70-00407ca4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00407c70(undefined4 param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_00402714(0xc);
  *puVar1 = DAT_0047b13c;
  puVar1[1] = *(undefined4 *)PTR_DAT_0047c608;
  puVar1[2] = param_1;
  DAT_0047b13c = puVar1;
  *(undefined1 **)PTR_DAT_0047c608 = &LAB_00407c44;
  return;
}

