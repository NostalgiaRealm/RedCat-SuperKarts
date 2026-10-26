/*
 * FUN_0042597c at 0042597c
 * undefined __register FUN_0042597c(int * param_1, int param_2)
 * Address ranges: 0042597c-004259f1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0042597c(int *param_1,int param_2)

{
  char cVar1;
  undefined2 extraout_var;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_20;
  undefined1 *puStack_1c;
  undefined1 *puStack_18;
  int local_8;
  
  puStack_18 = &stack0xfffffffc;
  local_8 = 0;
  puStack_1c = &LAB_004259f2;
  uStack_20 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_20;
  FUN_0043f64c((int)param_1,&local_8);
  cVar1 = FUN_0042984c(CONCAT22(extraout_var,*(undefined2 *)(param_2 + 4)),local_8);
  if (cVar1 != '\0') {
    cVar1 = FUN_00403088(param_1,extraout_EDX,extraout_ECX);
    if (cVar1 != '\0') {
      FUN_00403088(param_1,extraout_EDX_00,extraout_ECX_00);
      *(undefined4 *)(param_2 + 0xc) = 1;
      goto LAB_004259dc;
    }
  }
  FUN_00444c4c((int)param_1,param_2);
LAB_004259dc:
  *in_FS_OFFSET = uStack_20;
  puStack_18 = &LAB_004259f9;
  puStack_1c = (undefined1 *)0x4259f1;
  FUN_00403b50(&local_8);
  return;
}

