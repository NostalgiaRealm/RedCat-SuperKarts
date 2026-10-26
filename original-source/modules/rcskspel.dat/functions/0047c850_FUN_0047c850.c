/*
 * FUN_0047c850 at 0047c850
 * undefined FUN_0047c850(void)
 * Address ranges: 0047c850-0047c926
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_0047c850(int param_1,undefined4 *param_2,int *param_3,int *param_4)

{
  int *piVar1;
  void **ppvVar2;
  int *piVar3;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  piVar3 = param_4;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004d0f90;
  local_c = ExceptionList;
  ppvVar2 = &local_c;
  if (((*(int *)(param_1 + 0xc) == 0) ||
      (piVar1 = *(int **)(param_1 + 4), ppvVar2 = &local_c, param_3 != (int *)*piVar1)) ||
     (ppvVar2 = &local_c, param_4 != piVar1)) {
    while (ExceptionList = ppvVar2, param_3 != piVar3) {
      FUN_0047cf00();
      FUN_0047c930(&param_4,param_3);
      ppvVar2 = ExceptionList;
    }
  }
  else {
    local_4 = 1;
    piVar3 = (int *)piVar1[1];
    ExceptionList = &local_c;
    if ((int *)piVar1[1] != DAT_00544fb0) {
      do {
        FUN_0047ce50(piVar3[2]);
        piVar1 = (int *)*piVar3;
        FUN_0047d040(0);
        FUN_004bc150(piVar3);
        piVar3 = piVar1;
      } while (piVar1 != DAT_00544fb0);
    }
    *(int **)(*(int *)(param_1 + 4) + 4) = DAT_00544fb0;
    *(undefined4 *)(param_1 + 0xc) = 0;
    *(undefined4 *)*(undefined4 *)(param_1 + 4) = *(undefined4 *)(param_1 + 4);
    *(int *)(*(int *)(param_1 + 4) + 8) = *(int *)(param_1 + 4);
    param_3 = (int *)**(undefined4 **)(param_1 + 4);
  }
  *param_2 = param_3;
  ExceptionList = local_c;
  return;
}

