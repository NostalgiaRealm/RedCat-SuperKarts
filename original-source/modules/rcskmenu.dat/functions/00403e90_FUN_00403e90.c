/*
 * FUN_00403e90 at 00403e90
 * undefined __register FUN_00403e90(int * param_1, int param_2)
 * Address ranges: 00403e90-00403edb
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00403e90(int *param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar2 = 0;
  iVar4 = param_2;
  do {
    if (*(int *)(&stack0x00000000 + iVar4 * 4) != 0) {
      iVar2 = iVar2 + *(int *)(*(int *)(&stack0x00000000 + iVar4 * 4) + -4);
    }
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  puVar3 = FUN_00403c14(iVar2);
  puVar5 = puVar3;
  do {
    puVar1 = *(undefined4 **)(&stack0x00000000 + param_2 * 4);
    puVar6 = puVar5;
    if (puVar1 != (undefined4 *)0x0) {
      puVar6 = (undefined4 *)((int)puVar5 + puVar1[-1]);
      FUN_0040282c(puVar1,puVar5,puVar1[-1]);
    }
    param_2 = param_2 + -1;
    puVar5 = puVar6;
  } while (param_2 != 0);
  if (puVar3 != (undefined4 *)0x0) {
    puVar3[-2] = puVar3[-2] + -1;
  }
  FUN_00403ba4(param_1,puVar3);
                    /* WARNING: Could not recover jumptable at 0x00403eda. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(UNRECOVERED_JUMPTABLE);
  return;
}

