/*
 * FUN_00466ed4 at 00466ed4
 * undefined __register FUN_00466ed4(int * param_1)
 * Address ranges: 00466ed4-00466f16;00466f32-00466f59;00466f73-00466f78
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00466ed4(int *param_1)

{
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_20;
  undefined1 *puStack_1c;
  undefined1 *puStack_18;
  
  puStack_18 = (undefined1 *)0x466ee6;
  FUN_00444c8c((int)param_1);
  if ((char)param_1[0x5a] == '\0') {
    puStack_1c = &LAB_00466f5a;
    uStack_20 = *in_FS_OFFSET;
    *in_FS_OFFSET = &uStack_20;
    puStack_18 = &stack0xfffffffc;
    FUN_00403088(param_1,extraout_EDX,extraout_ECX);
    *in_FS_OFFSET = uStack_20;
  }
  else {
    puStack_1c = &LAB_00466f17;
    uStack_20 = *in_FS_OFFSET;
    *in_FS_OFFSET = &uStack_20;
    puStack_18 = &stack0xfffffffc;
    FUN_00403088(param_1,extraout_EDX,extraout_ECX);
    *in_FS_OFFSET = uStack_20;
  }
  return;
}

