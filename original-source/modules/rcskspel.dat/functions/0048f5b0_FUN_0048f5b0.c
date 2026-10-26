/*
 * FUN_0048f5b0 at 0048f5b0
 * undefined FUN_0048f5b0(void)
 * Address ranges: 0048f5b0-0048f5f7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_0048f5b0(int param_1,undefined4 param_2)

{
  int iVar1;
  
  *(undefined4 *)(param_1 + *(int *)(param_1 + 400) * 4) = param_2;
  iVar1 = *(int *)(param_1 + 400) + 1;
  *(int *)(param_1 + 400) = iVar1;
  if (99 < iVar1) {
    FUN_004afce0(s__s___d__num_alphaobjects_>_max___004fa420,
                 s_D__work_rcsk_Code_Engine_Prog_ob_004fa444,0x3d,100);
    *(undefined4 *)(param_1 + 400) = 99;
  }
  return;
}

