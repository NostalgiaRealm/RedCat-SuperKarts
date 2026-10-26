/*
 * FUN_00487c00 at 00487c00
 * undefined FUN_00487c00(void)
 * Address ranges: 00487c00-00487cc6
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Removing unreachable block (ram,0x00487c7b) */
/* WARNING: Removing unreachable block (ram,0x00487c81) */
/* WARNING: Removing unreachable block (ram,0x00487c97) */
/* WARNING: Removing unreachable block (ram,0x00487c99) */
/* WARNING: Removing unreachable block (ram,0x00487c9b) */

void __thiscall FUN_00487c00(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  
  if (((DAT_0053ba78 != 0) && (iVar1 = (**(code **)*param_1)(), 0 < iVar1)) &&
     (iVar5 = 0, 0 < iVar1)) {
    do {
      iVar2 = FUN_00486cb0();
      if (iVar2 == param_2) {
        iVar2 = *(int *)(param_1[1] + 4);
        puVar3 = (undefined4 *)(**(code **)(*param_1 + 8))();
        puVar6 = (undefined4 *)(iVar2 + iVar5 * 0x794);
        for (iVar4 = 0x1e5; iVar4 != 0; iVar4 = iVar4 + -1) {
          *puVar6 = *puVar3;
          puVar3 = puVar3 + 1;
          puVar6 = puVar6 + 1;
        }
        *(int *)(param_1[1] + 8) = *(int *)(param_1[1] + 8) + -0x794;
        iVar5 = iVar1;
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < iVar1);
  }
  return;
}

