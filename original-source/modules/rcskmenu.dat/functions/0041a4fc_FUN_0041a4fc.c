/*
 * FUN_0041a4fc at 0041a4fc
 * undefined __register FUN_0041a4fc(undefined4 * param_1, uint * param_2)
 * Address ranges: 0041a4fc-0041a579
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0041a4fc(undefined4 *param_1,uint *param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 *in_FS_OFFSET;
  undefined1 uVar3;
  undefined4 uStack_124;
  undefined1 *puStack_120;
  undefined1 *puStack_11c;
  byte local_10c [256];
  uint *local_c;
  uint *local_8;
  
  puStack_11c = &stack0xfffffffc;
  local_c = (uint *)0x0;
  puStack_120 = &LAB_0041a57a;
  uStack_124 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_124;
  iVar2 = param_1[2] + -1;
  uVar3 = iVar2 == 0;
  local_8 = param_2;
  if (-1 < iVar2) {
    do {
      piVar1 = (int *)FUN_0040f6b0(param_1,iVar2);
      FUN_00402df8(*piVar1,local_10c);
      FUN_00403d74((int *)&local_c,local_10c);
      FUN_00403ee0(local_c,local_8);
      if ((bool)uVar3) break;
      iVar2 = iVar2 + -1;
      uVar3 = iVar2 == -1;
    } while (!(bool)uVar3);
  }
  *in_FS_OFFSET = uStack_124;
  puStack_11c = &LAB_0041a581;
  puStack_120 = (undefined1 *)0x41a579;
  FUN_00403b50((int *)&local_c);
  return;
}

