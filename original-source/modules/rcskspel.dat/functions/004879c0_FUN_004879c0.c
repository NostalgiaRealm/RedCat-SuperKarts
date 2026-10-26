/*
 * FUN_004879c0 at 004879c0
 * undefined FUN_004879c0(void)
 * Address ranges: 004879c0-00487a98
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Removing unreachable block (ram,0x00487a41) */
/* WARNING: Removing unreachable block (ram,0x00487a47) */
/* WARNING: Removing unreachable block (ram,0x00487a5d) */
/* WARNING: Removing unreachable block (ram,0x00487a5f) */
/* WARNING: Removing unreachable block (ram,0x00487a61) */

void __fastcall FUN_004879c0(int *param_1)

{
  int iVar1;
  char cVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  int iStack_8;
  
  if ((((DAT_0053ba78 != 0) && (DAT_0053ba60 != 0)) && (DAT_0053b9b0 == 0)) &&
     (iStack_8 = (**(code **)*param_1)(), 0 < iStack_8)) {
    iVar5 = 0;
    do {
      cVar2 = FUN_00487740();
      if (cVar2 != '\0') {
        iVar1 = *(int *)(param_1[1] + 4);
        puVar3 = (undefined4 *)(**(code **)(*param_1 + 8))();
        puVar6 = (undefined4 *)(iVar1 + iVar5);
        for (iVar4 = 0x1e5; iVar4 != 0; iVar4 = iVar4 + -1) {
          *puVar6 = *puVar3;
          puVar3 = puVar3 + 1;
          puVar6 = puVar6 + 1;
        }
        *(int *)(param_1[1] + 8) = *(int *)(param_1[1] + 8) + -0x794;
      }
      iVar5 = iVar5 + 0x794;
      iStack_8 = iStack_8 + -1;
    } while (iStack_8 != 0);
  }
  return;
}

