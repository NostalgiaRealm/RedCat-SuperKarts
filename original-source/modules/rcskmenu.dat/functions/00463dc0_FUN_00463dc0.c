/*
 * FUN_00463dc0 at 00463dc0
 * undefined __register FUN_00463dc0(int * param_1, int param_2)
 * Address ranges: 00463dc0-00463e3b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00463dc0(int *param_1,int param_2)

{
  char cVar1;
  undefined2 extraout_var;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_20;
  undefined1 *puStack_1c;
  undefined1 *puStack_18;
  int local_8;
  
  puStack_18 = &stack0xfffffffc;
  local_8 = 0;
  puStack_1c = &LAB_00463e3c;
  uStack_20 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_20;
  FUN_0043f64c((int)param_1,&local_8);
  cVar1 = FUN_0042984c(CONCAT22(extraout_var,*(undefined2 *)(param_2 + 4)),local_8);
  if (cVar1 != '\0') {
    cVar1 = FUN_00403088(param_1,extraout_EDX,extraout_ECX);
    if (cVar1 != '\0') {
      (**(code **)(*param_1 + 0xb0))();
      FUN_00464410(param_1);
      *(undefined4 *)(param_2 + 0xc) = 1;
      goto LAB_00463e26;
    }
  }
  FUN_0042597c(param_1,param_2);
LAB_00463e26:
  *in_FS_OFFSET = uStack_20;
  puStack_18 = &LAB_00463e43;
  puStack_1c = (undefined1 *)0x463e3b;
  FUN_00403b50(&local_8);
  return;
}

