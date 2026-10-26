/*
 * FUN_0047cd30 at 0047cd30
 * undefined FUN_0047cd30(void)
 * Address ranges: 0047cd30-0047ce42
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int * FUN_0047cd30(int *param_1,int *param_2)

{
  void **ppvVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  void *local_c;
  undefined1 *puStack_8;
  undefined1 local_4;
  undefined3 uStack_3;
  
  puStack_8 = &LAB_004d0fc1;
  local_c = ExceptionList;
  uStack_3 = 0;
  piVar4 = param_1;
  ppvVar1 = &local_c;
  if (param_1 == DAT_00544fb0) {
    *param_2 = (int)DAT_00544fb0;
    return param_1;
  }
  do {
    ExceptionList = ppvVar1;
    local_4 = 0;
    iVar3 = piVar4[0xb];
    piVar2 = operator_new(0x30);
    piVar2[1] = (int)param_2;
    piVar2[0xb] = iVar3;
    if (param_1 == piVar4) {
      param_1 = piVar2;
    }
    iVar3 = FUN_0047cd30(piVar4[2],piVar2);
    piVar2[2] = iVar3;
    local_4 = 1;
    if (piVar2 + 3 != (int *)0x0) {
      *(char *)(piVar2 + 3) = (char)piVar4[3];
      FUN_0040b4f0(0);
      FUN_00412870(piVar4 + 3,0,0xffffffff);
      local_4 = 2;
      FUN_0047d0c0(piVar4 + 7);
    }
    *param_2 = (int)piVar2;
    piVar4 = (int *)*piVar4;
    ppvVar1 = ExceptionList;
    param_2 = piVar2;
  } while (piVar4 != DAT_00544fb0);
  *piVar2 = (int)DAT_00544fb0;
  ExceptionList = local_c;
  return param_1;
}

