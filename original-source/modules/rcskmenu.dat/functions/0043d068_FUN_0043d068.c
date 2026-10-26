/*
 * FUN_0043d068 at 0043d068
 * undefined FUN_0043d068(void)
 * Address ranges: 0043d068-0043d0c9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0043d068(int param_1,int *param_2)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  byte bVar5;
  
  bVar5 = 0;
  FUN_0043ceec(param_1,param_2);
  uVar1 = FUN_00403024(param_2,(int)&PTR_FUN_0043ae18);
  if ((char)uVar1 != '\0') {
    *(char *)(param_1 + 0x54) = (char)param_2[0x15];
    *(int *)(param_1 + 0x58) = param_2[0x16];
    *(char *)(param_1 + 0x6c) = (char)param_2[0x1b];
    piVar3 = param_2 + 0x11;
    piVar4 = (int *)(param_1 + 0x44);
    for (iVar2 = 4; iVar2 != 0; iVar2 = iVar2 + -1) {
      *piVar4 = *piVar3;
      piVar3 = piVar3 + (uint)bVar5 * -2 + 1;
      piVar4 = piVar4 + (uint)bVar5 * -2 + 1;
    }
    piVar3 = param_2 + 0x17;
    piVar4 = (int *)(param_1 + 0x5c);
    for (iVar2 = 4; iVar2 != 0; iVar2 = iVar2 + -1) {
      *piVar4 = *piVar3;
      piVar3 = piVar3 + (uint)bVar5 * -2 + 1;
      piVar4 = piVar4 + (uint)bVar5 * -2 + 1;
    }
    (**(code **)(**(int **)(param_1 + 0x40) + 8))(*(int **)(param_1 + 0x40),param_2[0x10]);
  }
  return;
}

