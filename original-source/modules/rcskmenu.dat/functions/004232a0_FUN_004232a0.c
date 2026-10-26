/*
 * FUN_004232a0 at 004232a0
 * undefined FUN_004232a0(void)
 * Address ranges: 004232a0-00423311
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004232a0(int *param_1,int param_2)

{
  char cVar1;
  undefined2 extraout_var;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_20;
  undefined1 *puStack_1c;
  undefined1 *puStack_18;
  int iStack_8;
  
  puStack_18 = &stack0xfffffffc;
  iStack_8 = 0;
  puStack_1c = &LAB_00423312;
  uStack_20 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_20;
  FUN_0043f64c((int)param_1,&iStack_8);
  cVar1 = FUN_0042984c(CONCAT22(extraout_var,*(undefined2 *)(param_2 + 4)),iStack_8);
  if (cVar1 != '\0') {
    cVar1 = FUN_00403088(param_1,extraout_EDX,extraout_ECX);
    if (cVar1 != '\0') {
      FUN_00445c74(param_1);
      *(undefined4 *)(param_2 + 0xc) = 1;
      goto LAB_004232fc;
    }
  }
  FUN_00444c4c((int)param_1,param_2);
LAB_004232fc:
  *in_FS_OFFSET = uStack_20;
  puStack_18 = &LAB_00423319;
  puStack_1c = (undefined1 *)0x423311;
  FUN_00403b50(&iStack_8);
  return;
}

