/*
 * FUN_004410fc at 004410fc
 * undefined FUN_004410fc(void)
 * Address ranges: 004410fc-0044115b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004410fc(int *param_1,int param_2)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  
  cVar1 = (**(code **)(*param_1 + 0x50))();
  if ((cVar1 == '\0') || (param_1[9] == 0)) {
    piVar2 = FUN_00440fe8(param_1,(undefined4 *)(*(int *)(param_2 + 8) + 0x44));
    if (piVar2 != (int *)0x0) {
      *(int **)(*(int *)(param_2 + 8) + 4) = piVar2;
      iVar3 = FUN_00445724(piVar2);
      *(int *)(*(int *)(param_2 + 8) + 8) = iVar3;
    }
  }
  else {
    FUN_00441070();
  }
  return;
}

